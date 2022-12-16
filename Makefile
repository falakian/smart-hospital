

output: walkIn.o List.o Patient.o
	g++  walkIn.o List.o Patient.o -o output

walkIn.o: walkIn.cpp List.h Patient.h
	g++  -c walkIn.cpp

List.o: List.h List.cpp
	g++  -c List.cpp

Patient.o: Patient.h Patient.cpp
	g++  -c Patient.cpp

clean:
	rm  *.o output 