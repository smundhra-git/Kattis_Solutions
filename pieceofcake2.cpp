#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

#define pii pair<int,int>
#define vp vector<pii>
#define vi vector<int>
#define FOR(n) for(int i = 0; i<n; i++)

const int t = 4;

using namespace std;

long long int max(long long a, long long b, long long c, long long d){
    if(a >= b && a >= c && a >= d) return a;
    if(b >= c && b >= d) return b;
    if(c >= d) return c;
    return d;
}

int main() {
    int n, h, v;
    cin >> n >> h >> v;
    //calculate all 4 volumes
    long long vol1, vol2, vol3, vol4;

    vol1 = h*v*t;
    vol2 = (n-h) * v * t;
    vol3 = h * (n-v) * t;
    vol4 = (n-h) * (n-v) * t;
    cout << max(vol1, vol2, vol3, vol4) << endl;
    return 0;

    
}
