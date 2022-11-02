#include <bits/stdc++.h>
using namespace std;

/*
    1. Here we can use a SET or a MAP
        (HAZTE PENDEJO EXPLICANDO EL SET)

    2. I think is better a map
        2.1. The KEY can be the number
        2.2. And the VALUE can be how many times that number is in the vector

    3. We know that a MAP is ordered dependinf of the KEY

    4. So the best thing we can do is push_back all to another vector of vectors

    5. Where the KEY will be the INDEX

    6. We will have something like this
    INPUT = [1,1,1,2,2,3,4,4,4]

    MAP         VECTOR
    [1:3]    i = 0    2    3     4
    [2:2]       [[], [3], [2], [1,4]]
    [3:1]
    [4:3]
    
    7. At the end, depending on how many numbers we want we just push_back to the result

*/

int main() {

    vector<int> nums = {1,2,3,4};
    int k = 3;

    map<int, int> Mymap;
    vector<int> res;

    for(int i=0; i<nums.size(); i++){
        Mymap[nums[i]]++;
    }

    vector<vector<int>> aux(nums.size() + 1);
    for (auto it = Mymap.begin(); it != Mymap.end(); it++) {
        cout << it->first << " " << it->second << endl;
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

    return 0;
}