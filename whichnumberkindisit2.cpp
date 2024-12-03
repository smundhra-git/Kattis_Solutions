#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <climits>
#define vi vector<int>
#define vii(n, m) vector<vector<char> > v(n, vector<char>(m, ' '))
#define viin vector<vector<int> > 
#define us unordered_set<int>
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 0; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;
bool isPerfectSquare(int n) {
    if (n < 0) return false; // Negative numbers cannot be perfect squares
    int sqrtN = static_cast<int>(sqrt(n)); // Calculate the square root and cast to int
    return sqrtN * sqrtN == n; // Check if the square of the integer part equals the number
}
void solve(){
    int n;
    cin >> n; 
    bool odd = (n%2 == 1 ? true : false);
    bool square = (isPerfectSquare(n) ? true : false);
    if(odd && square) cout << "OS" << endl;
    else if(odd) cout << "O" << endl;
    else if(square) cout << "S" << endl;
    else cout << "EMPTY" << endl;
    return;
}
int main() {
    mult(t);
    return 0;
}

