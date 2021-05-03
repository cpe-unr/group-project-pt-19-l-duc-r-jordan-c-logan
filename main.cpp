//CS 202 Semester Project - PT 19

/** @file */
#include <iostream>
#include "wav.h"
#include "waveHeader.h"
#include "fileIO.h"
#include "print.h"
#include "normalization.h"
#include <string>
#include "processor.h"
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

const std::string testfile = "yes-8bit-mono.wav";
const std::string normalizedfile = "yes-8bit-mono-normalized.wav";
const std::string limitedfile = "yes-8bit-mono-limited.wav";

int main() {
	//Need to have for loop going through and reading each file!!!
	
        //UNCOMMENT THESE WHEN READY

        Print p;
	p.modifyPrinter();
	p.processingPrinter();
        p.csvFilePrinter();	

        // Wav wav;
        // wav.readFile(testfile);
        // Processor *processorLimiter = new Limiter();
        // processorLimiter->processBuffer(wav.getBuffer(), wav.getBufferSize());
        // wav.writeFile(limitfile);

         //wav.readFile(testfile);
         //Processor *processorEcho = new Echo(7500);
         //processorEcho->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
         //wav.writeFile(echofile);

        // wav.readFile(testfile);
        // Processor *processorNoiseGate = new NoiseGate(.7);
        // processorNoiseGate->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
        // wav.writeFile(noisefile);

       // Wav wav;
       // wav.readFile(testfile);
       // Processor *processorNormalization = new Normalization();
       // processorNormalization->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth()); 
       // wav.writeFile(normalizedfile);

        // wav.readFile(testfile); 
        // Processor *processorLimiter = new Limiter(); 
        // processorLimiter->processBuffer(wav.getBuffer(), wav.getBufferSize());
        // wav.writeFile(limitedfile);

        return 0;
}

