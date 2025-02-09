#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = n+2;
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  map<i64, int> count;
  for (int i = 0; i < m; ++i) {
    count[b[i]]++;
  }

  i64 total = accumulate(b.begin(), b.end(), 0LL);

  auto can_remove = [&](i64 x, i64 y) -> bool {
    if (x == y) {
      return count.count(x) && count[x] >= 2;
    } else {
      return count.count(x) && count.count(y);
    }
  };

  i64 x = -1;
  for (int i = 0; i < m; ++i) {
    i64 prefix2 = total - b[i];
    if (prefix2 % 2 == 0) {
      i64 prefix = prefix2 / 2;
      if (can_remove(prefix, b[i])) {
        x = b[i];
        break;
      }
    }
  }

  if (x < 0) {
    cout << "-1" << endl;
    return;
  }

  i64 prefix = (total - x) / 2;
  vector<i64> a = b;
  auto it = find(a.begin(), a.end(), x);
  if (it == a.end()) {
    cout << "-1" << endl;
    return;
  }
  a.erase(it);
  it = find(a.begin(), a.end(), prefix);
  if (it == a.end()) {
    cout << "-1" << endl;
    return;
  }
  a.erase(it);

  if (accumulate(a.begin(), a.end(), 0LL) != prefix) {
    cout << "-1" << endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
