#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll sum = 0;
  for (int i = 0; i < n; ++i) sum += abs(a[i]);

  int i = 0;
  int neg_group = 0;
  while (i < n) {
    if (a[i] > 0) i++;
    else {
      bool found = false;
      while (i < n && a[i] <= 0)  {
        if (a[i] < 0) found = true;
        i++;
      }
      if (found) neg_group++;
    }
  }

  i = 0;
  int pos_group = 0;
  while (i < n) {
    if (a[i] < 0) i++;
    else {
      bool found = false;
      while (i < n && a[i] >= 0)  {
        if (a[i] > 0) found = true;
        i++;
      }
      if (found) pos_group++;
    }
  }

  int ops = min(neg_group, 1 + pos_group);
  cout << sum << " " << ops << endl;
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
