#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_X = 200000;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  i64 a_sum = accumulate(a.begin(), a.end(), 0LL);
  vector<bool> a_pos(MAX_X+1), a_neg(MAX_X+1);
  for (int i = 0; i < n; ++i) {
    i64 key = a_sum - a[i];
    if (key >= 0 && key <= MAX_X) {
      a_pos[key] = true;
    }
    if (key >= -MAX_X && key <= 0) {
      a_neg[-key] = true;
    }
  }

  i64 b_sum = accumulate(b.begin(), b.end(), 0LL);
  vector<bool> b_pos(MAX_X+1), b_neg(MAX_X+1);
  for (int i = 0; i < m; ++i) {
    i64 key = b_sum - b[i];
    if (key >= 0 && key <= MAX_X) {
      b_pos[key] = true;
    }
    if (key >= -MAX_X && key <= 0) {
      b_neg[-key] = true;
    }
  }

  vector<bool> pos(MAX_X+1), neg(MAX_X+1);
  for (int k1 = 0; k1 <= MAX_X; ++k1) {
    for (int k2 = 0; k2 <= MAX_X && k1 * k2 <= MAX_X; ++k2) {
      if (a_pos[k1] && b_pos[k2]) pos[k1 * k2] = true;
      if (a_neg[k1] && b_neg[k2]) pos[k1 * k2] = true;
      if (a_pos[k1] && b_neg[k2]) neg[k1 * k2] = true;
      if (a_neg[k1] && b_pos[k2]) neg[k1 * k2] = true;
    }
  }

  for (int i = 0; i < q; ++i) {
    int x = 0;
    cin >> x;

    bool ans = false;
    if (x >= 0) {
      ans = pos[x];
    } else {
      ans = neg[-x];
    }

    if (ans) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
