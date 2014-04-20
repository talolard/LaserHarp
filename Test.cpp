#include <RtAudio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sounds.h"
#include "AudioPlayer.h"
int main()
{
	srand(time(NULL));
	char Input ='a';
	AudioPlayer A;
	while (true){//A.Input[0] != 'q'){
		for (int i=0; i< 13; i++){
			if (!A.Reading){
				A.Input[i] = 97 + rand() %6;
			}
		}

	}
}
