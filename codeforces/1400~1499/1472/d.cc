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
  vector<vector<int>> vals(2);
  for (int i = 0; i < n; ++i) {
    vals[a[i] % 2].push_back(a[i]);
  }
  for (int p = 0; p < 2; ++p) {
    sort(vals[p].begin(), vals[p].end());
  }
  i64 balance = 0;
  for (int i = 0; i < n; ++i) {
    vector<int>& even = vals[0];
    vector<int>& odd = vals[1];
    int e = even.empty() ? 0 : even.back();
    int o = odd.empty() ? 0 : odd.back();
    if (i % 2 == 0) {
      // alice
      if (e >= o) {
        balance += e;
        if (!even.empty()) {
          even.pop_back();
        }
      } else {
        if (!odd.empty()) {
          odd.pop_back();
        }
      }
    } else {
      // bob
      if (o >= e) {
        balance -= o;
        if (!odd.empty()) {
          odd.pop_back();
        }
      } else {
        if (!even.empty()) {
          even.pop_back();
        }
      }
    }
  }
  if (balance == 0) {
    cout << "Tie" << endl;
  } else if (balance > 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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
