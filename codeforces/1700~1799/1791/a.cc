#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  string pool = "codeforces";
  unordered_set<char> valid(pool.begin(), pool.end());
  for (int t = 0; t < T; ++t) {
    char c = ' ';
    cin >> c;
    if (valid.count(c)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
