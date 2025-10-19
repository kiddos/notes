#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> count(26);
  for (char ch : s) {
    count[ch-'A']++;
  }
  int odd_count = 0;
  for (int c = 0; c < 26; ++c) {
    if (count[c] % 2 == 1) {
      odd_count++;
    }
  }
  if (odd_count > 1) {
    cout << "NO SOLUTION" << endl;
    return;
  }
  string left;
  for (int c = 0; c < 26; ++c) {
    left += string(count[c] / 2, c + 'A');
  }
  string right(left.rbegin(), left.rend());
  string ans = left;
  for (int c = 0; c < 26; ++c) {
    if (count[c] % 2 == 1) {
      ans.push_back(c + 'A');
    }
  }
  ans += right;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
