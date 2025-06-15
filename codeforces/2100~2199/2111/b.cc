#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool can_fit(int w, int l, int h, int n, vector<int>& f) {
  vector<int> sides = {w, l, h};
  for (int i = n; i >= 1; --i) {
    int size = f[i];
    for (int side : sides) {
      if (side < size) {
        return false;
      }
    }

    int largest_idx = max_element(sides.begin(), sides.end()) - sides.begin();
    sides[largest_idx] -= size;
  }
  return true;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> w(m), l(m), h(m);
  for (int i = 0; i < m; ++i) {
    cin >> w[i] >> l[i] >> h[i];
  }
  vector<int> f = {1, 1};
  for (int i = 2; i <= n; ++i) {
    int s = f.size();
    f.push_back(f[s-1] + f[s-2]);
  }

  vector<bool> ans;
  for (int i = 0; i < m; ++i) {
    ans.push_back(can_fit(w[i], l[i], h[i], n, f));
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i];
  }
  cout << endl;
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
