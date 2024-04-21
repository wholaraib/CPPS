#include <iostream>
using namespace std;
void heapify(int arr[], int N, int i) // N is last element for each iteration 
{
	int largest = i; // Initialize largest as root
	int l = 2 * i; // left = 2*i
	int r = 2 * i + 1; // right = 2*i + 1

	if(l < N && arr[l] > arr[largest]) // If left child is larger than root
		largest = l;

	if(r < N && arr[r] > arr[largest]) // If right child is larger than largest so far
		largest = r;

	if (largest != i)  // If largest is not root
    {
		swap(arr[i], arr[largest]);

		heapify(arr, N, largest); // Recursively heapify the affected sub tree
	}
}
// Main function to do heap sort
void heapSort(int arr[], int N)
{
	// Build heap (rearrange array)
	for (int i = N / 2; i >= 0; i--) heapify(arr, N, i);

	// One by one extract an element from heap
	for (int i = N - 1; i > 0; i--) 
    {
		// Move current root to end
		swap(arr[0], arr[i]);
        
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i) cout << arr[i] << " ";
	cout << "\n";
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}
