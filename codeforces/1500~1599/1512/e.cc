#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, l = 0, r = 0, s = 0;
  cin >> n >> l >> r >> s;

  int len = r-l+1;
  int largest = (n + n-len+1) * len / 2;
  int smallest = (1 + len) * len / 2;
  if (s < smallest || s > largest) {
    cout << "-1" << endl;
    return;
  }

  vector<int> p(n+1);
  for (int i = l, k = 1; i <= r; ++i) {
    p[i] = k++;
  }

  int missing = s - smallest;
  int each = missing / len;
  int extra = missing - each * len;
  for (int i = r; i >= l; --i) {
    int add = each;
    if (extra) {
      add++;
      extra--;
    }
    p[i] += add;
  }

  set<int> found;
  for (int i = l; i <= r; ++i) {
    found.insert(p[i]);
  }

  for (int i = 1, current = 1; i <= n; ++i) {
    if (p[i] == 0) {
      while (found.count(current)) {
        current++;
      }
      found.insert(current);
      p[i] = current++;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << p[i] << " ";
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
