// unordered_set::find
#include <bits/stdc++.h>
#include <unordered_set>
#include <map>
using namespace std;

int main ()
{
    /*------------------------------------------------------
    // PRIMERA SOLUCION
        
        RECUERDA QUE VAMOS A MOSTRAR LOS INDICES, NO LOS VALORES

        n = [2, 11, 7, 15]  target = 9

        1. We know that if we substract the target with a number of the vector, then we can find the two numbers
            Example:
                FORMULA -> target - n[0]

                9 - 2 = 7  ... 7 IS IN THE VECTOR

        2. We can use a map
            Where the KEY is the number in the vector
            and the VALUE is the index of the number
        
        3. then in a FOR loop

            4. We check if the substraction is in the map

                    5. If it is in the map, the we push back the indexes

            6. if not

                    7. We insert the value and the index in the map

    // O(n) en tiempo y memoria
    //------------------------------------------------------
    */

    vector<int> nums = {2, 7, 11, 15, 21};
    int target = 9;

    int diff;
    map<int, int> Mymap;
    vector<int> res;

    for (int i = 0; i < nums.size();i++){
        diff = target - nums[i];

        if(Mymap.find(diff) != Mymap.end()){ //También puede ser (Mymap.count(diff) > 0)
            res.push_back(Mymap[diff]);
            res.push_back(i);
            break;
        }
        else{
            Mymap.insert({nums[i], i});
        }
    }

    //return res;

}