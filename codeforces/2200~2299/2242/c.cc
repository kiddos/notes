#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<pair<int,int>> p;
  for (int i = 1; i <= n; ++i) {
    if (count[i] > 0) {
      p.push_back({count[i], i});
    }
  }
  sort(p.begin(), p.end());

  int size = p.size();
  int idx = 0;
  int left = n;
  int ans = 0;
  while (idx < size) {
    int j = idx;
    while (j+1 < size && p[j+1].first == p[j].first) {
      j++;
    }
    int op = p[idx].first - (idx > 0 ? p[idx-1].first : 0);
    int c = size-idx;
    int total_remove = op * c;
    left -= total_remove;

    if (left < k) {
      int to_add = k-left;
      if (to_add % c == 0) {
        ans++;
      }
    }
    // cout << "op=" << op << ", c=" << c << " remove=" << total_remove << ", left=" << left << endl;

    idx = j+1;
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
