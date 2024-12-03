#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>

#define vi vector<int>
#define in(n, v) for(int i = 0; i<n; i++) cin >> v[i];
#define mult(t)  while(t > 0){ solve(); t--; }
#define FOR(n) for(int i = 0; i<n; i++)


using namespace std;

int solve(int n){
    if(n <= 3) return 1;
    return solve(n-1) + 1;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
