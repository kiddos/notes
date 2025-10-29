#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<pair<int,int>> interval;
  for (int i = 0; i < n; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    interval.emplace_back(a, b);
  }

  multiset<int> members;
  for (int i = 0; i < k; ++i) {
    members.insert(i);
  }

  sort(interval.begin(), interval.end(), [&](auto& i1, auto& i2) {
    return i1.second < i2.second;
  });

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [a, b] = interval[i];
    auto it = members.upper_bound(a);
    if (it != members.begin()) {
      --it;
      members.erase(it);
      members.insert(b);
      ans++;
    }
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
