#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> count(26);
  for (char ch : s) {
    count[ch-'a']++;
  }
  int extra = 0;
  for (int c = 0; c < 26; ++c) {
    extra += count[c] % 2;
  }
  int remove = max(extra-1, 0);
  if (remove % 2 == 0) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
