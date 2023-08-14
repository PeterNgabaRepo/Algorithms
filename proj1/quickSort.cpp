#include "quickSort.h"

int step = 0;

int quickSort(vector<int>& list, int p, int r){
	if(p < r){
		int q = partition(list, p, r);
		step += 2;
		quickSort(list, p, q - 1);
		quickSort(list, q + 1, r);
	}
	step += 1;
	return step;
}

int partition(vector<int>& list, int p, int r){
	int x = list[r];
	int i = p - 1;

	step += 4;
	int temp;
	for(int j = p; j < r; j++){
		if(list[j] <= x){
			i++;
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			step += 5;
		}
		step += 3;
	}

	temp = list[i + 1];
	list[i + 1] = list[r];
	list[r] = temp;

	step += 3;

	return i + 1;
}
