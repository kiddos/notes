#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void change(vector<i64>& arr, int l, int r) {
  i64 diff = abs(arr[l] - arr[r]);
  for (int i = l; i <= r; ++i) {
    arr[i] = diff;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << a[0] << endl;
  } else if (n == 2) {
    i64 ans = max(a[0] + a[1], abs(a[0] - a[1]) * 2);
    cout << ans << endl;
  } else if (n == 3) {
    vector<pair<int,int>> possible = {{0, 1}, {0, 1}, {0, 2}, {0, 2}, {1, 2}, {1, 2}};
    i64 ans = a[0] + a[1] + a[2];
    do {
      vector<i64> b = a;
      for (auto [l, r] : possible) {
        change(b, l, r);
        i64 sum = b[0] + b[1] + b[2];
        ans = max(ans, sum);
      }
    } while (next_permutation(possible.begin(), possible.end()));
    cout << ans << endl;
  } else if (n >= 4) {
    i64 max_val = *max_element(a.begin(), a.end());
    i64 ans = max_val * n;
    cout << ans << endl;
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
