#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> mins(3), maxs(3);
  for (int i = 0; i < 3; ++i) {
    cin >> mins[i] >> maxs[i];
  }
  vector<int> ans = mins;
  int total = accumulate(ans.begin(), ans.end(), 0);
  int missing = n - total;
  for (int i = 0; i < 3; ++i) {
    int more = maxs[i] - mins[i];
    int take = min(more, missing);
    missing -= take;
    ans[i] += take;
  }
  for (int i = 0; i < 3; ++i) {
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
