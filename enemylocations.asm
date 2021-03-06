SECTION UNCONTENDED_enemy_locations

;;defc is define constant
defc bob	= 0	;
defc sue	= 1	;
defc joe	= 2	;
defc tam	= 3	;
defc jan	= 4	;


;	struct Enemy
;	{
;	unsigned char x;        			// Tile in X
;	unsigned char x_displacement;  		// Displacement in tile (0-23)
;	unsigned char y;        			// Y position
;	unsigned char sprite_number;		// Number of the enemy sprite: if 0, this enemy is not active
;	unsigned char movement;	// movement type, from one of the predefined ones
;	unsigned char energy;		// enemy energy level
;	unsigned char param1;		//	other data to be stored 1
;	unsigned char param2;		// other data to be stored 2
;	}  Enemy_structure[MAX_ENEMIES];


PUBLIC _LEVEL_1_ENEMIES_LOCATIONS
_LEVEL_1_ENEMIES_LOCATIONS:
;;pointer address = $f800

;;------------------------------
	defb  18	;;number of enemies + dummy		enemies_per_level
;;------------------------------

;; never put a enemy at 0 or 255
;; enemy should fall in range of 5 to 240?
;;should also try to limit to 6 enemies per 12 tiles
;;------------------------------
;       tile_X_position, x_displacement, y_position, sprite_number,	movement,   energy,	param1,	param2
defb    04,             01,              10,         1, 		    bob,        01,     $aa,    00;0
defb    05,             02,	             20,         2, 		    bob,        02,     $aa,    01;1
defb    07,		        03,	             30,         3, 		    bob,        03,     $aa,    02;2
defb    08,		        04,	             40,         4, 		    bob,        04,     $aa,    03;3
defb    09,		        05,	             50,         5, 		    bob,        05,     $aa,    04;4
defb    10,		        06,	             60,         5, 		    bob,        05,     $aa,    05;5
defb    16,		        07,	             70,         6, 		    bob,        06,		$aa,    06;6
defb    18,		        08,	             80,         7, 		    bob,        07,     $aa,    07;7
defb    20,		        09,	             90,         9, 		    bob,        08,     $aa,    08;8
defb    23,		        10,	             99,         9, 		    bob,        09,		$fe,    09;9
defb    25,		        11,	             100,        9, 		    bob,        09,		$fe,    10;10
defb    25,		        12,	             110,        9, 		    bob,        09,		$fe,    11;11
defb    26,		        13,	             90,         9, 		    bob,        09,		$fe,    12;12
defb    27,		        14,	             80,         9, 		    bob,        09,		$fe,    13;13
defb    28,		        15,	             70,         9, 		    bob,        09,		$fe,    14;14
defb    32,		        01,	             60,         9, 		    bob,        09,		$fe,    15;15
defb    35,		        02,	             50,         9, 		    bob,        09,		$fe,    16;16
; dummy enemy, to mark the end!
defb    $ff,            $ff, 	        80,          2, 		    bob,        10,     $ff,    $ff;end of list


;	defb		10, 		1, 	50, 		2, sue,		10, $ab,	10
;	defb		11,		2, 	20, 		2, sue,		11, $ac,	11
;	defb		12,		3,		80,		2, sue,		12, $ad,	12
;	defb		13,		4,		20,		2, sue,		13, $ae,	13
;	defb		14,		5,		80, 		2, sue, 	14, $af,	14
;	defb		15,		6,		20, 		2, sue,		15, $ba,	15
;	defb		15,		7,		50, 		2, sue, 	16, $bb,	16
;	defb		16,		8,		20,		2, sue, 	17, $bc,	17
;	defb		18,		9,		50,		2, sue, 	18, $bb, 	18
;	defb		19,		19,	20,		2, sue, 	19, $fe, 	19
;20

;	defb  	20,  		1, 	20, 		2, joe, 		20, $bc, 	20
;	defb  	20,  		2, 	50, 		2, joe, 		21, $bd, 	21
;	defb  	21,  		3, 	80, 		2, joe, 		22, $be, 	22
;	defb  	22,  		4, 	50, 		2, joe, 		23, $bf, 	23
;	defb  	23,  		5, 	80, 		2, joe, 		24, $bc, 	24
;	defb  	24,  		6, 	20, 		2, joe, 		25, $bd, 	25
;	defb  	25,  		7, 	50, 		2, joe, 		26, $be, 	26
;	defb  	27,  		8, 	80, 		2, joe, 		27, $bf, 	27
;	defb  	28,  		9, 	50, 		2, joe, 		28, $ba, 	28
;	defb  	29,  		0, 	80, 		2, joe, 		29, $fe, 	29
;30

