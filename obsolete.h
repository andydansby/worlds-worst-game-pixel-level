#ifndef OBSOLETE_H
#define OBSOLETE_H

//-----------------------------------------------------------------------
//	obsolete routines
//-----------------------------------------------------------------------





void enter_player_location (void)
{
	printf("Enter in your ship's location\n0 - 254\n");

	fgets(arrayInput,sizeof(arrayInput),stdin);
	player.tile_X_position = atoi(arrayInput);
	printf("\n\n");
	in_pause(200);
}


void print_player_location (void)
{
	printf("Player TILE position = %d\n", player.tile_X_position);
	printf("Press a Key");
	printf("\n\n");
	in_pause(400);
}

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

void clear_BaddyArray(void)
{
    for (temp6 = 0; temp6 < MAX_ENEMIES_ON_SCREEN; temp6 ++)
    {
        baddy[temp6].tile_X_position = 0;
        baddy[temp6].x_displacement = 0;
        baddy[temp6].y_position = 0;
        baddy[temp6].sprite_number = 0;
        baddy[temp6].movement = 0;
        baddy[temp6].energy = 0;
        baddy[temp6].param1 = 0;
        baddy[temp6].param2 = 0;
    }
}

void copy_to_baddies (unsigned char baddyArray, unsigned char enemyArray)
{
    //temp1
    baddy[baddyArray].tile_X_position = enemy_locations[enemyArray].tile_X_position;
    baddy[baddyArray].x_displacement  = enemy_locations[enemyArray].x_displacement;
    baddy[baddyArray].y_position      = enemy_locations[enemyArray].y_position;
    baddy[baddyArray].sprite_number   = enemy_locations[enemyArray].sprite_number;
    baddy[baddyArray].movement        = enemy_locations[enemyArray].movement;
    baddy[baddyArray].energy          = enemy_locations[enemyArray].energy;
    baddy[baddyArray].param1          = enemy_locations[enemyArray].param1;
    baddy[baddyArray].param2          = enemy_locations[enemyArray].param2;
}


void fill_baddies_array (void)
{
    clear_BaddyArray();//erasing the baddy struct

    unsigned char baddy_Scanner = 0;
    unsigned char window_scanner = window.windowLow;
    unsigned char baddy_count = 0;//no more than 10 entries

	//playerLow = player_x_position;
	//playerLow = player.x_position;
	playerLow = window.windowLow;

	//playerHigh = player_x_position + NEAR_PLAYER;
	//playerHigh = player.x_position + NEAR_PLAYER;
	playerHigh = window.windowHigh;


	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	while (baddy_count < MAX_ENEMIES_ON_SCREEN )
	{
		baddy_Scanner = enemy_locations[window_scanner].tile_X_position;

		if(baddy_Scanner > playerHigh)//if out of range
		{
		    return;
		    //break;
        }

        if(baddy_Scanner == 255)//if end of enemies list
		{
		    return;
		    //break;
        }

        if(baddy_Scanner < playerLow)//player has past by the baddy
        {
            baddy_count ++;
        }

		if (baddy_Scanner == 0)//to bypass deleted baddies
		{
		    window_scanner ++;
		}

		if((baddy_Scanner <= playerHigh) && (baddy_Scanner >= playerLow))
        {
            //copy to baddies struct
            baddy[baddy_count].tile_X_position  = enemy_locations[window_scanner].tile_X_position;
            baddy[baddy_count].x_displacement   = enemy_locations[window_scanner].x_displacement;
            baddy[baddy_count].y_position       = enemy_locations[window_scanner].y_position;
            baddy[baddy_count].sprite_number    = enemy_locations[window_scanner].sprite_number;
            baddy[baddy_count].movement         = enemy_locations[window_scanner].movement;
            baddy[baddy_count].energy           = enemy_locations[window_scanner].energy;
            baddy[baddy_count].param1           = enemy_locations[window_scanner].param1;
            baddy[baddy_count].param2           = enemy_locations[window_scanner].param2;
            //baddies[baddy_count].wherefrom = window_scanner;

            baddy_count ++;//found a baddy, increase count
        }


		window_scanner ++;

	}
}


