#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  set<int> one;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      one.insert(i);
    }
  }

  for (int k = 0; k < q; ++k) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      int s = 0;
      cin >> s;
      if (one.empty()) {
        int sum = n * 2;
        if (s > sum || s % 2 != 0) {
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
        }
      } else {
        int one_count = one.size();
        if (s % 2 != one_count % 2) {
          int s1 = 2 * (*one.rbegin()) - one_count + 1;
          int s2 = 2 * (n - *one.begin() - 1) - one_count + 1;
          if (s > max(s1, s2)) {
            cout << "NO" << endl;
          } else {
            cout << "YES" << endl;
          }
        } else {
          if (s > 2 * n - one_count) {
            cout << "NO" << endl;
          } else {
            cout << "YES" << endl;
          }
        }
      }
    } else if (type == 2) {
      int i = 0, v = 0;
      cin >> i >> v;
      i--;
      one.erase(i);
      a[i] = v;
      if (a[i] == 1) {
        one.insert(i);
      }
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
