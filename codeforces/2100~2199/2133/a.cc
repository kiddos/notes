#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int max_val = *max_element(a.begin(), a.end());
  vector<int> count(max_val+1);
  for (int x : a) {
    count[x]++;
  }

  for (int i = 1; i <= max_val; ++i) {
    if (count[i] >= 2) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
