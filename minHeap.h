#ifndef MINHEAP_H
#define MINHEAP_H

#include "graph.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class minHeap{
	//private member variable containing the heap array
	vector<vertex*> m_arr;

	public:
		//constructor initialization
		minHeap(vector<vertex*> vertices);

		//heap Array getter
		vector<vertex*> getArr();

		//maintains heap property recursively
		void minHeapify(int i);

		int parent(int i);

		int left(int i);

		int right(int i);

		//extracts vector with smallest key
		vertex* extractVertex();

		//builds heap utilizing and rearraning heapArray to maintain
		//heap property
		void buildHeap();

		int heapSize();

		//checks if vertex is in heap
		bool isInHeap(vertex* u);

                void decreaseKey(vertex* u, int newKey);

                int getIndex(vertex* u);
};

#endif


