#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  int val = -1;
  for (auto [ai, c] : count) {
    if (c == 1) {
      val = ai;
      break;
    }
  }

  if (val == -1) {
    cout << "-1" << endl;
  } else {
    int idx = find(a.begin(), a.end(), val) - a.begin() + 1;
    cout << idx << endl;
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
