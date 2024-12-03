#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

//try putting in as many strings as we could by not repeating characters
//for every problem - mark characters as true(used) and go ahead and try to take the maximum out of the rest
//and not use the problem and take the maximum out - whichever is the max is the answer
//cur marks the current problem
int solve(vector<string>& problems, int cur, vector<bool> chars) {
    if (cur == problems.size()) {
        return 0; // Base case: no more problems to consider
    }

    string p = problems[cur];
    vector<bool> copy = chars;

    // Check if the current string can be used
    bool canUse = true;
    for (char c : p) {
        if (copy[c - 'A']) { // Character already used
            canUse = false;
            break;
        }
        copy[c - 'A'] = true; // Mark character as used
    }

    // Recursive calls: include the current string or exclude it
    int exclude = solve(problems, cur + 1, chars);
    int include = 0;
    if (canUse) {
        include = 1 + solve(problems, cur + 1, copy);
    }

    return max(include, exclude);
}


int main() {
    int p, t;
    cin >> p >> t;
    vector<string> problems;
    FOR(t){
        string x;
        cin >> x;
        //if x has repeat character or has a char over p, dont take it
        unordered_set<char> u;
        bool okay = true;
        for(char c : x){
            if(c > p + 'A' -1 || u.find(c) != u.end()){
                okay = false;
            }
            u.insert(c);
        }
        if(okay) problems.push_back(x);
    }
    //input taken 
    vector<bool> chars(p, false);
    cout << solve(problems, 0, chars) << endl;

}
