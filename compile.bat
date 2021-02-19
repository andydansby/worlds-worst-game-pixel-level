cls

SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

rem --------------------------------
del "1output.tap"

zcc +zx -v -c -clib=new --fsigned-char -o objects.o @enemyList.lst
rem created are objects.o and zcc_opt.def

@REM pause

zcc +zx -m -v -startup=5 -clib=new objects.o @ramMAIN.lst -pragma-include:zpragma.inc  -o output

rem 32 column mode
rem zcc +zx -m  -startup=1 -clib=new objects.o @ramMAIN.lst -pragma-include:zpragma.inc  -o output
rem --------------------------------

@REM pause
copy "output_CODE.bin" misc
copy "output_UNASSIGNED.bin" misc
copy "output_UNCONTENDED_enemy_locations.bin" misc
move "output_CODE.bin" basic
move "output_UNASSIGNED.bin" basic
move "output_UNCONTENDED_enemy_locations.bin" basic
cd basic

@REM pause

appmake +zx -b output_CODE.bin -o code.tap --org 32768 --noloader --blockname code
appmake +zx -b output_UNCONTENDED_enemy_locations.bin -o data.tap --org 63488 --noloader --blockname edata


cd utils
	copy "bas2tap.exe" "..\"
cd ..

	bas2tap -a10 -sBASIC loader.bas basloader.tap


copy /b basloader.tap + code.tap + data.tap 1output.tap


move "1output.tap" "..\"

del "basloader.tap"
del "code.tap"
del "data.tap"

del "output_CODE.bin"
del "output_UNASSIGNED.bin"
del "output_UNCONTENDED_enemy_locations.bin"
cd ..


move "objects.o" misc
move "output.map" misc
move "zcc_opt.def" misc

call beep.bat