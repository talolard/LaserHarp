/*
 * Tone.h
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */

#ifndef TONE_H_
#define TONE_H_

class Tone {
	void CombineArrays (double* Target, int AddSubtract);
protected:
	int BufferLength;
	double* Buffer;
	bool IsOn;
	bool WasAdded;

public:
	virtual void AddTone(double* Target);
	virtual void RemoveTone(double* Target);
	virtual void Process(double* Target);
	Tone(int NumberOfFrames);
	void TurnOn() {IsOn=true;}
	void TurnOff() {IsOn=false;}
	virtual ~Tone();
};

#endif /* TONE_H_ */
