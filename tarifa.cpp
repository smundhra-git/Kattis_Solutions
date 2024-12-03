#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <unordered_map>


using namespace std;



int main() {
    int x, n;
    cin >> x >> n;
    int p = 0;
    for(int i = 0; i<n; i++){
        int v;
        cin >> v;
        p = p + x - v;
    }
    cout << p+x << endl;
    return 0;
}
