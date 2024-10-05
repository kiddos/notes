#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<vector<int>> p;
vector<vector<vector<int>>> indices(5);
void precompute() {
  vector<int> c;
  function<void(int)> generate = [&](int i) {
    if (c.size()) {
      p.push_back(c);
    }
    for (int j = i; j < 4; ++j) {
      c.push_back(j);
      generate(j+1);
      c.pop_back();
    }
  };

  generate(0);
  for (vector<int>& c : p) {
    indices[c.size()].push_back(c);
  }
}

void solve() {
  int k = 0, l = 0, m = 0, n = 0, d = 0;
  cin >> k >> l >> m >> n >> d;
  vector<int> divs = {k, l, m, n};

  auto compute_n = [&](int size) -> int {
    int total = 0;
    for (vector<int>& idx : indices[size]) {
      int x = divs[idx[0]];
      for (int j : idx) {
        x = lcm(x, divs[j]);
      }
      total += d / x;
    }
    return total;
  };

  int ans = compute_n(1) - compute_n(2) + compute_n(3) - compute_n(4);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  solve();
  return 0;
}
