#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(const string& s) {
  string t = "^#";
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    t.push_back(s[i]);
    t.push_back('#');
  }
  t.push_back('$');

  int m = t.length();
  vector<int> p(m);
  int l = 1, r = 1;
  for (int i = 1; i < m-1; ++i) {
    p[i] = max(0, min(r-i, p[l+r-i]));
    while (i+p[i] < m && i-p[i] >= 0 && t[i+p[i]] == t[i-p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) {
      r = i + p[i];
      l = i - p[i];
    }
  }

  for (int i = 0; i < m; ++i) {
    cout << t[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < m; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
  return vector<int>(p.begin()+1, p.end()-1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "abaaba";
  vector<int> p = manacher(s);
  return 0;
}
