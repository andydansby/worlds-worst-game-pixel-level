#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//used to print entire array
void print_enemy_location_array (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	//enemies_per_level =  cpu_bpeek(pointerAddy);	//how many enemies in array

	printf("enemy_locations Struct Members\n");
	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
        printf("%d\n", enemy_locations[temp1].tile_X_position);
		printf("%d\n", enemy_locations[temp1].x_displacement);
		printf("%d\n", enemy_locations[temp1].y_position);
		printf("%d\n", enemy_locations[temp1].sprite_number);
		printf("%d\n", enemy_locations[temp1].movement);
		printf("%d\n", enemy_locations[temp1].energy);
		printf("%d\n", enemy_locations[temp1].param1);
		printf("%d\n", enemy_locations[temp1].param2);

		printf("Array number %d\n", temp1);
		printf("***********************************\n");
	}
}




//-----------------------------------------------------------------------
//	other routines
//-----------------------------------------------------------------------

//keep
void pauseWipe (void)
{
	in_wait_key();
	in_pause(100);
	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");
}


//-------------------------------------------------------------
//	other routines
//-------------------------------------------------------------

//keep
unsigned char convert_pixel_to_tile (unsigned int pixel)
{
    //in this case, tile is 16 pixels wide
    //=SUM(C3 / 16)
    //C3 is pixel and D3 is calculation of C3
    unsigned char pixelTemp = pixel / 16;
    return pixelTemp;
}

//keep
unsigned int convert_tile_to_pixel (unsigned char tile, unsigned char offset)
{
    //in this case, tile is 16 pixels wide
    //=SUM(A3 * 16) + B3
    //A3 is tile, B3 is offset
    return (tile * 16) + offset;
}

//keep
void pauseScrolling (void)
{
    if (in_key_pressed( IN_KEY_SCANCODE_p ))
    {
        //ioctl(1, IOCTL_OTERM_PAUSE, 1);//stops auto scroll
        in_pause(600);
        printf("\nPress O to continue\n");
        in_pause(600);
        while (1)
        {
            if (in_key_pressed( IN_KEY_SCANCODE_o ))
            {
                break;
            }
        }
    }
}

//keep
void do_you_want_pausing (void)
{
    printf("\nDo you want (P)ausing or (C)ontinuous scrolling\n");
    while (1)
    {
        if (in_key_pressed( IN_KEY_SCANCODE_p ))
        {
            ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls and pause
            break;
        }
        if (in_key_pressed( IN_KEY_SCANCODE_c ))
        {
            ioctl(1, IOCTL_OTERM_PAUSE, 0);//continuously scrolls
            break;
        }
    }
}

//keep
void player_start_location (void)
{
    printf("Press P to pause scrolling\n\n");

	printf("Enter in player start tile    1 - 240    ");
	fgets(arrayInput,sizeof(arrayInput),stdin);
	playerStart = atoi(arrayInput);

	if (playerStart < 1)
        playerStart = 1;
    if (playerStart > 240)
        playerStart = 240;

	printf("\n");

	in_pause(600);
}

//keep
void fill_enemy_location_array (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer

	//enemies_per_level =  cpu_bpeek(pointerAddy);
	//intrinsic_label(enemies_per_level_results);

	enemies_per_level = cpu_bpeek(pointerAddy);

	pointerAddy ++;

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
	    enemy_locations[temp1].tile_X_position   = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].x_displacement  = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].y_position       = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].sprite_number    = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].movement	        = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].energy           = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param1           = cpu_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param2           = cpu_bpeek(pointerAddy);
		pointerAddy ++;
	}
}


/*
printf("player.x_displacement = %d   player.tile_X_position = %d  \n", player.x_displacement, player.tile_X_position);
printf("temp1 = %d   windowLow = %d  \n", temp1, window.windowLow);
printf("window.Low = %d   window.High = %d\n", window.windowLow, window.windowHigh);
printf("window.windowMax = %d   window.windowSize = %d\n", window.windowMax, window.windowSize);
printf("------------------------------------------------------\n");
*/


// from wwg 12-12-2020 version


