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
  string ans;
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      ans.push_back('R');
    }
    if (a[i] > 0) {
      ans.push_back('P');
      for (int k = 1; k < a[i]; ++k) {
        if (i == n-1) {
          ans += "LRP";
        } else {
          ans += "RLP";
        }
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
