/*
 * Sounds.h
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */

#ifndef SOUNDS_H_
#define SOUNDS_H_
#include "RtAudio.h"

int saw( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData );
int sine( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData );
int DoSound( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData );




#endif /* SOUNDS_H_ */
