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

  array<int,3> ans = {numeric_limits<int>::max(), -1, -1};
  map<int,int> count;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && (int)count.size() < k) {
      count[a[j]]++;
      j++;
    }
    if ((int)count.size() == k) {
      int len = j-i;
      array<int,3> result = {len, i+1, j};
      ans = min(ans, result);
    }
    if (--count[a[i]] == 0) {
      count.erase(a[i]);
    }
  }

  cout << ans[1] << " " << ans[2] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
