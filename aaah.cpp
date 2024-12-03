

#include <iostream>
using namespace std;


int main(){
    string jon;
    string doc;
    getline(cin, jon);
    getline(cin, doc);
    
    int jon_a = jon.length() - 2;
    int doc_a = doc.length() - 2;
    if(jon_a >= doc_a){
        cout << "go" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}