/*
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
vector<int> coins = {1, 3, 4}; // Change this to the denominations of your coins

vector<int> dp;

int solve(int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    int best = INF;
    for (auto c : coins) {
        best = min(best, solve(x-c)+1);
    }
    return dp[x] = best;
}

int main() {
    int x;
    cin >> x;
    dp.resize(x+1, -1);
    cout << solve(x) << endl;
    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
vector<int> coins = {1, 3, 4}; // Change this to the denominations of your coins

vector<int> value, first;

void solve(int n) {
    value.resize(n+1);
    first.resize(n+1);
    value[0] = 0;
    for (int x = 1; x <= n; x++) {
        value[x] = INF;
        for (auto c : coins) {
            if (x-c >= 0 && value[x-c]+1 < value[x]) {
                value[x] = value[x-c]+1;
                first[x] = c;
            }
        }
    }
}

void print_solution(int n) {
    if (n == 0) return;
    cout << first[n] << " ";
    print_solution(n-first[n]);
}

int main() {
    int n;
    cin >> n;
    solve(n);
    cout << value[n] << endl;
    print_solution(n);
    cout << endl;
    return 0;
}
