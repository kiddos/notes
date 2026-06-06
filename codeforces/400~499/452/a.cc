#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<string> words = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  vector<bool> matched(words.size());
  int size = words.size();
  for (int i = 0; i < size; ++i) {
    string& word = words[i];
    if (word.length() != s.length()) {
      continue;
    }
    int len = word.length();
    matched[i] = true;
    for (int j = 0; j < len; ++j) {
      if (s[j] != '.' && s[j] != word[j]) {
        matched[i] = false;
        break;
      }
    }
  }

  for (int i = 0; i < size; ++i) {
    if (matched[i]) {
      cout << words[i] << endl;
      break;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
