#include <bits/stdc++.h>
using namespace std;

vector<int> exact_sum(const vector<int> &books_price, int budget){
    int second_number = 0;
    int min_diff = INT_MAX;
    vector<int> result(2,0);
    unordered_map<int, int> book_dict;


    for(int i=0; i<books_price.size(); i++){
        second_number = budget - books_price[i];

        if(book_dict.find(second_number) != book_dict.end()){
            int diff_actual = abs(second_number - books_price[i]);

            if(diff_actual < min_diff){
                result[0] = min(books_price[i], second_number);
                result[1] = max(books_price[i], second_number);
                min_diff = diff_actual;
            }
        }
        book_dict[books_price[i]] = i + 1;
    }

    return result;
}

int main() {

    int n;

    while (cin >> n) {
        vector<int> book_prices(n);

        for (int i = 0; i < n; ++i) {
            cin >> book_prices[i];
        }

        int budget;
        cin >> budget;

        vector<int> result = exact_sum(book_prices, budget);

        cout << "Peter should buy books whose prices are " << result[0] << " and " << result[1] << "." << endl;
        cout << endl;
    }

    return 0;
}