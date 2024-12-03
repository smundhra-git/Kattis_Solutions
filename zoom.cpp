#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i++)

int main(){
    int n, k;
    cin >> n >> k;

    vi v(n);

    FOR(n){
        cin >> v[i];
    }

    int q = n/k;

    for(int i = k-1; i<n; i+=k){
        cout << v[i] << " ";
    }
    cout << endl;
    

}