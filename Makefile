CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized

BINARIES=testFunc

COMMON_OBJECTS=utility.o inventory.o cart.o

all: ${BINARIES}

tests: ${BINARIES}
	./testFunc

testFunc: testFunc.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 

clean:
	/bin/rm -f ${BINARIES} *.o
