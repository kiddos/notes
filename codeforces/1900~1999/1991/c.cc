#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> ans;
  set<i64> s(a.begin(), a.end());
  int k = 0;
  while ((s.size() > 1 || *s.begin() != 0) && k++ < 40) {
    i64 largest = *s.rbegin();
    i64 smallest = *s.begin();
    i64 diff = largest - smallest;
    if (diff % 2 == 1) {
      cout << "-1" << endl;
      return;
    }
    i64 middle = (largest + smallest) / 2;

    set<i64> s2;
    for (i64 val : s) {
      s2.insert(abs(val - middle));
    }
    ans.push_back(middle);
    s = std::move(s2);
  }

  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << " ";
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
