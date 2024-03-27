#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

namespace Images {
constexpr uint8_t Player_Bullets[] PROGMEM =
{
      8,   8,   0,   2,   2,   7,   2,   7,   0,   2,   2,   7,   0,   2,   2,   7,
      0,   2,   0,   2,   2,   7,   2,   7,   0,   2,   2,   7,   0,   2,   0,   7,
      0,   2,   0,   2,   2,   7,   0,   7,   0,   2,   0,   7,   0,   2,   0,   7,
      0,   2,   0,   2,   2,   7,   0,   2,   2,   7,   0,   2,   2,   7,   2,   7,
      0,   2,   0,   2,   0,   7,   0,   2,   2,   7,   0,   2,   2,   7,   2,   7,
      0,   2,   0,   2,   0,   7,   0,   2,   0,   7,   0,   2,   0,   7,   2,   7,
      0,   2, 
};
constexpr uint8_t Arrows[] PROGMEM =
{
      3,   8,   4,  14,  31,   4,   2,   1,   0,   0,   0,  31,  14,   4,   1,   2,
      4,   0,   0,   0, 
};
constexpr uint8_t HUD_Treasure[] PROGMEM =
{
      5,   8,   4,  14,  31,  14,   4,   4,  14,  31,  14,   4,   0,   0,   0,   0,
      0, 
};
constexpr uint8_t Treasure[] PROGMEM =
{
      7,   8,   0,   8,   8,  28,  28,  62,  62, 127,  28,  62,   8,  28,   0,   8,
      0,   8,   8,  28,  28,  62,  62, 127,  28,  62,   8,  28,   0,   8,   0,   8,
      8,  28,  28,  62,  62, 127,  28,  62,   8,  28,   0,   8,   0,   8,   8,  28,
     28,  62,  62, 127,  28,  62,   8,  28,   0,   8,   0,   8,   8,  28,  28,  62,
     62, 127,  28,  62,   8,  28,   0,   8,   0,   8,   0,  28,   0,  62,   0, 127,
      0,  62,   0,  28,   0,   8,   0,   8,   8,  28,  28,  62,  62, 127,  28,  62,
      8,  28,   0,   8,   0,   8,   0,  28,   0,  62,   0, 127,   0,  62,   0,  28,
      0,   8,   0,   8,   0,  28,   0,  62,   0, 127,   0,  62,   0,  28,   0,   8,
      0,   8,   8,  28,  28,  62,  62, 127,  28,  62,   8,  28,   0,   8,   0,   8,
      8,  28,  28,  62,  62, 127,  28,  62,   8,  28,   0,   8,   0,   8,   0,  28,
      0,  62,   0, 127,   0,  62,   0,  28,   0,   8, 
};
constexpr uint8_t Numbers_5x3_2D_MB[] PROGMEM =
{
      7,   8,  62,  34,  62,   0,  62,  34,  62,  62,  34,  62,   0,  62,  34,  62,
      0,   0,   0,   0,   0,   0,   0,  62,  34,  62,   0,  36,  62,  32,  62,  34,
     62,   0,  36,  62,  32,   0,   0,   0,   0,   0,   0,   0,  62,  34,  62,   0,
     58,  42,  46,  62,  34,  62,   0,  58,  42,  46,   0,   0,   0,   0,   0,   0,
      0,  62,  34,  62,   0,  42,  42,  62,  62,  34,  62,   0,  42,  42,  62,   0,
      0,   0,   0,   0,   0,   0,  62,  34,  62,   0,  14,   8,  62,  62,  34,  62,
      0,  14,   8,  62,   0,   0,   0,   0,   0,   0,   0,  62,  34,  62,   0,  46,
     42,  58,  62,  34,  62,   0,  46,  42,  58,   0,   0,   0,   0,   0,   0,   0,
     62,  34,  62,   0,  62,  42,  58,  62,  34,  62,   0,  62,  42,  58,   0,   0,
      0,   0,   0,   0,   0,  62,  34,  62,   0,   2,  58,   6,  62,  34,  62,   0,
      2,  58,   6,   0,   0,   0,   0,   0,   0,   0,  62,  34,  62,   0,  62,  42,
     62,  62,  34,  62,   0,  62,  42,  62,   0,   0,   0,   0,   0,   0,   0,  62,
     34,  62,   0,  46,  42,  62,  62,  34,  62,   0,  46,  42,  62,   0,   0,   0,
      0,   0,   0,   0,  36,  62,  32,   0,  62,  34,  62,  36,  62,  32,   0,  62,
     34,  62,   0,   0,   0,   0,   0,   0,   0,  36,  62,  32,   0,  36,  62,  32,
     36,  62,  32,   0,  36,  62,  32,   0,   0,   0,   0,   0,   0,   0,  36,  62,
     32,   0,  58,  42,  46,  36,  62,  32,   0,  58,  42,  46,   0,   0,   0,   0,
      0,   0,   0,  36,  62,  32,   0,  42,  42,  62,  36,  62,  32,   0,  42,  42,
     62,   0,   0,   0,   0,   0,   0,   0,  36,  62,  32,   0,  14,   8,  62,  36,
     62,  32,   0,  14,   8,  62,   0,   0,   0,   0,   0,   0,   0,  36,  62,  32,
      0,  46,  42,  58,  36,  62,  32,   0,  46,  42,  58,   0,   0,   0,   0,   0,
      0,   0,  36,  62,  32,   0,  62,  42,  58,  36,  62,  32,   0,  62,  42,  58,
      0,   0,   0,   0,   0,   0,   0,  36,  62,  32,   0,   2,  58,   6,  36,  62,
     32,   0,   2,  58,   6,   0,   0,   0,   0,   0,   0,   0,  36,  62,  32,   0,
     62,  42,  62,  36,  62,  32,   0,  62,  42,  62,   0,   0,   0,   0,   0,   0,
      0,  36,  62,  32,   0,  46,  42,  62,  36,  62,  32,   0,  46,  42,  62,   0,
      0,   0,   0,   0,   0,   0,  58,  42,  46,   0,  62,  34,  62,  58,  42,  46,
      0,  62,  34,  62,   0,   0,   0,   0,   0,   0,   0,  58,  42,  46,   0,  36,
     62,  32,  58,  42,  46,   0,  36,  62,  32,   0,   0,   0,   0,   0,   0,   0,
     58,  42,  46,   0,  58,  42,  46,  58,  42,  46,   0,  58,  42,  46,   0,   0,
      0,   0,   0,   0,   0,  58,  42,  46,   0,  42,  42,  62,  58,  42,  46,   0,
     42,  42,  62,   0,   0,   0,   0,   0,   0,   0,  58,  42,  46,   0,  14,   8,
     62,  58,  42,  46,   0,  14,   8,  62,   0,   0,   0,   0,   0,   0,   0,  58,
     42,  46,   0,  46,  42,  58,  58,  42,  46,   0,  46,  42,  58,   0,   0,   0,
      0,   0,   0,   0,  58,  42,  46,   0,  62,  42,  58,  58,  42,  46,   0,  62,
     42,  58,   0,   0,   0,   0,   0,   0,   0,  58,  42,  46,   0,   2,  58,   6,
     58,  42,  46,   0,   2,  58,   6,   0,   0,   0,   0,   0,   0,   0,  58,  42,
     46,   0,  62,  42,  62,  58,  42,  46,   0,  62,  42,  62,   0,   0,   0,   0,
      0,   0,   0,  58,  42,  46,   0,  46,  42,  62,  58,  42,  46,   0,  46,  42,
     62,   0,   0,   0,   0,   0,   0,   0,  42,  42,  62,   0,  62,  34,  62,  42,
     42,  62,   0,  62,  34,  62,   0,   0,   0,   0,   0,   0,   0,  42,  42,  62,
      0,  36,  62,  32,  42,  42,  62,   0,  36,  62,  32,   0,   0,   0,   0,   0,
      0,   0,  42,  42,  62,   0,  58,  42,  46,  42,  42,  62,   0,  58,  42,  46,
      0,   0,   0,   0,   0,   0,   0,  42,  42,  62,   0,  42,  42,  62,  42,  42,
     62,   0,  42,  42,  62,   0,   0,   0,   0,   0,   0,   0,  42,  42,  62,   0,
     14,   8,  62,  42,  42,  62,   0,  14,   8,  62,   0,   0,   0,   0,   0,   0,
      0,  42,  42,  62,   0,  46,  42,  58,  42,  42,  62,   0,  46,  42,  58,   0,
      0,   0,   0,   0,   0,   0,  42,  42,  62,   0,  62,  42,  58,  42,  42,  62,
      0,  62,  42,  58,   0,   0,   0,   0,   0,   0,   0,  42,  42,  62,   0,   2,
     58,   6,  42,  42,  62,   0,   2,  58,   6,   0,   0,   0,   0,   0,   0,   0,
     42,  42,  62,   0,  62,  42,  62,  42,  42,  62,   0,  62,  42,  62,   0,   0,
      0,   0,   0,   0,   0,  42,  42,  62,   0,  46,  42,  62,  42,  42,  62,   0,
     46,  42,  62,   0,   0,   0,   0,   0,   0,   0,  14,   8,  62,   0,  62,  34,
     62,  14,   8,  62,   0,  62,  34,  62,   0,   0,   0,   0,   0,   0,   0,  14,
      8,  62,   0,  36,  62,  32,  14,   8,  62,   0,  36,  62,  32,   0,   0,   0,
      0,   0,   0,   0,  14,   8,  62,   0,  58,  42,  46,  14,   8,  62,   0,  58,
     42,  46,   0,   0,   0,   0,   0,   0,   0,  14,   8,  62,   0,  42,  42,  62,
     14,   8,  62,   0,  42,  42,  62,   0,   0,   0,   0,   0,   0,   0,  14,   8,
     62,   0,  14,   8,  62,  14,   8,  62,   0,  14,   8,  62,   0,   0,   0,   0,
      0,   0,   0,  14,   8,  62,   0,  46,  42,  58,  14,   8,  62,   0,  46,  42,
     58,   0,   0,   0,   0,   0,   0,   0,  14,   8,  62,   0,  62,  42,  58,  14,
      8,  62,   0,  62,  42,  58,   0,   0,   0,   0,   0,   0,   0,  14,   8,  62,
      0,   2,  58,   6,  14,   8,  62,   0,   2,  58,   6,   0,   0,   0,   0,   0,
      0,   0,  14,   8,  62,   0,  62,  42,  62,  14,   8,  62,   0,  62,  42,  62,
      0,   0,   0,   0,   0,   0,   0,  14,   8,  62,   0,  46,  42,  62,  14,   8,
     62,   0,  46,  42,  62,   0,   0,   0,   0,   0,   0,   0,  46,  42,  58,   0,
     62,  34,  62,  46,  42,  58,   0,  62,  34,  62,   0,   0,   0,   0,   0,   0,
      0,  46,  42,  58,   0,  36,  62,  32,  46,  42,  58,   0,  36,  62,  32,   0,
      0,   0,   0,   0,   0,   0,  46,  42,  58,   0,  58,  42,  46,  46,  42,  58,
      0,  58,  42,  46,   0,   0,   0,   0,   0,   0,   0,  46,  42,  58,   0,  42,
     42,  62,  46,  42,  58,   0,  42,  42,  62,   0,   0,   0,   0,   0,   0,   0,
     46,  42,  58,   0,  14,   8,  62,  46,  42,  58,   0,  14,   8,  62,   0,   0,
      0,   0,   0,   0,   0,  46,  42,  58,   0,  46,  42,  58,  46,  42,  58,   0,
     46,  42,  58,   0,   0,   0,   0,   0,   0,   0,  46,  42,  58,   0,  62,  42,
     58,  46,  42,  58,   0,  62,  42,  58,   0,   0,   0,   0,   0,   0,   0,  46,
     42,  58,   0,   2,  58,   6,  46,  42,  58,   0,   2,  58,   6,   0,   0,   0,
      0,   0,   0,   0,  46,  42,  58,   0,  62,  42,  62,  46,  42,  58,   0,  62,
     42,  62,   0,   0,   0,   0,   0,   0,   0,  46,  42,  58,   0,  46,  42,  62,
     46,  42,  58,   0,  46,  42,  62,   0,   0,   0,   0,   0,   0,   0,  62,  42,
     58,   0,  62,  34,  62,  62,  42,  58,   0,  62,  34,  62,   0,   0,   0,   0,
      0,   0,   0,  62,  42,  58,   0,  36,  62,  32,  62,  42,  58,   0,  36,  62,
     32,   0,   0,   0,   0,   0,   0,   0,  62,  42,  58,   0,  58,  42,  46,  62,
     42,  58,   0,  58,  42,  46,   0,   0,   0,   0,   0,   0,   0,  62,  42,  58,
      0,  42,  42,  62,  62,  42,  58,   0,  42,  42,  62,   0,   0,   0,   0,   0,
      0,   0,  62,  42,  58,   0,  14,   8,  62,  62,  42,  58,   0,  14,   8,  62,
      0,   0,   0,   0,   0,   0,   0,  62,  42,  58,   0,  46,  42,  58,  62,  42,
     58,   0,  46,  42,  58,   0,   0,   0,   0,   0,   0,   0,  62,  42,  58,   0,
     62,  42,  58,  62,  42,  58,   0,  62,  42,  58,   0,   0,   0,   0,   0,   0,
      0,  62,  42,  58,   0,   2,  58,   6,  62,  42,  58,   0,   2,  58,   6,   0,
      0,   0,   0,   0,   0,   0,  62,  42,  58,   0,  62,  42,  62,  62,  42,  58,
      0,  62,  42,  62,   0,   0,   0,   0,   0,   0,   0,  62,  42,  58,   0,  46,
     42,  62,  62,  42,  58,   0,  46,  42,  62,   0,   0,   0,   0,   0,   0,   0,
      2,  58,   6,   0,  62,  34,  62,   2,  58,   6,   0,  62,  34,  62,   0,   0,
      0,   0,   0,   0,   0,   2,  58,   6,   0,  36,  62,  32,   2,  58,   6,   0,
     36,  62,  32,   0,   0,   0,   0,   0,   0,   0,   2,  58,   6,   0,  58,  42,
     46,   2,  58,   6,   0,  58,  42,  46,   0,   0,   0,   0,   0,   0,   0,   2,
     58,   6,   0,  42,  42,  62,   2,  58,   6,   0,  42,  42,  62,   0,   0,   0,
      0,   0,   0,   0,   2,  58,   6,   0,  14,   8,  62,   2,  58,   6,   0,  14,
      8,  62,   0,   0,   0,   0,   0,   0,   0,   2,  58,   6,   0,  46,  42,  58,
      2,  58,   6,   0,  46,  42,  58,   0,   0,   0,   0,   0,   0,   0,   2,  58,
      6,   0,  62,  42,  58,   2,  58,   6,   0,  62,  42,  58,   0,   0,   0,   0,
      0,   0,   0,   2,  58,   6,   0,   2,  58,   6,   2,  58,   6,   0,   2,  58,
      6,   0,   0,   0,   0,   0,   0,   0,   2,  58,   6,   0,  62,  42,  62,   2,
     58,   6,   0,  62,  42,  62,   0,   0,   0,   0,   0,   0,   0,   2,  58,   6,
      0,  46,  42,  62,   2,  58,   6,   0,  46,  42,  62,   0,   0,   0,   0,   0,
      0,   0,  62,  42,  62,   0,  62,  34,  62,  62,  42,  62,   0,  62,  34,  62,
      0,   0,   0,   0,   0,   0,   0,  62,  42,  62,   0,  36,  62,  32,  62,  42,
     62,   0,  36,  62,  32,   0,   0,   0,   0,   0,   0,   0,  62,  42,  62,   0,
     58,  42,  46,  62,  42,  62,   0,  58,  42,  46,   0,   0,   0,   0,   0,   0,
      0,  62,  42,  62,   0,  42,  42,  62,  62,  42,  62,   0,  42,  42,  62,   0,
      0,   0,   0,   0,   0,   0,  62,  42,  62,   0,  14,   8,  62,  62,  42,  62,
      0,  14,   8,  62,   0,   0,   0,   0,   0,   0,   0,  62,  42,  62,   0,  46,
     42,  58,  62,  42,  62,   0,  46,  42,  58,   0,   0,   0,   0,   0,   0,   0,
     62,  42,  62,   0,  62,  42,  58,  62,  42,  62,   0,  62,  42,  58,   0,   0,
      0,   0,   0,   0,   0,  62,  42,  62,   0,   2,  58,   6,  62,  42,  62,   0,
      2,  58,   6,   0,   0,   0,   0,   0,   0,   0,  62,  42,  62,   0,  62,  42,
     62,  62,  42,  62,   0,  62,  42,  62,   0,   0,   0,   0,   0,   0,   0,  62,
     42,  62,   0,  46,  42,  62,  62,  42,  62,   0,  46,  42,  62,   0,   0,   0,
      0,   0,   0,   0,  46,  42,  62,   0,  62,  34,  62,  46,  42,  62,   0,  62,
     34,  62,   0,   0,   0,   0,   0,   0,   0,  46,  42,  62,   0,  36,  62,  32,
     46,  42,  62,   0,  36,  62,  32,   0,   0,   0,   0,   0,   0,   0,  46,  42,
     62,   0,  58,  42,  46,  46,  42,  62,   0,  58,  42,  46,   0,   0,   0,   0,
      0,   0,   0,  46,  42,  62,   0,  42,  42,  62,  46,  42,  62,   0,  42,  42,
     62,   0,   0,   0,   0,   0,   0,   0,  46,  42,  62,   0,  14,   8,  62,  46,
     42,  62,   0,  14,   8,  62,   0,   0,   0,   0,   0,   0,   0,  46,  42,  62,
      0,  46,  42,  58,  46,  42,  62,   0,  46,  42,  58,   0,   0,   0,   0,   0,
      0,   0,  46,  42,  62,   0,  62,  42,  58,  46,  42,  62,   0,  62,  42,  58,
      0,   0,   0,   0,   0,   0,   0,  46,  42,  62,   0,   2,  58,   6,  46,  42,
     62,   0,   2,  58,   6,   0,   0,   0,   0,   0,   0,   0,  46,  42,  62,   0,
     62,  42,  62,  46,  42,  62,   0,  62,  42,  62,   0,   0,   0,   0,   0,   0,
      0,  46,  42,  62,   0,  46,  42,  62,  46,  42,  62,   0,  46,  42,  62,   0,
      0,   0,   0,   0,   0,   0, 
};
constexpr uint8_t Numbers_5x3_2D_WB[] PROGMEM =
{
      7,   8,  62,  62,  34,  34,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,
     62,  62,  34,  34,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  62,  62,
     34,  34,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  62,  62,  34,  34,
     62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  62,  62,  34,  34,  62,  62,
      0,   0,  36,  36,  62,  62,  32,  32,  62,  62,  34,  34,  62,  62,   0,   0,
     36,  36,  62,  62,  32,  32,  62,  62,  34,  34,  62,  62,   0,   0,  58,  58,
     42,  42,  46,  46,  62,  62,  34,  34,  62,  62,   0,   0,  58,  58,  42,  42,
     46,  46,  62,  62,  34,  34,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,
     62,  62,  34,  34,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,
     34,  34,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,  34,  34,
     62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,  34,  34,  62,  62,
      0,   0,  14,  14,   8,   8,  62,  62,  62,  62,  34,  34,  62,  62,   0,   0,
     14,  14,   8,   8,  62,  62,  62,  62,  34,  34,  62,  62,   0,   0,  14,  14,
      8,   8,  62,  62,  62,  62,  34,  34,  62,  62,   0,   0,  46,  46,  42,  42,
     58,  58,  62,  62,  34,  34,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,
     62,  62,  34,  34,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  62,  62,
     34,  34,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  34,  34,
     62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  34,  34,  62,  62,
      0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  34,  34,  62,  62,   0,   0,
      2,   2,  58,  58,   6,   6,  62,  62,  34,  34,  62,  62,   0,   0,   2,   2,
     58,  58,   6,   6,  62,  62,  34,  34,  62,  62,   0,   0,   2,   2,  58,  58,
      6,   6,  62,  62,  34,  34,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,
     62,  62,  34,  34,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  62,  62,
     34,  34,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  62,  62,  34,  34,
     62,  62,   0,   0,  46,  46,  42,  42,  62,  62,  62,  62,  34,  34,  62,  62,
      0,   0,  46,  46,  42,  42,  62,  62,  62,  62,  34,  34,  62,  62,   0,   0,
     46,  46,  42,  42,  62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,
     34,  34,  62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  34,  34,
     62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  34,  34,  62,  62,
     36,  36,  62,  62,  32,  32,   0,   0,  36,  36,  62,  62,  32,  32,  36,  36,
     62,  62,  32,  32,   0,   0,  36,  36,  62,  62,  32,  32,  36,  36,  62,  62,
     32,  32,   0,   0,  36,  36,  62,  62,  32,  32,  36,  36,  62,  62,  32,  32,
      0,   0,  58,  58,  42,  42,  46,  46,  36,  36,  62,  62,  32,  32,   0,   0,
     58,  58,  42,  42,  46,  46,  36,  36,  62,  62,  32,  32,   0,   0,  58,  58,
     42,  42,  46,  46,  36,  36,  62,  62,  32,  32,   0,   0,  42,  42,  42,  42,
     62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  42,  42,  42,  42,  62,  62,
     36,  36,  62,  62,  32,  32,   0,   0,  42,  42,  42,  42,  62,  62,  36,  36,
     62,  62,  32,  32,   0,   0,  14,  14,   8,   8,  62,  62,  36,  36,  62,  62,
     32,  32,   0,   0,  14,  14,   8,   8,  62,  62,  36,  36,  62,  62,  32,  32,
      0,   0,  14,  14,   8,   8,  62,  62,  36,  36,  62,  62,  32,  32,   0,   0,
     46,  46,  42,  42,  58,  58,  36,  36,  62,  62,  32,  32,   0,   0,  46,  46,
     42,  42,  58,  58,  36,  36,  62,  62,  32,  32,   0,   0,  46,  46,  42,  42,
     58,  58,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  42,  42,  58,  58,
     36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  42,  42,  58,  58,  36,  36,
     62,  62,  32,  32,   0,   0,  62,  62,  42,  42,  58,  58,  36,  36,  62,  62,
     32,  32,   0,   0,   2,   2,  58,  58,   6,   6,  36,  36,  62,  62,  32,  32,
      0,   0,   2,   2,  58,  58,   6,   6,  36,  36,  62,  62,  32,  32,   0,   0,
      2,   2,  58,  58,   6,   6,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,
     42,  42,  62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  42,  42,
     62,  62,  36,  36,  62,  62,  32,  32,   0,   0,  62,  62,  42,  42,  62,  62,
     36,  36,  62,  62,  32,  32,   0,   0,  46,  46,  42,  42,  62,  62,  36,  36,
     62,  62,  32,  32,   0,   0,  46,  46,  42,  42,  62,  62,  36,  36,  62,  62,
     32,  32,   0,   0,  46,  46,  42,  42,  62,  62,  58,  58,  42,  42,  46,  46,
      0,   0,  62,  62,  34,  34,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,
     62,  62,  34,  34,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  62,  62,
     34,  34,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  36,  36,  62,  62,
     32,  32,  58,  58,  42,  42,  46,  46,   0,   0,  36,  36,  62,  62,  32,  32,
     58,  58,  42,  42,  46,  46,   0,   0,  36,  36,  62,  62,  32,  32,  58,  58,
     42,  42,  46,  46,   0,   0,  58,  58,  42,  42,  46,  46,  58,  58,  42,  42,
     46,  46,   0,   0,  58,  58,  42,  42,  46,  46,  58,  58,  42,  42,  46,  46,
      0,   0,  58,  58,  42,  42,  46,  46,  58,  58,  42,  42,  46,  46,   0,   0,
     42,  42,  42,  42,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  42,  42,
     42,  42,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  42,  42,  42,  42,
     62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  14,  14,   8,   8,  62,  62,
     58,  58,  42,  42,  46,  46,   0,   0,  14,  14,   8,   8,  62,  62,  58,  58,
     42,  42,  46,  46,   0,   0,  14,  14,   8,   8,  62,  62,  58,  58,  42,  42,
     46,  46,   0,   0,  46,  46,  42,  42,  58,  58,  58,  58,  42,  42,  46,  46,
      0,   0,  46,  46,  42,  42,  58,  58,  58,  58,  42,  42,  46,  46,   0,   0,
     46,  46,  42,  42,  58,  58,  58,  58,  42,  42,  46,  46,   0,   0,  62,  62,
     42,  42,  58,  58,  58,  58,  42,  42,  46,  46,   0,   0,  62,  62,  42,  42,
     58,  58,  58,  58,  42,  42,  46,  46,   0,   0,  62,  62,  42,  42,  58,  58,
     58,  58,  42,  42,  46,  46,   0,   0,   2,   2,  58,  58,   6,   6,  58,  58,
     42,  42,  46,  46,   0,   0,   2,   2,  58,  58,   6,   6,  58,  58,  42,  42,
     46,  46,   0,   0,   2,   2,  58,  58,   6,   6,  58,  58,  42,  42,  46,  46,
      0,   0,  62,  62,  42,  42,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,
     62,  62,  42,  42,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  62,  62,
     42,  42,  62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  46,  46,  42,  42,
     62,  62,  58,  58,  42,  42,  46,  46,   0,   0,  46,  46,  42,  42,  62,  62,
     58,  58,  42,  42,  46,  46,   0,   0,  46,  46,  42,  42,  62,  62,  42,  42,
     42,  42,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  42,  42,  42,  42,
     62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  42,  42,  42,  42,  62,  62,
      0,   0,  62,  62,  34,  34,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,
     36,  36,  62,  62,  32,  32,  42,  42,  42,  42,  62,  62,   0,   0,  36,  36,
     62,  62,  32,  32,  42,  42,  42,  42,  62,  62,   0,   0,  36,  36,  62,  62,
     32,  32,  42,  42,  42,  42,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,
     42,  42,  42,  42,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,  42,  42,
     42,  42,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,  42,  42,  42,  42,
     62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,
      0,   0,  42,  42,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,
     42,  42,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,  14,  14,
      8,   8,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,  14,  14,   8,   8,
     62,  62,  42,  42,  42,  42,  62,  62,   0,   0,  14,  14,   8,   8,  62,  62,
     42,  42,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  42,  42,
     42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  42,  42,  42,  42,
     62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  42,  42,  42,  42,  62,  62,
      0,   0,  62,  62,  42,  42,  58,  58,  42,  42,  42,  42,  62,  62,   0,   0,
     62,  62,  42,  42,  58,  58,  42,  42,  42,  42,  62,  62,   0,   0,  62,  62,
     42,  42,  58,  58,  42,  42,  42,  42,  62,  62,   0,   0,   2,   2,  58,  58,
      6,   6,  42,  42,  42,  42,  62,  62,   0,   0,   2,   2,  58,  58,   6,   6,
     42,  42,  42,  42,  62,  62,   0,   0,   2,   2,  58,  58,   6,   6,  42,  42,
     42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  42,  42,  42,  42,
     62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,
      0,   0,  62,  62,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,
     46,  46,  42,  42,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,  46,  46,
     42,  42,  62,  62,  42,  42,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,
     62,  62,  14,  14,   8,   8,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,
     14,  14,   8,   8,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  14,  14,
      8,   8,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  14,  14,   8,   8,
     62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  14,  14,   8,   8,  62,  62,
      0,   0,  36,  36,  62,  62,  32,  32,  14,  14,   8,   8,  62,  62,   0,   0,
     36,  36,  62,  62,  32,  32,  14,  14,   8,   8,  62,  62,   0,   0,  58,  58,
     42,  42,  46,  46,  14,  14,   8,   8,  62,  62,   0,   0,  58,  58,  42,  42,
     46,  46,  14,  14,   8,   8,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,
     14,  14,   8,   8,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  14,  14,
      8,   8,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  14,  14,   8,   8,
     62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  14,  14,   8,   8,  62,  62,
      0,   0,  14,  14,   8,   8,  62,  62,  14,  14,   8,   8,  62,  62,   0,   0,
     14,  14,   8,   8,  62,  62,  14,  14,   8,   8,  62,  62,   0,   0,  14,  14,
      8,   8,  62,  62,  14,  14,   8,   8,  62,  62,   0,   0,  46,  46,  42,  42,
     58,  58,  14,  14,   8,   8,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,
     14,  14,   8,   8,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  14,  14,
      8,   8,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  14,  14,   8,   8,
     62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  14,  14,   8,   8,  62,  62,
      0,   0,  62,  62,  42,  42,  58,  58,  14,  14,   8,   8,  62,  62,   0,   0,
      2,   2,  58,  58,   6,   6,  14,  14,   8,   8,  62,  62,   0,   0,   2,   2,
     58,  58,   6,   6,  14,  14,   8,   8,  62,  62,   0,   0,   2,   2,  58,  58,
      6,   6,  14,  14,   8,   8,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,
     14,  14,   8,   8,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  14,  14,
      8,   8,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  14,  14,   8,   8,
     62,  62,   0,   0,  46,  46,  42,  42,  62,  62,  14,  14,   8,   8,  62,  62,
      0,   0,  46,  46,  42,  42,  62,  62,  14,  14,   8,   8,  62,  62,   0,   0,
     46,  46,  42,  42,  62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,
     34,  34,  62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  34,  34,
     62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  34,  34,  62,  62,
     46,  46,  42,  42,  58,  58,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,
     42,  42,  58,  58,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,  42,  42,
     58,  58,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,  42,  42,  58,  58,
      0,   0,  58,  58,  42,  42,  46,  46,  46,  46,  42,  42,  58,  58,   0,   0,
     58,  58,  42,  42,  46,  46,  46,  46,  42,  42,  58,  58,   0,   0,  58,  58,
     42,  42,  46,  46,  46,  46,  42,  42,  58,  58,   0,   0,  42,  42,  42,  42,
     62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  42,  42,  42,  42,  62,  62,
     46,  46,  42,  42,  58,  58,   0,   0,  42,  42,  42,  42,  62,  62,  46,  46,
     42,  42,  58,  58,   0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,
     58,  58,   0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,  58,  58,
      0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,  58,  58,   0,   0,
     46,  46,  42,  42,  58,  58,  46,  46,  42,  42,  58,  58,   0,   0,  46,  46,
     42,  42,  58,  58,  46,  46,  42,  42,  58,  58,   0,   0,  46,  46,  42,  42,
     58,  58,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,  58,  58,
     46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,  58,  58,  46,  46,
     42,  42,  58,  58,   0,   0,  62,  62,  42,  42,  58,  58,  46,  46,  42,  42,
     58,  58,   0,   0,   2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  58,  58,
      0,   0,   2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  58,  58,   0,   0,
      2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,
     42,  42,  62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,
     62,  62,  46,  46,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,  62,  62,
     46,  46,  42,  42,  58,  58,   0,   0,  46,  46,  42,  42,  62,  62,  46,  46,
     42,  42,  58,  58,   0,   0,  46,  46,  42,  42,  62,  62,  46,  46,  42,  42,
     58,  58,   0,   0,  46,  46,  42,  42,  62,  62,  62,  62,  42,  42,  58,  58,
      0,   0,  62,  62,  34,  34,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,
     62,  62,  34,  34,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  62,  62,
     34,  34,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  36,  36,  62,  62,
     32,  32,  62,  62,  42,  42,  58,  58,   0,   0,  36,  36,  62,  62,  32,  32,
     62,  62,  42,  42,  58,  58,   0,   0,  36,  36,  62,  62,  32,  32,  62,  62,
     42,  42,  58,  58,   0,   0,  58,  58,  42,  42,  46,  46,  62,  62,  42,  42,
     58,  58,   0,   0,  58,  58,  42,  42,  46,  46,  62,  62,  42,  42,  58,  58,
      0,   0,  58,  58,  42,  42,  46,  46,  62,  62,  42,  42,  58,  58,   0,   0,
     42,  42,  42,  42,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  42,  42,
     42,  42,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  42,  42,  42,  42,
     62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  14,  14,   8,   8,  62,  62,
     62,  62,  42,  42,  58,  58,   0,   0,  14,  14,   8,   8,  62,  62,  62,  62,
     42,  42,  58,  58,   0,   0,  14,  14,   8,   8,  62,  62,  62,  62,  42,  42,
     58,  58,   0,   0,  46,  46,  42,  42,  58,  58,  62,  62,  42,  42,  58,  58,
      0,   0,  46,  46,  42,  42,  58,  58,  62,  62,  42,  42,  58,  58,   0,   0,
     46,  46,  42,  42,  58,  58,  62,  62,  42,  42,  58,  58,   0,   0,  62,  62,
     42,  42,  58,  58,  62,  62,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,
     58,  58,  62,  62,  42,  42,  58,  58,   0,   0,  62,  62,  42,  42,  58,  58,
     62,  62,  42,  42,  58,  58,   0,   0,   2,   2,  58,  58,   6,   6,  62,  62,
     42,  42,  58,  58,   0,   0,   2,   2,  58,  58,   6,   6,  62,  62,  42,  42,
     58,  58,   0,   0,   2,   2,  58,  58,   6,   6,  62,  62,  42,  42,  58,  58,
      0,   0,  62,  62,  42,  42,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,
     62,  62,  42,  42,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  62,  62,
     42,  42,  62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  46,  46,  42,  42,
     62,  62,  62,  62,  42,  42,  58,  58,   0,   0,  46,  46,  42,  42,  62,  62,
     62,  62,  42,  42,  58,  58,   0,   0,  46,  46,  42,  42,  62,  62,   2,   2,
     58,  58,   6,   6,   0,   0,  62,  62,  34,  34,  62,  62,   2,   2,  58,  58,
      6,   6,   0,   0,  62,  62,  34,  34,  62,  62,   2,   2,  58,  58,   6,   6,
      0,   0,  62,  62,  34,  34,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,
     36,  36,  62,  62,  32,  32,   2,   2,  58,  58,   6,   6,   0,   0,  36,  36,
     62,  62,  32,  32,   2,   2,  58,  58,   6,   6,   0,   0,  36,  36,  62,  62,
     32,  32,   2,   2,  58,  58,   6,   6,   0,   0,  58,  58,  42,  42,  46,  46,
      2,   2,  58,  58,   6,   6,   0,   0,  58,  58,  42,  42,  46,  46,   2,   2,
     58,  58,   6,   6,   0,   0,  58,  58,  42,  42,  46,  46,   2,   2,  58,  58,
      6,   6,   0,   0,  42,  42,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,
      0,   0,  42,  42,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,
     42,  42,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,  14,  14,
      8,   8,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,  14,  14,   8,   8,
     62,  62,   2,   2,  58,  58,   6,   6,   0,   0,  14,  14,   8,   8,  62,  62,
      2,   2,  58,  58,   6,   6,   0,   0,  46,  46,  42,  42,  58,  58,   2,   2,
     58,  58,   6,   6,   0,   0,  46,  46,  42,  42,  58,  58,   2,   2,  58,  58,
      6,   6,   0,   0,  46,  46,  42,  42,  58,  58,   2,   2,  58,  58,   6,   6,
      0,   0,  62,  62,  42,  42,  58,  58,   2,   2,  58,  58,   6,   6,   0,   0,
     62,  62,  42,  42,  58,  58,   2,   2,  58,  58,   6,   6,   0,   0,  62,  62,
     42,  42,  58,  58,   2,   2,  58,  58,   6,   6,   0,   0,   2,   2,  58,  58,
      6,   6,   2,   2,  58,  58,   6,   6,   0,   0,   2,   2,  58,  58,   6,   6,
      2,   2,  58,  58,   6,   6,   0,   0,   2,   2,  58,  58,   6,   6,   2,   2,
     58,  58,   6,   6,   0,   0,  62,  62,  42,  42,  62,  62,   2,   2,  58,  58,
      6,   6,   0,   0,  62,  62,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,
      0,   0,  62,  62,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,
     46,  46,  42,  42,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,  46,  46,
     42,  42,  62,  62,   2,   2,  58,  58,   6,   6,   0,   0,  46,  46,  42,  42,
     62,  62,  62,  62,  42,  42,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,
     62,  62,  42,  42,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  62,  62,
     42,  42,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,  62,  62,  42,  42,
     62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  62,  62,  42,  42,  62,  62,
      0,   0,  36,  36,  62,  62,  32,  32,  62,  62,  42,  42,  62,  62,   0,   0,
     36,  36,  62,  62,  32,  32,  62,  62,  42,  42,  62,  62,   0,   0,  58,  58,
     42,  42,  46,  46,  62,  62,  42,  42,  62,  62,   0,   0,  58,  58,  42,  42,
     46,  46,  62,  62,  42,  42,  62,  62,   0,   0,  58,  58,  42,  42,  46,  46,
     62,  62,  42,  42,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,
     42,  42,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,  42,  42,
     62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  62,  62,  42,  42,  62,  62,
      0,   0,  14,  14,   8,   8,  62,  62,  62,  62,  42,  42,  62,  62,   0,   0,
     14,  14,   8,   8,  62,  62,  62,  62,  42,  42,  62,  62,   0,   0,  14,  14,
      8,   8,  62,  62,  62,  62,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,
     58,  58,  62,  62,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,
     62,  62,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  58,  58,  62,  62,
     42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  42,  42,
     62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  42,  42,  62,  62,
      0,   0,  62,  62,  42,  42,  58,  58,  62,  62,  42,  42,  62,  62,   0,   0,
      2,   2,  58,  58,   6,   6,  62,  62,  42,  42,  62,  62,   0,   0,   2,   2,
     58,  58,   6,   6,  62,  62,  42,  42,  62,  62,   0,   0,   2,   2,  58,  58,
      6,   6,  62,  62,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,
     62,  62,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  62,  62,
     42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,  62,  62,  42,  42,
     62,  62,   0,   0,  46,  46,  42,  42,  62,  62,  62,  62,  42,  42,  62,  62,
      0,   0,  46,  46,  42,  42,  62,  62,  62,  62,  42,  42,  62,  62,   0,   0,
     46,  46,  42,  42,  62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,
     34,  34,  62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  34,  34,
     62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  34,  34,  62,  62,
     46,  46,  42,  42,  62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,
     42,  42,  62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,  42,  42,
     62,  62,   0,   0,  36,  36,  62,  62,  32,  32,  46,  46,  42,  42,  62,  62,
      0,   0,  58,  58,  42,  42,  46,  46,  46,  46,  42,  42,  62,  62,   0,   0,
     58,  58,  42,  42,  46,  46,  46,  46,  42,  42,  62,  62,   0,   0,  58,  58,
     42,  42,  46,  46,  46,  46,  42,  42,  62,  62,   0,   0,  42,  42,  42,  42,
     62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,
     46,  46,  42,  42,  62,  62,   0,   0,  42,  42,  42,  42,  62,  62,  46,  46,
     42,  42,  62,  62,   0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,
     62,  62,   0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,  62,  62,
      0,   0,  14,  14,   8,   8,  62,  62,  46,  46,  42,  42,  62,  62,   0,   0,
     46,  46,  42,  42,  58,  58,  46,  46,  42,  42,  62,  62,   0,   0,  46,  46,
     42,  42,  58,  58,  46,  46,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,
     58,  58,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,
     46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  46,  46,
     42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  58,  58,  46,  46,  42,  42,
     62,  62,   0,   0,   2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  62,  62,
      0,   0,   2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  62,  62,   0,   0,
      2,   2,  58,  58,   6,   6,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,
     42,  42,  62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,
     62,  62,  46,  46,  42,  42,  62,  62,   0,   0,  62,  62,  42,  42,  62,  62,
     46,  46,  42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  62,  62,  46,  46,
     42,  42,  62,  62,   0,   0,  46,  46,  42,  42,  62,  62,  46,  46,  42,  42,
     62,  62,   0,   0,  46,  46,  42,  42,  62,  62, 
};
constexpr uint8_t Health[] PROGMEM =
{
     30,   8,   6,  15,  30,  15,   6,   0,   6,   9,  18,   9,   6,   0,   6,   9,
     18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,  15,  30,  15,
      6,   0,   6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,   9,
     18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,  15,  30,  15,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,
      6,   0,   6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,   9,
     18,   9,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,
      6,   0,   6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,  15,
     30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,  15,  30,  15,   6,   0,
      6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,
      6,   0,   6,   9,  18,   9,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,
     30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,
      6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,
      6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,
     30,  15,   6,   0,   6,  15,  30,  15,   6,   0,   6,  15,  30,  15,   6,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   6,   9,
     18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,
      6,   9,  18,   9,   6,   0,   6,   9,  18,   9,   6,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0, 
};
};