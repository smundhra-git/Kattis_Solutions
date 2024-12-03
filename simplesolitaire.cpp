#include <iostream>
#include <vector>

using namespace std;

vector<string> recard (vector<string> v){
    vector<string> m;
    for (int i = 0; i<v.size(); i++){
        if(v[i] != "NN")
            m.push_back(v[i]);
    }
    return m;
}

void print_vector(vector<string> v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

bool n_compare_suits(vector<string> &m, int pos)
{
    if(pos < 3){
        return false;
    }

    else if (m[pos][1] == m[pos- 3][1])
    {
        m[pos] = "NN";
        m[pos-3] = "NN";
        m = recard(m);
        return true;
    }
    return n_compare_suits(m, pos -1);
}


bool n_compare_cards(vector<string> &m, int pos)
{
    if(pos < 3){
        return false;
    }
    else if ((m[pos])[0] == (m[pos - 3])[0])
    {
        m[pos] = "NN";
        m[pos - 1] = "NN";
        m[pos - 2] = "NN";
        m[pos - 3] = "NN";
        m = recard(m);
        return true;
    }
    return n_compare_cards(m, pos -1);
}




int main()
{
    vector<string> cards;
    for (int i = 0; i < 52; i++){
        string c;
        cin >> c;
        cards.push_back(c);
        if (cards.size() > 3){
            bool posible = true;
            while (posible){
                int j = cards.size()-1;
                if(cards.size() < 3){
                    posible = false;
                }
                if(n_compare_cards(cards, j)){
                }
                else if (n_compare_suits(cards, j)){
                }
                else{
                    posible = false;
                }
            }
        }
    }
    cout << cards.size() << endl;
    print_vector(cards);
    return 0;
}
