#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> integers;

    for(int i = 0; i<n; i++){
        int t;
        cin >> t;
        integers.push_back(t);
    }

    vector<bool> v1;
    vector<bool> v2;

    v1.resize(n, false);
    v2.resize(n, false);


    //check for the elements which are bigger than the cur_max we have found
    int cur_max = integers[0];
    v1[0] = true;
    for(int i = 1; i<n; i++){
        if(integers[i] > cur_max){
            v1[i] = true;
            cur_max = integers[i];
        }
    }

    //same but for minimum
    int cur_min = integers[n-1];
    v2[n-1] = true; 

    for(int i = n-1; i >=0; i--){
        if(integers[i] < cur_min){
            v2[i] = true;
            cur_min = integers[i];
        }
    }
    int count = 0;
    for(int i = 0; i<n;i++){
        if(v1[i] && v2[i]){
            count++;
        }
    }
    cout << count << endl;

    return 0;
}