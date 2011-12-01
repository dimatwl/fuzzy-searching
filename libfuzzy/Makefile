CC=g++
CFLAGS=-Wall

SOURCES = libfuzzy.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET = libfuzzy.so
LCS = ./LCS
LEVENSHTEIN = ./levenshtein
LEVENSHTEIN_AUTOMATA = ./levenshtein_automata

LIBS = $(LCS) $(LEVENSHTEIN) $(LEVENSHTEIN_AUTOMATA)

RM=rm -f

all: LB $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) -pg -fPIC -shared $(SOURCES) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 

LB:
	for d in $(LIBS); \
	do\
		$(MAKE) --directory=$$d;\
	done


$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS)


-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

cleanall:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)
	for d in $(LIBS); \
	do\
		$(MAKE) clean --directory=$$d;\
	done
