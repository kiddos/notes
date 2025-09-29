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
  map<int,int> level;
  level[0]++;

  int i = 1;
  while (i < n) {
    int j = i;
    while (j+1 < n && a[j+1] > a[j]) {
      j++;
    }
    int count = j-i+1;
    auto it = level.begin();
    it->second--;
    level[it->first+1] += count;
    if (it->second == 0) {
      level.erase(it);
    }

    i = j+1;
  }

  int ans = level.rbegin()->first;
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
