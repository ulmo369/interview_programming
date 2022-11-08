#include <bits/stdc++.h>
using namespace std;

/**
 * 1. We go through the array and we start saving which number is the smallest.
 * 
 *          EXAMPLE with [7,1,5,3,6,4]
 *          The smallest number is 1
 * 
 * 2. Then we save the biggest difference between the smallest number and the current number, to see the biggest profit.
 * 
 *          EXAMPLE with [7,1,5,3,6,4]
 *          The biggest number is 6
 *          So the biggest difference is 5
 * 
 * TIME o(n)
 * space o(1)
 */

int main() {

    vector<int> prices = {7,1,5,3,6,4};

    int least = prices[0];
    int profit = 0;

    for(int i = 0; i < prices.size(); i++){
        least = min(least, prices[i]);              // We save the smallest number
        profit = max(profit, prices[i] - least);    // We make a substraccion between the current number and the smallest number
                                                    // To see the biggest profit
    }

    cout << profit;

}