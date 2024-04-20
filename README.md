Hidden Bog
------------------------------
an sdl2 based rpg Hidden Bog, is a grid based 2D rpg, where the player
moves in a hand drawn First Person world.

*new! "but it worked on my system!"

no GNU auto-tools, CMake, meson, ninja, scons, gradle or bazel required!

One thing thats very frustrating about learning C/++, was that
nobody tells you exactly how to compile your project. A lot of
the time building the project relies on whatever IDE you are using at
the time. What if your end user doesn't have an IDE? What packages do
they need to install to get it running.  Example: some distos of linux
separate the SDL, and SDL_dev packages! (this saves a whopping 2-3mb!
lol.)  but if you're downloading a free project from github and need
to compile it, you can only hope the developer left clear insutructions
in the readme for building.  I prefer hackable makefiles.  Makefiles
are their own "language" and are often not covered at all in any C
tutorial or book you're gonna find. I have also included a "make.sh"
in the src directory... this file just runs gcc on everything and
builds it. so you essentiually dont even need make to build this
project!

esentially my project requires SDL2 and SD2_image (working on getting
it removed), OpenGL is optional, and basically does nothing currently.
You can add it by adding -lGL from the makefile, and renaming
glfunctions.c.bak to glfunctions.c in the src directory.

Lore: You arrived in the town of Hamsford answering the lords call,
for adventurers.  The town of Hamsford is sinking into a mysterious
bog that appeared in the last rainy season.


TODOS:
*Need a collection of portraits for the character selection. - the code is there just need better portraits
*create code for a message box

Enemies(not implemented)
- (d)Tentacle worm
- (d)Wretched undead
- (d) pirate
- Drowned rodent
- Thief
- Rampaging peasant

===============================================
Required to Compile:
hidden bog needs some basic SDL2 libraries to run and their development libraries to compile.
See SDL documentation for additional info
https://wiki.libsdl.org/Installation#Linux.2FUnix
SDL2 development libs
     Mint/Ubuntu
	sudo apt-get install libsdl2-2.0  libsdl2-ttf-dev libsdl2-ttf-2.0-0 libsdl2-dev libsdl2-image-2.0-0 libsdl2-image-dev
Required to run:
	 sdl2 sdl2-image sdl2-ttf
Experimental code
	 sqlite3
