#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0, pos = 0;
  cin >> n >> x >> pos;
  int left = 0, right = n;
  int larger = n-x, smaller = x-1;
  i64 ans = 1;
  constexpr int MOD = 1e9 + 7;
  while (left < right) {
    int mid = (left + right) / 2;
    if (pos == mid) {
      left = mid + 1;
      break;
    } else if (pos < mid) {
      // use larger number
      ans *= larger;
      ans %=MOD;
      larger--;
      right = mid;
    } else if (pos > mid) {
      // use smaller number
      ans *= smaller;
      ans %= MOD;
      smaller--;
      left = mid + 1;
    }
  }

  // cout << "ans=" << ans << endl;
  // cout << "larger=" << larger << ",smaller=" << smaller << endl;
  // cout << "left=" << left << ", right=" << right << endl;
  // cout << "need larger=" << need_larger << endl;

  while (left < right) {
    int mid = (left + right) / 2;
    right = mid;
    ans *= larger;
    ans %= MOD;
    larger--;
  }

  int rest = larger + smaller;
  for (;rest >= 1; --rest) {
    ans *= rest;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
