// unordered_set::find
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. We put our two pointers at the BEGINNING and END of the array.
 * 
 * 2. We check which number is smallest in the pointers, because if we take the biggest the the water will drop down.
 * 
 * 3. Then we make the operation to check the area of the AREA
 * 
 * 4. And then we can just check if this result of the area is bigger that the last result.
 *  
 *  FOR EXAMPLE:
 *      
 *      the  was LAST AREA RESULT= 20
 *      and the NEW AREA RESULT = 30
 * 
 *      then now we are going to save this new Max Area
 * 
 * 5. And then we just move the pointer that is pointing to the smaller number.
 * 
 * 6. And then we just repeat the process.
 * 
 * @return int 
 */

int main ()
{
    vector<int> numbers = {1,8,6,2,5,4,8,3,7};

    int begin = 0;
    int end = numbers.size() - 1;

    int maxArea = 0;
    int operation = 0;

    while(begin < end){

        operation = min(numbers[begin], numbers[end]) * (end - begin);
        maxArea = max(maxArea, operation);

        if(numbers[begin] <= numbers[end]){
            begin++;
        }
        else{
            end--;
        }

    }

    cout << maxArea <<endl;


}