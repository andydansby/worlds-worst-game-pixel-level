#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

// Array of enemy locations in the game
// We use the same Entity structure, with just one difference: X now means the tile
struct Enemy
{
    unsigned char tile_X_position;  // Tile in X
    unsigned char x_displacement;   // Displacement in tile (0-23)
	unsigned char y_position;       // Y position
	unsigned char sprite_number;	// Number of the enemy sprite: if 0, this enemy is not active
	unsigned char movement;         // movement type, from one of the predefined ones
	unsigned char energy;           // shields
	unsigned char param1;           // Two parameters, to store some information that is entity-specific
	unsigned char param2;           // Two parameters, to store some information that is entity-specific
} enemy_locations[UNSIGNED_CHAR_MAX];

struct player
{
    unsigned char tile_X_position;
    // Displacement in tile (0-23) player position within tile

	unsigned char x_displacement;
	// Tile in X

	unsigned char x_position;
	// X position 0-255

	unsigned char y_position;
	// Y position 0-172

	unsigned char sprite_number;
	// used for player animation

	unsigned char fuel;
	//each loop needs to count down

	unsigned char shields;
	//each hit will lower shields

	unsigned char param1;
	// for something undefined for now, perhaps ship upgrades

	unsigned int map_x;
	//which pixel in the MAP 0-4080 the ship is flying through
}player;

//window struct should be in range of 1-255
//left side runs 1-238
//right side runs 17-255
//window size is 17 (double tiles, 2 character spaces)
struct window
{
    unsigned char windowLow;
    // far left side of window 1-238
    //windowLow should not go over 238, otherwise you have to use INT

	unsigned char windowHigh;
	// far right side of window

	unsigned char windowMax;
	// maximum placement of windowLow
	//windowHigh - windowLow

	unsigned char windowSize;
	//size of the window = 17

	unsigned char windowScan;
	//steps through the window
}window;


/////////// DEAD VARIABLES
//unsigned char playerLow = 0;
//unsigned char playerHigh = 0;
//unsigned char start_enemy_array_slot_temp = 0;
//unsigned char closest_baddy = 0;
//unsigned char indexToDelete [MAX_ENEMIES_ON_SCREEN];
//unsigned char number_of_index_baddies = 0;
//static unsigned char y8 = 1;//used in randomizer can be any 8 bit number
//unsigned char decision;
//unsigned char enemyToDelete = 254;
//unsigned int keypress;

//unsigned char temp4 = 0;
//unsigned char temp5 = 0;
//unsigned char temp6 = 0;
//unsigned char temp7 = 0;

//unsigned int ms_start, ms_end, ms_diff = 0;
//unsigned int clock_1 = 0;
//unsigned int clock_2 = 0;
//unsigned int clock_3 = 0;
//unsigned int clock_4 = 0;
/////////// DEAD VARIABLES

unsigned char playerStart = 0;

unsigned char temp1 = 0;
unsigned char temp2 = 0;
unsigned char temp3 = 0;

unsigned int intTemp1 = 0;
unsigned int intTemp2 = 0;

unsigned char enemies_per_level = 0;
unsigned char enemy_scan = 0;

//-----------------------------------------------------------------------
//used for binary search
unsigned char output;
unsigned char lo, hi, mid;
unsigned char start_enemy_array_slot = 0;
//-----------------------------------------------------------------------

unsigned int pointerAddy;

unsigned int arrayInput[5];


#endif
//leave blank line after
