#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

unordered_map<string, int> indices;

void precompute() {
  int i = 1;
  for (char c1 = 'a'; c1 <= 'z'; ++c1) {
    for (char c2 = 'a'; c2 <= 'z'; ++c2) if (c2 != c1) {
      string s;
      s.push_back(c1);
      s.push_back(c2);
      indices[s] = i++;
    }
  }
}

void solve() {
  string s;
  cin >> s;
  cout << indices[s] << endl;
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
