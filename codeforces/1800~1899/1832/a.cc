#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> freq(26);
  for (char ch : s) {
    freq[ch-'a']++;
  }

  int single = 0;
  int chars = 0;
  for (int i = 0; i < 26; ++i) {
    single += freq[i] % 2;
    chars += freq[i] > 1;
  }
  
  if (single <= 1 && chars > 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
