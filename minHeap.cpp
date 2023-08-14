#include "graph.h"
#include "minHeap.h"

minHeap::minHeap(vector<vertex*> vertices) : m_arr(vertices){
	buildHeap();
}

vector<vertex*> minHeap::getArr(){
	return m_arr;
}

int minHeap::left(int i){
	int left = (2 * i) + 1;
	return left;
}

int minHeap::right(int i){
	int right = (2 * i) + 2;
	return right;
}

int minHeap::parent(int i){
	int parent = (i - 1) / 2;
	return parent;
}

void minHeap::minHeapify(int i){
	//assumes the root of the subtree is the smallest
	int smallest = i;
	int l = left(i);
	int r = right(i);

	int n = m_arr.size();

	//if it is not then find out if the left or right is and set it
	//correspondingly
	if(l < n && m_arr[l]->getKey() < m_arr[smallest]->getKey()){
		smallest = l;
	}

	if(r < n && m_arr[r]->getKey() < m_arr[smallest]->getKey()){
		smallest = r;
	}

	//make the smallest part of the subtree its root and call the fxn on
	//the affected subtree
	if(smallest != i){
	        swap(m_arr[i], m_arr[smallest]);
		minHeapify(smallest);
	}
}

void minHeap::buildHeap(){
	int n = m_arr.size();

	int start = parent(n);

	//calls minHeap starting from the parent of the last of node and working
	//backwards and rearranging to maintain heap property
	for(int i = start; i >= 0; i--){
		minHeapify(i);
	}
}

vertex* minHeap::extractVertex(){
	int n = m_arr.size();
	vertex* v = new vertex();

	if(n <= 0){
		cout << "There are no vectors to extract" << endl;
		return v;
	}

	else if(n == 1){
		vertex* root = m_arr[0];
		m_arr.pop_back();
		return root;
	}

	else{
		//if heapArray is not 1 or less, then return root
		//and remove last vertex and make it the new root
		//then rearrange to maintain property
		vertex* root = m_arr[0];

		m_arr[0] = m_arr[n - 1];
		m_arr.pop_back();

		minHeapify(0);
		return root;
	}
}

int minHeap::heapSize(){
	int size = m_arr.size();
	return size;
}

bool minHeap::isInHeap(vertex* u){
	bool val = false;

	int n = m_arr.size();

	for(int i = 0; i < n; i++){
		if(u == m_arr[i]){
			val = true;
			return val;
		}
	}

	return val;

}

void minHeap::decreaseKey(vertex* u, int newKey){

  u->setKey(newKey);
  int i = getIndex(u);

  minHeapify(i);

}

int minHeap::getIndex(vertex* u){
  int n = m_arr.size();
  
  for(int i = 0; i < n; i++){
    if(u == m_arr[i]){
      return i;
    }
  }
  return -1;
}
