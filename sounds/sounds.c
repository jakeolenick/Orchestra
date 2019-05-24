#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ao/ao.h>
#include <math.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "convert.c"
#define BUF_SIZE 4096

/**
   HOW TO COMPILE
   gcc sounds.c -lao -ldl -lm
   
   DISCLAIMER
   Significant portions of this code are based on code from the
   following source:
   http://shuttersparks.blogspot.com/2011/02/simplest-way-to-play-raw-pcm-audio-on.html

   However, all sound manipulations using this have required understanding
   the borrowed code
*/

ao_device * playnote(char part[8], char note, ao_device *device, ao_sample_format format)
{  
    
  char *buffer;  
  int buf_size;  
  int sample;  
  float freq;
  int i;  
  
  if (!strcmp(part,"sine1")){
    int fd = open("eine kleine1",O_RDONLY);
    freq = convert4(note);
    /* -- Play some stuff -- */  
    buf_size = format.bits/8 * format.channels * format.rate;  
    buffer = calloc(buf_size, sizeof(char));
    for (i = 0; i < format.rate ; i++) {
      sample = (int)(0.75 * 32768.0 *
		     sin(2 * M_PI * freq * ((float) i/format.rate)));
      /* Put the same stuff in left and right channel */  
      buffer[4*i] = buffer[4*i+2] = sample & 0xff;  
      buffer[4*i+1] = buffer[4*i+3] = (sample >> 8) & 0xff;  
    }	 
    ao_play(device, buffer, buf_size/4);    
  }

  else if (!strcmp(part,"sine2")){
    int fd = open("eine kleine2", O_RDONLY);
    freq = convert2(note);
    /* -- Play some stuff -- */  
    buf_size = format.bits/8 * format.channels * format.rate;  
    buffer = calloc(buf_size, sizeof(char));
    for (i = 0; i < format.rate ; i++) {
      sample = (int)(0.75 * 32768.0 *
		     sin(2 * M_PI * freq * ((float) i/format.rate)));
      /* Put the same stuff in left and right channel */  
      buffer[4*i] = buffer[4*i+2] = sample & 0xff;  
      buffer[4*i+1] = buffer[4*i+3] = (sample >> 8) & 0xff;  
    }	 
    ao_play(device, buffer, buf_size/4);    
  }

  else if (!strcmp(part, "square1")){
    int fd = open("eine kleine3",O_RDONLY);
    freq = convert3(note);
    /* -- Play some stuff -- */  
    buf_size = format.bits/8 * format.channels * format.rate;  
    buffer = calloc(buf_size, sizeof(char));
    for (i = 0; i < format.rate ; i++) {
      sample = (int)(0.75 * 32768.0 *
		     floor(sin(2 * M_PI * freq * ((float) i/format.rate))));
      /* Put the same stuff in left and right channel */  
      buffer[4*i] = buffer[4*i+2] = sample & 0xff;  
      buffer[4*i+1] = buffer[4*i+3] = (sample >> 8) & 0xff;  
    }	 
    ao_play(device, buffer, buf_size/4);
  }

  else if (!strcmp(part,"square2")){
    int fd = open("eine kleine4",O_RDONLY);
    freq = convert1(note);
    /* -- Play some stuff -- */  
    buf_size = format.bits/8 * format.channels * format.rate;  
    buffer = calloc(buf_size, sizeof(char));
    for (i = 0; i < format.rate ; i++) {
      sample = (int)(0.75 * 32768.0 *
		     floor(sin(2 * M_PI * freq * ((float) i/format.rate))));
      /* Put the same stuff in left and right channel */  
      buffer[4*i] = buffer[4*i+2] = sample & 0xff;  
      buffer[4*i+1] = buffer[4*i+3] = (sample >> 8) & 0xff;  
    }	 
    ao_play(device, buffer, buf_size/4);
  }
 

  return device;
}  
