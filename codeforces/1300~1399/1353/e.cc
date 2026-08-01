#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int make_consecutive(const string& s) {
  int n = s.length();
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += s[i] == '1';
  }

  int window = 0;
  int min_window = 0;
  for (int i = 0; i < n; ++i) {
    int w = s[i] == '0' ? 1 : -1;
    window = min(w, window + w);
    min_window = min(min_window, window);
  }
  return total + min_window;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  int total_one = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      total_one++;
    }
  }

  int ans = n;
  for (int i = 0; i < k; ++i) {
    int ones = 0;
    string t;
    for (int j = i; j < n; j += k) {
      t.push_back(s[j]);
      ones += s[j] == '1';
    }
    int result = make_consecutive(t);
    int remove_ones = total_one - ones;
    ans = min(ans, result + remove_ones);
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
