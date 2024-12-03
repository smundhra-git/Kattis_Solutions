#include <iostream>

using namespace std;

int lowest(int a, int b, int c){
    if (a < b && a <c){
        return a;
    }    
    else if (b < a && b < c){
        return b;
    }
    return c;
}

int highest(int a, int b, int c){
    if (a > b && a > c){
        return a;
    }    
    else if (b > a && b > c){
        return b;
    }
    return c;
}

int find_b(int a, int b, int c, int temp1, int temp2){
    if(a!= temp1 && a!= temp2){
        return a;
    }
    if(b!= temp1 && b!= temp2){
        return b;
    }
    if(c!= temp1 && c!= temp2){
        return c;
    }
}


int main(){
    int a,b,c;
    string d;
    cin >> a;
    cin >> b;
    cin >> c;

    cin >> d;
    int temp1 = lowest(a,b,c);
    int temp2 = highest(a,b,c);
    b = find_b(a,b,c, temp1, temp2);
    a = temp1;
    c = temp2;

    if(d == "ABC"){
        cout << a << " " << b << ' ' << c << endl;
    }
    else if(d == "ACB"){
        cout << a << " " << c << ' ' << b << endl;
    }
    else if(d == "BAC"){
        cout << b << " " << a << ' ' << c << endl;
    }
    else if(d == "BCA"){
        cout << b << " " << c << ' ' << a << endl;
    }
    else if(d == "CAB"){
        cout << c << " " << a << ' ' << b << endl;
    }
    else if(d == "CBA"){
        cout << c << " " << b << ' ' << a << endl;
    }
    return 0;

}