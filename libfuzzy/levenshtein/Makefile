CC=g++
CFLAGS=-Wall -iquote "../headers"

SOURCES = levenshtein.cpp
DEPS = make.dep
TARGET = ../levenshtein.so



RM=rm -f

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -fPIC -shared $(SOURCES) -o $@


$(DEPS): $(SOURCES)
	$(CC) -MM -iquote "../headers" $(SOURCES) > $(DEPS)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

