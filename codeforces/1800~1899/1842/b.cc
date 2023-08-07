#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> c[i];

  auto can_read = [&](int book) -> bool {
    for (int b = 30; b >= 0; --b) if (!(x & (1<<b)) && (book & (1<<b))) {
      return false;
    }
    return true;
  };

  int y = 0;
  auto read_stack = [&](vector<int>& books) {
    for (int i = 0; i < n; ++i) {
      if (can_read(books[i])) {
        y |= books[i];
      } else {
        break;
      }
    }
  };

  read_stack(a);
  read_stack(b);
  read_stack(c);

  if (y == x) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
