//CS 202 Semester Project - PT 19

#include "print.h"

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
		std::cout << "Please enter a valid filename to store processsed audio: ";
		std::cin >> input3;
		//if(input3.is_open()){
			//New file created with processed audio//
		//}

		if(input2 == 1){
			std::cout << "Normalization Processing" << std::endl; 
			//Processor *normalizer = new normalizer();
			//normalizer->processBuffer(wav.getBuffer(),wav.getBufferSize());
			//wav.writeFile("limit.wav");
		}
		else if(input2 == 2){
			std::cout << "NoiseGate Processing" << std::endl; 

			//Processor *noise = new NoiseGate(140, 116);
			//noise->processBuffer(wav.getBuffer(),wav.getBufferSize());
			//wav.writeFile("noise.wav");
		}
		else{
			std::cout << "Echo Processing" << std::endl; 
			
			//Processor *processor = new Echo(10000);
			//processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
			//wav.writeFile("echos.wav");
		}
	}
}
	
void Print::csvFilePrinter(){
	int input4;

	std::cout << "Do you want a CSV file created containing all the files technical and metadata information? 1:yes 0:no" << std::endl;
	std::cin >> input4;
	if(input4 == 1){
		std::cout << "Writing CSV file!" << std::endl;
		//create CSV file with all the files info
	}
}
