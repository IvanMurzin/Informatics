#include "Color.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

const char *getColor(COLOR color) {
    switch (color) {
        case red:
            return ANSI_COLOR_RED;
        case green:
            return ANSI_COLOR_GREEN;
        case reset:
            return ANSI_COLOR_RESET;
        case blue:
            return ANSI_COLOR_BLUE;
        default:
            return "";
    }
}