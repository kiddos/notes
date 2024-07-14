#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_A = 10000;
constexpr int MAX_B = 10000;
constexpr int MAX_N = 100;

vector<vector<pair<int,int>>> results(MAX_N+1);

void precompute() {
  for (int n = 1; n <= 100; ++n) {
    string s = to_string(n);
    int len = s.length();
    for (int a = 1; a <= MAX_A; ++a) {
      int max_b = len * a - 1;
      int min_b = len * a - 6;
      for (int b = max(min_b, 1); b <= min(max_b, MAX_B); ++b) {
        int result = n * a - b;
        int total_len = len * a - b;
        string s2 = s;
        int i = 0;
        while ((int)s2.length() < total_len) {
          s2.push_back(s[(i++) % s.length()]);
        }
        if (result == stoi(s2)) {
          results[n].push_back({a, b});
        }
      }
    }
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>>& ans = results[n];
  cout << ans.size() << endl;
  for (auto& [a, b] : ans) {
    cout << a << " " << b << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
