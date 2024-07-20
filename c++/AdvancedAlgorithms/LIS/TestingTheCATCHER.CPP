#include <bits/stdc++.h>
using namespace std;

int misilesNum = 0;
vector<int> intersections;

void construct(const vector<int>& numbers){
    intersections.clear();
    misilesNum = 0;

    for(int i = 0; i < numbers.size(); i++){
        const int num = numbers[i];

        int pos = upper_bound(intersections.begin(), intersections.end(), num) - intersections.begin();

        if(pos == intersections.size()){
            intersections.push_back(num);
            misilesNum++;
        }
        else{
            intersections[pos] = num;
        }

        if(pos + 1 >= misilesNum){
            misilesNum = pos + 1;
        }
    }

}

int main(){
    vector<int> numbers;

    int T = 1;

    int num;

    string enter = "";

    while (cin >> num, num != -1) {

        numbers.clear();
        numbers.push_back(num);

        while (cin >> num, num != -1){
            numbers.push_back(num);
        }

        reverse(numbers.begin(), numbers.end());
        construct(numbers);

        cout << enter << "Test #" << T++ << ":\n  maximum possible interceptions: " << 
        misilesNum << endl;
        enter = "\n";
    }

}