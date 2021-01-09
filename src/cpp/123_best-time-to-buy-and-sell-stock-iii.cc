#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 =  -prices[0], sell2 = 0;
        for (int i = 0; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, prices[i] + buy1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, prices[i] + buy2);
        }
        return sell2;
    }
};