#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ones = 0, none_ones = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ones++;
    } else {
      none_ones++;
    }
  }
  if (!none_ones) {
    if (ones % 2 == 1) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
  } else {
    if (ones % 2 == 1) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  }
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
