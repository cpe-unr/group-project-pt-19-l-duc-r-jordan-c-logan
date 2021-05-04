//CS 202 Semester Project - PT 19

#include "print.h"
#include "fileIO.h"

void Print::modifyPrinter(){
 	int input1;
 	std::string file;

 	std::cout << "Do you want to modify any files metadata? 1:yes or 0:no" << std::endl;
 	std::cin >> input1;
	if(input1 == 1){    
 		std::cout << "What file? " << std::endl;
 		std::cin >> file;
 		//change metadata//
 		//save new metadata file//
 	}
}
	
void Print::processingPrinter(){
	int input2;
	std::string input3;

	std::cout << "What processing would you want done?" << std::endl;
	std::cout << "1 - Normalization" << std::endl;
	std::cout << "2 - Noise Gate" << std::endl;
	std::cout << "3 - Echo" << std::endl;
	std::cout << "0 - No Processing" << std::endl;
	std::cin >> input2;

	if(input2 != 0){
 		//std::cout << "Please enter a valid filename to store processsed audio (Ex. filename.wav): ";
		//std::cin >> input3;
		
		Wav wav;
		//TESTING LINE
		//wav.readFile("yes-8bit-mono.wav");		
        	wav.readFile(testfile);		

		if(input2 == 1){

			if (wav.getBitDepth() == 8)
        		{
                		Processor<unsigned char> *processorNormalization = new Normalization<unsigned char>();
                		processorNormalization->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
                		wav.writeFile(normalizedfile);
        		}
			else if (wav.getBitDepth() == 16)
        		{
                		Processor<short> *procesorNormalization = new Normalization<short>();
                		procesorNormalization->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
                		wav.writeFile(normalizedfile);
        		} 

		}
		else if(input2 == 2){
			std::cout << "NoiseGate Processing" << std::endl; 
				
			if (wav.getBitDepth() == 8)
        		{
                		wav.readFile(testfile);
                		Processor<unsigned char> *processorNoiseGate = new NoiseGate<unsigned char>(.05);
                		processorNoiseGate->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
                		wav.writeFile(gateFile); 
        		}
        		else if(wav.getBitDepth() == 16)
        		{
                		wav.readFile(testfile);
                		Processor<short> *processorNoiseGate = new NoiseGate<short>(.05);
                		processorNoiseGate->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
                		wav.writeFile(gateFile); 
        		}

		}
		else{
			std::cout << "Echo Processing" << std::endl; 
			if (wav.getBitDepth() == 8)
		        {
        		        wav.readFile(testfile);
                		Processor<unsigned char> *processorEcho = new Echo<unsigned char>(100000);
                		processorEcho->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
                		wav.writeFile(echofile);
        		}
        		else if (wav.getBitDepth() == 16)
        		{
                		wav.readFile(testfile);
                		Processor<short> *processorEcho = new Echo<short>(100000);
               			processorEcho->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());
               			processorEcho->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth(), wav.getNumChannels());

               			wav.writeFile(echofile);
        		}			
 		}
	}
}
	
void Print::csvFilePrinter(){
 	int input4;

	std::cout << "Do you want a CSV file created containing all the files technical and metadata information? 1:yes 0:no" << std::endl;
	std::cin >> input4;
	if(input4 == 1){
		std::string filename;

		std::cout << "Enter a filename for the CSV file (Ex. filname.csv): ";
		std::cin >> filename;
 		Wav wav;
		wav.readFile(testfile);

		FileIO* csv = new FileIO();
		csv->writeCsvFile(filename, wav.getBufferSize());
		delete csv;
	}
}

std::string Print::getFile() const{
	return testfile;
}

std::string Print::getFileTwo() const{
	return file2;
}
