#ifndef REQUIRE
#define REQUIRE
#define _POSIX_C_SOURCE 199309L /* This ensures timespec actually works */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>

struct coords{
    int x,y,z,l;
};


#endif
