#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 5 1
// 3 5 4 2 1
//
// 3 -> 2 -> 1
//
// 6 3
// 4 3 1 5 2 6
// 3 -> 5 -> 6

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];

  vector<int> used(n+1);
  int l = 1, r = n+1;
  while (l+1 < r) {
    int mid = l + (r-l) / 2;
    used[mid] = true;
    if (p[mid] <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }

  if (p[l] == x) {
    cout << "0" << endl;
    return;
  }

  vector<int> index(n+1);
  for (int i = 1; i <= n; ++i) {
    index[p[i]] = i;
  }

  cout << "1" << endl;
  cout << index[x] << " " << l << endl;
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
