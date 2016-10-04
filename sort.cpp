#include <iostream>
#include <algorithm>
#include <vector>

// bubblesort for array
/*
void bubbleSort(int *arr, int length)
{
	int i, j;
	bool isSorted = false;
	for (i = 0; (i < length-1) && (isSorted==false); i++) {
		isSorted = true;
		for (j = 0; j < length-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				isSorted = false;
			}
		}
	}
}
*/

void displaySwap(std::vector<int>&vector) {
	std::cout << "Swapping is happening: ";
	for(std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
}

// Simple Sort

// bubble sort for vector
void bubbleSort(std::vector<int> &vector)
{
	int i, j;
	bool isSorted = false; // flag to stop iteration if it is sorted
	for (i = 0; (i < vector.size()-1) && (isSorted==false); i++) {
		isSorted = true;
		for (j = 0; j < vector.size()-i-1; j++) {
			if (vector[j] > vector[j+1]) {
				std::swap(vector[j], vector[j+1]);
				displaySwap(vector);
				isSorted = false;
			}
		}
	}
}

// selection sort for vector
void selectionSort(std::vector<int> &vector) 
{
	int i, j, min, minIndex;
	for (i = 0; i < vector.size(); i++) {
		min = vector[i];
		minIndex = i;
		for (j = i + 1; j < vector.size(); j++) {
			if (vector[j] < min) {
				min = vector[j];
				minIndex = j;
			}
		}
		std::swap(vector[i], vector[minIndex]);
		displaySwap(vector);
	}
}

// insertion sort for vector
void insertionSort(std::vector<int> &vector)
{
	int i, j;
	for (i = 1; i < vector.size(); i++) {
		j = i;
		while (j > 0 && vector[j-1] > vector[j]) {
			std::swap(vector[j], vector[j-1]);
			displaySwap(vector);
			j--;
		}
	}
}

// Complex Sort

void merge(std::vector<int> &vector, int left, int middle, int right) 
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	//	create temp vector
	std::vector<int> LEFT(n1), RIGHT(n2);
	
	// copy data to temp vector LEFT and right
	for (i = 0; i < n1; i++) {
		LEFT.push_back(vector[left+i]);
	}
	for (j = 0; j < n2; j++) {
		RIGHT.push_back(vector[middle + 1 + j]);
	}
	
	// merge the temp back to vector 
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (LEFT[i] <= RIGHT[j]) {
			vector[k] = LEFT[i];
			i++;
		} else {
			vector[k] = RIGHT[i];
			j++;
		}
		k++;
	}
	
	//	copy the remaining elements of LEFT and RIGHT if left
	while (i < n1) {
		vector[k] = LEFT[i];
		i++;
		k++;
	}
	while (j < n2) {
		vector[k] = RIGHT[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<int> &vector, int left, int right) 
{
	if (left < right) {
		int middle = left+(right)/2;
		mergeSort(vector, left, middle);
		mergeSort(vector, middle+1, right);
		merge(vector, left, middle, right);
	}
}


int main() {
	std::vector<int> vector {2,5,6,10,0,9,7};
	std::cout << "Before Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	mergeSort(vector, 0, vector.size());	
	std::cout << "After Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	return 0;
}
