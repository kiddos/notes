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
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<int> b;
  for (auto [p, c] : count) {
    for (int k = 0; k < c/2; ++k) {
      b.push_back(p);
    }
  }
  if (b.size() < 4) {
    cout << "NO" << endl;
    return;
  }

  vector<int> p = {b[0], b[1], b[b.size()-2], b[b.size()-1]};
  cout << "YES" << endl;
  cout << p[0] << " " << p[1] << " "
    << p[0] << " " << p[3] << " "
    << p[2] << " " << p[1] << " "
    << p[2] << " " << p[3] << endl;
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
