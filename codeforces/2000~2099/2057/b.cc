#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<pair<int,int>> p(count.begin(), count.end());
  sort(p.begin(), p.end(), [&](auto& p1, auto& p2) {
    return p1.second < p2.second;
  });
  for (int i = 0; i+1 < (int)p.size(); ++i) {
    if (k >= p[i].second) {
      k -= p[i].second;
    } else {
      cout << p.size() - i << endl;
      return;
    }
  }
  cout << "1" << endl;
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
