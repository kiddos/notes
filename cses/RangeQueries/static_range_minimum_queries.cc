#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  int L = ceil(log2(n)) + 1;
  constexpr int inf = 1e9 + 10;
  vector<vector<int>> binary_lift(L+1, vector<int>(n, inf));
  for (int i = 0; i < n; ++i) {
    binary_lift[0][i] = x[i];
  }
  for (int p2 = 1; p2 <= L; ++p2) {
    int len = 1<<(p2-1);
    for (int i = 0; i < n-len; ++i) {
      int j = i + len;
      binary_lift[p2][i] = min(binary_lift[p2-1][i], binary_lift[p2-1][j]);
    }
  }

  auto query = [&](int l, int r) -> int {
    int len = r-l +1;
    int p2 = 0;
    while ((1<<(p2+1)) <= len) {
      p2++;
    }
    int i1 = l, i2 = r-(1<<p2)+1;
    return min(binary_lift[p2][i1], binary_lift[p2][i2]);
  };

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    ans.push_back(query(a, b));
  }
  for (int min_val : ans) {
    cout << min_val << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
