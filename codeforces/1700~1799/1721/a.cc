#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  string a;
  cin >> a;
  s += a;
  cin >> a;
  s += a;

  vector<int> char_counts(26);
  for (char ch : s) char_counts[ch-'a']++;

  vector<int> count;
  for (int i = 0; i < 26; ++i) if (char_counts[i] > 0) {
    count.push_back(char_counts[i]);
  }
  sort(count.begin(), count.end());
  
  if (count.size() == 1) {
    cout << "0" << endl;
  } else if (count.size() == 2) {
    cout << "1" << endl;
  } else if (count.size() == 3) {
    cout << "2" << endl;
  } else if (count.size() == 4) {
    cout << "3" << endl;
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