void search_window_for_baddies (void)
{
    clear_BaddyArray();

    temp1 = player.tile_X_position;
    temp2 = 0;//no more than 10 entries  MAX_ENEMIES_ON_SCREEN = 10
	temp3 = 0;

	ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls


	unsigned char screenLow = player.tile_X_position - 1;
	unsigned char screenHigh = screenLow + 16;
	unsigned char playerHigh;

	unsigned char windowLow = window.windowLow;
	unsigned char windowHigh = window.windowHigh;
	unsigned char enemy_tile_location;

	unsigned char number_of_enemies = 0;//no more than 10 entries  MAX_ENEMIES_ON_SCREEN = 10

	// MAX_PLAYER_POS = 240
	if (screenHigh > MAX_PLAYER_POS)
    {
        screenHigh = MAX_PLAYER_POS;
        return;
    }

    while (windowLow < windowHigh )
    {
        enemy_tile_location = enemy_locations[windowLow].tile_X_position;

        printf("%d    \n", enemy_tile_location);
        windowLow ++;
    }


}




void print_pointer_address()
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;

	printf(" LEVEL_1_ENEMIES_LOCATIONS\n pointer address\n\n");

	printf("%u\n", pointerAddy);
	printf("%x\n", pointerAddy);


	printf("\nPress the ANY key\nWherever that is");
}


