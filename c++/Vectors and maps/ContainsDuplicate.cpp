// unordered_set::find
#include <bits/stdc++.h>

using namespace std;
#include <unordered_set>

int main ()
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

        1. We can use a set, because it has a good function for this

        2. First we go through our vector with a FOR

                3. if the number were we are is in our set, then we return true
                4. if not we add the number to the set

        4. if at the end we dont find anything then we return false

    // O(n) en tiempo, porque recorremos una vez
    // O(n) because we are using the set
    //------------------------------------------------------
    */
    vector<int> num = {3,3};

    unordered_set<int> set;

    for (int i = 0; i < num.size(); i++) {
        if(set.count(num[i]) > 0){
            cout << "true";
        }
        set.insert(num[i]);
    }
    cout << "false";

    return 0;
}