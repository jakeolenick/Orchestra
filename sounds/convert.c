#include <stdio.h>
#include <stdlib.h>

//notes in equal temperament, rounded to nearest ten-thousandth
#define NOTE_D5 587.3296 * 2
#define NOTE_Db5 554.3653 * 2
#define NOTE_C5 523.2511 * 2
#define NOTE_B5 493.8833 * 2
#define NOTE_Bb5 466.1638 * 2
#define NOTE_A5 440.0000 * 2
#define NOTE_Ab5 415.3047 * 2
#define NOTE_G4 391.9954 * 2
#define NOTE_Gb4 369.9944 * 2
#define NOTE_F4 349.2282 * 2
#define NOTE_E4 329.6275 * 2
#define NOTE_Eb4 311.1270 * 2
#define NOTE_D4 587.3296
#define NOTE_Db4 554.3653
#define NOTE_C4 523.2511
#define NOTE_B4 493.8833
#define NOTE_Bb4 466.1638
#define NOTE_A4 440.0000
#define NOTE_Ab4 415.3047
#define NOTE_G3 391.9954
#define NOTE_Gb3 369.9944
#define NOTE_F3 349.2282
#define NOTE_E3 329.6275
#define NOTE_Eb3 311.1270
#define NOTE_D3 293.6648
#define NOTE_Db3 277.1826
#define NOTE_C3 261.6257
#define NOTE_B3 246.9417
#define NOTE_Bb3 233.0819
#define NOTE_A3 220.0000
#define NOTE_Ab3 (415.3047 / 2)
#define NOTE_G2 (391.9954 / 2)
#define NOTE_Gb2 (369.9944 / 2)
#define NOTE_F2 (349.2282 / 2)
#define NOTE_E2 (329.6275 / 2)
#define NOTE_Eb2 (311.1270 / 2)
#define NOTE_D2 (293.6648 / 2)
#define NOTE_Db2 (277.1826 / 2)
#define NOTE_C2 (261.6257 / 2)
#define NOTE_B2 (246.9417 / 2)
#define NOTE_Bb2 (233.0819 / 2)
#define NOTE_A2 110.0000
#define NOTE_Ab2 (415.3047 / 4)
#define NOTE_G1 (391.9954 / 4)
#define NOTE_Gb1 (369.9944 / 4)
#define NOTE_F1 (349.2282 / 4)
#define NOTE_E1 (329.6275 / 4)
#define NOTE_Eb1 (311.1270 / 4)
#define NOTE_D1 (293.6648 / 4)
#define NOTE_Db1 (277.1826 / 4)
#define NOTE_C1 (261.6257 / 4)
#define NOTE_B1 (246.9417 / 4)
#define NOTE_Bb1 (233.0819 / 4)
#define NOTE_A1 55.0000
#define NOTE_Ab1 (415.3047 / 8)
#define NOTE_G0 (391.9954 / 8)
#define NOTE_Gb0 (369.9944 / 8)
#define NOTE_F0 (349.2282 / 8)
#define NOTE_E0 (329.6275 / 8)
#define NOTE_Eb0 (311.1270 / 8)
#define NOTE_D0 (293.6648 / 8)
#define NOTE_Db0 (277.1826 / 8)
#define NOTE_C0 (261.6257 / 8)
#define NOTE_B0 (246.9417 / 8)
#define NOTE_Bb0 (233.0819 / 8)
#define NOTE_A0 27.5000


float convert0(char c){
  if(c == 'a' || c == 'A')
    return NOTE_C0;
  if(c == 'w' || c == 'W')
    return NOTE_Db0;
  if(c == 's' || c == 'S')
    return NOTE_D0;
  if(c == 'e' || c == 'E')
    return NOTE_Eb0;
  if(c == 'd' || c == 'D')
    return NOTE_E0;
  if(c == 'f' || c == 'F')
    return NOTE_F0;
  if(c == 't' || c == 'T')
    return NOTE_Gb0;
  if(c == 'g' || c == 'G')
    return NOTE_G0;
  if(c == 'y' || c == 'Y')
    return NOTE_Ab1;
  if(c == 'h' || c == 'H')
    return NOTE_A1;
  if(c == 'u' || c == 'U')
    return NOTE_Bb1;
  if(c == 'j' || c == 'J')
    return NOTE_B1;
  if(c == 'k' || c == 'K')
    return NOTE_C1;
  if(c == 'o' || c == 'O')
    return NOTE_Db1;
  if(c == 'l' || c == 'L')
    return NOTE_D1;
  else
    return 0;
}

