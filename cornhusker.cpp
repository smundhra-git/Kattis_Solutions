#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pii pair<int,int>
#define vp vector<pii>

using namespace std;

int main() {
    int sum = 0;
    for(int i = 0; i<5; i++){
        int x, y;
        cin >> x >> y;
        sum += (x*y);
    }
    int n, kwf;
    cin >> n >> kwf;
    cout << (n*(sum/5))/kwf << endl;
    return 0;
}
