#include <bits/stdc++.h>
using namespace std;


int main (){
    string s = "pwquikwhjkelmlbvcxzasnwwwwwww";

    unordered_set<char> letters; //We need somethig to store our repeat characters, a SET is a good choice
                                 //because it is fast to check if a character is in the set or not
    int back = 0;
    int front = 0;

    string longest = ""; //This is the string that we are going to return
    string actual = ""; //This is the actual string that we are going to check

    while (front < s.size()) {                         //We just keep moving till we finish our string

        if (letters.find(s[front]) == letters.end()) { //If the letter is not in the set

            letters.insert(s[front]);                 //We add it to the set
            actual += s[front];                       //We add it to the actual string
            
            if(actual.size() > longest.size()){       //We check if the actual string is longer than the longest
                longest = actual;                    //If it is, we update the longest string
            }
            front++;                                    //We move one step the front pointer

        } else {

            letters.erase(s[back]);         //We remove the letter from the set
            actual.erase(actual.begin());   //We remove the letter from the actual string
            back++;                        //We move one step the back pointer

        }
        cout << " result: " << longest << endl;

    }

    cout << longest << endl;

}