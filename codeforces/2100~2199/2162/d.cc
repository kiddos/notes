#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 query(int t, int l, int r) {
  cout << t << " " << l << " " << r << endl;
  i64 result = 0;
  cin >> result;
  return result;
}

void answer(int l, int r) {
  cout << "! " << l << " " << r << endl;
}

i64 added(int l, int r) {
  i64 result1 = query(1, l, r);
  i64 result2 = query(2, l, r);
  return result2 - result1;
}

void solve() {
  i64 n = 0;
  cin >> n;
  i64 new_sum = query(2, 1, n);
  i64 original_sum = (n+1) * n / 2;
  i64 length = new_sum - original_sum;

  int l = 1, r = n - length + 1;
  int start = 1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    i64 result = added(mid, n);
    if (result >= length) {
      start = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }

  answer(start, start + length - 1);
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
