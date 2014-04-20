/*
 * AudioPlayer.h
 *
 *  Created on: Apr 19, 2014
 *      Author: tal
 */
#include <vector>
class SineTone;
class RtAudio;
#ifndef AUDIOPLAYER_H_
#define AUDIOPLAYER_H_

class Tone;
class AudioPlayer {

	int Frames;
	void InitAudio();
	void InitTones();
	RtAudio* audio ;
	std::vector<SineTone*> Tones;
	int TestPlace;
	int TestCount;
public:
	char Input[13];
	void SineToneTest(double* OutBuf);
	AudioPlayer();
	virtual ~AudioPlayer();
	bool Reading;
};

#endif /* AUDIOPLAYER_H_ */
