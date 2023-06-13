#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<string>> words(3, vector<string>(n));
  unordered_map<string, int> word_count;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> words[i][j];
      word_count[words[i][j]]++;
    }
  }

  vector<int> scores(3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      if (word_count[words[i][j]] == 1) {
        scores[i] += 3;
      } else if(word_count[words[i][j]] == 2) {
        scores[i] += 1;
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    cout << scores[i] << " ";
  }
  cout << endl;
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
