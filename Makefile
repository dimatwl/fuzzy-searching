CC=g++
CFLAGS=-Wall

SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
DEPS = make.dep
TARGET = test

RM=rm -f

$(TARGET): $(OBJECTS)
	$(CC) -rdynamic -Wl,-rpath,. -L. -lfuzzy -o $@ $(OBJECTS) -ldl -Wl,--unresolved-symbols=ignore-in-shared-libs

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< 


$(DEPS): $(SOURCES)
	$(CC) -MM $(SOURCES) > $(DEPS)

-include $(DEPS)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(DEPS)

