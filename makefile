demo: main.cpp wav.o processor.o normalization.o echo.o noiseGate.o print.o fileIO.o normalization.a echo.a noiseGate.a
	g++ -std=c++11 -o demo main.cpp wav.o processor.o normalization.o echo.o noiseGate.o print.o fileIO.o normalization.a echo.a noiseGate.a

wav.o: wav.cpp wav.h waveHeader.h
	g++ -c -std=c++11 wav.cpp 

processor.o: processor.cpp processor.h normalization.h echo.h noiseGate.h
	g++ -c -std=c++11 processor.cpp 

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

normalization.a: normalization.o
	ar suvr normalization.a normalization.o

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

echo.a: echo.o
	ar suvr echo.a echo.o

noiseGate.o: noiseGate.cpp noiseGate.h
	g++ -c -std=c++11 noiseGate.cpp

noiseGate.a: noiseGate.o
	ar suvr noiseGate.a noiseGate.o

print.o: print.cpp print.h processor.h fileIO.h 
	g++ -c -std=c++11 print.cpp processor.h fileIO.h

fileIO.o: fileIO.cpp fileIO.h waveHeader.h
	g++ -c -std=c++11 fileIO.cpp waveHeader.h

clean:
	rm demo *.o *.h.gch *.a

