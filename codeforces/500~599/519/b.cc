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
  vector<int> b(n-1);
  for (int i = 0; i < n-1; ++i) {
    cin >> b[i];
  }
  vector<int> c(n-2);
  for (int i = 0; i < n-2; ++i) {
    cin >> c[i];
  }

  multiset<int> s(a.begin(), a.end());
  for (int i = 0; i < n-1; ++i) {
    s.erase(s.find(b[i]));
  }
  int ans1 = *s.begin();
  s = multiset<int>(a.begin(), a.end());
  for (int i = 0; i < n-2; ++i) {
    s.erase(s.find(c[i]));
  }
  s.erase(s.find(ans1));
  int ans2 = *s.begin();
  cout << ans1 << endl;
  cout << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
