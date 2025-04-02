#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int first_greater(int x, int k) {
  int d = (x + k - 1) / k;
  return d * k;
}

int last_smaller(int x, int k) {
  int d = x / k;
  return d * k;
}

bool valid_size(int left, int right, int size) {
  int l = first_greater(left, size);
  return l + size <= right;
}

int find_size(int left, int right) {
  for (int b = 20; b >= 0; --b) {
    int size = 1<<b;
    if (valid_size(left, right, size)) {
      return size;
    }
  }
  return 1;
}

map<array<int,4>,int> memo;

int divide(int l1, int r1, int l2, int r2) {
  if (l1 >= r1 || l2 >= r2) {
    return 0;
  }
  array<int,4> key = {l1, r1, l2, r2};
  if (memo.count(key)) {
    return memo[key];
  }

  int k1 = find_size(l1, r1);
  int k2 = find_size(l2, r2);
  int k = min(k1, k2);
  int l3 = first_greater(l1, k);
  int r3 = last_smaller(r1, k);
  int l4 = first_greater(l2, k);
  int r4 = last_smaller(r2, k);
  int size = (r3-l3) / k * (r4-l4) / k;
  int region1 = size;
  region1 += divide(l1, l3, l4, r4);
  region1 += divide(r3, r1, l4, r4);
  region1 += divide(l1, r1, l2, l4);
  region1 += divide(l1, r1, r4, r2);

  // int region2 = size;
  // region2 += divide(l1, l3, l2, r2);
  // region2 += divide(r3, r1, l2, r2);
  // region2 += divide(l3, r3, l2, l4);
  // region2 += divide(l3, r3, r4, r2);

  // cout << "l1=" << l1 << ",r1=" << r1 << ",l2=" << l2 << ",r2=" << r2 << endl;
  // cout << "k=" << k << ",l3=" << l3 << ",r3=" << r3 << ",l4=" << l4 << ",r4=" << r4;
  // cout << ",region=" << region1 << ',' << region2 << endl;
  // int ans = min(region1, region2);
  int ans = region1;
  return memo[key] = ans;
}

void solve() {
  int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
  cin >> l1 >> r1 >> l2 >> r2;
  int ans = divide(l1, r1, l2, r2);
  cout << ans << endl;
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
