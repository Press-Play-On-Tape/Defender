#pragma once

/**** FX data header generated by fxdata-build.py tool version 1.13 ****/

using uint24_t = __uint24;

// Initialize FX hardware using  FX::begin(FX_DATA_PAGE); in the setup() function.

constexpr uint16_t FX_DATA_PAGE  = 0xfe69;
constexpr uint24_t FX_DATA_BYTES = 99943;

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
  constexpr uint24_t Player_Thrust = 0x001D13;
  constexpr uint24_t Bullets = 0x0023D5;
  constexpr uint24_t Health = 0x00253F;
  constexpr uint24_t Enemy_00 = 0x00275D;
  constexpr uint24_t Enemy_01 = 0x002F3F;
  constexpr uint24_t Enemy_02 = 0x0030F1;
  constexpr uint24_t HUD = 0x00316B;
  constexpr uint24_t PPOT = 0x003209;
  constexpr uint24_t Sound_Volume = 0x00620B;
  constexpr uint24_t Sound_Checkbox = 0x006A4D;
  constexpr uint24_t Title = 0x006A5B;
  constexpr uint24_t Numbers_5x3_1D_WB = 0x012A5D;
  constexpr uint24_t Numbers_5x3_2D_WB = 0x012AB9;
  constexpr uint24_t Numbers_5x3_1D_MB = 0x0132EF;
  constexpr uint24_t Numbers_5x3_2D_MB = 0x01334B;
  constexpr uint24_t GameOver = 0x013B81;
  constexpr uint24_t Quit = 0x01424F;
  constexpr uint24_t BG_00 = 0x0146D1;
  constexpr uint24_t MG_00 = 0x015D53;
  constexpr uint24_t FG_00 = 0x017855;
}

