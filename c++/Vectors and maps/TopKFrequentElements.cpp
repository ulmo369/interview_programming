#include <bits/stdc++.h>
using namespace std;

/*
    1. Here we can use a SET or a MAP
        (HAZTE PENDEJO EXPLICANDO EL SET)

    2. I think is better a map
        2.1. The KEY can be the number
        2.2. And the VALUE can be how many times that number is in the vector

    3. We know that a MAP is ordered depending of the KEY

    4. So the best thing we can do is push_back all to another vector of vectors

    5. Where the VALUE(how many times the number is in the vector) will be the INDEX and the KEY will be the VECTOR

    6. We will have something like this
    INPUT = [1,1,1,2,2,3,4,4,4]

    MAP         VECTOR
    [1:3]    i = 0    1    2     3
    [2:2]       [[], [3], [2], [1,4]]
    [3:1]
    [4:3]
    
    7. At the end, depending on how many numbers we want we just push_back to the result
*/

int main() {

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
    int k = 2;

    map<int, int> Mymap;
    vector<int> res;

    for(int i=0; i<nums.size(); i++){
        Mymap[nums[i]]++;
    }

    vector<vector<int>> aux(nums.size() + 1);
    for (auto it = Mymap.begin(); it != Mymap.end(); it++) {
        //cout << it->first << " " << it->second << endl;
        aux[it->second].push_back(it->first);
    }


    for(int i = nums.size(); i >= 0; i--) {
        if (res.size() >= k) {
            break;
        }
        if (!aux[i].empty()) {
            res.insert(res.end(), aux[i].begin(), aux[i].end());
        }
    }

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;


    ////////////////////////////////////////////////////////////////////////////////////////////////
    // SOLUCION 2
    
    vector<int> nums = {7,5,4,3,2,1,5,4,3,2,1,5,5,4,1,1,1,2,3,3,2,2,2,2,6,6,6}; //{1,1,1,1,1,1,2,2,2,2,3,3,4,5}
    int k = 5;
    sort(nums.begin(), nums.end()); 

    map<int, vector<int>> Mymap;
    vector<int> res;

    int back = 0;
    int front = 1;

    int key = 0;

    while(front <= nums.size()) {
        //cout << nums[front] << " " << nums[back] << endl;
        if (nums[front] == nums[back]) {
            front++;
            back++;
            key++;
        }else if (nums[front] != nums[back]){
            //cout << nums[back] <<endl;
            key++;
            Mymap[key].push_back(nums[back]);
            //cout << nums[back] <<endl;
            front++;
            back++;
            key = 0;
        }
    }

    cout << "***************************************" <<endl;

    
    for(auto it = Mymap.begin(); it != Mymap.end(); it++) {
        cout << it->first << " ";
        for(int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";
            //res.push_back(it->second[i]);
        }
        cout << endl;
    }
    int count = 0;
    for(auto it = std::prev(Mymap.end()); it != Mymap.begin(); it--) {
        if (res.size() >= k) {
            break;
        }
        for(int t = 0; t < it->second.size(); t++) {
            if (res.size() >= k) {
                break;
            }
            res.push_back(it->second[t]);
            cout << res.size() << " ";   
        }
    }

    for(int i = 0; i < res.size(); i++) {
        //cout << res[i] << ",";
    }
}