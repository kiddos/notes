#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int greater = 0, less = numeric_limits<int>::max();
  set<int> s;
  for (int i = 0; i < n; ++i) {
    int a = 0, x = 0;
    cin >> a >> x;
    if (a == 1) {
      greater = max(greater, x);
    } else if (a == 2) {
      less = min(less, x);
    } else if (a == 3) {
      s.insert(x);
    }
  }

  if (less < greater) {
    cout << "0" << endl;
  } else {
    int ans = less - greater + 1;
    for (auto it = s.lower_bound(greater); it != s.end(); ++it) {
      if (*it > less) {
        break;
      }
      ans--;
    }
    cout << ans << endl;
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
