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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  map<int, int> a_count, b_count;
  for (int i = 0; i < n; ++i) {
    a_count[a[i]]++;
    b_count[b[i]]++;
  }

  set<int> s;
  for (auto& [ai, ci] : a_count) {
    for (auto& [bj, cj] : b_count) {
      if (ci > 0 && cj > 0) {
        if (!s.count(ai + bj)) {
          s.insert(ai + bj);
          ci--;
          cj--;
        }
      }
    }
  }

  if (s.size() >= 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
