#include "bubbleSort.h"

int bubbleSort(vector<int>& list){
	int n = list.size();
	int steps = 2;

	for(int i = 0; i < n - 1; i++){
		steps += 3;
		for(int j = n - 1; j > i; j--){
			if(list[j] < list[j - 1]){
				int temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
				steps += 4;
			}
			steps += 3;
		}
		steps += 1;
	}
	steps += 1;

	return steps;
}
