#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  multiset<int> left, right;
  for (int i = 0; i < n; ++i) left.insert(a[i]);
  right.insert(*left.rbegin());
  left.erase(prev(left.end()));
  i64 ans = *right.begin();
  int size = 1;
  for (int i = 0; i < n; ++i) {
    int idx = p[i]-1;
    if (left.count(a[idx])) {
      left.erase(left.find(a[idx]));
    } else {
      right.erase(right.find(a[idx]));
    }

    int len = i+2;
    while ((int)right.size() < len && !left.empty()) {
      right.insert(*left.rbegin());
      left.erase(prev(left.end()));
    }

    if ((int)right.size() == len) {
      i64 score = (i64) *right.begin() * len;
      if (score > ans) {
        ans = score;
        size = len;
      }
    }
  }

  cout << ans << " " << size << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}