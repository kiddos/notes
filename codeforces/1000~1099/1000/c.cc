#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  map<i64,int> line;
  for (int i = 0; i < n; ++i) {
    line[l[i]]++;
    line[r[i]+1]--;
  }

  vector<i64> ans(n+1);
  for (auto it = next(line.begin()); it != line.end(); ++it) {
    auto last = prev(it);
    it->second += last->second;
    int covered = last->second;
    i64 point_count = it->first - last->first;
    ans[covered] += point_count;
  }
  for (int k = 1; k <= n; ++k) {
    cout << ans[k] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
