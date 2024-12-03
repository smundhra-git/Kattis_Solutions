#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    int h, v;
    cin >> h >> v;
    int min = INT32_MAX;
    for(int i = 1; i< v+1; i++){
        double x = i * M_PI / 180;
        int r = ceil(h/sin(x));
        if(r < min) min = r;
    }
    cout << min << endl;
    return 0;
}
