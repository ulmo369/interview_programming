
#include <bits/stdc++.h>
using namespace std;

int main() {
    string texto = "hellonow";
    set <string> dictonary = { "hello", "hell", "on", "now" };

    string aux1 = "";
    string aux2 = "";

    for (int i = 0; i < texto.size(); i++) {
        aux1 += texto[i];
        if (dictonary.find(aux1) != dictonary.end()) {
            cout << aux1 << endl;
            aux2 += texto[i];
            aux2 = "";
        }
        
        else if(dictonary.find(aux2) != dictonary.end()){
            cout << aux2 << endl;
            aux2 = "";
        }
    }

    //Solution 2
    //O(n) if we consider find O(1)

    cout << "..................................................." << endl;
    for(auto it = dictonary.begin(); it != dictonary.end(); it++){
        int pos = texto.find(*it); // Find the word in the string
        cout << "palabra =" << *it << endl;
        if(pos != string::npos){ // If the word is found
            cout << *it << endl; // return the word that was found
        }
    }

}
