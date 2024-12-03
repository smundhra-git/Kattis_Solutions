#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int upside_down(int num) {
    string s = to_string(num);
    string g;
    for (char c : s) {
        if (c == '3' || c == '4' || c == '7') {
            return -1;
        } else if (c == '6') {
            g = '9' + g;
        } else if (c == '9') {
            g = '6' + g;
        } else {
            g = c + g;
        }
    }
    return stoi(g);
}

bool check_sum(vector<int>& numbers, int sum) {
    unordered_set<int> seen;
    for (int num : numbers) {
        int needed = sum - num;
        if (seen.count(needed)) return true;

        int flipped = upside_down(num);
        if (flipped != -1 && seen.count(sum - flipped)) return true;

        seen.insert(num);
        if (flipped != -1) seen.insert(flipped);
    }
    return false;
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << (check_sum(numbers, sum) ? "YES" : "NO") << endl;
    return 0;
}