void search_enemy_array7 (void)
{//very close
    temp1 = player.tile_X_position - 1;
	temp2 = 0;//no more than 6 entries
	temp3 = 0;

	playerLow = player.tile_X_position;
	playerHigh = player.tile_X_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	while (temp2 < playerHigh )
	{
		temp3 = enemy_locations[temp1].x_displacement;

		if(temp3 > playerHigh)
		{	break;}//if out of range

		if (temp3 == 0)
		{	temp1 ++;}//to bypass deleted baddies

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

		//enemy_locations[temp1].tile_X_position;
		//enemy_locations[temp1].x_displacement;
		//enemy_locations[temp1].y_position;
		//enemy_locations[temp1].sprite_number;
		//enemy_locations[temp1].movement;
		//enemy_locations[temp1].energy;
		//enemy_locations[temp1].param1;
		//enemy_locations[temp1].param2;

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


/*void search_enemy_array8 (void)
{
    temp1 = player_x_position - 1;
	temp2 = 0;//no more than 6 entries
	temp3 = 0;

	playerLow = player_x_position;
	playerHigh = player_x_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	while (temp2 < playerHigh )
	{
		temp3 = enemy_locations[temp1].x_desp;

		if(temp3 > playerHigh)
		    return;
        if (temp3 < playerLow)
            temp1 ++;

		if (temp3 == 0)
		{	temp1 ++;}//to bypass deleted baddies

		printf("%d    ", enemy_locations[temp1].x_desp);
		printf("%d    ", enemy_locations[temp1].x);
		printf("%d    ", enemy_locations[temp1].y);
		printf("%d    ", enemy_locations[temp1].sprnum);
		printf("%d    ", enemy_locations[temp1].movement);
		printf("%d    ", enemy_locations[temp1].energy);
		printf("%d    ", enemy_locations[temp1].param1);
		printf("%d    ", enemy_locations[temp1].param2);
		printf("\n");

		temp1 ++;//44046

		temp2 ++;//44046
	}
}*/


////////////////////////
// good time plastic banana routines

void bananaBackup ()
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



//kinda works but starts messing up badly at position 7
//was banana
void banana1 (unsigned char Win_low)
{
    unsigned char mapScan;
	unsigned char Win_high = Win_low + window.windowSize;//High

	if (Win_high > MAX_PLAYER_POS)
		Win_high = MAX_PLAYER_POS;

    printf ("Win_low = %d  Win_high = %d  .windowSize = %d\n", Win_low, Win_high, window.windowSize );
    printf("----------------------------\n");
    for (mapScan = Win_low; mapScan < Win_high; mapScan ++)
    {

        temp3 = enemy_locations[mapScan].tile_X_position;




        if(temp3 > Win_high)//outside the range of the window
		{
		    return;
		}

		if(temp3 < Win_low)//outside the range of the window
		{
		    //only works with 1 baddy
		    mapScan++;
		}

		if (temp3 == 0)//skip over deleted baddies
		{
		    mapScan ++;
        }//to bypass deleted baddies

        printf("mapScan = %d  ", mapScan);
		printf("ENEMY = %d   ", enemy_locations[mapScan].tile_X_position);
		printf("%d   ", enemy_locations[mapScan].x_displacement);
		printf("%d   ", enemy_locations[mapScan].y_position);
		printf("%d   ", enemy_locations[mapScan].sprite_number);
		printf("%d   ", enemy_locations[mapScan].movement);
		printf("%d   ", enemy_locations[mapScan].energy);
		printf("%d   ", enemy_locations[mapScan].param1);
		printf("%d", enemy_locations[mapScan].param2);
		printf("\n");
    }//end for
}


void banana2 (void)
{
    //temp1 = player_x_position - 1;
    temp1 = player.tile_X_position - 1;


	temp2 = 0;//no more than 6 entries
	temp3 = 0;

	//playerLow = player_x_position;
	//playerHigh = player_x_position + NEAR_PLAYER;
	playerLow = player.tile_X_position;
	playerHigh = player.tile_X_position + NEAR_PLAYER;


	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

    printf("bannana2\n");

	while (temp2 < playerHigh )
	{
		//temp3 = enemy_locations[temp1].x_desp;
		temp3 = enemy_locations[temp1].tile_X_position;

		if(temp3 > playerHigh)
		{
		    return;
		}
        if (temp3 < playerLow)
        {
            temp1 ++;
        }
		if (temp3 == 0)
		{
		    temp1 ++;
        }//to bypass deleted baddies

		printf("%d    ", enemy_locations[temp1].tile_X_position);
		printf("%d    ", enemy_locations[temp1].x_displacement);
		printf("%d    ", enemy_locations[temp1].y_position);
		printf("%d    ", enemy_locations[temp1].sprite_number);
		printf("%d    ", enemy_locations[temp1].movement);
		printf("%d    ", enemy_locations[temp1].energy);
		printf("%d    ", enemy_locations[temp1].param1);
		printf("%d    ", enemy_locations[temp1].param2);
		printf("\n");

		temp1 ++;
		temp2 ++;
	}
}

void banana3 (unsigned char Win_low)
{
	temp2 = 0;//no more than 6 entries
	temp3 = 0;


	//unsigned char Win_low = window.windowLow;//Low
	unsigned char Win_high = Win_low + window.windowSize;//High
	unsigned char Win_scan = Win_low;   //Win_low;


	if (Win_high > MAX_PLAYER_POS)
		Win_high = MAX_PLAYER_POS;

    printf ("Win_low = %d  Win_high = %d  .windowSize = %d\n", Win_low, Win_high, window.windowSize );
    printf("bannana\n");

	while (Win_scan < Win_high )
	{
		temp3 = enemy_locations[Win_scan].tile_X_position;

		if(temp3 > Win_high)//outside the range of the window
		{
		    return;
		}
		if (temp3 == 0)
		{
		    Win_scan ++;
        }//to bypass deleted baddies


        //in question
        /*if (temp3 < Win_scan)
        {
            Win_scan ++;
        }*/

        printf("Win_scan = %d \n   ", Win_scan);
		printf("%d    ", enemy_locations[Win_scan].tile_X_position);
		printf("%d    ", enemy_locations[Win_scan].x_displacement);
		printf("%d    ", enemy_locations[Win_scan].y_position);
		printf("%d    ", enemy_locations[Win_scan].sprite_number);
		printf("%d    ", enemy_locations[Win_scan].movement);
		printf("%d    ", enemy_locations[Win_scan].energy);
		printf("%d    ", enemy_locations[Win_scan].param1);
		printf("%d    ", enemy_locations[Win_scan].param2);
		printf("\n");

		//temp1 ++;
		Win_scan ++;
	}
	printf("Ba Na Nuh\n");
}

void banana4 (unsigned char Win_low)
{
	temp2 = 0;//no more than 6 entries
	temp3 = 0;

    unsigned char temp99 = 0;
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
        if(temp3 > Win_high)//outside the range of the window
		{
		    return;
		}

		if (temp3 == 0)
		{
		    Win_scan ++;
        }//to bypass deleted baddies

        printf("temp99 = %d \n   ", temp99);
		printf("%d    ", enemy_locations[temp99].tile_X_position);
		printf("%d    ", enemy_locations[temp99].x_displacement);
		printf("%d    ", enemy_locations[temp99].y_position);
		printf("%d    ", enemy_locations[temp99].sprite_number);
		printf("%d    ", enemy_locations[temp99].movement);
		printf("%d    ", enemy_locations[temp99].energy);
		printf("%d    ", enemy_locations[temp99].param1);
		printf("%d    ", enemy_locations[temp99].param2);
		printf("\n");
    }

	printf("Ba Na Nuh\n");
}








#endif
//leave blank line after

