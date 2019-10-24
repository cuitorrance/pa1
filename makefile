output: dictionary_test.o Dictionary.o
	g++ -Wall dictionary_test.o Dictionary.o -o output

dictionary_test.o: dictionary_test.cpp
	g++ -c dictionary_test.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

clean:
	rm *.o output
