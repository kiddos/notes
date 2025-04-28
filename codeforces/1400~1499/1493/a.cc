#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a;
  for (int i = k+1; i <= n; ++i) {
    a.push_back(i);
  }
  for (int i = k-1; i >= (k+1)/2; --i) {
    a.push_back(i);
  }
  cout << a.size() << endl;
  for (int x : a) {
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
