#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  map<int, int> counts;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x % 2 == 0) {
      x /= 2;
    }
    counts[x]++;
  }

  vector<int> rest;
  for (int i = 0; i < n; ++i) {
    int y = b[i];
    while (y % 2 == 0) {
      y /= 2;
    }
    if (counts.count(y)) {
      if (--counts[y] == 0) counts.erase(y);
    } else {
      rest.push_back(y);
    }
  }

  sort(rest.rbegin(), rest.rend());
  for (int r : rest) {
    bool used = false;
    while (r > 0) {
      if (counts.count(r)) {
        if (--counts[r] == 0) counts.erase(r);
        used = true;
        break;
      } else {
        r /= 2;
      }
    }

    if (!used) {
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
