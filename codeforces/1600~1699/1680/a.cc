#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
  cin >> l1 >> r1 >> l2 >> r2;

  int ans = 0;
  if (l1 == r1 && l2 == r2) {
    if (l1 == l2) {
      ans = l1;
    } else {
      ans = l1 + l2;
    }
  } else if (l1 == r1) {
    if (l1 >= l2 && l1 <= r2) {
      ans = l1;
    } else {
      ans = l1+l2;
    }
  } else if (l2 == r2) {
    if (l2 >= l1 && l2 <= r1) {
      ans = l2;
    } else {
      ans = l1+l2;
    }
  } else {
    if (l1 >= l2) {
      if (l1 <= r2) {
        ans = l1;
      } else {
        ans = l1 + l2;
      }
    } else {
      if (l2 <= r1) {
        ans = l2;
      } else {
        ans = l1 + l2;
      }
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
