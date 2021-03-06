// this is a place to put all of the unused funtions
// so that memory can be reduced

// ISLAND of MISFIT FUNCTIONS_H

{//numbers

//xorshift8 takes 12 ms to run
//full = 44149
//fill_baddies_array(); = 44146 = 3 ms
//auto_enemy_to_delete = 44139 = 7 ms
//index_cleared_baddies = 44146 = 3 ms
//clean_baddies_array = 44146 = 3 ms
//clean_enemy_array = 44146 = 3 ms

//44129 with adjustment in fill_baddies_array()
//	player.x_position ++;	44145
//	++ player.x_position;	44144
}



//we will need to eliminate
struct baddies
{
    unsigned char tile_X_position;
    // Displacement in tile (0-23) enemy position within tile
	unsigned char x_displacement;
	// Tile in X
	unsigned int x_position;
	// X position 0-255 (4080)
	unsigned char y_position;
	// Y position 0-172
	unsigned char sprite_number;	// Number of the enemy sprite: if 0, this enemy is not active
	unsigned char movement;	// movement type, from one of the predefined ones
	unsigned char energy;
	unsigned char param1;
	unsigned char param2;	// Two parameters, to store some information that is entity-specific
	signed int wherefrom;   //question, why is this a signed int?
} baddies[MAX_ENEMIES_ON_SCREEN];

//baddies[xx].wherefrom




void enter_enemy_to_delete (void)
{
	//unsigned int arrayInput[5];
	enemyToDelete = 254;
	printf("--------------------------------------------------\n");
	printf("Enter in enemy to kill    0 - 5    Enter = none  ");
	//fgets(arrayInput,sizeof(arrayInput),stdin);
	printf("\n-------------------------------- ------------------\n");
	gets(arrayInput);

	in_wait_nokey();

	if (strlen(arrayInput) == 0)
	{
		printf("\nNone selected \n");
		enemyToDelete = MAX_U_CHAR;
		printf("\n NONE Selected for removal \n");
   }
	else
   {
		enemyToDelete = atoi(arrayInput);
		printf("\n Variable enemyToDelete = %d", enemyToDelete);
		printf("\n %d Selected for removal \n", baddies[enemyToDelete].tile_X_position);
   }

	in_pause(500);

}

void print_delete_index (void)
{
	temp2 = 0;
	temp3 = 0;
	printf("\n");
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		printf("%d ) indexed entry %d\n", temp1, indexToDelete[temp1]);

		if (indexToDelete[temp1] == MAX_U_CHAR )
		{
			temp2 ++;
		}
		else
		{
			temp3 ++;
		}
	}
	printf("number of entries %d\n", temp3);
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

void Speed_test (void)
{
	player.tile_X_position = 0;

	fill_enemy_location_array (); // this is large array filled in with level info

	ms_start = timer();//just before our loop

	//44070 with nothing but loop
	//44099 with everything in loop
	while (player.tile_X_position < 250)
	{
		fill_baddies_array();

		decision = xorshift8() %6;
		//decision = 3;
		//min is 0 and 5 is max with %6

		auto_enemy_to_delete();

		index_cleared_baddies();
		//clean_baddies_array();

		clean_enemy_array();

		++ player.tile_X_position;
	}
	ms_end = timer();
	ms_diff = ms_end - ms_start;

	printf("finished in  %ld ms\n",ms_diff);
}

unsigned int timer (void)
{
	clock_1 = cpu_bpeek(23672);
	clock_2 = cpu_bpeek(23673);
	clock_3 = cpu_bpeek(23674);
	clock_4 = (65535*clock_3+256*clock_2+clock_1)/50;
	return clock_4;
}


// returns values from 1 to 255 inclusive, period is 255
unsigned char xorshift8(void) {
    //random number generator
    y8 ^= (y8 << 7);
    y8 ^= (y8 >> 5);
    return y8 ^= (y8 << 3);
}


