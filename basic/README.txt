LOADER.BAS

10 CLEAR VAL "24599"
clear out memory above 24600


20 POKE VAL "23739", VAL "111":REM DO NOT PRINT
do not print file names to the screen while loading

30 BORDER VAL "0": PAPER VAL "0": INK VAL "7": LOAD""SCREEN$
border black, paper black, ink white, and load screen

40 FOR N=VAL "1" TO VAL "5": READ C
read data values to load banks
order will be Bank 3, 4, 6, 1, 0

50 POKE VAL "23388", C: OUT VAL "32765", C : LOAD "" CODE 49152
poke 23388 and out 32765 will change the data bank, load data into memory 49152 which is memory bank location

60 NEXT N
next data section


70 LOAD "" CODE 24600
80 RANDOMIZE USR 24600
90 DATA VAL "19", VAL "20", VAL "22", VAL "17", VAL "16"






memory.bin

is a memory utility

load into emulator at address 28000 (any address should work)

print usr 28000
calculates the FREE SPACE left for BASIC Program in the system after you insert a clear command

print usr 28020
returns the length of a BASIC Program



