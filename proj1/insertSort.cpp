#include "insertSort.h"

int insertSort(vector<int>& list){
	int steps = 0;

	int n = list.size();
	steps += 2;

	for(int i = 1; i < n; i++){
		int key = list[i];

		int j = i - 1;

		steps += 4;

		while(j >= 0 and list[j] > key){
			list[j+1] = list[j];
			j--;
			steps += 4;
		}

		list[j+1] = key;
		steps += 3;
	}
	steps += 2;
	return steps;
}
