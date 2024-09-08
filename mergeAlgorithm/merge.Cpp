#include<iostream>

using namespace std;

/*
 * This program implements the Merge Sort algorithm to sort an array of integers.
 * Merge Sort is a "divide and conquer" algorithm that splits the array into two halves,
 * recursively sorts each half, and then merges the two sorted halves into one sorted array.
 */

class MergeSort {
    private:
    // Helper function that recursively sorts the array
    void mergeSort(int array[], int left, int right) {
        if(left < right) {
            // Find the middle point to divide the array into two halves
            int mid = left + (right - left) / 2;

            // Call mergeSort on the first half
            mergeSort(array, left, mid);

            // Call mergeSort on the second half
            mergeSort(array, mid + 1, right);

            // Merge the two halves sorted in the previous steps
            merge(array, mid, left, right);
        }
    }

    public:
    // This function initializes the merge sort process
    void sort(int array[], int n) {
        mergeSort(array, 0, n - 1);
    }

    // This function merges two halves of the array
    void merge(int array[], int mid, int left, int right) {
        int n1 = mid - left + 1;  // Size of the first half
        int n2 = right - mid;     // Size of the second half

        // Temporary arrays to store two halves
        int L[n1], R[n2];

        // Copy data to temporary arrays L[] and R[]
        for(int i = 0; i < n1; i++) {
            L[i] = array[left + i];
        }
        for(int i = 0; i < n2; i++) {
            R[i] = array[mid + 1 + i];
        }

        // Initial indexes for the two subarrays and the merged array
        int i = 0, j = 0, k = left;

        // Merge the temporary arrays back into array[left..right]
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if any
        while(i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while(j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }
};

int main() {
    // Example array to be sorted
    int array[] = {5, 2, 4, 1, 3};
    int n = sizeof(array) / sizeof(array[0]);

    // Create an object of the MergeSort class
    MergeSort sorter;
    sorter.sort(array, n);  // Sort the array

    // Print the sorted array
    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";  // Output each element of the sorted array
    }
    return 0;
}
