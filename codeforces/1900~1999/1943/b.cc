#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> manacher(const string& s) {
  string t = "^#";
  for (char ch : s) {
    t.push_back(ch);
    t.push_back('#');
  }
  t.push_back('$');

  int n = t.length();
  vector<int> p(n);
  int l = 1, r = 1;
  for (int i = 1; i < n-1; ++i) {
    p[i] = max(0, min(r-i, p[l+r-i]));
    while (t[i + p[i]] == t[i - p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) {
      r = i + p[i];
      l = i - p[i];
    }
  }
  return vector<int>(p.begin()+1, p.end()-1);
}

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<vector<int>> chars(26, vector<int>(n+1));
  for (int i = 1; i <= n; ++i) {
    int c = s[i-1] - 'a';
    chars[c][i]++;
  }
  for (int c = 0; c < 26; ++c) {
    for (int i = 1; i <= n; ++i) {
      chars[c][i] += chars[c][i-1];
    }
  }

  auto is_all_same = [&](int l, int r) -> bool {
    int len = r - l + 1;
    for (int c = 0; c < 26; ++c) {
      int count = chars[c][r+1] - chars[c][l];
      if (count != 0 && count != len) {
        return false;
      }
    }
    return true;
  };

  vector<int> p = manacher(s);

  auto is_palindrome = [&](int l, int r) -> bool {
    int len = r - l + 1;
    int palindrome_len = p[l * 2 + len] - 1;
    // cout << "p=" << palindrome_len << ", " << len << endl;
    return palindrome_len >= len;
  };

  vector<int> next_diff(n, n);
  vector<int> st;
  for (int i = 0; i < n; i += 2) {
    while (!st.empty() && s[st.back()] != s[i]) {
      next_diff[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }
  st.clear();
  for (int i = 1; i < n; i += 2) {
    while (!st.empty() && s[st.back()] != s[i]) {
      next_diff[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  auto is_alternating = [&](int l, int r) -> bool {
    int i1 = next_diff[l];
    int i2 = next_diff[l+1];
    // cout << "next diff: " << i1 << " " << i2 << endl;
    return i1 > r && i2 > r;
  };

  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    i64 ans = 0;
    l--;
    r--;
    int len = r - l;
    if (len >= 3 && !is_alternating(l, r)) {
      i64 l = len % 2 == 1 ? len : len-1;
      // cout << "add from 3 ~ " << l << endl;
      ans += (l + 3) * ((l - 3) / 2 + 1) / 2;
    }
    if (len >= 2 && !is_all_same(l, r)) {
      i64 l = len % 2 == 0 ? len : len-1;
      // cout << "add from 2 ~ " << l << endl;
      ans += (l + 2) * ((l - 2) / 2 + 1) / 2;
    }

    len = r - l + 1;
    if (!is_palindrome(l, r)) {
      // cout << "add " << len << endl;
      ans += len;
    }
    cout << ans << endl;
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
