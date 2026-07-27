#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> digits(const string& s) {
  int len = s.length();
  vector<int> d(len);
  for (int i = 0; i < len; ++i) {
    d[i] = s[i] - '0';
  }
  reverse(d.begin(), d.end());
  return d;
}

string multiply(const string& s1, const string& s2) {
  vector<int> d1 = digits(s1);
  vector<int> d2 = digits(s2);
  int len1 = d1.size(), len2 = d2.size();
  vector<int> output(len1+len2+2);
  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      output[i+j] += d1[i] * d2[j];
    }
  }
  int size = output.size();
  for (int i = 0, c = 0; i < size-1; ++i) {
    output[i] += c;

    int d = output[i] % 10;
    c = output[i] / 10;
    output[i] = d;
  }
  string ans;
  for (int i = 0; i < size; ++i) {
    ans.push_back(output[i] + '0');
  }
  while (!ans.empty() && ans.back() == '0') {
    ans.pop_back();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

bool ge(const string& s1, const string& s2) {
  if (s1.length() > s2.length()) {
    return true;
  } else if (s1.length() < s2.length()) {
    return false;
  }
  return s1 >= s2;
}

bool le(const string& s1, const string& s2) {
  if (s1.length() < s2.length()) {
    return true;
  } else if (s1.length() > s2.length()) {
    return false;
  }
  return s1 <= s2;
}

void solve() {
  string l, r, k;
  cin >> l >> r >> k;

  string p = "1";
  vector<string> ans;
  while (le(p, r)) {
    if (ge(p, l) && le(p, r)) {
      ans.push_back(p);
    }
    p = multiply(p, k);
  }

  if (ans.empty()) {
    cout << "-1" << endl;
  } else {
    for (string x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
