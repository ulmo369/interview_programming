#include <bits/stdc++.h>
using namespace std;

int main() {
    string input = "asdf";

    map<char, int> pairs; //try with a set
    vector<int> count(26);


    for(int i = input.size() - 1; i >= 0; i--){
        count[input[i] - 'a'] = i;

        if (pairs.count(input[i]) > 0){
            input.erase(count[input[i] - 'a'], 1);
        }

        pairs[input[i]]++;
    }

    cout << input;


}