#include <bits/stdc++.h>

using namespace std;

int main () 
{
    string w = "Hello World I am a programmer";

    //reverse the string
    reverse(w.begin(), w.end()); //O(n)

    //reverse the words
    int start = 0;
    for(int i = 0; i < w.size(); i++){//O(n)
        if(w[i] == ' '){//if we found a space then we reverse the word
            reverse(w.begin() + start, w.begin() + i);//O(n)
            start = i + 1;
        }
        if(i == w.size() - 1){// in the case od the last word we do something different
            reverse(w.begin() + start, w.begin() + i + 1);//O(n)
        }
        cout << w[i] << endl;
    }

    cout << w << endl;
}