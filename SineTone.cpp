/*
 * SineTone.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */

#include "SineTone.h"
#include "math.h"
SineTone::SineTone(int NumberOfFrames):

	Tone(NumberOfFrames)
{

}
void SineTone::InitTone(float Frequency,int SampleRate)
{
	Freq =(Frequency);
	SR = (SampleRate);
	float Step = 2*M_PI*Freq/SR;
	for (int i =0; i< BufferLength; i++){
		Buffer[i] += sin(i*Step);
	}
}
SineTone::~SineTone() {
	// TODO Auto-generated destructor stub
}

