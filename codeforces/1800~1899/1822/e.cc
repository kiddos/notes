#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (n % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  vector<int> char_freq(26);
  for (int i = 0; i < n; ++i) {
    char_freq[s[i]-'a']++;
    if (char_freq[s[i]-'a'] > n / 2) {
      cout << "-1" << endl;
      return;
    }
  }

  int total = 0;
  vector<int> incorrect(26);
  for (int i = 0; i *2 < n; ++i) {
    if (s[i] == s[n-i-1]) {
      incorrect[s[i]-'a']++;
      total++;
    }
  }

  for (int i = 0; i < 26; ++i) {
    if (incorrect[i]*2 > total) {
      cout << incorrect[i] << endl;
      return;
    }
  }
  cout << (total+1) / 2 << endl;
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
