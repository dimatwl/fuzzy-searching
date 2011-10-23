CC=g++
CFLAGS=-Wall

OBJECTS=main.o LCS.o levenshtein.o
TARGET=tst

RM=rm -f


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 

main.o: main.cpp main.h 
LCS.o: LCS.cpp LCS.h
levenshtein.o: levenshtein.cpp levenshtein.h

clean:
	$(RM) $(OBJECTS) $(TARGET)
