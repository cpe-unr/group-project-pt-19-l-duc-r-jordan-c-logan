## CS 202 Semester Project Template - PT 19 Project Outline

#Group Members 
Logan Church, Duc La, Jordan Rood

#Responsibilities
Duc-Wav functions, UI, CSV file
Jordan-File IO, Wav functions, UI, CSV file, comments
Logan-Editiing, Doxygen, Comments

# Description
Wav:
Functions:
	readFile() - read in wav file data
	writeFile() - modify wav file data
	getters for 8 and 16 bit buffers and bufferSize
	destructor to delete buffer from heap

	1. Similar to PA4, make Processor Abstract class (aka interface).
	2. Normalization inherits to processor and implements virtual method in own class for normalizing audio
	3. NoiseGating and Echo inherit and do similar implementations as normalization
		Each are own classes in separate files!! And these methods are only triggered if UI says to.
	*this class also helps file io with reading in wav files*
	
File IO:
Functions:
	makeCSVFile()
	
	1. read funtion(s) using templates for different read in type methods
	2. overwrite metadata function if UI alerts to and save this change in the file
	3. Probably have separate funtions in class to create and export CSV file with info that got read in at start of program


User Interaction/ printing:
Functions:
	modifyPrinter() - user interaction for modifying metadata
	processingPrinter() - user interaction for processing wav files
	csvFilePrinter() - user interaction for making a CSV file

	1. First prompt is triggered after all the files are read in
		- prompts user if they want to modify the metadata of any file 
			- if yes, prompt for the file and changes they want to make. Then, send to file IO classes to overwrite metadata
			- if no, move on
	2. Next prompts will regard processing of certain audio files
		- prompt user if they would like to process any audio files
			- if yes, prompt for file and the processors they want used and send over to Wav/processor classes
				also prompt for file name and check if valid to be saved there
			- if no, move on
	3. Last set of prompts will be for CSV file
		- prompt user if they would like a CSV file made containing all tech. info & metadata 
			- if yes, send to function(s) that create, write out file, and export to library
			- if no, end program!!



Rough overview

	System will read in wav files one at a time, extract all the technical info(Sample rate. etc.) and metadata from the file.
	This data should be stored into an object.
	The object should be added to an appropriate data structure.


	Sound file data (sound buffer. etc.) should be deleted from the HEAP, not disk!!
		EX:		Wav::~Wav() {
   					 if(buffer != NULL){
        			 	delete[] buffer;
   			    	 }	
				}//destructor for Wav and deletes buffer from heap 



	The data from each file is to be stored using a CLASS designed for the type of file 
		- MONO or STEREO: 8,16,24, or 32 bit samples

	When all the file are read and processed, the user can choose to modify the metadata of any file.
			std::cout << "Do you want to modify any files metadata? 1:yes or 0:no" << std::endl;
			std::cin >> input;
			if(input == 1){    
				std::cout << "What file? " << std::endl;
				std::cin >> file;
				//change metadata//
				//save new metadata file//
			}

	When the modification is complete, save the file with the new metadata.
		- The changes should override any current metadata, or create the metadata if it didn't exist before.

	Then, the user may choose to process the file by choosing one or more processors(i.e. Normalization, NoiseGating, Echo).

		std::cout << "Do you want to process the modified file? 1:yes 0:no " << std::endl;
		std::cin >> input2;
		if(input2 == 1){
			std::cout << "What processing would you want done?" << std::endl;
			std::cout << "1 - Normalization" << std::endl;
			std::cout << "2 - Noise Gating" << std::endl;
			std::cout << "3 - Echo" << std::endl;
			std::cin >> input3;
			if(input3 == 1){
				//Normalization processing//
			}
			else if(input3 == 2){
				//Noise Gate processing//
			}
			else{
				//Echo processing//
			}
		}

	After processing, prompt the user for a file name and check if valid:
		- if valid a new file is created with the processed audio 
		- the user is NOT allowed to save the file under a name of any of the existing files

		std::cout << "Please enter a valid filename: ";
		std::cin >> input4;
		if(input4.is_open()){
			
			//New file created with processed audio//

		}

	Prompt user if they would like a CSV file with all the files, their technical data(sample rates, etc.) and the file metadata 
		- if no metadata exists the phrase "No metadata present" should be included in the description for that file

		std::cout << "Would you like a CSV file created containing all the files technical and metadata? 1:yes 0:no" << std::endl;
		std::cin >> input5;
		if(input5 == 1){

			//create CSV file with all the files info//

		}

# Challenges
The CSV took a bit of time getting up and running and working with other parts such as the metadata.
The metadata caused a lot of issues, mainly trying to get it to work properly with the CSV file and the other functions. Had trouble looping in certain areas and modifying the metadata.
There were some other minor errors with but they didn't turn out to be nearly as troublesome.