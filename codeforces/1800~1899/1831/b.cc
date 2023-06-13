#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  unordered_map<int, int> lens;
  int last = -1;
  int ans = 0;
  for (int i = 0, len = 0; i < n; ++i) {
    if (a[i] == last) {
      len++;
    } else {
      len = 1;
    }
    last = a[i];
    lens[a[i]] = max(lens[a[i]], len);

    ans = max(ans, len);
  }

  last = -1;
  for (int i = 0, len = 0; i < n; ++i) {
    if (b[i] == last) {
      len++;
    } else {
      len = 1;
    }

    last = b[i];
    ans = max(ans, len + (lens.count(b[i]) ? lens[b[i]] : 0));
  }

  cout << ans << endl;
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
