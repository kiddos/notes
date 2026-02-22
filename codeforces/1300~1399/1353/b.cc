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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  multiset<int> sa(a.begin(), a.end());
  multiset<int> sb(b.begin(), b.end());
  for (int i = 0; i < k; ++i) {
    int x = *sa.begin();
    int y = *sb.rbegin();
    if (x >= y) {
      break;
    }
    sa.erase(sa.begin());
    sb.erase(prev(sb.end()));
    sa.insert(y);
    sb.insert(x);
  }
  int ans = 0;
  for (int x : sa) {
    ans += x;
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
