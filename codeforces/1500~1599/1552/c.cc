#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
  }

  int m = n * 2;
  vector<int> connected_to(m+1);
  for (int i = 0; i < k; ++i) {
    connected_to[x[i]] = y[i];
    connected_to[y[i]] = x[i];
  }

  vector<int> end_points;
  for (int i = 1; i <= m; ++i) {
    if (!connected_to[i]) {
      end_points.push_back(i);
    }
  }
  int size = end_points.size();
  int half = size / 2;
  for (int i = 0; i < half; ++i) {
    int p1 = end_points[i];
    int p2 = end_points[i+half];
    connected_to[p1] = p2;
    connected_to[p2] = p1;
  }

  int ans = 0;
  for (int start = 1; start <= m; ++start) {
    int end = connected_to[start];
    for (int p = start+1; p < end; ++p) {
      int p2 = connected_to[p];
      if (p2 > end) {
        ans++;
      }
    }
  }
  cout << ans << endl;
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
