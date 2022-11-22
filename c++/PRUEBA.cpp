#include <bits/stdc++.h>
using namespace std;

int main() {

    map<char, int> Mymap;

    Mymap['d'] = 1;
    Mymap['a'] = 0;
    Mymap['c'] = 5;
    Mymap['b'] = 1;

    for(auto it = Mymap.begin(); it != Mymap.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

}