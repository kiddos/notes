#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  int m = s[0].length();
  for (int j = 0; j < m; ++j) {
    vector<int> found(10);
    for (int i = 0; i < n; ++i) {
      found[s[i][j]-'0'] = 1;
    }
    int count = accumulate(found.begin(), found.end(), 0);
    if (count > 1) {
      cout << j << endl;
      return;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
