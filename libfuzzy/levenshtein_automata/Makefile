CC=g++
CFLAGS=-Wall -iquote "./" -iquote "../headers"

SOURCES = levenshtein_automata.cpp
DEPS = make.dep
TARGET = ../../levenshtein_automata.so

RM=rm -f

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -fPIC -shared $(SOURCES) -o $@


$(DEPS): $(SOURCES)
	$(CC) -MM -iquote "./" -iquote "../headers" $(SOURCES) > $(DEPS)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

