#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AllToCero(vector<vector<int>> &matrix){
    vector<vector<int>> res = matrix;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){

            if(matrix[i][j] == 0){
                res[i].assign(matrix[i].size(), 0);
                int k = 0;
                while(k < matrix.size()){
                    res[k][j] = 0;
                    k++;
                }
            }

        }
    }

    return res;
}

int main() {
    vector<vector<int>> matrix = {
    {5, 4, 3, 9},
    {2, 0, 7, 6},
    {1, 3, 4, 0},
    {9, 8, 3, 4}
    };

    cout << "Original matrix: " << endl;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Result matrix: " << endl;
    vector<vector<int>> res = AllToCero(matrix);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}