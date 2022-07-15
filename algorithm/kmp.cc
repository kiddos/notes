#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(const string& s, const string& p) {
  auto compute_lps = [&]() -> vector<int> {
    int n = p.length(), i = 1, len = 0;
    vector<int> lps(n);
    while (i < n) {
      if (p[i] == p[len]) {
        lps[i++] = ++len;
      } else {
        if (len != 0) {
          len = lps[len - 1];
        } else {
          lps[i++] = 0;
        }
      }
    }
    return lps;
  };

  vector<int> ans;
  vector<int> lps = compute_lps();
  int i = 0, j = 0;
  int n = s.length(), m = p.length();
  while (i < n) {
    if (s[i] == p[j]) {
      i++;
      j++;
    }

    if (j == m) {
      ans.push_back(i - j);
      j = lps[j - 1];
    } else if (i < n && s[i] != p[j]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "ABABDABACDABABCABAB";
  string p = "ABABCABAB";
  vector<int> ans = kmp(s, p);
  assert(ans.size() == 1);
  assert(ans[0] == 10);
  return 0;
}
