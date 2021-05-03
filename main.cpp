<<<<<<< HEAD
=======
//CS 202 Semester Project - PT 19

>>>>>>> e35af725492486ec242c8b475000f049ba3f225e
/** @file */
#include <iostream>
#include "wav.h"
#include "waveHeader.h"
#include "fileIO.h"
#include "print.h"
#include "normalization.h"
#include "processor.h"
#include "echo.h"
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

const std::string testfile = "yes-16-bit-mono.wav";
const std::string normalizedfile = "yes-16bit-mono-normalized.wav";
const std::string echofile = "yes-16bit-mono-echo.wav";

int main() {
	//Need to have for loop going through and reading each file!!!
	
        //UNCOMMENT THESE WHEN READY

        Print p;
	p.modifyPrinter();
	p.processingPrinter();
        p.csvFilePrinter();	

<<<<<<< HEAD
        Wav wav;
        wav.readFile(testfile);
=======
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
>>>>>>> e35af725492486ec242c8b475000f049ba3f225e

        if (wav.getBitDepth() == 8)
        {
                Processor<unsigned char> *processorNormalization = new Normalization<unsigned char>();
                processorNormalization->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(normalizedfile);
                std::cout << "Worked" << std::endl;
        }

        else if (wav.getBitDepth() == 16)
        {
                Processor<short> *procesorNormalization = new Normalization<short>();
                procesorNormalization->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(normalizedfile);
                //std::cout << "Worked" << std::endl;
        }

        if (wav.getBitDepth() == 8)
        {
                wav.readFile(testfile);
                Processor<unsigned char> *processorEcho = new Echo<unsigned char>(100000);
                processorEcho->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(echofile);
        }

        else if (wav.getBitDepth() == 16)
        {
                wav.readFile(testfile);
                Processor<short> *processorEcho = new Echo<short>(100000);
                processorEcho->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(echofile);
        }

        return 0;
}
