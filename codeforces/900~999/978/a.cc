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
  set<int> found;
  vector<int> ans;
  for (int i = n-1; i >= 0; --i) {
    if (!found.count(a[i])) {
      ans.push_back(a[i]);
      found.insert(a[i]);
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
