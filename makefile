demo: main.cpp processor.o normalization.o echo.o noiseGate.o print.o
	g++ -std=c++11 -o demo main.cpp processor.o normalization.o echo.o noiseGate.o print.o

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

processor.o: processor.cpp processor.h normalization.h echo.h noiseGate.h
	g++ -c -std=c++11 processor.cpp

normalization.o: normalization.cpp normalization.h
	g++ -c -std=c++11 normalization.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

noiseGate.o: noiseGate.cpp noiseGate.h
	g++ -c -std=c++11 noiseGate.cpp

print.o: print.cpp print.h
	g++ -c -std=c++11 print.cpp

clean:
	rm demo *.o
