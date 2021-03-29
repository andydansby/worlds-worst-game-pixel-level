// compile with
// zcc +zx -m -create-app -startup=5 -clib=new  main.c -o output

//--------------------- MACROS
#define memory_bpeek(a)    (*(unsigned char *)(a))
#define memory_bpoke(a,b)  (*(unsigned char *)(a) = b)

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define NEAR_PLAYER 17              //16 tiles per screen + 1 for 1 tile right
#define UNSIGNED_CHAR_MAX 255
#define MAX_PLAYER_POS 240
//--------------------- MACROS


#include <stdio.h>//standard input output
#include <stdlib.h> // for atoi
#include <sys/ioctl.h>//to control scrolling
//#include <string.h>
//#include <intrinsic.h>//temp to place labels	powerful troubleshooting tool

#include <input.h>
#include <arch/spectrum.h>
#include "globalVariables.h"
#include "functions.h"

void Manual_test (void)
{
	///define enemy variables & array
	fill_enemy_location_array ();
	// look at enemy_locations[]
	// this is large array filled in with level info
	// THIS copies enemy array in asm to struct in C

    //Print_it_all();// just in case you want to see the entire array

    player_start_location();//input where you want to start

    ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls and pause
    //ioctl(1, IOCTL_OTERM_PAUSE, 0);//continuously scrolls

	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");

	///define player variables
	player.x_displacement = 0;// starting position is beginning of tile
	player.tile_X_position = playerStart;
    player.x_position = 0;
    player.y_position = 0;
    player.sprite_number = 1;
    player.fuel = 255;
    player.shields = 127;
    player.param1 = 0;
	player.map_x = convert_tile_to_pixel(playerStart, 0); //start at tile X, offset 0
    ///define player variables

    ///define window variables
	window.windowSize = 17;
	window.windowLow = playerStart - 1;///NOTE this assumes the player is always in the same place just one ahead of the left window edge
	window.windowHigh = window.windowLow + window.windowSize;
	window.windowMax = 238;
	window.windowScan = 0;
	///define window variables

    //printVariables ();//just in case you want to see the variables above

    do_you_want_pausing();

	while (1)
	{
        //need formula
        // convert tile 0-16 (tiles) and x_displacement
        temp1 = convert_pixel_to_tile(player.map_x);//function to convert pixel location to tile
        temp2 = player.tile_X_position;//lg
		temp3 = player.x_displacement;//lg

		intTemp1 = convert_tile_to_pixel(temp1, temp3);
		intTemp2 = player.map_x;//lg

		window.windowHigh = window.windowLow + window.windowSize;

        printf("############################################################\n");
        //map_x goes up to 4080
        printf("player@tile = %d -- x_displacement = %d -- map_x = %u\n", player.tile_X_position,player.x_displacement, player.map_x);
        printf("##############################################################\n");

        //in with a tile location of player
        //out with the closest array slow
        temp1 = search(window.windowLow);
        enemyScanWindow(temp1);

        player.x_displacement ++;//increase the 0-15 placement in the character block
        player.map_x ++;//increase the 0-4080 pixel in the large map

		if (player.x_displacement > 15)
        {
            player.tile_X_position ++;//increase the tile up to windowMax
            window.windowLow ++;
            player.x_displacement = 0;

            printf("====================================================\n");
            printf("need to increase tile and reset offset to 0\n");
            printf("Player currently at tile = %d and map_x = %u\n", player.tile_X_position, player.map_x);
            printf("Press a Key \n");
            printf("====================================================\n");
            printf("\n");
            do_you_want_pausing();

            //pause
            in_pause(0);
            zx_cls(INK_BLACK | PAPER_WHITE);
        }

		if (player.tile_X_position > MAX_PLAYER_POS)
		{
		    printf("main level over once you reach tile 240\n");
		    printf("time for BOSS\n");
			break;
		}

	}//endless loop
}



void main (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;//a reference to ememylocations.asm

	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	enemies_per_level =  memory_bpeek(pointerAddy);//first byte is number of enemies

	zx_cls(INK_BLACK | PAPER_WHITE);
	//puts("\x16\x01\x02");
	//		\x16 == set cursor position
	//		\x01 = x position (01) in hex
	//		\x02 = y position (0C) in hex

	printf("Welcome to the most boring game ever\n");

	while (1)
	{
        Manual_test();
	}
}





