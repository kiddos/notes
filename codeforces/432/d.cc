#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> z_function(const string& s) {
  int n = s.length();
  int l = 0, r = 0;
  vector<int> z(n);
  for (int i = 0; i < n; ++i) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  vector<int> z = z_function(s);
  vector<int> count(n+1);
  set<int> lengths;
  for (int i = 0; i < n; ++i) {
    if (z[i] == 0) continue;

    count[z[i]]++;
    if (i + z[i] == n) {
      lengths.insert(z[i]);
    }
  }
  for (int i = n-1; i >= 1; --i) {
    count[i] += count[i+1];
  }

  cout << lengths.size() + 1 << endl;
  for (int len : lengths) {
    cout << len << " " << count[len]+1 << endl;
  }
  cout << n << " 1" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
