CXX=g++ 
CXXFLAGS = -g --std=c++20 -Wall

all: examheap

examheap: examheap.o heap.o
	${CXX} ${CXXFLAGS} examheap.o heap.o -o examheap

examheap.o: examheap.cpp
	${CXX} ${CXXFLAGS} examheap.cpp -c

heap.o: heap.cpp
	${CXX} ${CXXFLAGS} heap.cpp -c

clean:
	rm examheap *.o