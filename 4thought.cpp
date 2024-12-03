#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;
using namespace std;


// Helper function to convert an equation to string format
string formatEquation(int a, char op1, int b, char op2, int c, char op3, int d) {
    stringstream ss;
    ss << "4 " << op1 << " 4 " << op2 << " 4 " << op3 << " 4";
    return ss.str();
}

// Precompute all possible results using four 4's and store them in a map
unordered_map<int, string> precomputeResults() {
    unordered_map<int, string> results;
    vector<char> operations;
    operations.push_back('+');
    operations.push_back('-');
    operations.push_back('*');
    operations.push_back('/');

    // Iterate over all combinations of operations
    for (char op1 : operations) {
        for (char op2 : operations) {
            for (char op3 : operations) {
                // Simulate operation precedence
                vector<int> values(4, 4); // Initialize 4 values, all set to 4
                vector<char> ops;        // Declare an empty vector for operations
                ops.push_back(op1);      // Add operations to the vector
                ops.push_back(op2);
                ops.push_back(op3);

                // Handle * and / first
                for (int i = 0; i < ops.size(); i++) {
                    if (ops[i] == '*' || ops[i] == '/') {
                        int a = values[i];
                        int b = values[i + 1];
                        if (ops[i] == '/' && b == 0) continue; // Avoid division by zero
                        values[i] = (ops[i] == '*') ? (a * b) : (a / b);
                        values.erase(values.begin() + i + 1);
                        ops.erase(ops.begin() + i);
                        i--; // Adjust index for shifted vectors
                    }
                }

                // Handle + and -
                int result = values[0];
                for (int i = 0; i < ops.size(); i++) {
                    result = (ops[i] == '+') ? (result + values[i + 1]) : (result - values[i + 1]);
                }

                // Store the result and the equation
                string equation = formatEquation(4, op1, 4, op2, 4, op3, 4);
                results[result] = equation;
            }
        }
    }

    return results;
}

int main() {
    // Precompute results
    unordered_map<int, string> results = precomputeResults();

    // Read input
    int t;
    cin >> t;

    while (t--) {
        int target;
        cin >> target;

        // Output the result
        if (results.find(target) != results.end()) {
            cout << results[target] << " = " << target << endl;
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}
