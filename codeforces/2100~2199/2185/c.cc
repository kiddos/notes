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
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  int size = a.size();
  int i = 0;
  int ans = 0;
  while (i < size) {
    int j = i;
    while (j+1 < size && a[j+1] == a[j]+1) {
      j++;
    }
    int len = j-i+1;
    ans = max(ans, len);
    i = j+1;
  }
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
