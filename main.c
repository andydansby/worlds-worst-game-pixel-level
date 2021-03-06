// compile with
// zcc +zx -m -create-app -startup=1 -clib=new  main.c -o output

//--------------------- MACROS
//#define memory_bpeek(a)    (*(unsigned char *)(a))
#define cpu_bpeek(a)    (*(unsigned char *)(a))
#define cpu_bpoke(a,b)  (*(unsigned char *)(a) = b)

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define MAX_ENEMIES 255
#define MAX_ENEMIES_ON_SCREEN 10
//MAX_ENEMIES_ON_SCREEN should be the number of enemies you want to see on screen + 1
#define NEAR_PLAYER 16 //16 tiles per screen

#define UNSIGNED_CHAR_MAX 255
#define MAX_U_CHAR 255
#define MAX_PLAYER_POS 240
//--------------------- MACROS





#include <stdio.h>//standard input output
#include <stdlib.h> // for atoi
#include <string.h>
#include <sys/ioctl.h>//to control scrolling


#include <input.h>

#include <arch/spectrum.h>

#include <intrinsic.h>//temp to place labels	powerful troubleshooting tool

#include "globalVariables.h"
#include "functions.h"

void Manual_test (void)
{
	player_start_location();

	//look at enemy_locations[]
	fill_enemy_location_array ();
	// this is large array filled in with
	//level info
	//THIS copies enemy array in asm to struct in C
    //seems OK

    //do_you_want_pausing ();
    ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls and pause

    //ioctl(1, IOCTL_OTERM_PAUSE, 0);//continuously scrolls


	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");

	player.x_displacement = 0;
	// starting position is beginning of tile
	player.tile_X_position = playerStart;
    player.x_position = 0;
    player.y_position = 0;
    player.sprite_number = 1;
    player.fuel = 255;
    player.shields = 127;
    player.param1 = 0;
	player.map_x = convert_tile_to_pixel(playerStart, 0); //start at tile X, offset 0


	window.windowSize = 15;
	window.windowLow = playerStart - 1;
	window.windowHigh = window.windowLow + window.windowSize;
	window.windowMax = 235;

/*struct player
{
    unsigned char x_displacement;   // Displacement in tile (0-23) player position within tile
	unsigned char tile_X_position;	// Tile in X
	unsigned char x_position;	// X position 0-255
	unsigned char y_position;	// Y position 0-172
	unsigned char sprite_number;	// used for player animation
	unsigned char fuel;	//each loop needs to count down
	unsigned char shields;	//each hit will lower shields
	unsigned char param1;	// for something undefined for now, perhaps ship upgrades
	unsigned int map_x;	//which pixel in the MAP 0-4080 the ship is flying through
}player;*/

	//print variables
    /*	while (1)
    {
        printf ("player.x_displacement = %d\n", player.x_displacement);
        printf ("player.tile_X_position = %d\n", player.tile_X_position);
        printf ("player.x_position = %d\n", player.x_position);
        printf ("player.y_position = %d\n", player.y_position);
        printf ("player.sprite_number = %d\n", player.sprite_number);
        printf ("player.fuel = %d\n", player.fuel);
        printf ("player.shields = %d\n", player.shields);
        printf ("player.param1 = %d\n", player.param1);
        printf ("player.map_x = %d\n", player.map_x);


        temp1 = convert_pixel_to_tile(player.map_x);//function to convert pixel location to tile
        temp3 = player.tile_X_position;
		temp4 = player.x_displacement;
		intTemp2 = convert_tile_to_pixel(temp3, temp4);

        printf ("\n");
        printf ("playerStart = %d\n", playerStart);
        printf ("convert_pixel_to_tile = temp1 = %d\n", temp1);
        printf ("convert_tile_to_pixel = intTemp2 = %d\n", intTemp2);
        printf ("\n");
        //in_wait_key();
        //in_wait_nokey();
        //break;
    }*/

	while (1)
	{
        pauseScrolling();

        //need formula
        // convert tile 0-16 (tiles)
        // and x_displacement
        //0 - 16
        temp1 = convert_pixel_to_tile(player.map_x);//function to convert pixel location to tile
        temp3 = player.tile_X_position;
		intTemp2 = convert_tile_to_pixel(temp3, temp4);

		intTemp1 = player.map_x;//lg
		temp2 = player.tile_X_position;//lg
		temp4 = player.x_displacement;//lg


		//ioctl(1, IOCTL_OTERM_PAUSE, 0);//scrolls
		ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls

		window.windowHigh = window.windowLow + window.windowSize;



        printf("??############################################################\n");
        printf("Player at tile = %d -- map_x = %d -- Displacement = %d\n", player.tile_X_position, intTemp1, temp4);
        printf (".windowLow = %d  .windowHigh = %d  .windowSize = %d\n", window.windowLow, window.windowHigh, window.windowSize );
        printf("window.windowMax = %d   window.windowSize = %d\n", window.windowMax, window.windowSize);
        //printf("Player at tile = %d -- map_x = %d -- Displacement = %d\n", temp1, intTemp2, temp4);
        //printf("Player currently at tile = %d -- pixel = %d -- Displacement = %d\n", temp1, temp2, temp4);
        //printf("Player currently at tile = %d\n", player.tile_X_position);
        printf("##############################################################\n");


        //banana();
        //orange();//<<<<<<testing
        apple();


        //printBaddyArray();

        /*if (player.x_displacement < 15)
        {
            ioctl(1, IOCTL_OTERM_PAUSE, 0);//scrolls
        }
        else
        {
            ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls
        }*/


        player.x_displacement ++;//increase the 0-15 placement in the character block
        player.map_x ++;//increase the 0-4080 pixel in the large map

		if (player.x_displacement > 15)
        {
            player.tile_X_position ++;//increase the tile up to windowMax
            window.windowLow ++;
            player.x_displacement = 0;

            printf("====================================================\n");
            printf("need to increase tile and reset offset to 0\n");
            printf("Player currently at tile = %d and map_x = %d\n", player.tile_X_position, player.map_x);
            printf("Press a Key \n");
            printf("====================================================\n");
            printf("\n");

            //pause
            in_pause(0);
            zx_cls(INK_BLACK | PAPER_WHITE);
        }

		if (player.tile_X_position > window.windowMax)
		{
		    //level over once you reach windowMax
			break;
		}

	}//endless loop
}



void main (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;//a reference to ememylocations.asm

	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer
	enemies_per_level =  cpu_bpeek(pointerAddy);//first byte is number of enemies

	zx_cls(INK_BLACK | PAPER_WHITE);
	puts("\x16\x01\x02");
	//		\x16 == set cursor position
	//		\x01 = x position (01) in hex
	//		\x02 = y position (0C) in hex

	printf("Welcome to the most boring game ever\n");

	printf("\n1 for Manual Entry Test");
	//printf("\n2 for the Speed Test");// haven't worked on
	//printf("\n3 for Display Enemy Array");

	while (1)
	{
	    /*
	    zx_cls(INK_BLACK | PAPER_WHITE);
        puts("\x16\x01\x02");
	    Manual_test();//bypass initial screen
	    */

        Manual_test();

/*		if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			in_wait_nokey();
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			Manual_test();
		}
		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			in_wait_nokey();
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			Speed_test();
		}
		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			in_wait_nokey();
			zx_cls(INK_BLACK | PAPER_WHITE);
			puts("\x16\x01\x02");
			//print_enemy_location_array();
            // to show entire array
		}


*/

	}


}





