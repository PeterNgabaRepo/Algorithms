#include "insertSort.h"
#include "bucketSort.h"
using namespace std;

int bucketSort(vector<int>& list){
	int steps = 0;
	int n = list.size();
	int max = 0;

	steps += 3;

	for(int i = 0; i < n; i++){
		steps += 2;

		if(list[i] > max){
			max = list[i];
			steps += 2;
		}
		steps += 1;
	}
	steps += 1;

	int buckets = int(floor(max / 10)) + 1;

	vector<int> b[buckets];

	int i = 0;
	steps += 3;

	while(i < n){
	  	b[ int(floor(list[i] / 10)) ].push_back(list[i]);
		i++;
		steps += 3;
	}

	i = 0;
	steps += 2;

	while(i < buckets){
		insertSort(b[i]);
		i++;
		steps += 3;
	}

	int k = 0;
	steps += 3;

	for(int i = 0; i < buckets; i++){
		steps += 3;
		int m = b[i].size();
		for (int j = 0; j < m; j++){
			list[k] = b[i][j];
			k++;
			steps += 4;
		}
		steps += 3;
	}
	return steps;
}
