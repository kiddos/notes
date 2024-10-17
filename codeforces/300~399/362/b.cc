#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> d(m);
  for (int i = 0; i < m; ++i) {
    cin >> d[i];
  }

  sort(d.begin(), d.end());
  if (!d.empty() && (d[0] == 1 || d.back() == n)) {
    cout << "NO" << endl;
    return;
  }

  int i = 0;
  while (i < m) {
    int j = i;
    while (j+1 < m && d[j+1] == d[j] + 1) {
      j++;
    }
    int len = j-i + 1;
    if (len > 2) {
      cout << "NO" << endl;
      return;
    }
    i = j+1;
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