float convert1(char c){
  if(c == 'a' || c == 'A')
    return NOTE_C1;
  if(c == 'w' || c == 'W')
    return NOTE_Db1;
  if(c == 's' || c == 'S')
    return NOTE_D1;
  if(c == 'e' || c == 'E')
    return NOTE_Eb1;
  if(c == 'd' || c == 'D')
    return NOTE_E1;
  if(c == 'f' || c == 'F')
    return NOTE_F1;
  if(c == 't' || c == 'T')
    return NOTE_Gb1;
  if(c == 'g' || c == 'G')
    return NOTE_G1;
  if(c == 'y' || c == 'Y')
    return NOTE_Ab2;
  if(c == 'h' || c == 'H')
    return NOTE_A2;
  if(c == 'u' || c == 'U')
    return NOTE_Bb2;
  if(c == 'j' || c == 'J')
    return NOTE_B2;
  if(c == 'k' || c == 'K')
    return NOTE_C2;
  if(c == 'o' || c == 'O')
    return NOTE_Db2;
  if(c == 'l' || c == 'L')
    return NOTE_D2;
  else
    return 0;
}

float convert2(char c){
  if(c == 'a' || c == 'A')
    return NOTE_C2;
  if(c == 'w' || c == 'W')
    return NOTE_Db2;
  if(c == 's' || c == 'S')
    return NOTE_D2;
  if(c == 'e' || c == 'E')
    return NOTE_Eb2;
  if(c == 'd' || c == 'D')
    return NOTE_E2;
  if(c == 'f' || c == 'F')
    return NOTE_F2;
  if(c == 't' || c == 'T')
    return NOTE_Gb2;
  if(c == 'g' || c == 'G')
    return NOTE_G2;
  if(c == 'y' || c == 'Y')
    return NOTE_Ab3;
  if(c == 'h' || c == 'H')
    return NOTE_A3;
  if(c == 'u' || c == 'U')
    return NOTE_Bb3;
  if(c == 'j' || c == 'J')
    return NOTE_B3;
  if(c == 'k' || c == 'K')
    return NOTE_C3;
  if(c == 'o' || c == 'O')
    return NOTE_Db3;
  if(c == 'l' || c == 'L')
    return NOTE_D3;
  else
    return 0;
}

float convert3(char c){
  if(c == 'a' || c == 'A')
    return NOTE_C3;
  if(c == 'w' || c == 'W')
    return NOTE_Db3;
  if(c == 's' || c == 'S')
    return NOTE_D3;
  if(c == 'e' || c == 'E')
    return NOTE_Eb3;
  if(c == 'd' || c == 'D')
    return NOTE_E3;
  if(c == 'f' || c == 'F')
    return NOTE_F3;
  if(c == 't' || c == 'T')
    return NOTE_Gb3;
  if(c == 'g' || c == 'G')
    return NOTE_G3;
  if(c == 'y' || c == 'Y')
    return NOTE_Ab4;
  if(c == 'h' || c == 'H')
    return NOTE_A4;
  if(c == 'u' || c == 'U')
    return NOTE_Bb4;
  if(c == 'j' || c == 'J')
    return NOTE_B4;
  if(c == 'k' || c == 'K')
    return NOTE_C4;
  if(c == 'o' || c == 'O')
    return NOTE_Db4;
  if(c == 'l' || c == 'L')
    return NOTE_D4;
  else
    return 0;
}

float convert4 (char c){
  if(c == 'a' || c == 'A')
    return NOTE_C4;
  if(c == 'w' || c == 'W')
    return NOTE_Db4;
  if(c == 's' || c == 'S')
    return NOTE_D4;
  if(c == 'e' || c == 'E')
    return NOTE_Eb4;
  if(c == 'd' || c == 'D')
    return NOTE_E4;
  if(c == 'f' || c == 'F')
    return NOTE_F4;
  if(c == 't' || c == 'T')
    return NOTE_Gb4;
  if(c == 'g' || c == 'G')
    return NOTE_G4;
  if(c == 'y' || c == 'Y')
    return NOTE_Ab5;
  if(c == 'h' || c == 'H')
    return NOTE_A5;
  if(c == 'u' || c == 'U')
    return NOTE_Bb5;
  if(c == 'j' || c == 'J')
    return NOTE_B5;
  if(c == 'k' || c == 'K')
    return NOTE_C5;
  if(c == 'o' || c == 'O')
    return NOTE_Db5;
  if(c == 'l' || c == 'L')
    return NOTE_D5;
  else
    return 0;
}
