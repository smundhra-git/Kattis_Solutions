#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> populations(n);

    // Input the populations of each region
    for (int i = 0; i < n; ++i) {
        cin >> populations[i];
    }

    // Sort the populations in ascending order
    sort(populations.begin(), populations.end());
    //sorted 3 3 11

    int r = ceil(n/2); //it is 2
    int v = 0;
    for(int i = r+1; i < n; i++){
        v += populations[i];
    }
    //for 3 and 3
    //3/2 = 1 
    for(int i = 0; i<=r; i++){
        int p = populations[i]/2;
        v += p;
    }
    cout << v << endl;

    return 0;
}
