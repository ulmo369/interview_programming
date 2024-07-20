#include <bits/stdc++.h>
using namespace std;

bool binary_search(const vector<int> &v, int number){

    int left = 0;
    int right = v.size();
    int mid = 0;
    bool found = false;

    while(left <= right){
        mid = left + (right - left) / 2;

        if (v[mid] == number) {
            found = true;
            break;
        }

        if (v[mid] > number) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }


    return found;

}

vector<int> exact_sum(const vector<int> &books_price, int budget){
    int second_number = 0;
    int min_diff = INT_MAX;
    vector<int> result(2,0);

    vector<int> books_price_copy = books_price;
    sort(books_price_copy.begin(), books_price_copy.end());

    for(int i=0; i<books_price.size(); i++){
        second_number = budget - books_price[i];

        if(binary_search(books_price_copy, second_number)){
            int diff_actual = abs(second_number - books_price[i]);

            if(diff_actual < min_diff){
                result[0] = min(books_price[i], second_number);
                result[1] = max(books_price[i], second_number);
                min_diff = diff_actual;
            }
        }
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