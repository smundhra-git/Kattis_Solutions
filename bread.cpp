#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#define vi vector<int>
#define vii vector<vector<int> >
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge function for counting inversions
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;

    // Merge while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // All remaining elements in left half are inversions
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy merged array back to the original array
    for (int p = 0; p < temp.size(); p++) {
        arr[left + p] = temp[p];
    }

    return invCount;
}

// Recursive function for merge sort and counting inversions
long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long invCount = 0;

    // Count inversions in left and right halves
    invCount += mergeSortAndCount(arr, left, mid);
    invCount += mergeSortAndCount(arr, mid + 1, right);

    // Count cross inversions
    invCount += mergeAndCount(arr, left, mid, right);

    return invCount;
}

// Function to count inversions
long long countInversions(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> initial(n), target(n);
    for (int i = 0; i < n; i++) cin >> initial[i];
    for (int i = 0; i < n; i++) cin >> target[i];

    // Check if both sequences are permutations of 1 to n
    vector<int> freq(n + 1, 0);
    for (int x : initial) freq[x]++;
    for (int x : target) freq[x]--;
    for (int count : freq) {
        if (count != 0) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    // Count inversions and check parity
    long long initialInversions = countInversions(initial);
    long long targetInversions = countInversions(target);

    if ((initialInversions % 2) == (targetInversions % 2)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}

