#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int len = r-l+1;
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int a = 0;
    cin >> a;
    if (a >= l && a <= r) {
      count++;
    }
  }
  return count;
}

void answer(int ans) {
  cout << "! " << ans << endl;
}

void solve() {
  int n = 0;
  cin >> n;


  int l = 1, r = n;
  int ans = 0;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int q = query(l, mid);
    if (q % 2 == 1) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  answer(ans);
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
