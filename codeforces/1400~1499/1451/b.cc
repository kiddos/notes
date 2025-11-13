#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int find_subseq(const string& s, const string& t, int start) {
  int n = s.length(), m = t.length();
  for (int i = start, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      j++;
    }
    if (j == m) {
      return i+1;
    }
  }
  return -1;
}

bool has_subseq(const string& s, const string& t) {
  int m = t.length();
  for (int i = 0; i < m-1; ++i) {
    string prefix = t.substr(0, i+1);
    string suffix = t.substr(i+1);
    int first = find_subseq(s, prefix, 0);
    if (first < 0) {
      continue;
    }
    int second = find_subseq(s, suffix, first+1);
    if (second >= 0) {
      return true;
    }
  }
  return false;
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<bool> ans;
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    l--;
    r--;
    string sub = s.substr(l, r-l+1);
    ans.push_back(has_subseq(s, sub));
  }

  for (bool result : ans) {
    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
