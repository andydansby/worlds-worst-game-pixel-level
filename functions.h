#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//keep
static unsigned char convert_pixel_to_tile (unsigned int pixel)
{
    //in this case, tile is 16 pixels wide
    //=SUM(C3 / 16)
    //C3 is pixel and D3 is calculation of C3
    //unsigned char pixelTemp = pixel / 16;
    //return pixelTemp;

    //temp1 = pixel / 16;
    //return temp1;

    return pixel / 16;
}

//keep
static unsigned int convert_tile_to_pixel (unsigned char tile, unsigned char offset)
{
    //in this case, tile is 16 pixels wide
    //=SUM(A3 * 16) + B3
    //A3 is tile, B3 is offset
    return (tile * 16) + offset;
}

//keep
static void do_you_want_pausing (void)
{
    printf("\nDo you want (P)ausing or (C)ontinuous scrolling\n");
    printf("<ENTER> = (P)ausing\n");
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
        if (in_key_pressed( IN_KEY_SCANCODE_ENTER ))
        {
            ioctl(1, IOCTL_OTERM_PAUSE, 1);//scrolls and pause
            break;
        }
    }
}

//keep
static void player_start_location (void)
{
    printf("Press P to pause scrolling\n\n");
	printf("Enter in player start tile    1 - 240\n");
	fgets(arrayInput,sizeof(arrayInput),stdin);
	playerStart = atoi(arrayInput);

	if (playerStart < 1)
        playerStart = 1;
    if (playerStart > 240)
        playerStart = 240;
	in_pause(600);
}

//keep
static void fill_enemy_location_array (void)
{
	extern unsigned int LEVEL_1_ENEMIES_LOCATIONS;//needed to pull variable from assembly
	pointerAddy = &LEVEL_1_ENEMIES_LOCATIONS;//address of pointer

	//enemies_per_level =  memory_bpeek(pointerAddy);
	//intrinsic_label(enemies_per_level_results);

	enemies_per_level = memory_bpeek(pointerAddy);

	pointerAddy ++;

	for (temp1 = 0; temp1 < enemies_per_level; temp1 ++)
	{
	    enemy_locations[temp1].tile_X_position  = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].x_displacement   = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].y_position       = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].sprite_number    = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].movement	        = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].energy           = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param1           = memory_bpeek(pointerAddy);
		pointerAddy ++;
		enemy_locations[temp1].param2           = memory_bpeek(pointerAddy);
		pointerAddy ++;
	}
	for (temp1 = enemies_per_level; temp1 < 255; temp1 ++)
    {
        enemy_locations[temp1].tile_X_position  = 255;
		enemy_locations[temp1].x_displacement   = 255;
		enemy_locations[temp1].y_position       = 255;
		enemy_locations[temp1].sprite_number    = 255;
		enemy_locations[temp1].movement	        = 255;
		enemy_locations[temp1].energy           = 255;
		enemy_locations[temp1].param1           = 255;
		enemy_locations[temp1].param2           = 255;
    }
}


//binary search
static unsigned char search(unsigned char value)
{
    //enemy_locations[0].tile_X_position
    //start_enemy_array_slot = 0;
	if(value < enemy_locations[0].tile_X_position)
	{
	    //start_enemy_array_slot = 0;
	    return 0;
		//return enemy_locations[0].tile_X_position;
	}
	if(value > enemy_locations[enemies_per_level-1].tile_X_position)
	{
	    //start_enemy_array_slot = enemies_per_level-1;
	    return enemies_per_level-1;
		//return enemy_locations[enemies_per_level-1].tile_X_position;
	}

	lo = 0;
	hi = enemies_per_level - 1;

	while (lo <= hi)
	{
		mid = (hi + lo) / 2;

		if (value < enemy_locations[mid].tile_X_position)
		{
			hi = mid - 1;
		}
		else if (value > enemy_locations[mid].tile_X_position)
		{
			lo = mid + 1;
		}
		else
		{
		    //start_enemy_array_slot = mid;
		    return mid;
			//return enemy_locations[mid].tile_X_position;
		}
	}
	// lo == hi + 1
	//return (enemy_locations[lo].tile_X_position - value) < (value - enemy_locations[hi].tile_X_position) ? enemy_locations[lo].tile_X_position : enemy_locations[hi].tile_X_position;
	//return (a[lo] - value) < (value - a[hi]) ? a[lo] : a[hi]
	//abs(a[lo]-value) < abs(a[hi]-value)

	output = enemy_locations[lo].tile_X_position - value;

    if (output < value - enemy_locations[hi].tile_X_position)
    {
        //start_enemy_array_slot = lo;
        return lo;
        //return enemy_locations[lo].tile_X_position;
    }
    else
    {
        //start_enemy_array_slot = hi;
        return hi;
        //return enemy_locations[hi].tile_X_position;
    }
}


static void enemyScanWindow (unsigned char start_enemy_array_slot)
{
    temp1 = start_enemy_array_slot;
    temp2 = enemy_locations[temp1].tile_X_position;
    temp3 = 0;
    //unsigned char furthest_enemy = 0;

    if (temp2 < window.windowLow)
    {
        ++ temp1;
        //startingPosition = enemy_locations[starting_slot].tile_X_position;
    }
    //temp2 no longer used, so reuse it

    window.windowMax = temp1 + NEAR_PLAYER;
    temp2 = window.windowHigh;

    printf("temp1= %d ### ",temp1);
    printf("WindowHigh = temp2 = %d ",window.windowHigh);
    printf("\n");

    printf("WindowLow= %d  ", window.windowLow);
    printf("windowScan= %d  ",window.windowScan);
    printf("windowMax= %d",window.windowMax);
    printf("\n");
    printf("-------------------------------\n");

    for (temp3 = temp1; temp3 < UNSIGNED_CHAR_MAX; ++ temp3 )
    {
        enemy_scan = enemy_locations[temp3].tile_X_position;

        if (enemy_scan > temp2)
        {
            break;
        }
        if (enemy_scan == 255)
        {
            break;
        }

        printf("ArraySLOT=[%d] ",temp3);
        printf("enemy_scan= %d ",enemy_scan);
        printf("\n");
    }
    printf("-------------------------------\n");
}



#endif
//leave blank line after

