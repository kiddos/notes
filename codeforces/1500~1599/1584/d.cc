#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  i64 x = 0;
  cin >> x;
  return x;
}

int find_last(int l, int r, int x) {
  int ans = l;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    i64 y = query(1, mid);
    if (y <= x) {
      l = mid+1;
      ans = mid;
    } else {
      r = mid-1;
    }
  }
  return ans;
}

void answer(int i, int j, int k) {
  cout << "! " << i << " " << j << " " << k << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  i64 max_val = query(1, n);
  int i = find_last(1, n, 0);
  i64 len1 = max_val - query(i+1, n);
  int j = i + len1 + 1;
  i64 first_part = (len1 + 1) * len1 / 2;
  i64 second_part = max_val - first_part;
  // x * x + x = q * 2
  // x = (-1 + sqrt(4 * q * 2 + 1)) / 2
  int len2 = (sqrt(8 * second_part + 1) - 1) / 2;
  int k = j + len2;
  answer(i, j, k);
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
