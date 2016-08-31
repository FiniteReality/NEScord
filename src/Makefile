.PHONY: all clean

# Use CC65 to compile our code
CL=../cc65/bin/cl65
# Compiler flags
CFLAGS=-t nes
# Linker flags
LDFLAGS=

SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=nescord

all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CL) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CL) -c $(CFLAGS) $< -o $@

