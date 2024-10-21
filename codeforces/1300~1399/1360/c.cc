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

  sort(a.begin(), a.end());

  bool found_adj = false;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i-1]+1) {
      found_adj = true;
      break;
    }
  }

  vector<int> p(2);
  for (int i = 0; i < n; ++i) {
    p[a[i]%2]++;
  }

  if (p[0] % 2 == 1 || p[1] % 2 == 1) {
    if (!found_adj) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else {
    cout << "YES" << endl;
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
