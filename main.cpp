/** @file */
#include <iostream>
#include "wav.h"
#include "waveHeader.h"
#include "fileIO.h"
#include "print.h"
#include "normalization.h"
#include "processor.h"
#include "echo.h"
#include "noiseGate.h"
#include <string>

// /**
//  * \brief   The function bar.
//  *
//  * \details This function does something which is doing nothing. So this text
//  *          is totally senseless and you really do not need to read this,
//  *          because this text is basically saying nothing.
//  *
//  * \note    This text shall only show you, how such a \"note\" section
//  *          is looking. There is nothing which really needs your notice,
//  *          so you do not really need to read this section.
//  *
//  * \param[in]     a    Description of parameter a.
//  * \param[out]    b    Description of the parameter b.
//  * \param[in,out] c    Description of the parameter c.
//  *
//  * \return        The error return code of the function.
//  *
//  * \retval        ERR_SUCCESS    The function is successfully executed
//  * \retval        ERR_FAILURE    An error occurred
//  */
// void fn(){

// }

int main() 
{	
        //UNCOMMENT THESE WHEN READY

	do{
		int exit;

        	Print p;
		p.modifyPrinter();
		p.processingPrinter();
        	p.csvFilePrinter();

		std::cout << "Exit the program? 1:yes 0:no ";
		std::cin >> exit;
	
	}while(exit == 0);
        
	return 0;
	
	//Example of how to access metadata
	  //Wav wav; //Create object
	  //std::string testFile;
	  //testFile = "yes-8-bit-mono.wav";

	  //wav.readFile(testFile); //Read in file based on User input

		
	  //Iterate through all elements inside the vector with this for each loop
	  //for (std::string x : wav.getSubChunk())
	  //{
	    //std::cout << x << std::endl;
	  //}
	  
	  //Iterate through all elements inside the actual data
	  //for (std::string s : wav.getActualData())
	  //{

	    //std::cout << s << std::endl;

	  //}
	
	  //So the output should be like ths: 
	  //INAM: Owner of a lonely heart
	  //IART: YES
	
	  //But the output is like this: 
	  //INAM
	  //IART
	  //Owner of a lonely heart
	  //YES
}
