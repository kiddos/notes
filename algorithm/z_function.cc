#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  int l = 0, r = 0;
  vector<int> z(n);
  for (int i = 1; i < n; ++i) {
    if (i < r) {
      z[i] = min(r-i, z[i-l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i+z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

int main(void) {
  const string s = "aaaabaa";
  vector<int> z = z_function(s);
  for (int i = 0; i < (int)s.length(); ++i) {
    cout << z[i] << " ";
  }
  cout << endl;
  return 0;
}
