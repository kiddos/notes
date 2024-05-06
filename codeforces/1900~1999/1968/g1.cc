#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> compute_lps(const string &p) {
  int n = p.length();
  vector<int> lps(n);
  int len = 0;
  int i = 1;
  while (i < n) {
    if (p[i] == p[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) {
        len = lps[len-1];
      } else {
        lps[i++] = 0;
      }
    }
  }
  return lps;
}

void solve() {
  int n = 0, l = 0, r = 0;
  cin >> n >> l >> r;
  string s;
  cin >> s;

  int k = l;

  auto possible = [&](int len) -> bool {
    if (len == 0) return true;

    string p = s.substr(0, len);
    vector<int> lps = compute_lps(p);

    int i = len, j = 0;
    int count = 1;
    while (i < n) {
      if (s[i] == p[j]) {
        i++;
        j++;
      }

      if (j == len) {
        count++;
        j = 0;
      } else if (i < n && s[i] != p[j]) {
        if (j != 0) {
          j = lps[j-1];
        } else {
          i++;
        }
      }
    }
    return count >= k;
  };

  auto find_lcp = [&]() -> int {
    int l = 0, r = n / k;
    int ans = 0;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (possible(mid)) {
        l = mid+1;
        ans = mid;
      } else {
        r = mid-1;
      }
    }
    return ans;
  };

  int ans = find_lcp();
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
