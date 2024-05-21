#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int x) {
  cout << "? " << l << " " << x << endl;
  int r = 0;
  cin >> r;
  return r;
}

void answer(int m) {
  cout << "! " << m << endl;
  int result = 0;
  cin >> result;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  auto find_max_val = [&]() -> int {
    for (int x = 1; x <= n; ++x) {
      int result = query(1, x * n);
      if (result == n) {
        return x;
      }
    }
    return -1;
  };

  auto check_split = [&](int x) -> bool {
    int l = 1;
    for (int s = 0; s < k; ++s) {
      if (l > n) {
        return false;
      }
      int r = query(l, x);
      if (r == n+1) {
        return false;
      }
      l = r+1;
    }
    return l == n+1;
  };
  
  int max_val = find_max_val();
  for (int mul = 1; mul <= n / k; ++mul) {
    if (check_split(max_val * mul)) {
      answer(max_val * mul);
      return;
    }
  }

  answer(-1);
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
