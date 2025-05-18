#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= k; i++) {
            dp[k] += dp[i - 1] * dp[k - i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}