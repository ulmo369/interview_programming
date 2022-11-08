#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {5,9,0,0,0};
    
    bool existed = false;

    int selected = 7;//lo que selecciona el cliente

    for(int i = 0; i < nums.size(); i++){ // for i = 1 to 10
        if(nums[i] == 0){
            if(existed == false){
                nums[i] = selected; //agregamos lo que selecciono el cliente al arreglo
                existed = true;
            }
        }

    }
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << ',';
    }


}