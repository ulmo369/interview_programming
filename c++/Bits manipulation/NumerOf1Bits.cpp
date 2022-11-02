#include <bits/stdc++.h>

using namespace std;

int main () 
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION

    1. We check the last number with n%2 (module) and we add it to the result
    2. We move one to the left with n = n >> 1
    3. This until we finish the number

    // O(32) = O(1) porque recorremos nomas 1 vez el numero
    //------------------------------------------------------
    */

    long long int n = 0111101;
    int res = 0;
    int res2 = 0;

    while (n > 0){
        res = res + n % 2; // Aqui le sacamos el modulo para saber si el numero en el que estamos es 0 o 1
        n = n >> 1; // Aqui lo movemos un numero a la izquierda = 0101'0'1
    }
    
    cout << res << endl;

    //--------------------------------------------------------
    // SEGUNDA SOLUCION
    // O(32) = O(1) porque recorremos nomas 1 vez el numero
    //--------------------------------------------------------

    long long int n2 = 0111101;
    while (n2){
        n2 = n2 & (n2 - 1); // Aqui sacamos un AND logico al numero con el mismo menos 1
                            // 001101 & (001101 - 1) = 001101 & 001100 = 001100
        res2 ++;
    }
    
    cout << res2 << endl;
}
