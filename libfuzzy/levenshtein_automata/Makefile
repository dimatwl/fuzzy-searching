CC=g++
CFLAGS=-Wall

SOURCES = levenshtein_automata.cpp DFA.cpp NFA.cpp DFAState.cpp NFAState.cpp pair.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET = levenshtein_automata.so

RM=rm -f

$(TARGET): $(SOURCES)
	$(CC) -fPIC -shared $(SOURCES) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

