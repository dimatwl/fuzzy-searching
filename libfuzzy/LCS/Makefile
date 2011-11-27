CC=g++
CFLAGS=-Wall

SOURCES = LCS.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET = LCS.so

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