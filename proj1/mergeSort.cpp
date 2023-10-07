#include "mergeSort.h"

int steps = 0;

int mergeSort(vector<int>& list, int p, int r){

	if(p < r){
		int q = floor((p + r) / 2);
		steps += 2;
		mergeSort(list, p, q);
		mergeSort(list, q + 1, r);
		merge(list, p, q, r);
	}
	steps += 1;

	return steps;
}

void merge(vector<int>& list, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;

	int left[n1];
	int right[n2];

	steps += 5;

	for(int i = 0; i < n1; i++){
		left[i] = list[p + i];
		steps += 3; 
	}

	steps += 2;

	for(int i = 0; i < n2; i++){
		right[i] = list[q + i + 1];
		steps += 3;
	}


	int i = 0;
	int j = 0;

	steps += 3;

	for(int k = p; k <= r; k++){
		steps += 2;

		if((left[i] <= right[j] and i < n1 and j < n2) || j >= n2){
			list[k] = left[i];
			i++;
			steps += 5;
		}
		else{
			list[k] = right[j];
			j++;
			steps += 2;
		}
	}
	steps += 1;
}
