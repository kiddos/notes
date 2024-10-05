#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  vector<int> c1(26), c2(26);
  for (char ch : s1) {
    c1[ch-'A']++;
  }
  for (char ch : s2) {
    c1[ch-'A']++;
  }
  for (char ch : s3) {
    c2[ch-'A']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (c1[i] != c2[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
