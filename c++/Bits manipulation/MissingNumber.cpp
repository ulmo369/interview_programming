#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

        1. We know that we are going 1 by 1. Ex: 1, 2, 3, 4 and not 1, 3, 6...

        2. With this we know that the biggest number is always there

        3. So the thing that we can do is a XOR for each iteration and value

            3.1. Explanation of XOR
                -------------
                | 1 ^ 1 = 0 |
                | 0 ^ 0 = 0 |
                | 1 ^ 0 = 1 |
                | 0 ^ 1 = 1 |
                -------------

        4. And that with the result


    // O(n porque recorremos n veces para encontrar el res
    //------------------------------------------------------
    */
    vector<int> nums = {1, 0, 3};

    int n = nums.size();
    
    int result = nums.size();
    for (int i = 0; i < n; i++) {
        result = result ^ nums[i] ^ i; //result ^ = nums[i] ^ i  ... WE USE i BECAUSE THE BIGGEST NUMBER IS ALWAYS THERE
;                                      //i WILL HAVE THE NUMBER THAT IS MISSING
    }

    cout << result << endl;
    
}
