#include <iostream>
#include <vector>

using namespace std;

struct answers{
    int time;
    char question;
    bool right;
};


int main(){
    vector<answers> input;
    int correct = 0;
    int t = 0; 
    
    bool run = true;
    while(run){
        int time;
        char question;
        string right;
        
        cin >> time;
        if (time == -1)
            break;
        cin >> question >> right; 
        
        struct answers ans;
        ans.time = time;
        ans.question = question;
        ans.right = (right == "right");
        
        input.push_back(ans);
    }
    
    for(int i =0; i<input.size(); i++){
        if(input[i].right){
            char q = input[i].question;
            correct++;
            if(i == 0)
                t = t + input[i].time;
            else{
                for(int j =0; j<i; j++){
                    if (q == input[j].question)
                        t = t + 20;
                }
                t = t + input[i].time;
            }
        }
    }

    cout << correct << " " << t << endl;

    return 0;
}