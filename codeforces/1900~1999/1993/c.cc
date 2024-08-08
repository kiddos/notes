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

  auto merge = [&](pair<int,int>& l1, pair<int,int>& l2) -> pair<int,int> {
    if (l1 > l2) {
      swap(l1, l2);
    }
    int diff = l2.first - l1.first;
    int ks = diff / (2 * k);
    l1.first += ks * k * 2;
    l1.second += ks * k * 2;
    if (max(l1.first, l2.first) < min(l1.second, l2.second)) {
      return {max(l1.first, l2.first), min(l1.second, l2.second)};
    }
    l1.first += k * 2;
    l1.second += k * 2;
    if (max(l1.first, l2.first) < min(l1.second, l2.second)) {
      return {max(l1.first, l2.first), min(l1.second, l2.second)};
    }
    return {-1, -1};
  };

  pair<int,int> light = {a[0], a[0] + k};
  for (int i = 1; i < n; ++i) {
    pair<int,int> l2 = {a[i], a[i] + k};
    light = merge(light, l2);
    // cout << light.first << "~" << light.second << endl;
    if (light.first < 0) {
      cout << "-1" << endl;
      return;
    }
  }

  cout << light.first << endl;
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
