#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s1;
  cin >> s1;
  i64 pos = 0;
  cin >> pos;
  int n = s1.length();
  int l = 1, r = n;

  i64 remove = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 len = (n + n - mid + 1) * mid / 2;
    if (len >= pos) {
      r = mid-1;
      remove = mid - 1;
    } else {
      l = mid+1;
    }
  }

  // cout << "remove: " << remove << endl;
  if (remove == 0) {
    cout << s1[pos-1];
  } else {
    i64 prefix_len = (n + n - (remove-1))  * (remove) / 2;
    // cout << "prefix len = " << prefix_len << endl;
    pos -= prefix_len;
    // cout << "pos=" << pos << endl;
    string si;
    for (char ch : s1) {
      while (!si.empty() && ch < si.back() && r > 0) {
        r--;
        si.pop_back();
      }
      si.push_back(ch);
    }
    while (!si.empty() && r > 0) {
      r--;
      si.pop_back();
    }
    cout << si[pos-1];
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