;	defb  	30, 		0, 	20, 		2, tam, 	30, $ca, 	30
;	defb  	30,  		0, 	50, 		2, tam, 	31, $cb, 	31
;	defb  	32,  		0, 	80, 		2, tam, 	32, $cc, 	32
;	defb  	33,  		0, 	50, 		2, tam, 	33, $cd, 	33
;	defb  	34,  		0, 	80, 		2, tam, 	34, $ce, 	34
;	defb  	35,  		0, 	20, 		2, tam, 	35, $cf, 	35
;	defb  	36,  		0, 	50, 		2, tam, 	36, $ca, 	36
;	defb  	36,  		0, 	80, 		2, tam, 	37, $cb, 	37
;	defb  	37,  		0, 	50, 		2, tam, 	38, $cc, 	38
;	defb  	38,  		0, 	80, 		2, tam, 	39, $fe, 	39
;40

;	defb  	40,  		0, 	20, 		2, jan, 		40, $da, 	40
;	defb  	40,  		0, 	50, 		2, jan, 		41, $db, 	41
;	defb  	41,  		0, 	80, 		2, jan, 		42, $dc, 	42
;	defb  	42,  		0, 	50, 		2, jan, 		43, $dd, 	43
;	defb  	43,  		0, 	80, 		2, jan, 		44, $de, 	44
;	defb  	44,  		0, 	20, 		2, jan, 		45, $df, 	45
;	defb  	45,  		0, 	50, 		2, jan, 		46, $da, 	46
;	defb  	46,  		0, 	80, 		2, jan, 		47, $db, 	47
;	defb  	47,  		0, 	50, 		2, jan, 		48, $dc, 	48
;	defb  	48,  		0, 	80, 		2, jan, 		49, $fe, 	49
;50

;	defb  	50,  		0, 	20, 		2, bob, 	50, $ea, 	50
;	defb  	50,  		0, 	50, 		2, sue, 	51, $eb, 	51
;	defb  	50,  		0, 	80, 		2, joe, 		52, $ec, 	52
;	defb  	51,  		0, 	50, 		2, tam, 	53, $ed, 	53
;	defb  	51,  		0, 	80, 		2, jan, 		54, $ee, 	54
;	defb  	55,  		0, 	20, 		2, bob, 	55, $ef, 	55
;	defb  	56,  		0, 	50, 		2, sue, 	56, $ef, 	56
;	defb  	57,  		0, 	80, 		2, joe, 		57, $ed, 	57
;	defb  	58,  		0, 	50, 		2, tam, 	58, $eb, 	58
;	defb  	59,  		0, 	80, 		2, jan, 		59, $fe, 	59
;60

;	defb  	60,  		0, 	20, 		2, jan, 		60, $fa, 	60
;	defb  	62,  		0, 	50, 		2, tam, 	61, $fa, 	61
;	defb  	63,  		0, 	80, 		2, joe, 		62, $fa, 	62
;	defb  	64,  		0, 	50, 		2, sue, 	63, $fa, 	63
;	defb  	65,  		0, 	80, 		2, bob, 	64, $fa, 	64
;	defb  	66,  		0, 	20, 		2, jan, 		65, $fa, 	65
;	defb  	66,  		0, 	50, 		2, tam, 	66, $fa, 	66
;	defb  	67,  		0, 	80, 		2, joe, 		67, $fa, 	67
;	defb  	68,  		0, 	50, 		2, sue, 	68, $fa, 	68
;	defb  	68,  		0, 	80, 		2, bob, 	69, $fe, 	69
;70

;	defb  	70,  		0, 	20, 		2, bob, 	70, $aa, 	70
;	defb  	72,  		0, 	50, 		2, bob, 	71, $aa, 	71
;	defb  	73,  		0, 	80, 		2, jan, 		72, $aa, 	72
;	defb  	74,  		0, 	50, 		2, jan, 		73, $aa, 	73
;	defb  	75,  		0, 	80, 		2, tam, 	74, $aa, 	74
;	defb  	76,  		0, 	20, 		2, tam, 	75, $aa, 	75
;	defb  	76,  		0, 	50, 		2, joe, 		76, $aa, 	76
;	defb  	77,  		0, 	80, 		2, joe, 		77, $aa, 	77
;	defb  	78, 		0, 	50, 		2, sue, 	78, $aa, 	78
;	defb  	79,  		0, 	80, 		2, sue, 	79, $fe, 	79
;80

