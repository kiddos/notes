#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int sum = 0;
  cin >> sum;
  return sum;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0, t = 0;
  cin >> n >> t;
  for (int i = 0; i < t; ++i) {
    int k = 0;
    cin >> k;

    int l = 1, r = n;
    int idx = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int sum = query(1, mid);
      int zeros = mid - sum;
      if (zeros >= k) {
        r = mid-1;
        idx = mid;
      } else {
        l = mid+1;
      }
    }
    answer(idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
