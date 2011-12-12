CC=g++
CFLAGS=-Wall -iquote "../headers"

SOURCES = LCS.cpp
DEPS = make.dep
TARGET = ../../LCS.so

RM=rm -f

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -fPIC -shared $(SOURCES) -o $@


$(DEPS): $(SOURCES)
	$(CC) -MM -iquote "../headers" $(SOURCES) > $(DEPS)


-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)
