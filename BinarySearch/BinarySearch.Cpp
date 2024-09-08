#include <iostream>
#include <vector>

using namespace std;

/**
 * Performs a binary search on a sorted array to find a given element.
 *
 * Parameters:
 * - arr: A sorted vector of integers to search in.
 * - left: The leftmost index of the current search subarray.
 * - right: The rightmost index of the current search subarray.
 * - x: The element to search for.
 *
 * Return value:
 * - The index of the element in the array if found, otherwise -1.
 */

int binarySearch(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If the element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] < x)
            left = mid + 1;

        // Else the element can only be present in right subarray
        else
            right = mid - 1;
    }

    // Element is not present in the array
    return -1;
}

int main() {
    vector<int> arr = {10, 30, 40, 60, 80};
    int x = 70;
    int result = binarySearch(arr, 0, arr.size() - 1, x);

    if (result != -1)
        cout << "Element " << x << " is present at index " << result << endl;
    else
        cout << "Element " << x << " is not present in array" << endl;

    return 0;
}
