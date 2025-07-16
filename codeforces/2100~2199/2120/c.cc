#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0;
  cin >> n >> m;

  i64 max_m = (n+1) * n / 2;
  i64 min_m = n;
  if (m > max_m || m < min_m) {
    cout << "-1" << endl;
    return;
  }

  i64 left = m - n;
  vector<int> chain;
  vector<int> rest;
  for (int node = n; node > 1; --node) {
    int add = node - 1;
    if (left >= add) {
      chain.push_back(node);
      left -= add;
    } else {
      rest.push_back(node);
    }
  }
  chain.push_back(1);
  while (!rest.empty()) {
    chain.push_back(rest.back());
    rest.pop_back();
  }
  cout << chain[0] << endl;
  for (int i = 1; i < (int)chain.size(); ++i) {
    cout << chain[i-1] << " " << chain[i] << endl;
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
