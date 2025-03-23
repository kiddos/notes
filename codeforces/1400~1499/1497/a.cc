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
  vector<int> count(101);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (!count[i]) {
      break;
    }
    count[i]--;
    ans.push_back(i);
  }
  for (int i = 0; i <= 100; ++i) {
    while (count[i]-- > 0) {
      ans.push_back(i);
    }
  }
  for (int x: ans) {
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
