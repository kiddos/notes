#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string to_binary(int x) {
  if (x == 0) {
    return "0";
  }
  string b;
  while (x > 0) {
    int d = x % 2;
    x /= 2;
    b.push_back(d + '0');
  }
  reverse(b.begin(), b.end());
  return b;
}

bool is_symmetric(const string& s) {
  int l = 0, r = s.length()-1;
  while (l <= r) {
    if (l == r) {
      if (s[l] != '0') {
        return false;
      }
    } else {
      if (s[l] != s[r]) {
        return false;
      }
    }
    l++;
    r--;
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  string b = to_binary(n);
  for (int p = 0; p < 32; ++p) {
    string b2 = string(p, '0') + b;
    if (is_symmetric(b2)) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
