SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: graph output.graphml

graph: $(OBJECTS)
	gcc -o $@ $^

output.graphml: graph
	./$^ > $@

clean:
	rm -rf $(OBJECTS) graph output.graphml
