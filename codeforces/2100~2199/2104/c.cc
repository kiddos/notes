#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == 'A' && s.back() == 'A') {
    cout << "Alice" << endl;
  } else if (s[0] == 'B' && s.back() == 'B') {
    cout << "Bob" << endl;
  } else if (s[0] == 'A' && s.back() == 'B') {
    // if bob has card that can take the smallest card, bob wins
    for (int i = 1; i < n-1; ++i) {
      if (s[i] == 'B') {
        cout << "Bob" << endl;
        return;
      }
    }
    cout << "Alice" << endl;
  } else if (s[0] == 'B' && s.back() == 'A') {
    // Alice cannot play the largest card, since bob will just win
    // in this case, who owns the second largest card wins
    if (s[n-2] == 'A') {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
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
