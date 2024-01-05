// unordered_set::find
#include <bits/stdc++.h>

using namespace std;
#include <unordered_set>

/*
    1. I think here we can use maps, but how?

    2. Maybe we can store each word in the map
        (PIENSA Y ACTUA COMO QUE ESTAS ANALIZANDO E INVENTANDOTE UNA SOLUCION)
        (ESTA ES LA SOLUCION)
        Due to we are searching anagrams, we can use the ASCII of each letter

        2.1. The KEY can be the number that we got with the ASCII value of each letter of the word
        2.2. The VALUE will be the vector of the words with that number

    3. So we need first something that give us the KEY

    4. And then just store the VALUE

*/

string getKey(string str) {
    vector<int> count(26);
    for (int j = 0; j < str.size(); j++) {
        count[str[j] - 'a']++; // Turn the letter into a number
    }

    string key = "";
    for (int i = 0; i < 26; i++) {
        key.append(to_string(count[i] + 'a')); // add the number to the key
    }

    return key;
}

int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++) {
        string key = getKey(strs[i]); // We make our word into a key
        m[key].push_back(strs[i]); // We store the word into the value of the key
    }
    
    vector<vector<string>> result;
    for (auto it = m.begin(); it != m.end(); it++) {
        result.push_back(it->second);
    }
    
    
    for(int i = 0; i < result.size(); i++) {//RETURN RESULT
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ,";
        }
    }



    ////////////////////////////////////////////////////////////////////////////////////////////////
    // SOLUCION 2

    

}