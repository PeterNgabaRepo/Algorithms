#include  <iostream>
#include  <fstream>
#include  <chrono>
#include  <vector>
#include  <string>
#include  "insertSort.h"
#include  "mergeSort.h"
#include  "bucketSort.h"
#include  "bubbleSort.h"
#include  "quickSort.h"
#include  "bogoSort.h"
using namespace std;

const int EXITFAILURE = -1;
const int EXITSUCCESS = 0;

int main(){
	string filename;
	vector<int> list;
	int number;
	int sortChoice;
	int steps;

	const int insertSortIndex = 1;
	const int mergeSortIndex = 2;
	const int bucketSortIndex = 3;
	const int bubbleSortIndex = 4;
	const int quickSortIndex = 5;
	const int bogoSortIndex = 6;

	cout << "Enter the file you wish to sort" << endl;
	cin >> filename;

	//filename = "sortFile2.txt";

	//Prints Sort Menu
	cout << "1 - Insertion Sort" << endl;
	cout << "2 - Merge Sort" << endl;
	cout << "3 - Bucket Sort" << endl;
	cout << "4 - Bubble Sort" << endl;
	cout << "5 - Quick Sort" << endl;
	cout << "6 - Bogo Sort" << endl;

	cout << endl << "Enter the index for the sort you wish to use" << endl;
	cin >> sortChoice;

	//Read in numbers from file
	fstream myfile;

	myfile.open(filename);

	if(!myfile.is_open()){
		cerr << "Could not open the file - '" << filename << "'" << endl;
		return EXITFAILURE;
	}

	while(myfile >> number){
		list.push_back(number);
	}
	myfile.close();

	//Use corresponding sorts and calculate runtime
	auto start = std::chrono::high_resolution_clock::now();

	if(sortChoice == insertSortIndex){
		steps = insertSort(list);
	}
	else if(sortChoice == mergeSortIndex){
		steps = mergeSort(list, 0, list.size() - 1);
	}
	else if(sortChoice == bucketSortIndex){
		steps = bucketSort(list);
	}
	else if(sortChoice == bubbleSortIndex){
		steps = bubbleSort(list);
	}
	else if(sortChoice == quickSortIndex){
		steps = quickSort(list, 0, list.size() - 1);
	}
	else if(sortChoice == bogoSortIndex){
		steps = bogoSort(list);
	}

	auto stop = std::chrono::high_resolution_clock::now();

	//Outputs sorted list
        for(auto it = begin(list); it != end(list); it++){
                cout << *it  << " ";
        }
        cout << endl;

        //Outputs statistics
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	auto duration2 = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

        cout << "The number of input elements is: " << list.size() << endl;
	cout << "Time taken to sort in microseconds: " << duration.count() << endl;
	cout << "Time taken to sort in seconds: " << duration2.count() << endl;
	cout << "Number of steps taken is: " << steps << endl;

	return EXITSUCCESS;
}



