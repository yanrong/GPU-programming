PWD := $(shell pwd)
CC := gcc
CXX := g++

COMMON := $(PWD)/../../common
CFLAGS :=
CXXFLAGS := -I$(PWD)/../../ -I$(COMMON) -I/usr/include/freetype2 -I/usr/include/libpng16
LDFLAGS := -lGL -lGLEW -lglfw -ldl -lfreetype
HEADERCSOURCE := $(wildcard $(COMMON)/*.c)
HEADERCCSOURCE :=  $(COMMON)/fileSystem.cc $(COMMON)/shader_s.cc
CCSOURCE := $(wildcard *.cc)
CCEXECUTABLE := $(CCSOURCE:.cc=)
COBJS := $(HEADERCSOURCE:.c=.o)
CCOBJES := $(HEADERCCSOURCE:.cc=.o)

all: $(CCEXECUTABLE)

$(COBJS) : $(HEADERCSOURCE)
	$(CC) -c -o $@ $< $(LDFLAGS) $(CFLAGS)

#we add the .o file to dependency list, it will automatically generate .o by implicit rules
$(CCEXECUTABLE): $(CCSOURCE) $(COBJS) $(CCOBJES)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

.PHONY: installclean

installclean:
	rm -rf $(CCEXECUTABLE)

.PHONY: clean

clean: installclean
	rm -rf *.o $(COMMON)/*.o