#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

    1. We know that the biggest bit is 2147483648

    2. So, If the the first bit is 1, then the result is equal to that value 

    2. And then we move one to the left with n >> 1 

    3. With this we check the other 31 bits

        4. We devide the biggest bit by 2 -> 2147483648/2

        5. if the bit where we are is 1, then we add the new value to the result (step 4)

        6. And then, we just move one to the left with n = n >> 1;

    // O(n) memory and O(1) tiempo
    ------------------------------------------------------
    */
    
    long long int n = 010101101010101001; //INPUT

    long long val = 2147483648; //biggest bit
    long long res = 0;
    
    
    if(n%2 == 1){
        res = 2147483648;
    }

    n = n >> 1;
    for (int i = 0; i < 31; i++){
        val = val / 2;
        if((n & 1) == 1){
            res = res + val;
        }
        n = n >> 1;
    }

    cout << res;
}