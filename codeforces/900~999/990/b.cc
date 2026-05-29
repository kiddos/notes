#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, K = 0;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  int ans = 0;
  for (auto it = count.begin(); it != count.end(); ++it) {
    auto it2 = next(it);
    if (it2 != count.end()) {
      if (it2->first > it->first + K) {
        ans += it->second;
      }
    } else {
      ans += it->second;
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
