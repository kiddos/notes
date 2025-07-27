#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  i64 start_h = h[k-1];
  sort(h.begin(), h.end());
  int start_index = find(h.begin(), h.end(), start_h) - h.begin();
  i64 water_height = 1;
  for (int i = start_index+1; i < n; ++i) {
    int require_time = h[i] - h[i-1];
    if (water_height + require_time > h[i-1]+1) {
      cout << "NO" << endl;
      return;
    }
    water_height += require_time;
    if (h[i] == h.back()) {
      break;
    }
  }
  cout << "YES" << endl;
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
