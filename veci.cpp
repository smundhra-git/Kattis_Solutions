#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void permute(string a, int l, int r, vector<string>& permut)  
{  
    // Base case  
    if (l == r)  
        permut.push_back(a);
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
            // Swapping done  
            swap(a[l], a[i]);  
  
            // Recursion called  
            permute(a, l+1, r, permut);  
  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
} 

int main(){
   string x;
   cin >> x;

   int x_int = stoi(x);

    vector<char> d;
   //now d is 1, 5, 6 and couls be at max 6

    vector<string> permut;

    permute(x, 0, x.size()-1, permut);
    sort(permut.begin(), permut.end());

    for(int i = 0; i<permut.size(); i++){
        if(stoi(permut[i]) > x_int){
            cout << permut[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;



   

}