#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 100000;
constexpr int MOD = 1000000007;

vector<i64> p2(MAX_N+1, 1);
void precompute() {
  for (int i = 1; i <= MAX_N; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }
}

void solve() {
  int t = 0;
  cin >> t;
  vector<int> n(t);
  for (int i = 0; i < t; ++i) {
    cin >> n[i];
  }
  vector<int> k(t);
  for (int i = 0; i < t; ++i) {
    cin >> k[i];
  }

  for (int i = 0; i < t; ++i) {
    cout << p2[k[i]] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  solve();
  return 0;
}
