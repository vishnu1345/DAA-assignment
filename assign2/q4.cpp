#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
};


bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<Item>& items, int W) {

    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    int currWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currWeight + items[i].weight <= W) {
           
            currWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
           
            int remain = W - currWeight;
            totalProfit += (double)items[i].profit * ((double)remain / items[i].weight);
            break; 
        }
    }

    return totalProfit;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;

    double maxProfit = fractionalKnapsack(items, W);
    cout << "Maximum profit in knapsack: " << maxProfit << endl;

    return 0;
}