void search_enemy_array_que (void)
{
    //signed int s_int_temp1 = 0;

	playerLow = player_x_desp_position;
	playerHigh = player_x_desp_position + NEAR_PLAYER;//   NEAR_PLAYER = 2

	if (playerHigh > MAX_PLAYER_POS)
    {
        //MAX_PLAYER_POS = 255
		playerHigh = MAX_PLAYER_POS;
    }

    //printf("WTF1\n");
    printf("playerLow = %d", playerLow);
    printf("      ");
    printf("playerHigh = %d\n", playerHigh);
    printf("\n");


    for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; temp1 ++)
    //for (temp2 = 0; temp2 < MAX_ENEMIES_ON_SCREEN; temp2 ++)
    {
        temp3 = enemy_locations[temp2].x_desp;

        if ((temp3 >= playerLow) && (temp3 <= playerHigh) )
        {
            temp2 = temp1 + playerLow;

            printf("--------------------------\n");
            printf("temp1 = %d", temp1);
            printf("      ");
            printf("temp2 = %d", temp2);
            printf("      ");
            printf("s_int_temp1 = %d", s_int_temp1);
            printf("      ");
            printf("temp3 = %d\n", temp3);
            printf("--------------------------\n");



            //if (temp3 == 0)
            //{	temp1 ++;}//to bypass deleted baddies

            printf("x_desp = %d\n", enemy_locations[temp2].x_desp);

            printf("x = %d", enemy_locations[temp2].x);
            printf("        ");
            printf("y = %d\n", enemy_locations[temp2].y);

            printf("sprnum = %d", enemy_locations[temp2].sprnum);
            printf("        ");
            printf("movement = %d", enemy_locations[temp2].movement);
            printf("        ");
            printf("energy = %d\n", enemy_locations[temp2].energy);

            printf("param1 = %d", enemy_locations[temp2].param1);
            printf("        ");
            printf("param2 = %d\n", enemy_locations[temp2].param2);

            //printf("--------------------------\n");
        }

    }
}

void search_near_to_player (void)
{
	//#define cpu_bpeek(a)    (*(unsigned char *)(a))
	//player.x_displacement  = where the player is
	//player.tile_X_position = where the player is
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	//enemies_per_level =  cpu_bpeek(pointerAddy);

	playerLow = player.tile_X_position - 2;
	playerHigh = player.tile_X_position + 2;

	if (playerLow < 0)
		playerLow = 0;
	if (playerHigh > 254)
		playerHigh = 254;
}

void print_enemy_array (void)
{
	printf("\nEnemy Array\n");

	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
			printf("%d)---", temp1);

			printf("%d    ", enemy_locations[temp1].tile_X_position);
            printf("%d    ", enemy_locations[temp1].x_displacement);
			printf("%d    ", enemy_locations[temp1].y_position);
			printf("%d    ", enemy_locations[temp1].sprite_number);
			printf("%d    ", enemy_locations[temp1].movement);
			printf("%d    ", enemy_locations[temp1].energy);
			printf("%d    ", enemy_locations[temp1].param1);
			printf("%d    ", enemy_locations[temp1].param2);
			//wherefrom
			printf("\n");
			//printf("----------------------------------------------------\n");
	}
	//printf("\n\nPress a Key");
}

void print_entire_enemy_array (void)
{
	printf("\nPress x to quit\n\n");
	for (temp1 = 0; temp1 < MAX_ENEMIES; ++ temp1)
	{
		printf("%d)---", temp1);

		printf("%d    ", enemy_locations[temp1].x_displacement);
		printf("%d    ", enemy_locations[temp1].tile_X_position);
		printf("%d    ", enemy_locations[temp1].y_position);
		printf("%d    ", enemy_locations[temp1].sprite_number);
			//printf("\n");
		printf("%d    ", enemy_locations[temp1].movement);
		printf("%d    ", enemy_locations[temp1].energy);
		printf("%d    ", enemy_locations[temp1].param1);
		printf("%d    ", enemy_locations[temp1].param2);
		printf("\n");

		if (in_key_pressed( IN_KEY_SCANCODE_x ))
		{
			break;
		}
	}
	printf("\nPress ENTER\n");
	in_wait_nokey();
}

void print_arrays (void)
{
	printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
	while (1)
	{
		if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_entire_enemy_array();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}
		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_baddies_array();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}
		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			print_delete_index();
			printf("\n1 for the entire enemy array\n2 for the baddies array\n3 for the delete index\nPress ENTER for next");
		}
			//print_delete_index
		if (in_key_pressed( IN_KEY_SCANCODE_ENTER ))
		{
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			break;
		}
	}
	in_wait_nokey();
}


//not using baddies array any longer
void purge_baddies_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; temp1 ++)
	{
		//clean baddies array
		baddies[temp1].x_displacement = 0;
		baddies[temp1].tile_X_position = 0;
		baddies[temp1].y_position = 0;
		baddies[temp1].sprite_number = 0;
		baddies[temp1].movement = 0;
		baddies[temp1].energy = 0;
		baddies[temp1].param1 = 0;
		baddies[temp1].param2 = 0;
		baddies[temp1].wherefrom = 0;
	}
}

