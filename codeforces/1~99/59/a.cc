#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int l = 0, u = 0;
  for (char ch : s) {
    if (islower(ch)) {
      l++;
    } else if (isupper(ch)) {
      u++;
    }
  }
  if (l >= u) {
    transform(s.begin(), s.end(), s.begin(),
              [&](char ch) { return tolower(ch); });
  } else {
    transform(s.begin(), s.end(), s.begin(),
              [&](char ch) { return toupper(ch); });
  }
  cout << s << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
