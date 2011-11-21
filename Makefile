CC=g++
CFLAGS=-Wall

SOURCES = main.cpp
LCSSOURCES = LCS.cpp general_algorithm.cpp matching_algorithm.cpp
LEVSOURCES = levenshtein.cpp general_algorithm.cpp matching_algorithm.cpp
LEVAUTOMATASOURCES = levenshtein_automata.cpp DFA.cpp NFA.cpp DFAState.cpp NFAState.cpp pair.cpp
FUZLIBSOURCES = fuzzy_lib.cpp general_algorithm.cpp matching_algorithm.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
LCSDEPS = lcsmake.dep
LEVDEPS = levmake.dep
LEVAUTOMATADEPS = levautmake.dep
FUZLIBDEPS = fuzlibmake.dep
TARGET = agrep
LCSTARGET = LCS.so
LEVTARGET = levenshtein.so
LEVAUTOMATATARGET = levenshtein_automata.so
FUZLIBTARGET = fuzzy_lib.so


RM=rm -f

all: $(TARGET) $(LCSTARGET) $(LEVTARGET) $(LEVAUTOMATATARGET) $(FUZLIBTARGET) $(DEPS) $(LCSDEPS) $(LEVDEPS) $(LEVAUTOMATADEPS) $(FUZLIBDEPS)

$(TARGET): $(OBJECTS)
	$(CC) -ldl -o $@ $(OBJECTS) -Wl,-undefined -Wl,dynamic_lookup

$(LCSTARGET): $(LCSSOURCES)
	$(CC) -fPIC -shared $(LCSSOURCES) -o $@

$(LEVTARGET): $(LEVSOURCES)
	$(CC) -fPIC -shared $(LEVSOURCES) -o $@

$(LEVAUTOMATATARGET): $(LEVAUTOMATASOURCES)
	$(CC) -fPIC -shared $(LEVAUTOMATASOURCES) -o $@

$(FUZLIBTARGET): $(FUZLIBSOURCES)
	$(CC) -fPIC -shared $(FUZLIBSOURCES) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS)

$(LCSDEPS): $(LCSSOURCES)
	$(CC) -MM $(LCSSOURCES) > $(LCSDEPS)

$(LEVDEPS): $(LEVSOURCES)
	$(CC) -MM $(LEVSOURCES) > $(LEVDEPS)

$(LEVAUTOMATADEPS): $(LEVAUTOMATASOURCES)
	$(CC) -MM $(LEVAUTOMATASOURCES) > $(LEVAUTOMATADEPS)

$(FUZLIBDEPS): $(FUZLIBSOURCES)
	$(CC) -MM $(FUZLIBSOURCES) > $(FUZLIBDEPS)

-include $(DEPS)
-include $(LCSDEPS)
-include $(LEVDEPS)
-include $(LEVAUTOMATADEPS)
-include $(FUZLIBDEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS) $(LCSTARGET) $(LCSDEPS) $(LEVTARGET) $(LEVDEPS) $(LEVAUTOMATATARGET) $(LEVAUTOMATADEPS) $(FUZLIBDEPS) $(FUZLIBTARGET)

