#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 xor_prefix(i64 x) {
  // cout << "x=" << x << endl;
  i64 ans = 0;
  for (i64 b = 0; b < 60; ++b) {
    i64 cycle = (1LL<<(b+1));
    i64 bit_count = x / cycle * (1LL << b);
    i64 first = x / cycle * cycle + (1LL << b);
    bit_count += max(x - first + 1, 0LL);
    // cout << first << " ";
    // cout << bit_count << " ";
    if (bit_count % 2 == 1) {
      ans |= (1LL<<b);
    }
  }
  // cout << endl;
  return ans;
}

i64 find_first(i64 i, i64 k, i64 low) {
  i64 l = 0;
  i64 r = 1LL << (60 - i);
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 x = (mid << i) | k;
    if (x >= low) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}

i64 find_last(i64 i, i64 k, i64 high) {
  i64 l = 0;
  i64 r = 1LL << (60-i);
  i64 ans = -1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 x = (mid << i) | k;
    if (x <= high) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}

void solve() {
  i64 l = 0, r = 0, i = 0, k = 0;
  cin >> l >> r >> i >> k;

  i64 ans = xor_prefix(r) ^ xor_prefix(l-1);
  i64 first = find_first(i, k, l);
  i64 last = find_last(i, k, r);
  // cout << first << "~" << last << endl;
  if (first >= 0 && last >= 0 && first <= last) {
    i64 xor_remove = xor_prefix(last) ^ (first > 0 ? xor_prefix(first-1) : 0);
    xor_remove <<= i;
    ans ^= xor_remove;
    // cout << "xor_remove =" << xor_remove << endl;

    i64 count = (last - first) + 1;
    if (count % 2 == 1) {
      ans ^= k;
    }
    // cout << "count=" << count << endl;
  }
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
