#include <iostream>
#include <vector>

using namespace std;

/**
 * Sorts a given array using the bubble sort algorithm.
 *
 * Bubble sort is a simple sorting algorithm that repeatedly goes through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 *
 * Parameters:
 * - arr: The vector of integers to be sorted.
 *
 * Algorithm principle:
 * 1. For each element in the array (except the last one):
 *    a. For each element from the beginning to n-i-1:
 *       i. Compare the current element with the next element.
 *       ii. If the current element is greater than the next, swap them.
 * 2. Repeat step 1 until all elements are in their correct positions.
 *
 * Time complexity:
 * - Worst and average case: O(n^2)
 * - Best case (already sorted array): O(n)
 *
 * Space complexity:
 * - O(1) (in-place algorithm, requires no extra memory beyond the input array)
 */
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) { // Traverse array from 0 to n-2
        for (int j = 0; j < n - i - 1; j++) { // Last i elements are already in place
            if (arr[j] > arr[j+1]) { // If the current element is greater than the next
                swap(arr[j], arr[j+1]); // Swap them
            }
        }
    }
}

int main() {
    vector<int> arr = {55, 66, 78, 34, 89, 90, 9};
    bubbleSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
