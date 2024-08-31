#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  reverse(a.begin(), a.end());
  int largest = a[0];

  auto can_perform = [&](int x, int l, int r) -> bool {
    return x >= l && x <= r;
  };

  for (int i = 0; i < m; ++i) {
    char op = '\0';
    cin >> op;
    int l = 0, r = 0;
    cin >> l >> r;
    int add = 0;
    if (op == '+') {
      add = 1;
    } else if (op == '-') {
      add = -1;
    }
    if (can_perform(largest, l, r)) {
      largest += add;
    }
    cout << largest << " ";
  }
  cout << endl;
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