;	defb  	80,  		0, 	20, 		2, bob, 	80, $aa, 	80
;	defb  	82,  		0, 	50, 		2, bob, 	81, $aa, 	81
;	defb  	83,  		0, 	80, 		2, jan, 		82, $aa, 	82
;	defb  	84,  		0, 	50, 		2, jan, 		83, $aa, 	83
;	defb  	85,  		0, 	80, 		2, tam, 	84, $aa, 	84
;	defb  	86,  		0, 	20, 		2, tam, 	85, $aa, 	85
;	defb  	86,  		0, 	50, 		2, joe, 		86, $aa, 	86
;	defb  	87,  		0, 	80, 		2, joe, 		87, $aa, 	87
;	defb  	88, 		0, 	50, 		2, sue, 	88, $aa, 	88
;	defb  	89,  		0, 	80, 		2, sue, 	89, $fe, 	89
;90

;	defb  	90,  		0, 	20, 		2, bob, 	90, $aa, 	90
;	defb  	92,  		0, 	50, 		2, bob, 	91, $aa, 	91
;	defb  	93,  		0, 	80, 		2, jan, 		92, $aa, 	92
;	defb  	94,  		0, 	50, 		2, jan, 		93, $aa, 	93
;	defb  	95,  		0, 	80, 		2, tam, 	94, $aa, 	94
;	defb  	96,  		0, 	20, 		2, tam, 	95, $aa, 	95
;	defb  	96,  		0, 	50, 		2, joe, 		96, $aa, 	96
;	defb  	97,  		0, 	80, 		2, joe, 		97, $aa, 	97
;	defb  	98, 		0, 	50, 		2, sue, 	98, $aa, 	98
;	defb  	99,  		0, 	80, 		2, sue, 	99, $fe, 	99
;100

;	defb  	100,  	0, 	20, 		2, bob, 	100, $aa,  100
;	defb  	102,  	0, 	50, 		2, bob, 	101, $aa,  101
;	defb  	103,  	0, 	80, 		2, jan, 		102, $aa,  102
;	defb  	104,  	0, 	50, 		2, jan, 		103, $aa,  103
;	defb  	105,  	0, 	80, 		2, tam, 	104, $aa,  104
;	defb  	106,  	0, 	20, 		2, tam, 	105, $aa,  105
;	defb  	106,  	0, 	50, 		2, joe, 		106, $aa,  106
;	defb  	107,  	0, 	80, 		2, joe, 		107, $aa,  107
;	defb  	108, 	0, 	50, 		2, sue, 	108, $aa,  108
;	defb  	109, 	0, 	80, 		2, sue, 	109, $fe,   109
;;110







;struct Enemy
;{
;	unsigned char x;        // Tile in X
;	unsigned char x_displacement;   // Displacement in tile (0-23)
;	unsigned char y_position;        // Y position
;	unsigned char sprite_number;	// Number of the enemy sprite: if 0, this enemy is not active
;	unsigned char movement;	// movement type, from one of the predefined ones
;	unsigned char energy;
;	unsigned char param1;
;	unsigned char param2;	// Two parameters, to store some information that is entity-specific
;} Enemy_structure;




PUBLIC _someting_else
_someting_else:
;defs 0x1000


;defb 	tile_X_position	x_displacement	y_position  sprite_number	movement	energy		param1	    param2
defb    01,		        02,		        03,         04,		        05,				06,			07,			08
defb    $0b,            $0c,		    $0d,        $0e,            $0f,            $10,        $11,        $12
defb    21,		        22,		        23,         24,		        25,				26,			27,			28
defb    31,		        32,		        33,         34,		        25,				36,			37,			38
defb    41,		        42,		        43,         44,		        25,				46,			47,			48
defb    51,		        52,		        53,         54,		        25,				56,			57,			58
defb    61,		        62,		        63,         64,		        25,				66,			67,			68
defb    71,		        72,		        73,         74,		        25,				76,			77,			78
defb    81,		        82,		        83,         84,		        25,				86,			87,			88
