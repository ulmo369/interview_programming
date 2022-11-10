#include <bits/stdc++.h>
using namespace std;

/**
 * 1. We need somethig to store our repeat characters, a SET is a good choice
 *    because it is fast to check if a character is in the set or not
 * 
 *    We also need a way to track everything, so we are using 2 kind of pointers
 *    one for the back and one to check the current character.
 *    So if we see that a letter is repeated on the SET, we just erase the letter of the back pointer that we already checked.
 *    because we want to keep cheacking with out losing the other letters that we already checked.
 * 
 *    EXAMPLE: "dvdf"
 * 
 * 2. We go through our string
 * 
 * 3. if the character IS NOT in the SET
 * 
 *      3.1. we add it to the SET
 *      3.2. We check distance between the 2 pointers
 *      3.3. We move one step the front pointer
 * 
 *      s[0] = d // d is not in the set, we add it
 *               // distance = 1 (front - back = 1)
 * 
 *      s[1] = v // v is not in the set, we add it
 *               // distance = 2 (front - back = 2)
 * 
 *      s[2] = f // f is not in the set, we add it
 *               // distance = 3 (front - back = 3)
 * 
 * 
 * 4. if the character IS IN the SET
 * 
 *     4.1. We remove the character of the BACK POINTER from the SET
 *     4.2. We move one step the back pointer
 * 
 *     s[2] = d // d is in the set, we remove the letter of the back pointer
 *             // we move the back pointer one step, back = 1
 * 
 * @return int 
 */

int main (){
    string s = "dvdf";

    unordered_set<char> letters;
    int back = 0;
    int front = 0;

    int distance = 0;

    while (front < s.size()) {                         //We just keep moving till we finish our string

        if (letters.find(s[front]) == letters.end()) { //If the letter is not in the set

            letters.insert(s[front]);                  //We add it to the set
            distance = max(distance, front - back + 1);//We can check the distance between the 2 pointers and keep the max
            cout << "front: " << s[front];
            front++; //We move one step the front pointer

        } else {

            letters.erase(s[back]);         //We remove the letter from the set
            cout << "back: " << s[back];
            back++;                        //We move one step the back pointer

        }
        cout << " result: " << distance << endl;

    }

    cout << distance << endl;

}