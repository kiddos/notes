#include <bits/stdc++.h>

using namespace std;

string bitwise_or(const string& s1, const string& s2) {
  if (s1.empty()) return s2;
  if (s2.empty()) return s1;
  int n = max(s1.length(), s2.length());

  string ans(n, '0');
  for (int k = n-1, i = s1.length()-1, j = s2.length()-1; k >= 0; --k, --i, --j) {
    int bit1 = i >= 0 && s1[i] == '1' ? 1 : 0;
    int bit2 = j >= 0 && s2[j] == '1' ? 1 : 0;
    if (bit1 || bit2) {
      ans[k] = '1';
    }
  }
  return ans;
}

string remove_prefix_zero(const string& s) {
  int i = 0;
  while (i < s.length() && s[i] == '0') {
    i++;
  }
  if (i == s.length()) return "0";
  return s.substr(i);
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  s = remove_prefix_zero(s);
  // cout << "s=" << s << endl;
  n = s.length();

  int i = 0;
  while (i < n && s[i] == '1') i++;
  if (i == n) {
    cout << s << endl;
    return;
  }

  int k = n-i;
  // cout << "k=" << k << endl;
  string x = s;
  while (x.length() >= k && x[x.length()-k] == '0') {
    x.pop_back();
  }
  // cout << "x=" << x << endl;

  string ans = s;
  while (x.length() >= k && x[x.length()-k] == '1') {
    string y = bitwise_or(s, x);
    // cout << "y=" << y << endl;
    if (y > ans) {
      ans = y;
    }
    x.pop_back();
  }

  ans = remove_prefix_zero(ans);
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
