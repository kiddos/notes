#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0, l = 0, r = 0;
  cin >> n >> k >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 ans = 0;
  map<int,int> count1, count2;
  for (int c = 0, b1 = 0, b2 = 0; c < n; ++c) {
    count1[a[c]]++;
    count2[a[c]]++;
    while ((int)count1.size() > k) {
      if (--count1[a[b1]] == 0) {
        count1.erase(a[b1]);
      }
      b1++;
    }
    while ((int)count2.size() >= k) {
      if (--count2[a[b2]] == 0) {
        count2.erase(a[b2]);
      }
      b2++;
    }

    if ((int)count1.size() == k) {
      int len1 = min(c - b1+1, r);
      int len2 = max(c-(b2-1)+1, l);
      int count = max(len1 - len2 + 1, 0);
      ans += count;
    }
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
