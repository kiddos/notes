#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  constexpr i64 MIN_VAL = -1e18;
  vector<i64> b = a;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      b[i] = MIN_VAL;
    }
  }
  i64 sum = 0;
  vector<i64> prefix(n);
  for (int i = 0; i < n; ++i) {
    sum = max(sum + b[i], 0LL);
    prefix[i] = sum;
    if (sum > k) {
      cout << "NO" << endl;
      return;
    }
  }
  sum = 0;
  vector<i64> suffix(n+1);
  for (int i = n-1; i >= 0; --i) {
    sum = max(sum + b[i], 0LL);
    suffix[i] = sum;
  }

  bool found = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      i64 pref = prefix[i];
      i64 suff = suffix[i+1];
      if (pref + suff == k) {
        found = true;
        break;
      }
    } else if (s[i] == '0') {
      i64 pref = i > 0 ? prefix[i-1] : 0;
      i64 suff = suffix[i+1];
      i64 total = pref + suff;
      i64 missing = k - total;
      b[i] = missing;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
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
