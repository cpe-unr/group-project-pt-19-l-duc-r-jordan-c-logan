demo: main.cpp wav.o processor.o normalization.o echo.o noiseGate.o print.o fileIO.o  
	g++ -std=c++11 -o demo main.cpp wav.o processor.o normalization.o echo.o noiseGate.o print.o fileIO.o

wav.o: wav.cpp wav.h waveHeader.h
	g++ -c -std=c++11 wav.cpp 

processor.o: processor.cpp processor.h normalization.h echo.h noiseGate.h
	g++ -c -std=c++11 processor.cpp

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noiseGate.o: noiseGate.cpp noiseGate.h
	g++ -c -std=c++11 noiseGate.cpp

print.o: print.cpp print.h processor.h fileIO.h 
	g++ -c -std=c++11 print.cpp processor.h fileIO.h

fileIO.o: fileIO.cpp fileIO.h waveHeader.h
	g++ -c -std=c++11 fileIO.cpp waveHeader.h

clean:
	rm demo *.o *.h.gch *.csv
