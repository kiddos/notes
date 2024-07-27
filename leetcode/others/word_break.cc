#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  bool word_break(const string& s, vector<string>& word_dict) {
    if (s.length() == 0) return true;
    if (memo_.count(s)) return memo_[s];

    for (string& word : word_dict) {
      string prefix = s.substr(0, word.length());
      if (prefix == word) {
        string suffix = s.substr(word.length());
        if (word_break(suffix, word_dict)) {
          memo_[s] = true;
          return true;
        }
      }
    }
    memo_[s] = false;
    return false;
  }

 private:
  unordered_map<string, bool> memo_;
};


class Solution2 {
 public:
  bool word_break(const string& s, vector<string>& word_dict) {
    unordered_set<string> words(word_dict.begin(), word_dict.end());

    int n = s.length();
    vector<bool> dp(n+1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && words.count(s.substr(j, i-j))) {
          dp[i] = true;
        }
      }
    }
    return dp[n];
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;
    int n = 0;
    cin >> n;
    vector<string> word_dict(n);
    for (int i = 0; i < n; ++i) {
      cin >> word_dict[i];
    }

    bool ans = Solution1().word_break(s, word_dict);
    cout << ans << endl;
    ans = Solution2().word_break(s, word_dict);
    cout << ans << endl;
  }
  return 0;
}
