#include <iostream>
#include <vector>

// bubblesort for array
void bubbleSort(int *arr, int length)
{
	int step = 0;
	bool isSorted = false;
	for (int i = 0; (i < length-1) && (isSorted==false); i++) {
		isSorted = true;
		for (int j = 0; j < length-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				step += 1;
				isSorted = false;
			}
		}
	}
	std::cout << "Total step is " << step << std::endl;
}

// bubble sort for vector
void bubbleSort(std::vector<int> &vector)
{
	int step = 0;
	bool isSorted = false;
	for (int i = 0; (i < vector.size()-1) && (isSorted==false); i++) {
		isSorted = true;
		for (int j = 0; j < vector.size()-i-1; j++) {
			if (vector[j] > vector[j+1]) {
				std::swap(vector[j], vector[j+1]);
				step += 1;
				isSorted = false;
			}
		}
	}
	std::cout << "Total step is " << step << std::endl;
}

// selection sort for array
// selection sort for vector
void selectionSort(std::vector<int> &vector) 
{
	for (int i = 0; i < vector.size(); i++) {
		int min = vector[i];
		int minIndex = i;
		for (int j = i + 1; j < vector.size(); j++) {
			if (vector[j] < min) {
				min = vector[j];
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(vector[i], vector[minIndex]);
		}
		std::cout << "Sorting (" << i << ")";
		for (int k = 0; k < vector.size(); k++) {
			std::cout << vector[k] << " ";
		}
		std::cout << "\n";
		}
}

int main() {
	std::vector<int> vector {2,5,6,10,0,9,7};
	std::cout << "Before Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	selectionSort(vector);	
	std::cout << "After Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	return 0;
}
