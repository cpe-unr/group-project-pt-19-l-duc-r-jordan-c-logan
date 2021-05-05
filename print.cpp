//CS 202 Semester Project - PT 19

#include "print.h"
#include "fileIO.h"
#include "metaChunksHeader.h"

void Print::modifyPrinter(){
 	int input1;
 	std::string file;
	std::string metaChoice, newMeta;

 	std::cout << "Do you want to modify any files metadata? 1:yes or 0:no" << std::endl;
 	std::cin >> input1;
	if(input1 == 1){    
 		std::cout << "What file? " << std::endl;
 		std::cin >> file;
		
		//std::cin >> file;

		Wav wav;
		wav.readFile(file);
		wav.getSubChunk();
		wav.getActualData();

		std::cout << "What would metadata would you like to change? (Example: INAM)" << std::endl;
   		std::cin >> metaChoice;

    		int index = -1;
    		for (int i = 0; i < wav.getSubChunk().size(); i++) {
    			if (wav.getSubChunk()[i] == metaChoice) {
        			index = i;
        			break;
     			}	
    		}

    		if (index == -1)
    		{
			std::cout << "Could not find the metadata!" << std::endl;
    		}
    		else 
    		{
     			std::cout << "The current metadata for that file is " << wav.getActualData()[index] << std::endl;
	
      			std::cout << "What would you like to change it to?"; 
      			std::cin >> newMeta; 
	
      			wav.getActualData()[index] = newMeta; 
    		}

 		//change metadata//
 		//save new metadata file//
 		//change metadata
 		//save new metadata file
	}
	
	//This was what I wanted to do instead, but I ran into a free pointer error that I just couldn't figure out
	//Get the metadata 
    // std::cout << "What would metadata would you like to change? (Example: INAM)" << std::endl;
    // std::cin.ignore();
    // std::cin.getline(metaChoice, 5);
    // //std::cin.ignore();

    // //Convert it
    // std::copy(std::begin(metaChoice), std::end(metaChoice), std::begin(metaChoiceConverted));

    // // for (std::array<char, 4> x : subChunk)
    // // {
    // //   for (int i =0; i < x.size() ; i++) 
    // //   {
    // //     std::cout<< x[i];
    // //   }
    // // }

    // for (int i = 0; i < 5; i++)
    // {
    //   std::cout << metaChoiceConverted[i];
    // }

    // int index = -1;
    // //std::cout << wav.subChunk.size() << std::endl;


    // for (int i = 0; i < wav.subChunk.size(); i++) {
    //   if (wav.subChunk[i] == metaChoiceConverted)
    //   {
    //     index = i;
    //     break;
    //   }
    // }

    // std::cout << "The index:" << index << std::endl;

    // //std::cout << wav.subChunk[index] << std::endl;
    // //std::cout << wav.actualData[index] << std::endl;

    // if (index == -1)
    // {
    //   std::cout << "Could not find the metadata!" << std::endl;
    // }

    // else 
    // {
    //   std::cout << "The current metadata for that file is " << wav.actualData[index] << std::endl;

    //   std::cout << "What would you like to change it to?"; 
    //   std::cin.ignore();
    //   std::getline(std::cin, newMeta, '\n'); 

    //   wav.actualData[index] = newMeta; 
    // }

    // std::cout << "Free test" << std::endl;
 		// //change metadata//
 		// //save new metadata file//
    
    // wav.writeFile(file);

}
	
void Print::processingPrinter(){
	int input2;
	//std::string input3;

	std::cout << "What processing would you want done?" << std::endl;
	std::cout << "1 - Normalization" << std::endl;
	std::cout << "2 - Noise Gate" << std::endl;
	std::cout << "3 - Echo" << std::endl;
	std::cout << "0 - No Processing" << std::endl;
	std::cin >> input2;

	if(input2 != 0){
		
		Wav wav;
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

std::string Print::getFileThree() const{
	return file3;
}

std::string Print::getFileFour() const{
	return file4;
}

