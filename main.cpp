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

        Print p;
	p.modifyPrinter();
	p.processingPrinter();
        p.csvFilePrinter();	

        return 0;
}
