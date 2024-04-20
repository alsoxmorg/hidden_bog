#!/bin/bash

#alternate to make, for some compatibility, and undseranding
#what is going on.
# Define the source files and compiler flags
SRCDIR="src/"
SRC_FILES="actors.c chargen.c crafting.c crafting.c data.c gameoptions.c glfunctions.c input.c main.c maps.c render.c renderports.c resources.c scene.c sheet_character.c sheet_dialogue.c sheet_inventory.c text.c update.c"

LAZY_SRC_FILES="*.c"


CFLAGS="-Wall -Wextra -std=c99 -Wunused-but-set-variable" #`sdl2-config --cflags --libs`"

#if you do not have sdl2-config in path, consider installing it.
#alternativly you can use "-I/pathtoyour/SDL.h -L/pathtoyour/libSDL2.so"
SDL2FLAGS="`sdl2-config --cflags --libs`"
LIBFLAGS="-lGL -lSDL2_image"

# Compile the source files into object files
for file in $LAZY_SRC_FILES; do
    #for file in $SRC_FILES; do
    echo "compiling" $file "..."
    gcc -c $CFLAGS $SDL2FLAGS $LIBFLAGS $file
done

# Link the object files into an executable
echo "linking to executable"
gcc $CFLAGS $SDL2FLAGS $LIBFLAGS -o game *.o #$SRC_FILES.o


# copy the game executable out of src dir
echo "copying game back to main directory"
cp game ../
