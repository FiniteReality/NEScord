.PHONY: all

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


$(EXECUTABLE): $(OBJECTS)
	$(CL) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CL) -c $(CFLAGS) $< -o $@

