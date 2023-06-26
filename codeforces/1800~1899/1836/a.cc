#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  vector<int> l(n);
  for (int i = 0; i < n; ++i) cin >> l[i];

  sort(l.begin(), l.end());

  vector<int> lines(200);
  for (int i = 0; i < n; ++i) {
    if (l[i] == 0) {
      lines[l[i]]++;
    } else {
      if (lines[l[i]-1] > 0) {
        lines[l[i]-1]--;
        lines[l[i]]++;
      } else {
        cout << "NO" << endl;
        return;
      }
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
