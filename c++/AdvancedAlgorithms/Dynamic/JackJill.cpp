#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase = 0;
    int route = 0;
    int Nstations;
    int station;

    cin >> testcase;

    while(testcase--){
        cin >> Nstations;
        int aux = 1;
        int start = 10000000;
        int end;
        int sum = 0;
        int ans = 0;

        for (int i = 2; i <= Nstations; i++){
            cin >> station;
            sum += station;

            if (sum < 0){
                sum = 0;
                aux = i;
            }

            if(sum >= ans){
                if(sum > ans || (sum == ans && (i - aux > end - start))){
                    start = aux;
                    end = i;
                }
                ans = sum;
            }
        }
        if (ans > 0){
            cout << "The nicest part of route " << ++route << " is between stops " << start << " and " << end << endl;
        }else{
            cout << "Route " << ++route << " has no nice parts" << endl;
        }
    }
}