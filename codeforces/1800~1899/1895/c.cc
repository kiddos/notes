#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i] = to_string(a[i]);
  }

  auto digit_sum = [&](const string& x) -> int {
    int digit_sum = 0;
    for (char ch : x) {
      digit_sum += ch - '0';
    }
    return digit_sum;
  };

  map<array<int,3>, int> counts;
  for (int i = 0; i < n; ++i) {
    int len = s[i].length();
    int sum = digit_sum(s[i]);
    int prefix = sum;
    int suffix = 0;
    string&x = s[i];
    for (int r = len-1; r >= 0; --r) {
      int diff = prefix - suffix;
      array<int, 3> key = {len, len-r-1, diff};
      counts[key]++;
      // cout << "suffix len=" << len-r-1 << ", diff=" << diff<< endl; 

      prefix -= (x[r] - '0');
      suffix += (x[r] - '0');
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int len = s[i].length();
    string& x = s[i];
    // cout << "s=" << x << endl;
    for (int len2 = 4 + len % 2; len2 > 0; len2 -= 2) {
      int total_len = len2 + len;
      int target_len = total_len / 2;
      int prefix_len = 0;
      int suffix_len = 0;
      if (len2 > len) {
        suffix_len = len2 - target_len;
      }
      if (len > len2) {
        prefix_len = len - target_len;
      }
      string x1 = x.substr(0, prefix_len);
      string x2 = x.substr(prefix_len);
      int prefix = digit_sum(x1);
      int suffix = digit_sum(x2);
      int diff = suffix - prefix;
      array<int, 3> key = {len2, suffix_len, diff};
      if (counts.count(key)) {
        ans += counts[key];
      }
    }
    // cout << "ans=" << ans << endl;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
