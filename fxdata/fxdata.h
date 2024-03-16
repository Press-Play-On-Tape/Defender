#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.13 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfe65;
constexpr uint24_t FX_DATA_BYTES = 100967;

constexpr uint16_t FX_SAVE_PAGE  = 0xfff0;
constexpr uint24_t FX_SAVE_BYTES = 2;

namespace Music
{
  constexpr uint24_t Song_MainTheme = 0x000000;
  constexpr uint24_t SFX_Three_Inc = 0x00179D;
  constexpr uint24_t SFX_Three_Dec = 0x0017B9;
  constexpr uint24_t SFX_Death = 0x0017D5;
  constexpr uint24_t SFX_Victory = 0x001889;
  constexpr uint24_t SFX_XPGain = 0x00193D;
}

namespace Images
{
  constexpr uint24_t Player = 0x001951;
  constexpr uint24_t Player_Thrust = 0x001E93;
  constexpr uint24_t Bullets = 0x002555;
  constexpr uint24_t Enemy_00 = 0x0026BF;
  constexpr uint24_t Enemy_00_Pickup = 0x002EA1;
  constexpr uint24_t Enemy_01 = 0x004937;
  constexpr uint24_t Enemy_02 = 0x004AE9;
  constexpr uint24_t Treasure = 0x004B93;
  constexpr uint24_t PPOT = 0x004C3D;
  constexpr uint24_t Sound_Volume = 0x007C3F;
  constexpr uint24_t Sound_Checkbox = 0x008481;
  constexpr uint24_t Title = 0x00848F;
  constexpr uint24_t GameOver = 0x014491;
  constexpr uint24_t Quit = 0x014B5F;
  constexpr uint24_t BG_00 = 0x014FE1;
  constexpr uint24_t MG_00 = 0x016663;
  constexpr uint24_t FG_00 = 0x018165;
}

