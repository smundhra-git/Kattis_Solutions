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
#define pii pair<int, int>
#define in(n, v) for(int i = 0; i < n; i++) cin >> v[i];
#define mult(t) int t; cin >> t; while (t > 0) { solve(); t--; }
#define FOR(n) for(int i = 1; i < n; i++)
#define print(n) for(auto x : n) cout << x << " "; cout << endl;

using namespace std;

bool isValidPizza(const vector<int>& pizza, const set<pair<int, int> >& restrictions) {
    for (size_t i = 0; i < pizza.size(); i++) {
        for (size_t j = i + 1; j < pizza.size(); j++) {
            if (restrictions.count(make_pair(pizza[i], pizza[j])) || restrictions.count(make_pair(pizza[j], pizza[i]))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    set<pair<int, int> > restrictions;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        restrictions.insert(make_pair(a, b));
    }
    
    int totalPizzas = 0;
    int maxMask = (1 << n); // Total subsets of n ingredients
    
    for (int mask = 0; mask < maxMask; mask++) {
        vector<int> currentPizza;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currentPizza.push_back(i + 1); // Ingredients are 1-indexed
            }
        }
        if (isValidPizza(currentPizza, restrictions)) {
            totalPizzas++;
        }
    }
    
    cout << totalPizzas << endl;
    return 0;
}
