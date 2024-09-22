#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_A = 300000;
vector<int> x(MAX_A+1);
void precompute() {
  for (int i = 1; i <= MAX_A; ++i) {
    x[i] = x[i-1] ^ i;
  }
}

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  // must have 0...a-1 (a numbers)
  // so xor value now = 1 ^ 2 ^ 3 ... ^ a-1
  // but we need b
  // if xor value is already b, then don't need anything else
  // if the number we need is a, then we will need another value
  // else just use that
  int xor_val = x[a-1];
  int ans = a;
  if (xor_val == b) {
    cout << ans << endl;
  } else if ((xor_val ^ b) == a) {
    cout << ans+2 << endl;
  } else {
    cout << ans+1 << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
