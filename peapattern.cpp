#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

string counter(string &m){
    stringstream output;
    for(char i = '0'; i <= '9'; i++){
        int count = 0;
        for(int j = 0; j < m.size(); j++){
            if(m[j] == i){
                count++;
            }
        }
        if(count > 0){
            output << count << i;
        }
    }
    return output.str();
}

bool find(vector<string> store, string m){
    for(int i = 0; i<store.size(); i++){
        if(store[i] == m){
            return true;
        }
    }
    return false;
}

int main(){
    string n, m;
    cin >> n >> m;

    vector<string> store;

    store.push_back(n);

    if(n == m){
        cout << 1 << endl;
        return 0;
    }

    bool solved = false;
    while(!solved){
        string g = counter(n);
        if(g == m){
            cout << store.size() + 1 << endl;
            return 0;
        }

        else if (store.size() > 100){
            cout << "I'm bored" << endl; 
            return 0;
        }

        else if(find(store, g)){
            cout << "Does not appear" << endl;
            return 0;
        }
        store.push_back(g);
        n = g;
    }
    return 0;
}