void apple()
{
	//unsigned char enemyCounter = 0;
	unsigned char baddyStart = 0;
	unsigned char baddyEnd = 0;
	unsigned char enemyLow = 0;
	unsigned char enemyHigh = 0;

	unsigned char windowStart = player.tile_X_position - 1;
	unsigned char windowEnd = player.tile_X_position + NEAR_PLAYER;

	unsigned char arrayScan = 0;

	if (windowEnd > MAX_PLAYER_POS)
    {
		windowEnd = MAX_PLAYER_POS;
    }

    //need to find enemy closest to player in window
    for (temp1 = 0; temp1 < enemies_per_level; temp1++)
    {
        baddyStart = enemy_locations[temp1].tile_X_position;

        if (baddyStart == windowStart)
        {
            //found the lowest location in window
            enemyLow = temp1;
            break;
        }
    }

    //find the enemy furthest to player in window
    for (temp2 = temp1; temp2 < enemies_per_level; temp2++)
    {
        baddyEnd = enemy_locations[temp2].tile_X_position;

        if (baddyEnd == windowEnd)
        {
            //found the highest location in window
            enemyHigh = temp2;
            break;
        }
    }

    //show the ranges
    printf ("enemyLow = %d\n", enemyLow);
    printf ("enemyHigh = %d\n", enemyHigh);
    printf ("baddyStart = %d\n", baddyStart);
    printf ("baddyEnd = %d\n", baddyEnd);

    arrayScan = enemyLow;

    while (arrayScan <= enemyHigh)
	{
		baddyStart = enemy_locations[arrayScan].tile_X_position;

		if(baddyStart >= baddyEnd)
        {
            //printf("GREATER THAN\n");
            return;
        }//seems working

		if (baddyStart == 0)
		{
		    //printf("NOT EXISTING\n");
		    //baddy deleted
        }//to bypass deleted baddies

		printf("arrayScan=%d   \n", arrayScan);
        printf("%d    ", enemy_locations[arrayScan].tile_X_position);
        printf("%d    ", enemy_locations[arrayScan].x_displacement);
        printf("%d    ", enemy_locations[arrayScan].y_position);
        printf("%d    ", enemy_locations[arrayScan].sprite_number);
        printf("%d    ", enemy_locations[arrayScan].movement);
        printf("%d    ", enemy_locations[arrayScan].energy);
        printf("%d    ", enemy_locations[arrayScan].param1);
        printf("%d    ", enemy_locations[arrayScan].param2);
        printf("\n");

        arrayScan ++;
	}
}

//seems to be working
void orange ()
{
    unsigned char playerPosition = player.tile_X_position;

    unsigned char windowLow = player.tile_X_position - 1;
    unsigned char WinScan = windowLow;
    unsigned char WinHigh = player.tile_X_position + NEAR_PLAYER;

    unsigned char arrayScan = 0;
    unsigned char playerLow = player.tile_X_position;
	unsigned char playerHigh = player.tile_X_position + NEAR_PLAYER;
	unsigned char baddyLocation;


	if (WinHigh > MAX_PLAYER_POS)
		WinHigh = MAX_PLAYER_POS;

    baddyLocation  = enemy_locations[arrayScan].tile_X_position;

    while (baddyLocation < windowLow)
    {
        arrayScan ++;
        baddyLocation = enemy_locations[arrayScan].tile_X_position;
    }

    //no more than 6 entries
    while (arrayScan <= WinHigh )
	{
		baddyLocation = enemy_locations[arrayScan].tile_X_position;

		if(baddyLocation >= WinHigh)
        {
            //printf("GREATER THAN\n");
            return;
        }//seems working

		if (baddyLocation == 0)
		{
		    //printf("NOT EXISTING\n");
		    //temp1 ++;
        }//to bypass deleted baddies


		printf("arrayScan=%d   ", arrayScan);
        printf("%d    ", enemy_locations[arrayScan].tile_X_position);
        printf("%d    ", enemy_locations[arrayScan].x_displacement);
        printf("%d    ", enemy_locations[arrayScan].y_position);
        printf("%d    ", enemy_locations[arrayScan].sprite_number);
        printf("%d    ", enemy_locations[arrayScan].movement);
        printf("%d    ", enemy_locations[arrayScan].energy);
        printf("%d    ", enemy_locations[arrayScan].param1);
        printf("%d    ", enemy_locations[arrayScan].param2);
        printf("\n");

        arrayScan ++;
	}

}

//working but native approach
void banana ()//working but native approach
{
    unsigned char Win_scan = 0;
    unsigned char Win_start = 0;
    unsigned char Win_position = 0;
    unsigned char Baddy_tile = 0;

    //try not to go over 6-10 enemies at a time
    //otherwise will get too slow
    temp1 = window.windowLow;
    temp2 = window.windowHigh;

	if (temp2 > MAX_PLAYER_POS)
		temp2 = MAX_PLAYER_POS;

    printf (".windowLow = %d  .windowHigh = %d  .windowSize = %d\n", temp1, temp2, Win_scan );
    printf("bannana\n");

    for (Win_position = 0; Win_position < 255; Win_position ++)
    {
        for (Win_scan = Win_start; Win_scan < 255; Win_scan ++)
        {
            Baddy_tile = enemy_locations[Win_scan].tile_X_position;

            if (Baddy_tile < temp1)//below
            {
                Win_start ++;
                break;
            }

            if (Baddy_tile > temp2)//above
            {
                return;
            }

            //printf("Win_position= %d  Win_scan= %d Win_start= %d", Win_position,Win_scan,Win_start);

            printf("Win_scan=%d   ", Win_scan);
            printf("%d    ", enemy_locations[Win_scan].tile_X_position);
            printf("%d    ", enemy_locations[Win_scan].x_displacement);
            printf("%d    ", enemy_locations[Win_scan].y_position);
            printf("%d    ", enemy_locations[Win_scan].sprite_number);
            printf("%d    ", enemy_locations[Win_scan].movement);
            printf("%d    ", enemy_locations[Win_scan].energy);
            printf("%d    ", enemy_locations[Win_scan].param1);
            printf("%d    ", enemy_locations[Win_scan].param2);
            printf("\n");
        }
    }
	printf("Ba Na Nuh\n");
}


