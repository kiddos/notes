#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  vector<int> count(n+1);
  for (int i = 0; i < n; ++i) {
    count[c[i]]++;
  }
  int max_count = *max_element(count.begin(), count.end());
  int ans = n - max_count;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
