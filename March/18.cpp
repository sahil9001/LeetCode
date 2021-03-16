class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        long long int buy = 0, sell = INT_MIN;
        for (int price: prices) {
            buy = max(buy, sell + price - fee);
            sell = max(sell, buy - price);
        }
        return buy;
    }
};