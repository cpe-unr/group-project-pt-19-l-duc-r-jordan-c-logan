// //CS 202 Semester Project - PT 19

// #include "print.h"
// #include "fileIO.h"

// void Print::modifyPrinter(){
// 	int input1;
// 	std::string file;

// 	std::cout << "Do you want to modify any files metadata? 1:yes or 0:no" << std::endl;
// 	std::cin >> input1;
// 	if(input1 == 1){    
// 		std::cout << "What file? " << std::endl;
// 		std::cin >> file;
// 		//change metadata//
// 		//save new metadata file//
// 	}
// }
	
// void Print::processingPrinter(){
// 	int input2;
// 	std::string input3;

// 	std::cout << "What processing would you want done?" << std::endl;
// 	std::cout << "1 - Normalization" << std::endl;
// 	std::cout << "2 - Noise Gate" << std::endl;
// 	std::cout << "3 - Echo" << std::endl;
// 	std::cout << "0 - No Processing" << std::endl;
// 	std::cin >> input2;

// 	if(input2 != 0){
// 		std::cout << "Please enter a valid filename to store processsed audio (Ex. filename.wav): ";
// 		std::cin >> input3;
		
// 		Wav wav;
// 		//TESTING LINE
// 		wav.readFile("yes-8bit-mono.wav");		

// 		if(input2 == 1){
// 			std::cout << "Normalization Processing" << std::endl;
 
// 			Processor *normalizer = new Normalization();
// 			normalizer->processBuffer(wav.getBuffer(),wav.getBufferSize(), wav.getBitDepth());
// 			wav.writeFile(input3); 
// 		}
// 		else if(input2 == 2){
// 			std::cout << "NoiseGate Processing" << std::endl; 
	
// 			Processor *noise = new NoiseGate(140, 116);
// 			noise->processBuffer(wav.getBuffer(),wav.getBufferSize(), wav.getBitDepth());
// 			wav.writeFile(input3);
// 		}
// 		else{
// 			std::cout << "Echo Processing" << std::endl; 
			
// 			Processor *echo = new Echo(10000);
// 			echo->processBuffer(wav.getBuffer(),wav.getBufferSize(), wav.getBitDepth());	
// 			wav.writeFile(input3);
// 		}
	
// 	}
// }
	
// void Print::csvFilePrinter(){
// 	int input4;

// 	std::cout << "Do you want a CSV file created containing all the files technical and metadata information? 1:yes 0:no" << std::endl;
// 	std::cin >> input4;
// 	if(input4 == 1){
// 		std::string filename;

// 		std::cout << "Enter a filename for the CSV file (Ex. filname.csv): ";
// 		std::cin >> filename;

// 		Wav wav;

// 		FileIO* csv = new FileIO();
// 		csv->writeCsvFile(filename, wav.getBufferSize());
// 		delete csv;
// 	}
// 	//creates CSV file with all the files info
// }

