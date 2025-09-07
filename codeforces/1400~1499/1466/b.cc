#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[x[i]]++;
  }
  for (auto it = count.begin(); it != count.end(); ++it) {
    if (it->second > 1) {
      count[it->first+1]++;
    }
  }
  int ans = count.size();
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
