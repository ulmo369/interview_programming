#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

    STEPS FOR REVERSE A NUMBER:

    n = 123
    while (n)
        1. aux = n%10 //here we take the last number

        2. n = n/10   //here we erase the last number

        (AQUI VAN LAS LIMITANTES DE ESTE PROBLEMA)

        3. res = (res*10) + aux //here we make this (res*10 -> 3 * 10 = 30) + (aux = 2) = 32


    // O(log n) TIME porque vamos dividiendo el numero
    .  O(1) memory
    //------------------------------------------------------
    */
    
    int n = 123456;
    int help;
    int res = 0;
    

    int MAX_ = 2147483647;
    int MIN_ = -2147483648;

    while(n){
        help = n%10;
        n = n/10;
        
        if((res > MAX_/10) or (res == MAX_/10 && help >= MAX_/10 )){
            return 0;
        }
        if((res < MIN_/10) or (res == MIN_/10 && help <= MIN_/10 )){
            return 0;
        }
        
        res = (res * 10) + help;
    }

    return res;
}