//not using baddies array any longer
void fill_baddies_array(void)
{
	temp2 = 0;//no more than 6 entries
	temp1 = player.tile_X_position -1;

	playerLow = player.tile_X_position;
	playerHigh = player.tile_X_position + NEAR_PLAYER;

	if (playerHigh > MAX_PLAYER_POS)
		playerHigh = MAX_PLAYER_POS;

	while (temp2 < MAX_ENEMIES_ON_SCREEN )
	{
		temp3 = enemy_locations[temp1].tile_X_position;

		if(temp3 > playerHigh)
		{	break;}//if out of range

		if (temp3 == 0)
		{	temp1 ++;}//to bypass deleted baddies

		/*printf("\ntemp1 = %d", temp1);
		printf("     temp2 = %d", temp2);
		printf("     temp3 = %d", temp3);*/

		//copy to baddies struct
		baddies[temp2].x_displacement   = enemy_locations[temp1].x_displacement;
		baddies[temp2].tile_X_position  = enemy_locations[temp1].tile_X_position;
		baddies[temp2].y_position       = enemy_locations[temp1].y_position;
		baddies[temp2].sprite_number    = enemy_locations[temp1].sprite_number;
		baddies[temp2].movement         = enemy_locations[temp1].movement;
		baddies[temp2].energy           = enemy_locations[temp1].energy;
		baddies[temp2].param1           = enemy_locations[temp1].param1;
		baddies[temp2].param2           = enemy_locations[temp1].param2;
		baddies[temp2].wherefrom        = temp1;

		temp1 ++;//44046
		//++ temp1;//44051

		temp2 ++;//44046
		//++ temp2;//44048
	}
}

//not using baddies array any longer
void print_baddies_array (void)
{
	printf("\nBaddies Array\n");

	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
			printf("%d)---", temp1);

			printf("%d    ", baddies[temp1].x_displacement);
			printf("%d    ", baddies[temp1].tile_X_position);
			printf("%d    ", baddies[temp1].y_position);
			printf("%d    ", baddies[temp1].sprite_number);
			//printf("\n");
			printf("%d    ", baddies[temp1].movement);
			printf("%d    ", baddies[temp1].energy);
			printf("%d    ", baddies[temp1].param1);
			printf("%d    ", baddies[temp1].param2);
			printf("%d    ", baddies[temp1].wherefrom);
			//wherefrom
			printf("\n");
			//printf("----------------------------------------------------\n");
	}
	//printf("\n\nPress a Key");
}

//not using baddies array any longer
void auto_enemy_to_delete (void)
{
	enemyToDelete = decision;

	//tag baddy entry
	baddies[enemyToDelete].x_displacement	= 0;
	baddies[enemyToDelete].tile_X_position = 0;//<---
	baddies[enemyToDelete].y_position = 0;
	baddies[enemyToDelete].sprite_number = MAX_U_CHAR;
	baddies[enemyToDelete].movement = 0;
	baddies[enemyToDelete].energy = 0;
	baddies[enemyToDelete].param1 = 0;
	baddies[enemyToDelete].param2 = 0;
}

void delete_single_baddy (void)
{
	for (temp1 = enemyToDelete; temp1 < MAX_ENEMIES_ON_SCREEN -1; temp1 ++)
	{
		baddies[temp1].x_displacement   = baddies[temp1 + 1].x_displacement;
		baddies[temp1].tile_X_position  = baddies[temp1 + 1].tile_X_position;
		baddies[temp1].y_position       = baddies[temp1 + 1].y_position;
		baddies[temp1].sprite_number    = baddies[temp1 + 1].sprite_number;
		baddies[temp1].movement         = baddies[temp1 + 1].movement;
		baddies[temp1].energy           = baddies[temp1 + 1].energy;
		baddies[temp1].param1           = baddies[temp1 + 1].param1;
		baddies[temp1].param2           = baddies[temp1 + 1].param2;
	}
}


void print_nearest_baddies(void)
{
	printf("Nearest Baddies\n");

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		if ((enemy_locations[temp1].tile_X_position >= playerLow) && (enemy_locations[temp1].tile_X_position <= playerHigh) )
		{
			printf("%d)---", temp1);

			printf("%d    ", enemy_locations[temp1].x_displacement);
			printf("%d    ", enemy_locations[temp1].tile_X_position);
			printf("%d    ", enemy_locations[temp1].y_position);
			printf("%d    ", enemy_locations[temp1].sprite_number);
			//printf("\n");
			printf("%d    ", enemy_locations[temp1].movement);
			printf("%d    ", enemy_locations[temp1].energy);
			printf("%d    ", enemy_locations[temp1].param1);
			printf("%d    ", enemy_locations[temp1].param2);
			printf("\n");
			printf("----------------------------------------------------\n");
		}
	}
	printf("\n\nPress a Key");
}

