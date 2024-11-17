#include "Header.h"
#include <iostream>

using namespace std;

void enter(int &n, int &W, vector<pair<int, int>> &items) {
    cout << "Nhap so luong do vat va trong luong toi da cua tui: ";
    cin >> n >> W;
    items.resize(n);
    cout << "Nhap trong luong va gia tri cua tung do vat (wi vi):\n";
    for (int i = 0; i < n; i++) {
        cout << "Do vat " << i + 1 << ": ";
        cin >> items[i].first >> items[i].second;
    }
}

void trace_back(int n, int W, vector<vector<int>> &dp, vector<pair<int, int>> &items) {
    vector<int> chosen_items;
    int max_value = dp[n][W];
    int weight = W;
    
    for (int i = n; i > 0; i--) {
        if (dp[i][weight] != dp[i-1][weight]) {
            chosen_items.push_back(i);
            weight -= items[i-1].first;
        }
    }

    cout << "Tong gia tri lon nhat: " << max_value << endl;
    cout << "Cac mon do duoc chon: ";
    sort(chosen_items.begin(), chosen_items.end());
    for (int item : chosen_items) {
        cout << item << " ";
    }
    cout << endl;
}

void solution(int n, int W, vector<pair<int, int>> &items) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i-1].first <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - items[i-1].first] + items[i-1].second);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    trace_back(n, W, dp, items);
}