/*printf("Win_scan = %d \n   ", Win_scan);
		printf("%d    ", enemy_locations[Win_scan].tile_X_position);
		printf("%d    ", enemy_locations[Win_scan].x_displacement);
		printf("%d    ", enemy_locations[Win_scan].y_position);
		printf("%d    ", enemy_locations[Win_scan].sprite_number);
		printf("%d    ", enemy_locations[Win_scan].movement);
		printf("%d    ", enemy_locations[Win_scan].energy);
		printf("%d    ", enemy_locations[Win_scan].param1);
		printf("%d    ", enemy_locations[Win_scan].param2);
		printf("\n");*/


void bananaWORKS ()
{
    //try not to go over 6-10 enemies at a time
    //otherwise will get too slow
    temp1 = window.windowLow;
    temp2 = window.windowHigh;
    temp3 = window.windowSize;
	temp4 = window.windowMax;
	temp8 = 0;//used to read tile position of baddy


    unsigned char Win_scan = 0;
    unsigned char Win_win = 0;
	unsigned char Win_start = 0;

	if (temp2 > MAX_PLAYER_POS)
		temp2 = MAX_PLAYER_POS;

    printf (".windowLow = %d  .windowHigh = %d  .windowSize = %d\n", temp1, temp2, temp3 );
    printf("bannana\n");

    for (Win_win = 0; Win_win < 255; Win_win ++)//for (Win_win = 0; Win_win < 15; Win_win ++)
    {
        for (Win_scan = Win_start; Win_scan < 255; Win_scan ++)
        {
            temp8 = enemy_locations[Win_scan].tile_X_position;

            if (temp8 < temp1)//below
            {
                Win_start ++;
                break;
            }

            if (temp8 > temp2)//above
            {
                return;
            }

            //printf("Win_win= %d  Win_scan= %d Win_start= %d", Win_win,Win_scan,Win_start);

            printf("Win_scan=%d   ", Win_scan);
            printf("%d    ", enemy_locations[Win_scan].tile_X_position);
            printf("%d    ", enemy_locations[Win_scan].x_displacement);
            printf("%d    ", enemy_locations[Win_scan].y_position);
            printf("%d    ", enemy_locations[Win_scan].sprite_number);
            printf("%d    ", enemy_locations[Win_scan].movement);
            printf("%d    ", enemy_locations[Win_scan].energy);
            printf("%d    ", enemy_locations[Win_scan].param1);
            printf("%d    ", enemy_locations[Win_scan].param2);
            printf("\n");
        }
    }
	printf("Ba Na Nuh\n");
}



void bannanaTest (unsigned char Win_low)
{
	temp2 = 0;//no more than 6 entries
	temp3 = 0;

    unsigned char temp99;
	//unsigned char Win_low = window.windowLow;//Low
	unsigned char Win_high = Win_low + window.windowSize;//High
	unsigned char Win_scan = Win_low;   //Win_low;


	if (Win_high > MAX_PLAYER_POS)
		Win_high = MAX_PLAYER_POS;

    printf ("Win_low = %d  Win_high = %d  .windowSize = %d\n", Win_low, Win_high, window.windowSize );
    printf("bannana\n");

    //for (temp99 = Win_low; temp99 < Win_high; temp99 ++)//indexes wrong
    for (temp99 = 0; temp99 < 240; temp99 ++)
    {
        temp3 = enemy_locations[temp99].tile_X_position;
        printf("temp99 = %d   ", temp99);
        printf("enemy_locations.tile_X_position = %d   ", temp3);
        printf("\n");

        /*printf("temp99 = %d \n   ", temp99);
		printf("%d    ", enemy_locations[temp99].tile_X_position);
		printf("%d    ", enemy_locations[temp99].x_displacement);
		printf("%d    ", enemy_locations[temp99].y_position);
		printf("%d    ", enemy_locations[temp99].sprite_number);
		printf("%d    ", enemy_locations[temp99].movement);
		printf("%d    ", enemy_locations[temp99].energy);
		printf("%d    ", enemy_locations[temp99].param1);
		printf("%d    ", enemy_locations[temp99].param2);
		printf("\n");*/
    }

	printf("Ba Na Nuh\n");
}





#endif
//leave blank line after


