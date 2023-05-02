#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    string s;
    cin >> n >> s;

    string s2;
    for (int i = 0; i < n; ++i) {
      char c = tolower(s[i]);
      if (s2.empty() || c != s2.back()) {
        s2.push_back(c);
      }
    }
    if (s2 == "meow") {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
