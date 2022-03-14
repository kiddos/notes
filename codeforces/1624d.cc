#include <bits/stdc++.h>

using namespace std;

int solve(string s, int k) {
  vector<int> count(26);
  for (char ch : s) count[ch-'a']++;
  int pairs = 0, one_char = 0;
  for (int c : count) {
    pairs += c / 2;
    one_char += c % 2;
  }

  auto can_make = [&](int size) {
    int p = pairs, o = one_char;
    for (int kk = 0; kk < k; ++kk) {
      if (o) {
        o--;
        int require_pair = size / 2;
        if (require_pair > p) return false;
        p -= require_pair;
      } else {
        if (size % 2 == 1) {
          p--;
          o++;
          int require_pair = size / 2;
          if (require_pair > p) return false;
          p -= require_pair;
        } else {
          int require_pair = size / 2;
          if (require_pair > p) return false;
          p -= require_pair;
        }
      }
    }
    return true;
  };

  int ans = 1;
  int l = 1, r = s.length();
  while (l <= r) {
    int m = l + (r-l) / 2;
    if (can_make(m)) {
      ans = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t -- > 0) {
    int n = 0, k = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = solve(s, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
