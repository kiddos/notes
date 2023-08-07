#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<string> game(3);
  for (int i = 0; i < 3; ++i) cin >> game[i];

  unordered_map<char, int> counts;
  for (int i = 0; i < 3; ++i) {
    counts.clear();
    for (int j = 0; j < 3; ++j) {
      counts[game[i][j]]++;
    }
    if (counts.size() == 1 && counts.begin()->first != '.') {
      cout << counts.begin()->first << endl;
      return;
    }
  }

  for (int j = 0; j < 3; ++j) {
    counts.clear();
    for (int i = 0; i < 3; ++i) {
      counts[game[i][j]]++;
    }
    if (counts.size() == 1 && counts.begin()->first != '.') {
      cout << counts.begin()->first << endl;
      return;
    }
  }

  counts.clear();
  for (int i = 0; i < 3; ++i) {
    counts[game[i][i]]++;
  }
  if (counts.size() == 1 && counts.begin()->first != '.') {
    cout << counts.begin()->first << endl;
    return;
  }

  counts.clear();
  for (int i = 0; i < 3; ++i) {
    counts[game[2-i][i]]++;
  }
  if (counts.size() == 1 && counts.begin()->first != '.') {
    cout << counts.begin()->first << endl;
    return;
  }

  cout << "DRAW" << endl;
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
