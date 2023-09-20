#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res;

    int k = 3;

    set<int> mySet;
    int maxN = 0;
    int min = 0;

    for(int i = 0; i < nums.size(); i++){

        mySet.insert(nums[i]);
        min++;

        if(min % 3 == 0){
            maxN = *mySet.rbegin();
            res.push_back(maxN);
            mySet.erase(nums[0]);
        }

    }


    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

}