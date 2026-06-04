#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<int> state(n);
  for (int i = 0; i < n; ++i) {
    state[i] = s[i] - '0';
  }
  int total_on = accumulate(state.begin(), state.end(), 0);

  auto update_state = [&](int t) {
    for (int i = 0; i < n; ++i) {
      if (t - b[i] < 0) {
        continue;
      }
      if ((t - b[i]) % a[i] == 0) {
        total_on -= state[i];
        state[i] = 1-state[i];
        total_on += state[i];
      }
    }
  };

  int ans = total_on;
  for (int t = 1; t <= 5000; ++t) {
    update_state(t);
    ans = max(ans, total_on);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
