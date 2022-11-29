#include <bits/stdc++.h>
using namespace std;

bool isPermutation(vector<int>& count) {
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}


/**
 * @brief 
 * 
 * 1. We will use a hashtable to mark the letters of string1 and string2
 * here we can use a VECTOR
 * 
 * 2. First we mark the first characters of S2 and S1
 * 
 * 3. if (The letters of S2 are the same as S1) {
 *     return true
 * }
 * 
 * 4. If not, we will check the window till we find the permutation
 * 
 * 5. Since we already have checked the first characters, we will move to the next ones
 * for(i = s1.size() till s2.size()){
 *      count[s2[i] - 'a']--; //We mark the character were we are
        count[s2[i - m] - 'a']++; //and we dismark the character that we mark in the other step or the other iteration 
 * }
 * 
 * 6. If we find the permutation we return true
 * 
 * @return int 
 */

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << s1 << " " << s2 << endl;
        int m = s1.size();
        int n = s2.size();
        if (m > n) {//if s1 is bigger then is false
            return false;
        }
        
        vector<int> count(26);
        for (int i = 0; i < m; i++) { 
            count[s1[i] - 'a']++;//We mark which characters are present in s1
            count[s2[i] - 'a']--;//We mark the first characters that are present in s2
        }

        if (isPermutation(count)) {
            cout << "true";
        }
        
        for (int i = m; i < n; i++) {//Since we alreade have checked the first characters, we will move to the next ones
            count[s2[i] - 'a']--; //We mark the character were we are
            count[s2[i - m] - 'a']++; //and we dismark the character that we mark in the other step or the other iteration 

            if (isPermutation(count)) {
                //cout << "TRUE";
            }
        }
        
        //cout << "FALSE";
}