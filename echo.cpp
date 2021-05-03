#include "echo.h"

Echo::Echo(int newDelay): delay(newDelay){};

void Echo::processBuffer(unsigned char* buffer, int bufferSize, short bitdepth){
	
	float adj_n;
	float adj_delayed_n;
	float finalEcho;
	float echoLevel = 0.5f;

	for(int i = 0; i < bufferSize - delay; i++){
		adj_n = (float)(buffer[i] - 128);
		adj_delayed_n = (float)(buffer[i + delay] - 128);
		finalEcho = adj_n * echoLevel + adj_delayed_n * 0.5F + 128;
		buffer[i + delay] = (unsigned char)(round(finalEcho));
	}
}
