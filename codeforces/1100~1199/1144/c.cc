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
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> inc, dec;
  for (auto& [x, c] : count) {
    if (c > 2) {
      cout << "NO" << endl;
      return;
    }
    if (c <= 2) {
      inc.push_back(x);
    }
    if (c == 2) {
      dec.push_back(x);
    }
  }
  reverse(dec.begin(), dec.end());

  cout << "YES" << endl;
  cout << inc.size() << endl;
  for (int x : inc) cout << x << " ";
  cout << endl;
  cout << dec.size() << endl;
  for (int x : dec) cout << x << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
