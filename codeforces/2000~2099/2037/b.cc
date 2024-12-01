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

  int size = n-2;
  unordered_set<int> s;
  for (int i = 0; i < n; ++i) {
    if (size % a[i] == 0 && s.count(size / a[i])) {
      cout << a[i] << " " << size / a[i] << endl;
      return;
    } 
    s.insert(a[i]);
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
