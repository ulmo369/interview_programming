// unordered_set::find
#include <bits/stdc++.h>
#include <unordered_set>
#include <map>
using namespace std;

int main ()
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

        1. We can use maps here

        2. We put the elements of each anagram in a map.
        .  The KEy will be the letter
        .  the VALUE how many times does the letter exist.

        3. Then in a FOR we check if the maps match.

    // O(n) en tiempo, porque recorremos una vez
    // O(n) en memoria, porque usamos memoria extra en los maps
    //------------------------------------------------------
    */

    string s = "anagrama";
    string t = "tptoitut";

    map<char, int> S, T;

    if(s.size() != t.size()){
        cout << "false";
    }

    for(int i = 0; i < s.size(); i++){
        S[s[i]] = S[s[i]] + 1;
        T[t[i]] = T[t[i]] + 1;
    }

    for(auto it = T.begin(); it != T.end(); it++) {

        if(T[it->first] != S[it->first]){
            cout << "false"; //RETURN
            break;
        }
    }

    cout << "true"; //RETURN


}