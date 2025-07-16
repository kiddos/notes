#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  int last = n;
  while (k > 0) {
    int idx = -1;
    for (int i = 0; i < n-1; ++i) {
      if (h[i+1] > h[i]) {
        idx = i;
        break;
      }
    }
    if (idx < 0) {
      break;
    }

    h[idx]++;
    k--;
    last = idx;
  }

  if (k > 0) {
    cout << "-1" << endl;
  } else {
    cout << last+1 << endl;
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
