#include <bits/stdc++.h>
using namespace std;

/**
 * 1. We can search the biggest substring with the maximum amount of the same character
 *      
 *      EXAMPLE: "ABABBA" k = 2
 *      here we know that "A[BABBA]" is the biggest substring
 *      and 'B' is most repeated character.
 *  
 *  But how we can do that? 
 * 
 * 2. First we need somehwere to store the counter of each letter
 *      Here we can use a VECTOR or a MAP
 * 
 * 3. Then we will check if the susbstring is valid
 *      LIKE THIS...
 *  
 *      if the (size of the substring) - (most repeated character) <= k {
 *          
 *          Our RESULT will be now the size of the susbstring
 *          
 *          And then we move one step
 * 
 *      }
 * 
 * 4. Maybe we can use two pointers
 *  
 *      - With the first one we check the front letters
 * 
 *      - And with the second one, if the susbstring is not valid we move this pointer one step.
 *        and in the counter of our letters we take 1 away from the letter where this pointer was.
 * 
 * 
 * Memory O(26) Because we store the counters of the 26 letters of the alphabet
 * time O(n)
 * 
 * 
 * @return int 
 */

int main() {
    string s = "ABABBA"; 
    int k = 1;

    int first = 0;
    int second = 0;

    int maxLetter = 0;
    vector<int> letters(26); // Int because we will use the ASCII

    int res = 0;

    while(first < s.size()) {
        letters[s[first] - 'A']++; // We transform the letter into a number from 1 to 26. A = 0, B = 1 ...

        maxLetter = max(maxLetter, letters[s[first] - 'A']); // We check if the letter where we are is the biggest one

        if(first - second + 1 - maxLetter > k){ // if the substring is not valid
            letters[s[second] - 'A']--; // We take away that letter
            second++; // We move the second pointer
        }
        res = max(res, first - second + 1); // The result will be the distance of the susbtring between first and second point 
        first++;
    }

    cout << res<< endl;

}