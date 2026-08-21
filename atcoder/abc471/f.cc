#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string remove_prefix_zero(string s) {
  int len = s.length();
  int idx = 0;
  while (idx < len && s[idx] == '0') {
    idx++;
  }
  if (idx == len) {
    return "0";
  }
  return s.substr(idx);
}

bool has_none_zero(const string& s) {
  for (char ch : s) {
    if (ch != '0') {
      return true;
    }
  }
  return false;
}

string combine(vector<string>& selected) {
  sort(selected.begin(), selected.end(), [&](const string& s1, const string& s2) {
    string c1 = s1 + s2;
    string c2 = s2 + s1;
    return c1 > c2;
  });

  int size = selected.size();
  string ans;
  for (int i = 0; i < size; ++i) {
    ans += selected[i];
  }
  ans = remove_prefix_zero(ans);
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end(), [&](const string& s1, const string& s2) {
    if (s1.length() == s2.length()) {
      return s1 > s2;
    }
    return s1.length() > s2.length();
  });

  vector<string> selected1;
  for (int i = 0; i < k-1; ++i) {
    selected1.push_back(s[i]);
  }

  i64 best = 0;
  for (int i = k-1; i < n; ++i) {
    string p = remove_prefix_zero(s[i]);
    best = max(best, stoll(p));
  }
  selected1.push_back(to_string(best));

  vector<string> selected2;
  for (int i = 0; i < k; ++i) {
    selected2.push_back(s[i]);
  }

  string ans1 = combine(selected1);
  string ans2 = combine(selected2);
  string ans;
  if (ans1.length() == ans2.length()) {
    ans = max(ans1, ans2);
  } else if (ans1.length() > ans2.length()) {
    ans = ans1;
  } else {
    ans = ans2;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
