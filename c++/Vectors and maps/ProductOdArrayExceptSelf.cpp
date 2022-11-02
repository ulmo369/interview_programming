// unordered_set::find
#include <bits/stdc++.h>

using namespace std;
#include <unordered_set>

int main ()
{
    /*------------------------------------------------------------------------------
    // PRIMERA SOLUCION

        1. This one is not that difficult

        2. We can just multiply everything going ones to the left and another one to the right

        3. For example, we can have a "GOING" variable
            int going = 1; // the value is one because 0 will always 0 in a multiplication

        4. Then...
            
            WE know that our INPUT is this one
            nums = [1,2,3,4] 
            
            And in our index we are going to asign the GOING variable to the result, like this
            i = 0
                [1,0,0,0] //SIZE OF OUR INPUT

                then we multiply the GOING variable by the value in the INPUT
                going = going * nums[i] = 1
            
            and we can repeat that with all the other numbers
            i = 1
                [1,1,0,0] //SIZE OF OUR INPUT

                then we multiply again
                going = going * nums[i] = 2
            .
            .
            .
            at the end we are going to have something like this
            PIENSA TANTITO Y ESCRIBELO LENTO

            We know we have this
            [1,1,0,0]
            and the value of GOING is 2

            So the next ones will be like this [1,1,2,0]

            PIENSA Y TARDATE

            The last one something like this [1,1,2,6]

        5. The next step will quiet the same, but from the end to the beginning

            we will another variable like GOING, but this time we are going to call it RETURNING
            int returning = 1;

            and we do the same steps, but when we are asigning the value to the result vector
            we multiply the value of the result vector by the varible RETURNING.


    // O(n) en tiempo, porque recorremos una vez
    // O(1) en memoria, porque no usamos memoria extra, solo en el prefix y postfix
    //------------------------------------------------------------------------------
    */
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> res(nums.size());

    int going = 1;

    for (int i = 0; i < nums.size(); i++){ //We start from the beginning to the end
        res[i] = going; // We asign the going variable to the result vector
        going = going * nums[i]; // and we multiply
    }

    int returning = 1;
    for (int i = nums.size() - 1; i >= 0; i--){ //then from the end to the beginning
        res[i] = res[i] * returning; //This is the inly change that we said, we multiply the returning value by the result value
        returning = returning * nums[i]; // and we multiply
    }

    for (int i = 0; i < nums.size(); i++){
        cout << res[i] << ", ";
    }

}