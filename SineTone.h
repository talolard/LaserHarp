/*
 * SineTone.h
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */

#ifndef SINETONE_H_
#define SINETONE_H_

#include "Tone.h"

class SineTone: public Tone {

public:
	float Freq, SR;
	SineTone(int NumberOfFrames);
	void InitTone(float Frequency,int SampleRate);
	virtual ~SineTone();
};

#endif /* SINETONE_H_ */
