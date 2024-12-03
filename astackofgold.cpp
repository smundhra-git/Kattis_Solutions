#include <iostream>

using namespace std;

int main(){
    int w, s;
    cin >> w >> s;
    for(int i = 0; i<s; i++){
        if((w - (29370*(i+1))) %29260 == 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}