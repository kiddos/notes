#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0, n = 0;
  cin >> x >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  set<int> pos = {0, x};
  map<int,int> lengths = {{x, 1}};
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    auto it = pos.lower_bound(p[i]);
    int right = *it, left = *prev(it);
    int original_length = right - left;
    if (--lengths[original_length] == 0) {
      lengths.erase(original_length);
    }
    int len1 = p[i] - left, len2 = right - p[i];
    lengths[len1]++;
    lengths[len2]++;
    pos.insert(p[i]);
    ans.push_back(lengths.rbegin()->first);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
