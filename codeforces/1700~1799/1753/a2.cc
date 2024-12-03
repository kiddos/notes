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

  int sum = 0;
  for (int i = 0, c = 1; i < n; ++i, c = -c) {
    sum += a[i] * c;
  }
  if (sum == 0) {
    cout << "1" << endl;
    cout << "1 " << n << endl;
    return;
  }
  if (sum % 2 != 0) {
    cout << "-1" << endl;
    return;
  }

  vector<pair<int,int>> ans;
  int i = 0;
  while (i < n) {
    int p = i;
    int c = 1;
    while (p < n && a[p] == 0) {
      p++;
      c = -c;
    }
    if (p >= n) break;

    int x = c * a[p];
    int q = p+1;
    c = 1;
    while (q < n && a[q] == 0) {
      q++;
      c = -c;
    }
    int y = c * a[q];

    // cout << i << " " << p << " " << q << " " << x << " " << y << endl;
    if (x + y == 0) {
      ans.emplace_back(i, p);
      ans.emplace_back(p+1, q);
    } else {
      if (i < p) {
        // invert first
        ans.emplace_back(i, i);
        ans.emplace_back(i+1, p);
        ans.emplace_back(p+1, q);
      } else if (p+1 < q) {
        // invert second
        ans.emplace_back(i, p);
        ans.emplace_back(p+1, p+1);
        ans.emplace_back(p+2, q);
      } else if (i == q-1) {
        ans.emplace_back(i, q);
      } else {
        assert(false);
      }
    }

    i = q+1;
  }

  ans.back().second = n-1;

  cout << ans.size() << endl;
  for (auto [l, r] : ans) {
    cout << l+1 << " " << r+1 << endl;
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
