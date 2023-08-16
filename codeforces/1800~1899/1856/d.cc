#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int r) {
  if (l == r) {
    return 0;
  }
  cout << "? " << l << " " << r << endl;
  int x = 0;
  cin >> x;
  return x;
}

void solve() {
  function<int(int,int)> divide = [&](int l, int r) -> int {
    if (l == r) {
      return l;
    }

    int mid = l + (r-l) / 2;
    int i = divide(l, mid);
    int j = divide(mid+1, r);
    
    int q1 = query(l, j-1);
    int q2 = query(l, j);
    if (q1 == q2) {
      return j;
    }
    // its impossible to have q1 > q2, since the inversion adds up
    return i;
  };

  int n = 0;
  cin >> n;
  int ans = divide(1, n);
  cout << "! " << ans << endl;
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
