#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_VAL = 1e7;
vector<int> min_div(MAX_VAL+1);

void precompute() {
  iota(min_div.begin(), min_div.end(), 0);

  for (int i = 2; i <= MAX_VAL; ++i) {
    if (min_div[i] != i) continue;

    for (int j = i*2; j <= MAX_VAL; j += i) {
      min_div[j] = i;
    }
  }
}

void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  int diff = y-x;
  if (diff == 1) {
    cout << "-1" << endl;
    return;
  }

  int z = diff;
  vector<int> div;
  while (z > 1) {
    if (div.empty() || div.back() != min_div[z]) {
      div.push_back(min_div[z]);
    }
    z /= min_div[z];
  }

  int ans = numeric_limits<int>::max();
  for (int d : div) {
    int c = (x + d - 1) / d;
    ans = min(ans, c * d - x);
  }
  cout << ans << endl;
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
