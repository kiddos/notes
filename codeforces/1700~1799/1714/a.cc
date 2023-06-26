#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, H = 0, M = 0;
  cin >> n >> H >> M;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    int h = 0, m = 0;
    cin >> h >> m;
    t[i] = h * 60 + m;
  }

  int T = H * 60 + M;
  sort(t.begin(), t.end());
  auto it = lower_bound(t.begin(), t.end(), T);
  if (it == t.end()) {
    int diff = *t.begin() + 1440 - T;
    cout << diff / 60 << " " << diff % 60 << endl;
  } else {
    int diff = *it - T;
    cout << diff / 60 << " " << diff % 60 << endl;
  }
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
