#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_bits(int x) {
  vector<int> bits;
  for (int b = 0; b < 31; ++b) {
    if (x & (1<<b)) {
      bits.push_back(b);
    }
  }
  return bits;
}

void solve() {
  i64 u = 0, v = 0;
  cin >> u >> v;

  vector<int> u_bits = get_bits(u);
  vector<int> v_bits = get_bits(v);

  if (v_bits.size() > u_bits.size()) {
    cout << "NO" << endl;
    return;
  }
  if (v < u) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 0, j = 0; i < (int)v_bits.size(); ++i) {
    int count = 0;
    if (j < (int)u_bits.size() && u_bits[j] <= v_bits[i]) {
      j++;
      count++;
    }
    if (count == 0) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
