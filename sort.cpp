#include <iostream>
#include <algorithm>
#include <vector>


// Simple Sort

// bubble sort for vector
template <typename Comparable>
void bubbleSort(std::vector<Comparable> &vector)
{
	int i;
	int j;
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
template <typename Comparable>
void selectionSort(std::vector<Comparable> &vector) 
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
	}
}

// insertion sort for vector
template <typename Comparable>
void insertionSort(std::vector<Comparable> &vector)
{
	int i;
	int j;
	for (i = 1; i < vector.size(); i++) {
		j = i;
		while (j > 0 && vector[j-1] > vector[j]) {
			std::swap(vector[j], vector[j-1]);
			j--;
		}
	}
}

// Complex Sort

// merge sort
template <typename Comparable>
void mergeSort(std::vector<Comparable> &, std::vector<Comparable> &, int, int);
template <typename Comparable>
void merge(std::vector<Comparable> &, std::vector<Comparable> &, int, int, int);

/**
 * Merge Sort algorithm (driver)
 */
template <typename Comparable>
void mergeSort(std::vector<Comparable> &a)
{
    std::vector<Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size()-1);
}

/**
 * Internal method that make recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result
 * left is the left-most index of the subarray
 * right is the right-most index of the subarray
 */
template <typename Comparable>
void mergeSort(std::vector<Comparable> &a,
               std::vector<Comparable> &tmpArray, int left, int right)
{
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

/**
 * Internal method that merges two sorted halves of the subarray
 * a is an array of Comparable items
 * tmpArray is an array to place the merged result
 * leftPos is the left-most index of the subarray
 * rightPos is the index of the start of the second half
 * rightEnd is the right-most index of the subarray
 */
template <typename Comparable>
void merge(std::vector<Comparable> &a, std::vector<Comparable> &tmpArray,
           int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // main loop
    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        } else {
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
        }
    }

    while (leftPos <= leftEnd) {
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
    }

    while (rightPos <= rightEnd) {
        tmpArray[tmpPos++] = std::move(a[rightPos++]);
    }

    for (int i = 0; i < numElements; ++i, --rightEnd) {
        a[rightEnd] = std::move(tmpArray[rightEnd]);
    }
}


// quicksort
// ** cannot compare with the same number in vector (bug)

template <typename Comparable>
void quickSort(std::vector<Comparable> &, int, int);
template <typename Comparable>
int partition(std::vector<Comparable> &, int, int);

/**
 * Quicksort algorithm (driver)
 */
template <typename Comparable>
void quickSort(std::vector<Comparable> &a)
{
    quickSort(a, 0, a.size() - 1);
}

template <typename Comparable>
void quickSort(std::vector<Comparable> &a, int first, int last) 
{
    int cut;
    if (first < last) {
        cut = partition(a, first, last);
        quickSort(a, first, cut);
        quickSort(a, cut+1, last);
    }
}

template <typename Comparable>
int partition(std::vector<Comparable> &a, int first, int last) 
{
    int pivot, temp;
    int loop, cutPoint, bottom, top;
    pivot = a[first];
    bottom = first;
    top = last;
    loop = 1;

    while (loop) {
        while (a[top] > pivot) {
            top--;
        }
        while (a[bottom] < pivot) {
            bottom++;
        }
        if (bottom < top) {
            std::swap(a[bottom], a[top]);
        } else {
            loop = 0;
            cutPoint = top;
        }
    }
    return cutPoint;
}


// main function
int main() {
	std::vector<int> vector {70,15,85,25,8,16,22,35};
	std::cout << "Before Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	quickSort(vector);	
	std::cout << "After Sort: ";
	for (std::vector<int>::iterator itr=vector.begin(); itr < vector.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << "\n";
	return 0;
}
