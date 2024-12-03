#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<vector<int>, int> combination_count;

    for (int i = 0; i < n; ++i) {
        vector<int> courses(5);
        for (int j = 0; j < 5; ++j) {
            cin >> courses[j];
        }
        // Sort the courses to handle different orderings of the same combination
        sort(courses.begin(), courses.end());
        
        // Count each combination
        combination_count[courses]++;
    }

    // Find the maximum frequency of any combination
    int max_popularity = 0;
    for (const auto& entry : combination_count) {
        if (entry.second > max_popularity) {
            max_popularity = entry.second;
        }
    }

    // Count how many students have combinations that match the maximum popularity
    int prize_winners = 0;
    for (const auto& entry : combination_count) {
        if (entry.second == max_popularity) {
            prize_winners += entry.second;
        }
    }

    cout << prize_winners << endl;
    return 0;
}