void index_cleared_baddies (void)
{
	temp2 = 0;
	number_of_index_baddies = 0;

	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		if (baddies[temp1].sprite_number == MAX_U_CHAR)//<---
		{
			indexToDelete[temp2] = baddies[enemyToDelete].wherefrom;
			number_of_index_baddies ++;
		}
		else
		{
			indexToDelete[temp2] = MAX_U_CHAR;
		}

		//now clean baddies array at the same time to speed things along
		baddies[temp1].x_displacement = 0;
		baddies[temp1].tile_X_position = 0;
		baddies[temp1].y_position =  0;
		baddies[temp1].sprite_number = 0;
		baddies[temp1].movement = 0;
		baddies[temp1].energy = 0;
		baddies[temp1].param1 = 0;
		baddies[temp1].param2 = 0;
		baddies[temp1].wherefrom = 0;

		temp2 ++;
	}
}

void clean_baddies_array (void)
{
	for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; ++ temp1)
	{
		baddies[temp1].x_displacement = 0;
		baddies[temp1].tile_X_position = 0;
		baddies[temp1].y_position =  0;
		baddies[temp1].sprite_number = 0;
		baddies[temp1].movement = 0;
		baddies[temp1].energy = 0;
		baddies[temp1].param1 = 0;
		baddies[temp1].param2 = 0;
		baddies[temp1].wherefrom = 0;
	}
}

/////////////////////////////


void search_exact_to_player (void)
{
	//player.tile_X_position  = where the player is
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	//enemies_per_level =  cpu_bpeek(pointerAddy);

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
		if (enemy_locations[temp1].tile_X_position == player.tile_X_position)
		{
			printf("%d\n", enemy_locations[temp1].x_displacement);
			printf("%d\n", enemy_locations[temp1].tile_X_position);
			printf("%d\n", enemy_locations[temp1].y_position);
			printf("%d\n", enemy_locations[temp1].sprite_number);
			printf("%d\n", enemy_locations[temp1].movement);
			printf("%d\n", enemy_locations[temp1].energy);
			printf("%d\n", enemy_locations[temp1].param1);
			printf("%d\n", enemy_locations[temp1].param2);
			printf("---------\n");
		}
	}
	printf("\n\nPress a Key");
}



void search_enemy_array2 (void)
{
    temp2 = 0;//no more than 6 entries
	temp1 = player.x_displacement;

	playerLow = player.x_displacement;
	playerHigh = player.x_displacement + NEAR_PLAYER;//   NEAR_PLAYER = 2

	if (playerHigh > MAX_PLAYER_POS)    //MAX_PLAYER_POS = 255
		playerHigh = MAX_PLAYER_POS;


    //printf("WTF1\n");

    while (temp2 < MAX_ENEMIES_ON_SCREEN )  //MAX_ENEMIES_ON_SCREEN = 6
	{
	    //printf("WTF2\n");


		temp3 = enemy_locations[temp1].x_displacement;

		if(temp3 > playerHigh)
		{	break;}//if out of range

		if (temp3 == 0)
		{	temp1 ++;}//to bypass deleted baddies

		printf("x_displacement = %d\n", enemy_locations[temp1].x_displacement);

		printf("tile_X_position = %d", enemy_locations[temp1].tile_X_position);
		printf("        ");
		printf("y_position = %d\n", enemy_locations[temp1].y_position);

        printf("sprite_number = %d", enemy_locations[temp1].sprite_number);
        printf("        ");
        printf("movement = %d", enemy_locations[temp1].movement);
        printf("        ");
		printf("energy = %d\n", enemy_locations[temp1].energy);

		printf("param1 = %d", enemy_locations[temp1].param1);
        printf("        ");
		printf("param2 = %d\n", enemy_locations[temp1].param2);

        printf("--------------------------\n");


		temp1 ++;//44046
		//++ temp1;//44051

		temp2 ++;//44046
		//++ temp2;//44048
	}
}


