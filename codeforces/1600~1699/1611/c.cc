#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  
  if (a[1] == n || a[n] == n) {
    reverse(a.begin()+1, a.end());
    for (int i = 1; i <= n; ++i)  cout << a[i] << " ";
    cout << endl;
  } else {
    cout << "-1" << endl;
  }
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
