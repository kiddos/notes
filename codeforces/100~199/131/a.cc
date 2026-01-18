#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  bool all_cap = all_of(s.begin(), s.end(), [](char c) {
    return isupper(c);
  });
  bool first_not_cap = islower(s[0]);
  bool rest_upper = all_of(s.begin() + 1, s.end(), [](char c) {
    return isupper(c);
  });
  if (all_cap) {
    for (char& c : s) {
      c = tolower(c);
    }
  } else if (first_not_cap && rest_upper) {
    for (char& c : s) {
      if (isupper(c)) {
        c = tolower(c);
      } else {
        c = toupper(c);
      }
    }
  }
  cout << s << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