void search_enemy_array3 (void)
{
    temp2 = 0;//no more than 6 entries
	temp1 = player.x_displacement;

	playerLow = player.x_displacement;
	playerHigh = player.x_displacement + NEAR_PLAYER;//   NEAR_PLAYER = 2

	if (playerHigh > MAX_PLAYER_POS)    //MAX_PLAYER_POS = 255
		playerHigh = MAX_PLAYER_POS;

    while (temp2 < MAX_ENEMIES_ON_SCREEN )  //MAX_ENEMIES_ON_SCREEN = 6
	{
		temp3 = enemy_locations[temp1].x_displacement;

		if(temp3 > playerHigh)
		{	break;}//if out of range

		printf("x_displacement = %d\n", enemy_locations[temp1].x_displacement);
		printf("tile_X_position = %d", enemy_locations[temp1].tile_X_position);
		printf("        ");
		printf("y_position = %d\n", enemy_locations[temp1].y_position);
        printf("sprite_number = %d", enemy_locations[temp1].sprite_number);
        printf("        ");
        printf("movement = %d", enemy_locations[temp1].movement);
        printf("        ");
		printf("energy = %d\n", enemy_locations[temp1].energy);
		printf("param1 = %d", enemy_locations[temp1].param1);
        printf("        ");
		printf("param2 = %d\n", enemy_locations[temp1].param2);
        printf("--------------------------\n");

		temp1 ++;//44046
		//++ temp1;//44051

		temp2 ++;//44046
		//++ temp2;//44048
	}
}
//end routine


void search_enemy_array4 (void)
{
    signed int s_int_temp1 = 0;

	playerLow = player.x_displacement;
	playerHigh = player.x_displacement + NEAR_PLAYER;//   NEAR_PLAYER = 2

	if (playerHigh > MAX_PLAYER_POS)
    {
        //MAX_PLAYER_POS = 255
		playerHigh = MAX_PLAYER_POS;
    }

    printf("playerLow = %d", playerLow);
    printf("      ");
    printf("playerHigh = %d\n", playerHigh);
    printf("\n");

    for (temp2 = 0; temp2 < MAX_ENEMIES_ON_SCREEN; temp2 ++)
    {
        temp1 = player.x_displacement + temp2;
        temp3 = enemy_locations[temp1].x_displacement;

        printf("--------------------------\n");
        printf("temp1 = %d", temp1);
        printf("      ");
        printf("temp2 = %d", temp2);
        printf("      ");
        printf("temp3 = %d\n", temp3);
        printf("--------------------------\n");

		if(temp3 > playerHigh)
		{	break;}//if out of range

		printf("x_displacement = %d\n", enemy_locations[temp3].x_displacement);
		printf("tile_X_position = %d", enemy_locations[temp3].tile_X_position);
		printf("        ");
		printf("y_position = %d\n", enemy_locations[temp3].y_position);
        printf("sprite_number = %d", enemy_locations[temp3].sprite_number);
        printf("        ");
        printf("movement = %d", enemy_locations[temp3].movement);
        printf("        ");
		printf("energy = %d\n", enemy_locations[temp3].energy);
		printf("param1 = %d", enemy_locations[temp3].param1);
        printf("        ");
		printf("param2 = %d\n", enemy_locations[temp3].param2);
    }
}

void search_enemy_array5 (void)
{
    unsigned char temp4;
    signed int temp5;

	playerLow = player.tile_X_position;
	playerHigh = playerLow + NEAR_PLAYER;//   NEAR_PLAYER = 2

	if (playerHigh > MAX_PLAYER_POS)
    {
        //MAX_PLAYER_POS = 250
		playerHigh = MAX_PLAYER_POS;
    }
    printf("playerLow = %d", playerLow);
    printf("      ");
    printf("playerHigh = %d\n", playerHigh);
    printf("\n");

    for (temp1 = 0; temp1 < MAX_ENEMIES_ON_SCREEN; temp1 ++)
    {//MAX_ENEMIES_ON_SCREEN = 6
        temp3 = enemy_locations[temp1].x_displacement;
        if(temp3 > playerHigh)
        {
            printf("TOO HIGH\n");
            return;
        }//if out of range

        if ( (temp3 >= playerLow) && (temp3 <= playerHigh) )
        {
            //printf("IN RANGE\n");

            temp2 = temp1 + playerLow;
            temp4 = temp2 - 1;

            printf("-------------------------------------------\n");
            printf("loop = %d", temp1);
            printf("      ");
            printf("temp2 = %d", temp2);
            printf("      ");
            printf("temp3 = %d", temp3);
            printf("      ");
            printf("temp4 = %d\n", temp4);
            printf("-------------------------------------------\n");

            printf("x_displacement = %d\n", enemy_locations[temp1].x_displacement);
           //printf("--------------------------\n");
        }
        printf("FINISHED IF\n\n");
    }
    printf("Should not SEE ME\n");
}









