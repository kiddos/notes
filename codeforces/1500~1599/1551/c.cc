#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> words;
  for (int i = 0; i < n; ++i) {
    string word;
    cin >> word;
    words.push_back(word);
  }

  auto find_max_length = [&](char ch) -> int {
    vector<int> scores;
    for (int i = 0; i < n; ++i) {
      int score = 0;
      for (char c : words[i]) {
        if (c == ch) {
          score++;
        } else {
          score--;
        }
      }
      scores.push_back(score);
    }
    sort(scores.rbegin(), scores.rend());

    int current = 0;
    for (int i = 0; i < n; ++i) {
      current += scores[i];
      if (current <= 0) {
        return i;
      }
    }
    return n;
  };

  int ans = 0;
  for (char ch = 'a'; ch <= 'e'; ++ch) {
    ans = max(ans, find_max_length(ch));
  }
  cout << ans << endl;
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
