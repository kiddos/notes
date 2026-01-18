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
  vector<vector<int>> group(2);
  for (int i = 0; i < n; ++i) {
    group[a[i]%2].push_back(i+1);
  }
  if (group[0].size() > 1) {
    cout << group[1][0] << endl;
  } else {
    cout << group[0][0] << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
