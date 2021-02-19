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














#endif
//leave blank line after

