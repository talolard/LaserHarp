/*
 * AudioPlayer.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */
float Freqs[] =	{
			220,
			233.08,
			246.94,
			261.63,
			277.18,
			293.66,
			311.13,
			329.63,
			349.23,
			369.99,
			392,
			415.30,
			440
	};
#include "AudioPlayer.h"
#include <RtAudio.h>
#include "SineTone.h"
int DoSound( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *userData )
{
	static int Count =0;
	Count++;
	if (Count %131) return 0;
	AudioPlayer* P = static_cast<AudioPlayer*>(userData);
	P->SineToneTest((double*)outputBuffer);
	return 0;

}
AudioPlayer::AudioPlayer(): Tones( sizeof(Freqs)/sizeof(float)),Frames(64*2) {
	// TODO Auto-generated constructor stub
	InitTones();
	InitAudio();

	TestPlace =0;
	TestCount=1;

}

void AudioPlayer::InitAudio() {
	RtAudio::StreamParameters parameters;
	parameters.nChannels = 2;
	parameters.firstChannel = 0;
	unsigned int sampleRate = 44100;
	unsigned int bufferFrames = 64; // 256 sample frames
	double data[2];  // 0 indicates the default or first available device
	RtAudio::StreamOptions Opt;
	audio = new RtAudio();
		Opt.streamName ="Tal";
	try{
		audio->stopStream();
	}
	catch (...){}
	audio->closeStream();
	parameters.deviceId = audio->getDefaultOutputDevice();
	audio->openStream( &parameters, NULL, RTAUDIO_FLOAT64,
	sampleRate, &bufferFrames, &DoSound, (void *)this,&Opt );
	audio->startStream();
}
void AudioPlayer::InitTones()
{
	int NumTones= sizeof(Freqs)/sizeof(float);
	//Tones = new SineTone[NumTones](Frames);
	//SineTone* T = static_cast<SineTone*>(Tones);
	for (int i=0; i < NumTones; i++){
		Tones[i] = new SineTone(Frames);
		Tones[i]->InitTone(Freqs[i],44100);
	}
}
AudioPlayer::~AudioPlayer()
{

	audio->stopStream();
	audio->closeStream();
	delete audio;
}
void AudioPlayer::SineToneTest(double* OutBuf)
{
	Reading =true;
	int NumTones= sizeof(Freqs)/sizeof(float);
	for (int i=0; i <Frames*2; i++){
		//OutBuf[i]=0;
	}
	for (int i=0; i< NumTones; i++){
		Tones[i]->TurnOff();
		Tones[i]->Process(OutBuf);
	}
	for (int i =0; i < NumTones; i++)
	{
		if (Input[i] =='a'){
			Tones[i]->TurnOn();
			Tones[i]->Process(OutBuf);
			//Input[i] ='b';
		}
	}
		/*TestPlace++;
		if (TestPlace >= NumTones){
			TestPlace = TestPlace % NumTones;
			TestCount++;
			if (TestCount>13){
				TestCount=1;
			}
		}
	}*/
	for (int i=0; i<Frames; i++ ){
		//OutBuf[i] /=TestCount;
	}
	//std::cout << TestCount<<std::endl;
	Reading =false;

}
