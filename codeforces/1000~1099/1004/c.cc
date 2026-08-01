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
  vector<int> unique_count(n);
  set<int> s;
  for (int i = n-1; i >= 0; --i) {
    s.insert(a[i]);
    unique_count[i] = s.size();
  }

  s.clear();
  i64 ans = 0;
  for (int i = 0; i < n-1; ++i) {
    if (s.count(a[i])) {
      continue;
    }
    s.insert(a[i]);
    ans += unique_count[i+1];
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
