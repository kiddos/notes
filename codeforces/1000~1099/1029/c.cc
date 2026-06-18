#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  pair<int,int> max_seg = {0, 1e9};
  pair<int,int> seg = max_seg;
  vector<pair<int,int>> p(n);
  for (int i = 0; i < n; ++i) {
    seg.first = max(seg.first, l[i]);
    seg.second = min(seg.second, r[i]);
    p[i] = seg;
  }

  seg = max_seg;
  vector<pair<int,int>> s(n);
  for (int i = n-1; i >= 0; --i) {
    seg.first = max(seg.first, l[i]);
    seg.second = min(seg.second, r[i]);
    s[i] = seg;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    pair<int,int> left = i > 0 ? p[i-1] : max_seg;
    pair<int,int> right = i+1 < n ? s[i+1] : max_seg;
    pair<int,int> joined = {max(left.first, right.first), min(left.second, right.second)};
    int len = max(joined.second - joined.first, 0); 
    ans = max(ans, len);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
