#include "bogoSort.h"

int steps2 = 0;

bool sorted(vector<int>& list){
	const int n = list.size();

	steps2 += 2;

	for(int i = 1; i < n; i++){
		steps2 += 2;
		if(list[i] < list[i - 1]){
			steps2 += 1;
			return false;
		}
		steps2 += 1;
	}
	steps2 += 1;

	return true;
}

void shuffle(vector<int>& list){
	int temp;
	int randVal;
	const int n = list.size();

	steps2 += 4;

	for(int i = 0; i < n; i++){
		randVal = rand();

		temp = list[i];
		list[i] = list[randVal % n];
		list[randVal % n] = temp;
		steps2 += 6;
	}
	steps2 += 1;
}

int bogoSort(vector<int>& list){
	while(!sorted(list)){
		shuffle(list);
	}
	return steps2;
}

