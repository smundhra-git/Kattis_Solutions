#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <unordered_map>


using namespace std;



int main() {
    int max = -1;
    int c = 0;
    for(int i = 0; i<5; i++){
        int sum = 0;
        for(int j = 0; j<4; j++){
            int x;
            cin >> x;
            sum += x;
        }
        if(sum > max){
            max = sum;
            c = i;
        }
    }
    cout << c+1 << " " << max << endl;
    return 0;
}
