#include <bits/stdc++.h>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& p) {
  for (int i = 0; i < p.size(); ++i) {
    os << p[i] << " ";
  }
  return os;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);

  cout << n << endl;
  cout << p << endl;
  swap(p[0], p[1]);
  cout << p << endl;

  for (int i = 2; i < n; ++i) {
    swap(p[i], p[i-1]);
    cout << p << endl;
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
