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
  vector<int> min_index(n+1, n), max_index(n+1, -1);
  for (int i = 0; i < n; ++i) {
    min_index[a[i]] = min(min_index[a[i]], i);
    max_index[a[i]] = max(max_index[a[i]], i);
  }

  int l = n, r = -1;
  vector<int> line(n+2);
  for (int i = 1; i <= n; ++i) {
    l = min(l, min_index[i]);
    r = max(r, max_index[i]);
    int len = r-l+1;
    if (len > i) {
      cout << "0" << endl;
      return;
    }

    // cout << "i=" << i << ",len=" << len << ", " << r-i+1 << "~" << l+i-1 << endl;
    line[max(r-i+1, 0)]++;
    line[min(l+i, n+1)]--;
  }
  int size = line.size();
  for (int i = 1; i < size; ++i) {
    line[i] += line[i-1];
  }
  int ans = 0;
  for (int i = 0; i < size; ++i) {
    if (line[i] == n) {
      ans++;
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
