#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {5,9,1,2,3,5};

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

    cout << endl;

    nums.assign(nums.size(), 0);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }


}