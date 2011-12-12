CC=g++
CFLAGS=-Wall -iquote "./headers"

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
	$(CC) $(CFLAGS) -fPIC -shared $(SOURCES) -o $@


LB:
	for d in $(LIBS); \
	do\
		$(MAKE) --directory=$$d;\
	done


$(DEPS): $(SOURCES)
	$(CC) -MM -iquote "./headers" $(SOURCES) > $(DEPS)


-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

cleanall:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)
	for d in $(LIBS); \
	do\
		$(MAKE) clean --directory=$$d;\
	done
