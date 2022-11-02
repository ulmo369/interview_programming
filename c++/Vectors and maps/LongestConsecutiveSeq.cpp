// unordered_set::find
#include <bits/stdc++.h>

using namespace std;
#include <unordered_set>

int main ()
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION
    INPUT = [2,5,1,8,3]

    1. We put everything in a SET and we will have everything sorted
        SET = [1,2,3,5,8]

    2. We are going to have also 2 counters
        longest = 0
        count = 0

    3. Then we just go through the SET
        SET = [1,2,3,5,8]

        4. And if a number (n - 1) is already in the set
            5.we add 1 to the counter
        
        6. otherwise
            7. the counter is equal to 1
        
        8. At the end we just check which counter is bigger, longest or count.

    ''''''''''''''''''''

    SET = [1,2,3,5,8]

    9. In our first case 
        1 - 1 = 0, but 0 is not in the SET, so the counter is equal to 1.

    10. in the second case 
        2 - 1 = 1, but 1 is in the SET, so we add 1 to the counter.


    // O(n) en tiempo, porque recorremos una vez
    // O(n) en memoria, porque usamos memoria extra en el set
    //------------------------------------------------------*/
    vector<int> nums = {4,5,6,7};

    set<int> Myset(nums.begin(), nums.end());
    int length = 0;
    int longest = 0;

    for (auto it = Myset.begin(); it != Myset.end(); ++it) {//We go here throught the set
        if(Myset.count(*it - 1)){   // we check if n - 1 is in the SET
            length ++;
        }
        else{
            length = 1;
        }
        longest = max(longest, length); // We check which one is bigger
    }
    cout << "RES = " << longest;
}