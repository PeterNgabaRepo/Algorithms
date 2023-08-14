CXX = g++ -ggdb
CXXFLAGS = -Wall

driver: graph.o minHeap.o driver.cpp
	$(CXX) $(CXXFLAGS) graph.h minHeap.cpp driver.cpp -o driver

minHeap.o: minHeap.h minHeap.cpp
	$(CXX) $(CXXFLAGS) -c minHeap.cpp

graph.o: graph.h
	$(CXX) $(CXXFLAGS) -c graph.h
clean:
	rm *~

run:
	./driver
