# worlds-worst-game-pixel-level
Not really a game but using structs for enemy management.

This is written to be compiled for the ZX Spectrum and
compiled with Z88dk.

It's for a tile based game that moves pixel by pixel

On starting, enter in a tile number 1-240

The program will advance pixel by pixel (displacement within tile)
until it reaches the end of the tile (displacement 15)

Each tile is 16 pixels wide.

Once you reach the end of the current tile (displacement == 15)
you will advance to the next tile.

You can only see 17 tiles ahead of you.

Any enemy further than 17 tiles more more are invisible to you
Any enemy further than 1 tile behind you are invisible to you


Now using binary search to find enemies closest to you.



