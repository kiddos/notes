#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum State {
  SORTED,
  NOT_SORTED,
  UNKNOWN
};

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  vector<State> states = {SORTED};
  for (int i = 0; i < n; ++i) {
    if (s[i] == '+') {
      if (states.size() == 1) {
        states.push_back(SORTED);
      } else {
        if (states.back() == NOT_SORTED) {
          states.push_back(NOT_SORTED);
        } else {
          states.push_back(UNKNOWN);
        }
      }
    } else if (s[i] == '-') {
      states.pop_back();
    } else if (s[i] == '0') {
      if (states.back() == SORTED) {
        cout << "NO" << endl;
        return;
      }

      states.back() = NOT_SORTED;
    } else if (s[i] == '1') {
      if (states.back() == NOT_SORTED) {
        cout << "NO" << endl;
        return;
      }

      fill(states.begin(), states.end(), SORTED);
    }
  }

  cout << "YES" << endl;
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
