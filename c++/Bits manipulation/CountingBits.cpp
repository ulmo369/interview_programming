#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

        1. We have to check how everything is moving
            We know that...
            
            INT  BINARY  EXPLANATION
            0 -> 0000 -> 
            1 -> 0001 -> 
            2 -> 0010 -> 
            3 -> 0011 ->

            We repeate the same sequence of 0,1,2 and 3
            4 -> 0100 -> last two numbers like 0
.                  ^^ 
            5 -> 0101 -> last two numbers like 1
.                  ^^ 
            6 -> 0110 -> last two numbers like 2
.                  ^^ 
            7 -> 0111 -> last two numbers like 3
.                  ^^  

            We repeate the same sequence of 1,2,3,4,5,6 and 7
            8 -> 1000 -> last three numbers like 4
.                 ^^^

        2. How we are doing this?
            2.1. First we have to check if our number is even (PARES) with the MODULE (i%2)
                    With this we know if the last Binary number is going to be ON or OFF
            
            2.2. Then we check the carrie numbers that we need 
                    (res[i/2]) With this we do this:
                            i    BINARY        EXPLANATION
                            5 -> 0101 -> last two numbers like 1 or like 2 because they have only 1 Binary number ON
                            7 -> 0111 -> last two numbers like 3

            2.3. Our formula can be -> res[i] = res[i/2] + (i%2)

    // O(n) time and memory
    //------------------------------------------------------
    */
    
    int n = 5; //INPUT
    vector <int> res(n+1);
    
    for(int i = 0; i < res.size(); i++){
        res[i] = res[i/2] + (i%2);
    }

    //Return res;
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
    }
}
