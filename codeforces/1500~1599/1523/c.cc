#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string format_result(vector<int>& s) {
  string version;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i > 0) {
      version.push_back('.');
    }
    version += to_string(s[i]);
  }
  return version;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      s.push_back(1);
    } else {
      while (s.back() + 1 != a[i]) {
        s.pop_back();
      }

      if (s.back() + 1 == a[i]) {
        s.back() += 1;
      }
    }
    cout << format_result(s) << endl;
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
