#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
  string ans;
  for (char ch : s) {
    char ch2 = tolower(ch);
    if (vowels.count(ch2)) {
      continue;
    }
    ans.push_back('.');
    ans.push_back(ch2);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
