#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int getMaxProfit(vector<int> stockPrices) {
    int buyPoint = 0;
    int sellPoint = 1;
    int maxProfit = 0;

    while (sellPoint < stockPrices.size() && buyPoint < stockPrices.size()) {
        int boughtPrice = stockPrices[buyPoint];
        int soldPrice = stockPrices[sellPoint];

        if (soldPrice < boughtPrice) {
            buyPoint++;
            sellPoint = buyPoint + 1;
            continue;
        } else {
            int profit = soldPrice - boughtPrice;
            if (maxProfit < profit) {
                maxProfit = profit;
            }
            sellPoint++;
        }
    }
    
    return maxProfit;
}

bool verifyMaxProfit(vector<int> stockPrices, int maxProfit) {
    int max = 0;
    for (int i = 0; i < stockPrices.size(); i++) {
        for (int j = i + 1; j < stockPrices.size(); j++) {
            int profit = stockPrices[j] - stockPrices[i];
            if (max < profit) {
                max = profit;
            }
        }
    }

    return max == maxProfit;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    vector<int> stockPrices;

    for (int i = 0; i < 100; i++) {
        stockPrices.push_back(rand());
    }
    
    cout << "stockPrices: ";
    for (auto price : stockPrices) {
        cout << price << ", ";
    }
    cout << endl;
    int maxProfit = getMaxProfit(stockPrices);
    cout << "profit: " << maxProfit << endl;
    cout << "Is the answer correct: " << verifyMaxProfit(stockPrices, maxProfit) << endl;

    return 0;
}
