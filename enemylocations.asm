SECTION UNCONTENDED_enemy_locations

;;defc is define constant
defc bob	= 0	;
defc sue	= 1	;
defc joe	= 2	;
defc tam	= 3	;
defc jan	= 4	;


PUBLIC _LEVEL_1_ENEMIES_LOCATIONS
_LEVEL_1_ENEMIES_LOCATIONS:
;;pointer address = $f800

;;------------------------------
defb  25	;;number of enemies + dummy	(start counting at 0) = enemies_per_level
;;------------------------------

;; never put a enemy at 0 or 255
;; enemy should fall in range of 5 to 240?
;;should also try to limit to 6 enemies per 12 tiles
;;------------------------------
;       tile_X_position, x_displacement, y_position, sprite_number,	movement,   energy,	param1,	param2
defb    003,            01,              10,         1, 		    bob,        01,     $aa,    00;0
defb    004,            02,	             20,         2, 		    bob,        02,     $aa,    01;1
defb    006,		    03,	             30,         3, 		    bob,        03,     $aa,    02;2
defb    007,		    04,	             40,         4, 		    bob,        04,     $aa,    03;3
defb    009,		    05,	             50,         5, 		    bob,        05,     $aa,    04;4
defb    012,		    06,	             60,         5, 		    bob,        05,     $aa,    05;5
defb    016,		    07,	             70,         6, 		    bob,        06,		$aa,    06;6
defb    021,		    08,	             80,         7, 		    bob,        07,     $aa,    07;7
defb    022,		    09,	             90,         9, 		    bob,        08,     $aa,    08;8
defb    026,		    10,	             99,         9, 		    bob,        09,		$fe,    09;9
defb    032,		    11,	             100,        9, 		    bob,        09,		$fe,    10;10
defb    033,		    12,	             110,        9, 		    bob,        09,		$fe,    11;11
defb    034,		    13,	             90,         9, 		    bob,        09,		$fe,    12;12
defb    041,		    14,	             80,         9, 		    bob,        09,		$fe,    13;13
defb    049,		    15,	             70,         9, 		    bob,        09,		$fe,    14;14
defb    060,		    01,	             60,         9, 		    bob,        09,		$fe,    15;15
defb    079,		    02,	             50,         9, 		    bob,        09,		$fe,    16;16
defb    099,		    01,	             60,         9, 		    bob,        09,		$fe,    15;17
defb    100,		    02,	             50,         9, 		    bob,        09,		$fe,    16;18
defb    101,		    02,	             50,         9, 		    bob,        09,		$fe,    17;19
defb    105,		    02,	             50,         9, 		    bob,        09,		$fe,    18;20
defb    107,		    02,	             50,         9, 		    bob,        09,		$fe,    19;21
defb    108,		    02,	             50,         9, 		    bob,        09,		$fe,    20;22
defb    238,		    02,	             50,         9, 		    bob,        09,		$fe,    21;23

; dummy enemy, to mark the end!
defb    $ff,            $ff, 	         80,         2, 		    bob,        10,     $ff,    $ff;24  end of list

PUBLIC _someting_else
_someting_else:

;defb 	tile_X_position	x_displacement	y_position  sprite_number	movement	energy		param1	    param2
defb    01,		        02,		        03,         04,		        05,				06,			07,			08

