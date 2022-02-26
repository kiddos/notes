#include <bits/stdc++.h>

using namespace std;

// Substring with Concatenation of All Words
//
// the question provided that words for all the same length
// try all possibility for every possible starting index
// ie. if the current word has some left continue to search until the count is 0

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> count;
    unordered_set<int> lengths;
    int total_len = 0;
    for (string& word : words) {
      total_len += word.length();
      count[word]++;
      lengths.insert(word.length());
    }

    int used = 0;
    function<bool(int)> dfs = [&](int index) {
      if (used == words.size()) return true;
      for (int len : lengths) {
        string p = s.substr(index, len);
        if (count.count(p) && count[p] > 0) {
          count[p]--;
          used++;
          if (dfs(index + len)) {
            used--;
            count[p]++;
            return true;
          }
          count[p]++;
          used--;
        }
      }
      return false;
    };

    vector<int> ans;
    int n = s.length();
    for (int i = 0; i <= n - total_len; ++i) {
      if (dfs(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};
  vector<int> ans = Solution().findSubstring(s, words);
  vector<int> true_ans = {0, 9};
  sort(ans.begin(), ans.end());
  assert(ans.size() == true_ans.size());
  for (int i = 0; i < true_ans.size(); ++i) assert(ans[i] == true_ans[i]);

  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "word"};
  true_ans = {};
  ans = Solution().findSubstring(s, words);
  assert(ans.size() == true_ans.size());
  for (int i = 0; i < true_ans.size(); ++i) assert(ans[i] == true_ans[i]);

  s = "barfoofoobarthefoobarman";
  words = {"bar", "foo", "the"};
  true_ans = {6, 9, 12};
  ans = Solution().findSubstring(s, words);
  assert(ans.size() == true_ans.size());
  for (int i = 0; i < true_ans.size(); ++i) assert(ans[i] == true_ans[i]);

  return 0;
}
