#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];

int main() {
    int n;
    cin >> n;
    vi v(n);
    in(n, v);  // Read the n numbers into the vector v

    // Sort the numbers to easily find consecutive sequences
    sort(v.begin(), v.end());

    vector<string> ans;  // This will store the results as strings
    int count = 0;  // To track the length of the current sequence
    int b = -1;  // Start of the current sequence

    for (int i = 0; i < v.size(); i++) {
        if (i == 0 || v[i] - v[i - 1] == 1) {
            // If it's the first element or consecutive with the previous one
            if (count == 0) b = v[i];  // Start a new sequence
            count++;  // Increase the length of the current sequence
        } else {
            // If the current number is not consecutive
            if (count >= 3) {
                // If the sequence length is at least 3, add it as a range
                ans.push_back(to_string(b) + "-" + to_string(v[i - 1]));
            } else {
                // Otherwise, add each number individually
                for (int j = 0; j < count; j++) {
                    ans.push_back(to_string(v[i - count + j]));
                }
            }
            count = 1;  // Reset the count for the new sequence starting from the current number
            b = v[i];  // New sequence starts here
        }
    }

    // Handle the last sequence
    if (count >= 3) {
        ans.push_back(to_string(b) + "-" + to_string(v.back()));
    } else {
        for (int i = 0; i < count; i++) {
            ans.push_back(to_string(v[v.size() - count + i]));
        }
    }

    // Print the results
    for (const string& s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
