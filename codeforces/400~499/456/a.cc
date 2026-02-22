#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  map<int, vector<int>> laptops;
  for (int i = 0; i < n; ++i) {
    laptops[a[i]].push_back(b[i]);
  }

  multiset<int> bs(b.begin(), b.end());
  for (auto [ai, b_list] : laptops) {
    for (int bi : b_list) {
      bs.erase(bs.find(bi));
    }
    for (int bi : b_list) {
      auto it = bs.upper_bound(bi);
      if (it != bs.begin()) {
        cout << "Happy Alex" << endl;
        return;
      }
    }
  }
  cout << "Poor Alex" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
