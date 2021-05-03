// #include "echo.h"

// Echo::Echo(int newDelay): delay(newDelay){};

<<<<<<< HEAD
// void Echo::processBuffer(unsigned char* buffer, int bufferSize){
=======
void Echo::processBuffer(unsigned char* buffer, int bufferSize, short bitdepth){
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
	
// 	float adj_n;
// 	float adj_delayed_n;
// 	float finalEcho;
// 	float echoLevel = 0.5f;

<<<<<<< HEAD
// 	for(int i = 0; i < bufferSize - delay; i++){
// 		adj_n = (float)(buffer[i] - 128);
// 		adj_delayed_n = (float)(buffer[i + delay] - 128);
// 		finalEcho = adj_n * echoLevel + adj_delayed_n * 0.5F + 128;
// 		buffer[i + delay] = (unsigned char)(round(finalEcho));
// 	}
// }

=======
	for(int i = 0; i < bufferSize - delay; i++){
		adj_n = (float)(buffer[i] - 128);
		adj_delayed_n = (float)(buffer[i + delay] - 128);
		finalEcho = adj_n * echoLevel + adj_delayed_n * 0.5F + 128;
		buffer[i + delay] = (unsigned char)(round(finalEcho));
	}
}
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
