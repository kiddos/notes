#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  getline(cin, s);
  int n = s.length();
  for (int i = n-1; i >= 0; --i) {
    if (isalpha(s[i])) {
      char ch = tolower(s[i]);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      return;
    }
  }

  cout << "NO" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
} 
