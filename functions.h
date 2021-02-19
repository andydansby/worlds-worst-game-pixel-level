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

void printBaddyArray(void)
{
    for (temp6 = 0; temp6 < 10; temp6 ++)
    {
        //printf("FQU\n");
        printf("%d    ", baddy[temp6].tile_X_position);
        printf("%d    ", baddy[temp6].x_displacement);
        printf("%d    ", baddy[temp6].y_position);
        printf("%d    ", baddy[temp6].sprite_number);
        printf("%d    ", baddy[temp6].movement);
        printf("%d    ", baddy[temp6].energy);
        printf("%d    ", baddy[temp6].param1);
        printf("%d    ", baddy[temp6].param2);
        //printf("\nFQU\n");
        printf("\n");
    }
}

void copy_to_baddies (unsigned char arrayMembers)
{
    //temp1
    baddy[arrayMembers].tile_X_position = enemy_locations[temp1].tile_X_position;
    baddy[arrayMembers].x_displacement  = enemy_locations[temp1].x_displacement;
    baddy[arrayMembers].y_position      = enemy_locations[temp1].y_position;
    baddy[arrayMembers].sprite_number   = enemy_locations[temp1].sprite_number;
    baddy[arrayMembers].movement        = enemy_locations[temp1].movement;
    baddy[arrayMembers].energy          = enemy_locations[temp1].energy;
    baddy[arrayMembers].param1          = enemy_locations[temp1].param1;
    baddy[arrayMembers].param2          = enemy_locations[temp1].param2;
}


void printIt (void)
{
    //this is when the search area (temp1) finds an enemy on the same tile
    printf("%d    ", enemy_locations[temp8].tile_X_position);
    printf("%d    ", enemy_locations[temp8].x_displacement);
    printf("%d    ", enemy_locations[temp8].y_position);
    printf("%d    ", enemy_locations[temp8].sprite_number);
    printf("%d    ", enemy_locations[temp8].movement);
    printf("%d    ", enemy_locations[temp8].energy);
    printf("%d    ", enemy_locations[temp8].param1);
    printf("%d    ", enemy_locations[temp8].param2);
    printf("\n");
}


//last one was search_window_for_baddies3
void search_window_for_baddies (void)
{
    //sliding window algorithm
    unsigned char number_of_baddies = 0;
    unsigned char sliding_window = window.windowLow;
    unsigned char baddy_tile_placement = 0;
    unsigned char arrayMembers = 0;
    unsigned char windowLow = window.windowLow;
    unsigned char windowHigh = window.windowHigh;

    printf("windowLow = %d  windowHigh = %d\n", window.windowLow, window.windowHigh);
    while (arrayMembers < 10)//.no more than 10 members
    {
        for (temp1 = windowLow; temp1 < windowHigh; ++temp1)//move search bar through window
        {
            temp2 = enemy_locations[baddy_tile_placement].tile_X_position;


            if (temp2 == 255)//end of enemy list
            {
                //printf("FOUND END of baddies\n");
                return;
            }
            if (temp2 > windowHigh)//end of enemy list
            {
                //printf("TOP end of Range\n");
                return;
            }
            //if (sliding_window == 15)
            if (sliding_window >= windowHigh)//end of enemy range outside of window
            {
                //printf("END of window\n");
                return;
            }

//            printf("arrayMembers= %d  baddy_tile_placement= %d\n", arrayMembers, baddy_tile_placement);
//            printf("temp1= %d  sliding_window= %d  temp2=  [ %d ] \n", temp1, sliding_window, temp2);

            if (temp2 == 0)//enemy was destroyed
            {
                //printf("DEAD BADDY\n");
                ++ sliding_window;
            }

            //if ((temp2 > 0) && (temp2 < 255))
            if ((temp2 > windowLow) && (temp2 < windowHigh))//found an active baddy
            {
                //printf("MATCH and Copy\n");
                copy_to_baddies(temp1);
                ++ baddy_tile_placement;
                ++ arrayMembers;
            }



            ++ sliding_window;

        }//end for
    }//end while
    //printf("end while\n\n");
    //printBaddyArray();
}







//very close
void search_enemy_array (void)
{
    //player must start at tile 1 or higher
    temp1 = player.tile_X_position - 1;
	temp2 = 0;//no more than 6 enemies at a time
	temp3 = 0;

	//player low should be player.tile_X_position + window size of some sort

	playerLow = player.tile_X_position;
	playerHigh = player.tile_X_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

    //while (temp2 < playerHigh )
    //while (temp1 < playerHigh )nope
	while (temp2 < playerHigh )
	{
		temp3 = enemy_locations[temp1].x_displacement;

		if(temp3 > playerHigh)
		    return;
        if (temp3 < playerLow)
            temp1 ++;

		if (temp3 == 0)
		{	temp1 ++;}//to bypass deleted enemies

		/*printf("\ntemp1 = %d", temp1);
		printf("     temp2 = %d", temp2);
		printf("     temp3 = %d", temp3);*/

		printf("%d    ", enemy_locations[temp1].x_displacement);
		printf("%d    ", enemy_locations[temp1].tile_X_position);
		printf("%d    ", enemy_locations[temp1].y_position);
		printf("%d    ", enemy_locations[temp1].sprite_number);
		printf("%d    ", enemy_locations[temp1].movement);
		printf("%d    ", enemy_locations[temp1].energy);
		printf("%d    ", enemy_locations[temp1].param1);
		printf("%d    ", enemy_locations[temp1].param2);
		printf("\n");

		//
        //defb 01, 11, 10, 1, bob, 01, $aa, 00;0
        //defb 02, 12, 20, 2, bob, 02, $aa, 01;1
        //defb 03, 13, 30, 3, bob, 03, $aa, 02;2
        //defb 04, 14, 40, 4, bob, 04, $aa, 03;3
        //defb 05, 15, 50, 5, bob, 05, $aa, 04;4
        //defb 05, 16, 60, 5, bob, 05, $aa, 05;5
        //defb 06, 17, 70, 6, bob, 06, $aa, 06;6
        //defb 07, 18, 80, 7, bob, 07, $aa, 07;7
        //defb 08, 19, 90, 9, bob, 08, $aa, 08;8
        //defb 09, 19, 99, 9, bob, 09, $fe, 09;9
        ////////////////////////////////////////////////
        //defb $ff, $ff, 80, 2, bob, 10, $ff, $ff
        // dummy enemy, to mark the end

		temp1 ++;//44046
		//++ temp1;//44051

		temp2 ++;//44046
		//++ temp2;//44048
	}
}

















//enemy_locations is large array
void clean_enemy_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		if (indexToDelete[temp1] != MAX_U_CHAR)
		{
			enemyToDelete = indexToDelete[temp1];

			enemy_locations[enemyToDelete].x_displacement	= 0;
			enemy_locations[enemyToDelete].tile_X_position = 0;
			enemy_locations[enemyToDelete].y_position = 0;
			enemy_locations[enemyToDelete].sprite_number = 0;
			enemy_locations[enemyToDelete].movement = 0;
			enemy_locations[enemyToDelete].energy = 0;
			enemy_locations[enemyToDelete].param1 = 0;
			enemy_locations[enemyToDelete].param2 = 0;
		}
	}
}








#endif
//leave blank line after


