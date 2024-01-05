#include <bits/stdc++.h>

using namespace std;

int main () 
{ 
    string s = "abccba";
    string visited = "";

    for(int i = 0; i < s.size(); i++){
        if(visited.find(s[i]) == string::npos){
            visited += s[i];
        }
    }

}