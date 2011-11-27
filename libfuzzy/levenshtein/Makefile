CC=g++
CFLAGS=-Wall

SOURCES = levenshtein.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET = levenshtein.so



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

