/*
 * Tone.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */

#include "Tone.h"

Tone::Tone(int NumberOfFrame) {
	BufferLength = NumberOfFrame;// Not sure why 2 but thats the size of the buffer
	Buffer = new double[BufferLength];
	bool IsOn =false;
	bool WasAdded =false;
}

Tone::~Tone() {
	delete Buffer;
	// TODO Auto-generated destructor stub
}

void Tone::CombineArrays(double* Target, int AddSubtract)
{
	for (int i=0; i<BufferLength; i++){
		Target[i] +=  Buffer[i]*AddSubtract;
	}
}
void Tone::AddTone(double* Target)
{
	if (!WasAdded){
		CombineArrays(Target,1);
		WasAdded =true;
	}
}
void Tone::RemoveTone(double* Target)
{
	if (WasAdded){
		CombineArrays(Target,-1); // Subtract the tone
		WasAdded =false;
	}
}

void Tone::Process(double* Target)
{
	if (IsOn){
		AddTone(Target);
	}
	else
	{
		RemoveTone(Target);
	}
}
