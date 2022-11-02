#include <bits/stdc++.h>

using namespace std;

/**
 * 1. We put our two pointers at the BEGINNING and END of the array.
 * 
 * 2. Then we check if the character in the pointers are same or not.
 * 
 * 3. BUT THERE IS SOMETHING IMPORTANT! if we found a symbol or a space, we have to ignore it.
 * 
 *      3.1. So, if we found something like that we just keep moving that pointer.
 */

int main () 
{
    string s = "A man, a plan, a canal: Panama";

    int point1 = 0;
    int point2 = s.size() - 1;

    while (point1 < point2){

        while (!isalnum(s[point1]) && point1 < point2) {//checamos si point1 es un caracter alfanumerico
            point1++;
        }
        while (!isalnum(s[point2]) && point1 < point2) {//checamos si point2 es un caracter alfanumerico
            point2--;
        }
        if (tolower(s[point1]) != tolower(s[point2])) {//checamos si los caracteres son diferentes
            return false;
        }
        point1++;
        point2--;
    }
    return true;

}