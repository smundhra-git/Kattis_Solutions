#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> votes(n);
    unordered_map<string, int> umap;
    for(int i = 0; i<n; i++){
        cin >> votes[i];
        umap[votes[i]]++;
    }
    //output the elements with minimum count
    //if multiple minimum count, cout in alphabetical order
    int min = INT32_MAX;
    for(auto x : umap){
        if(x.second < min){
            min = x.second;
        }
    }
    
    vector<string> result;
    for(auto x : umap){
        if(x.second == min){
            result.push_back(x.first);
        }
    }
    sort(result.begin(), result.end());
    for(string r : result){
        cout << r << endl;
    }


}
