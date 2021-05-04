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

const std::string testfile = "yes-8bit-mono.wav";
const std::string normalizedfile = "yes-8bit-mono-normalized.wav";
const std::string echofile = "yes-8bit-mono-echo.wav";
const std::string gateFile = "yes-8bit-mono-gated.wav";

int main() 
{
        //Need to have for loop going through and reading each file!!!
	
        //UNCOMMENT THESE WHEN READY

        Print p;
	p.modifyPrinter();
	//p.processingPrinter();
        //eap.csvFilePrinter();	

        Wav wav;
        wav.readFile(testfile);

        if (wav.getBitDepth() == 8)
        {
                Processor<unsigned char> *processorNormalization = new Normalization<unsigned char>();
                processorNormalization->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(normalizedfile);
        }

        else if (wav.getBitDepth() == 16)
        {
                Processor<short> *procesorNormalization = new Normalization<short>();
                procesorNormalization->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(normalizedfile);
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

        if (wav.getBitDepth() == 8)
        {
                wav.readFile(testfile);
                Processor<unsigned char> *processorNoiseGate = new NoiseGate<unsigned char>(.05);
                processorNoiseGate->processBuffer(wav.getBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(gateFile); 
        }

        else if(wav.getBitDepth() == 16)
        {
                wav.readFile(testfile);
                Processor<short> *processorNoiseGate = new NoiseGate<short>(.05);
                processorNoiseGate->processBuffer(wav.getShortBuffer(), wav.getBufferSize(), wav.getBitDepth());
                wav.writeFile(gateFile); 
        }

        return 0;
}
