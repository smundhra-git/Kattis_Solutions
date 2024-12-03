#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    //quad 1 or 4
    if (abs(x) == x){
        if(abs(y) == y){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << 4 << endl;
            return 0;
        }
    }
    else{
        if(abs(y) == y){
            cout << 2 << endl;
            return 0;
        }
        else{
            cout << 3 << endl;
            return 0;
        }
    }
    return 0;
}