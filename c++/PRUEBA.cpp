#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 10;
    int ans = 0, remainder, i = 0;

    // Until the value of n becomes 0.
    while(n != 0){
        remainder = n % 10;    
        ans += remainder * pow(2, i);
        i++; 

        // Remove the rightmost digit of n.
        n = n / 10;
    }
    cout << ans;
}