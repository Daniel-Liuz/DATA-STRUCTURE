#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n < 0) {
       cout << 0 << endl;
        return 0;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    cout << dp[n] << endl;

    return 0;
}
