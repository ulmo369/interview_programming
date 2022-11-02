// unordered_set::find
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. We put our two pointers at the BEGINNING and END of the array.
 * 
 * 2. We make the sum and we check if it is equal to the target.
 * 
 *      2.1 If is bigger than the target, we move the END minus one.
 * 
 *      2.2 But if is smaller than the target, we move the BEGINNING plus one.
 * 
 *      2.3. And if is equal to the target, we RETURN the two indexes.
 */

int main ()
{

    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> res;

    int begin = 0;
    int end = numbers.size() - 1;

    while (begin < end){ //IMPORTANTE
        int sum = numbers[begin] + numbers[end];

        if(sum > target){
            end--;
        }
        else if(sum < target){
            begin++;
        }
        else{
            res.push_back(begin + 1);
            res.push_back(end + 1);
            cout << sum <<endl;
            break;
        }
    }


}