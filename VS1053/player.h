#ifndef PLAYER_H
#define PLAYER_H
#include "vs10xx.h"

/** Playing states definations. */
volatile typedef enum {
  PS_STOP,	       // Player stop						 
  PS_PLAY,         // Start to player                                                                    
} playerStatetype;


class Player
{
public:
  void begin(void);
  void playFile(char *file);
  void selectfile(char n);
  void stop(void);
  void run(void);
  void read(void);
private:
    
};

#endif

