#include <bits/stdc++.h>

using namespace std;

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
    while (t[i+p[i]] == t[i-p[i]]) {
      p[i]++;
    }
    if (i + p[i] > r) {
      r = i + p[i];
      l = i - p[i];
    }
  }
  return vector<int>(p.begin()+1, p.end()-1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "abaaba";
  vector<int> p = manacher(s);
  for (int len : p) cout << len <<" ";
  cout << endl;
  return 0;
}
