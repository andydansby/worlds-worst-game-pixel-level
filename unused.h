#ifndef UNUSED_H
#define UNUSED_H

void Print_it_all (void)
{
    temp1 = 0;
    temp2 = enemies_per_level;
    printf("\n");
    printf ("The number of baddies = enemies_per_level = %d", enemies_per_level);
    printf("\n");
    for (temp1 = 0; temp1 < temp2; temp1 ++)
    {
        printf ("enemy_locations[%d].tile_X_position = %d",temp1, enemy_locations[temp1].tile_X_position);
        printf("\n");
    }
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
void pauseWipe (void)
{
	in_wait_key();
	in_pause(100);
	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");
}


void printVariables (void)
{
    //print variables

    printf ("player.x_displacement = %ud\n", player.x_displacement);
    printf ("player.tile_X_position = %ud\n", player.tile_X_position);
    printf ("player.x_position = %ud\n", player.x_position);
    printf ("player.y_position = %ud\n", player.y_position);
    printf ("player.sprite_number = %ud\n", player.sprite_number);
    printf ("player.fuel = %ud\n", player.fuel);
    printf ("player.shields = %ud\n", player.shields);
    printf ("player.param1 = %ud\n", player.param1);
    printf ("player.map_x = %ud\n", player.map_x);


    temp1 = convert_pixel_to_tile(player.map_x);//function to convert pixel location to tile
    temp3 = player.tile_X_position;
    temp4 = player.x_displacement;
    intTemp2 = convert_tile_to_pixel(temp3, temp4);

    printf ("\n");
    printf ("playerStart = %ud\n", playerStart);
    printf ("convert_pixel_to_tile = temp1 = %ud\n", temp1);
    printf ("convert_tile_to_pixel = intTemp2 = %ud\n", intTemp2);
    printf ("\n");

    while (1)
    {
        in_wait_key();
        in_wait_nokey();
        break;
    }
    return;
}



//used to print entire array
void print_enemy_location_array (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	//enemies_per_level =  memory_bpeek(pointerAddy);	//how many enemies in array

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


unsigned int timer (void)
{
	clock_1 = memory_bpeek(23672);
	clock_2 = memory_bpeek(23673);
	clock_3 = memory_bpeek(23674);
	clock_4 = (65535*clock_3+256*clock_2+clock_1)/50;
	return clock_4;
}

void resetTimer (void)//clear the clock
{
    memory_bpoke(23672,0);
    memory_bpoke(23673,0);
    memory_bpoke(23674,0);
}




#endif
//leave blank line after

