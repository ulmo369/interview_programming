#include <bits/stdc++.h>

using namespace std;

vector<int> sum2(int target, vector<int> &numbers, int current){
    vector<int> res;
    int begin = current;
    int end = numbers.size()-1;

    while (begin < end){ //IMPORTANTE
        int sum = numbers[begin] + numbers[end];

        if(sum > target){
            end--;
        }
        else if(sum < target){
            begin++;
        }
        else{
            res.push_back(numbers[begin] );
            res.push_back(numbers[end] );
            return res;
            break;
        }
    }
    return {0};
}

int main () 
{

    vector<int> nums = {-25, -10, -7, -3, 2, 4, 8, 10};
    int target = -8;


    for(int i = 0; i < nums.size(); i++){
        int newTarget = target - nums[i];
        vector<int> res = sum2(newTarget, nums, i);
        if(res[0] != 0){
            res.push_back(nums[i]);
            cout <<"[" << res[0] << ',' << res[1] << ',' << res[2] << "]" <<endl;
            break;
        }else{
            cout << 1;
            break;
        }
    }
}