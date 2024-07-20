#include <bits/stdc++.h>
using namespace std;

string rule;
int Nwords;
string words[101];
string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

string ans[1000];


void backtrack(int index){
    if(index == rule.size()){

        for (int i = 0; i < index; i++){
            cout << ans[i];
        }
        cout << endl; 
    }

    else{

        if(rule[index] == '#'){
            for (int i = 0; i < Nwords; i++){
                ans[index] = words[i];
                backtrack(index + 1);
            }
        }

        else {
            for (int i = 0; i < 10; i++){
                ans[index] = numbers[i];
                backtrack(index + 1);
            }
        }
    }
}

int main(){
    int NumOfRules;
    while (cin >> Nwords){
        
        for (int i = 0; i < Nwords; i++){
            cin >> words[i];
        }





        cout << "--" << endl;
        cin >> NumOfRules;





        while(NumOfRules--){
            cin >> rule;
            backtrack(0);
        }
    }
    

}