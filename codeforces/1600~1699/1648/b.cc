#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> s(a.begin(), a.end());
  vector<int> b(s.begin(), s.end());
  vector<i64> d;
  for (int i = 1; i <= c; ++i) {
    if (!s.count(i)) {
      d.push_back(i);
    }
  }

  int size = b.size();
  vector<int> prefix(c+1);
  for (int i = 0; i < size; ++i) {
    prefix[b[i]]++;
  }
  for (int i = 1; i <= c; ++i) {
    prefix[i] += prefix[i-1];
  }

  auto contains = [&](int l, int r) -> bool {
    int count = prefix[min(r-1, c)] - (l > 0 ? prefix[l-1] : 0);
    return count > 0;
  };

  for (int i = 0; i < (int)d.size(); ++i) {
    for (int j = 0; j < size && d[i] * b[j] <= c; ++j) {
      if (contains(d[i] * b[j], (d[i]+1) * b[j])) {
        // cout << "d[i]=" << d[i] << endl;
        // cout << d[i] * b[j] << "~" << (d[i]+1) * b[j] << endl;
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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
