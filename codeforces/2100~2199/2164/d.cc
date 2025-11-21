#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, kmax = 0;
  cin >> n >> kmax;
  string s, t;
  cin >> s >> t;
  auto possible = [&](int max_move) -> bool {
    vector<int> moves(n);
    for (int i = 0, j = 0; i < n; ++i) {
      j = max(j, i-max_move);
      while (j < i && s[j] != t[i]) {
        j++;
      }
      if (s[j] != t[i]) {
        return false;
      }
      moves[i] = i - j;
    }
    return true;
  };

  int max_move = -1;
  for (int k = 0; k <= kmax; ++k) {
    if (possible(k)) {
      max_move = k;
      break;
    }
  }

  if (max_move < 0) {
    cout << "-1" << endl;
    return;
  }

  vector<int> moves(n);
  for (int i = 0, j = 0; i < n; ++i) {
    j = max(j, i-max_move);
    while (j < i && s[j] != t[i]) {
      j++;
    }
    moves[i] = i - j;
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << moves[i] << " ";
  // }
  // cout << endl;

  int max_moves = *max_element(moves.begin(), moves.end());
  if (max_moves > kmax) {
    cout << "-1" << endl;
    return;
  }
  vector<string> ans;
  for (int j = 0; j < max_moves; ++j) {
    string s2;
    for (int i = 0; i < n; ++i) {
      if (moves[i] > 0) {
        s2.push_back(s[i-1]);
        moves[i]--;
      } else {
        s2.push_back(s[i]);
      }
    }
    s = std::move(s2);
    ans.push_back(s);
  }

  if (s != t) {
    cout << "-1" << endl;
    return;
  }

  cout << ans.size() << endl;
  for (string& temp : ans) {
    cout << temp << endl;
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
