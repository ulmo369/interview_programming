#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*----------------
    ->PRIMERA SOLUCION

    1. We are going to use XOR

    2. Explanation of XOR
        -------------
        | 1 ^ 1 = 0 |
        | 0 ^ 0 = 0 |
        | 1 ^ 0 = 1 |
        | 0 ^ 1 = 1 |
        -------------
    
    3. input (1, 2, 3, 1, 2)
        for(list)
            list[0] = 1 --> res = 1 [1]
            list[1] = 2 --> res = res ^ list[1] = 3 [1, 2]
            list[2] = 3 --> res = res ^ list[2] = 6 [1, 2, 3]
            list[3] = 1 --> res = res ^ list[3] = 5 [2, 3]
            list[4] = 2 --> res = res ^ list[4] = 3 [3]
    
    -> TIEMPO O(n)
    -> MEMORIA O(1)
    //-------------------
    */
    int res = 0;
    vector<int> n = {4, 1, 2, 1, 4, 3, 5, 3, 5};

    for (int i = 0; i < n.size(); i++){
        res = res ^ n[i];
    }

    cout << res << endl;

    //-----------------------------------
    // SEGUNDA SOLUCION
    // FUERZA BRUTA O(nlogn) por el sort
    //-----------------------------------

    sort(n.begin(), n.end());

    for(int i = 0; i < n.size(); i++){
        if(n.size() == 1){
            break;
        }
        else if(n[i] == n[i + 1]){
            i++;
        }
        else{
            cout << n[i];
            break;
        }
    }

}