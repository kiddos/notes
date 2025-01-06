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
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum % n != 0) {
    cout << "NO" << endl;
    return;
  }
  i64 ave = sum / n;
  map<i64, int> bits;
  for (int i = 0; i < n; ++i) {
    i64 diff = abs(ave - a[i]);
    i64 lowbit = diff & (-diff);
    i64 pow2 = diff + lowbit;
    // cout << "diff=" << diff << ", lowbit=" << lowbit << endl;
    i64 bit_count = bitset<64>(pow2).count();
    if (bit_count > 1) {
      cout << "NO" << endl;
      return;
    }
    if (a[i] > ave) {
      bits[pow2]++;
      bits[lowbit]--;
    } else {
      bits[lowbit]++;
      bits[pow2]--;
    }
  }

  for (auto [p2, count] : bits) {
    // cout << "p2=" << p2 << ", count=" << count << endl;
    if (count != 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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
