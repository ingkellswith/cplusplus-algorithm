# Rod Cutting Problem
## Memoization
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve rod cutting problem using memoization
int rodCuttingMemoization(int n, vector<int>& prices, vector<int>& memo, vector<int>& cuts) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    
    int maxRevenue = 0;
    for (int i = 1; i <= n; ++i) {
        int currentRevenue = prices[i - 1] + rodCuttingMemoization(n - i, prices, memo, cuts);
        if (currentRevenue > maxRevenue) {
            maxRevenue = currentRevenue;
            cuts[n] = i;
        }
    }
    
    memo[n] = maxRevenue;
    return maxRevenue;
}

void printCuts(int n, vector<int>& cuts) {
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
    cout << endl;
}

int main() {
    int n = 4; // Example rod length
    vector<int> prices = {2, 5, 7, 8}; // Example prices

    vector<int> memo(n + 1, -1);
    vector<int> cuts(n + 1, 0);
    int maxRevenue = rodCuttingMemoization(n, prices, memo, cuts);
    
    cout << "Maximum revenue (Memoization): " << maxRevenue << endl;
    cout << "Cuts at lengths: ";
    printCuts(n, cuts);
    return 0;
}
```

## Tabulation
```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve rod cutting problem using tabulation
int rodCuttingTabulation(int n, vector<int>& prices, vector<int>& cuts) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int maxRevenue = 0;
        for (int j = 1; j <= i; ++j) {
            if (maxRevenue < prices[j - 1] + dp[i - j]) {
                maxRevenue = prices[j - 1] + dp[i - j];
                cuts[i] = j;
            }
        }
        dp[i] = maxRevenue;
    }

    return dp[n];
}

void printCuts(int n, vector<int>& cuts) {
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
    cout << endl;
}

int main() {
    int n = 4; // Example rod length
    vector<int> prices = {2, 5, 7, 8}; // Example prices

    vector<int> cuts(n + 1, 0);
    int maxRevenue = rodCuttingTabulation(n, prices, cuts);
    
    cout << "Maximum revenue (Tabulation): " << maxRevenue << endl;
    cout << "Cuts at lengths: ";
    printCuts(n, cuts);
    return 0;
}
```