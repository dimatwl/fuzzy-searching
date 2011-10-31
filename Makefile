CC=g++
CFLAGS=-Wall

SOURCES = main.cpp LCS.cpp levenshtein.cpp general_algorithm.cpp fuzzy_lib.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET=tst

RM=rm -f


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)
