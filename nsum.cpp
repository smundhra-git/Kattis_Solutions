#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#define pii pair<int,int>
#define vp vector<pii>
#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    FOR(n){
        int x;
        cin >> x;
        sum += x;
    }
    cout << sum << endl;   
    
}
