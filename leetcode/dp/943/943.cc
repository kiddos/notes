#include <bits/stdc++.h>

using namespace std;

// Find the Shortest Superstring
// this is TSP problem
//
// idea is to use DP
// 1. compute the overlapping
// 2. dp[mask][i] means the most overlapping we can get with mask and ending with ith word
// 3. after computing the DP, we need to retrace the last word to the beginning

class Solution {
 public:
  string shortestSuperstring(vector<string>& words) {
    int n = words.size();
    vector<vector<int>> overlap(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
        if (i != j) {
          overlap[i][j] = compute_overlap(words[i], words[j]);
        }
    }

    int m = 1 << n;
    vector<vector<int>> dp(m, vector<int>(n));
    vector<vector<int>> parent(m, vector<int>(n, -1));
    for (int mask = 0; mask < m; ++mask) {
      for (int i = 0; i < n; ++i)
        if (mask & (1 << i)) {
          int without_i = mask ^ (1 << i);
          for (int j = 0; j < n; ++j)
            if (without_i & (1 << j)) {
              int ol = dp[without_i][j] + overlap[j][i];
              if (ol > dp[mask][i]) {
                dp[mask][i] = ol;
                parent[mask][i] = j;
              }
            }
        }
    }

    auto last = max_element(dp.back().begin(), dp.back().end());
    int last_word = distance(dp.back().begin(), last);

    vector<int> seq;
    int current = last_word, current_mask = m - 1;
    vector<bool> visited(n);
    while (current != -1) {
      visited[current] = true;
      seq.push_back(current);
      int p = parent[current_mask][current];
      current_mask ^= (1 << current);
      current = p;
    }
    for (int i = 0; i < n; ++i)
      if (!visited[i]) seq.push_back(i);
    reverse(seq.begin(), seq.end());

    string ans = words[seq[0]];
    for (int j = 1; j < seq.size(); ++j) {
      ans += words[seq[j]].substr(overlap[seq[j - 1]][seq[j]]);
    }
    return ans;
  }

  int compute_overlap(const string& w1, const string& w2) {
    for (int len = min(w1.length(), w2.length()); len >= 0; --len) {
      if (w2.substr(0, len) == w1.substr(w1.length() - len)) return len;
    }
    return 0;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> words = {"alex", "loves", "leetcode"};
  string ans = Solution().shortestSuperstring(words);
  assert(ans == "leetcodelovesalex");

  words = {"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
  ans = Solution().shortestSuperstring(words);
  assert(ans == "gctaagttcatgcatc");

  words = {"yeeiebcz", "qbqhdytk",  "ygueikth",
           "thqzyeei", "gyygueikt", "ikthqzyee"};
  ans = Solution().shortestSuperstring(words);
  assert(ans == "qbqhdytkgyygueikthqzyeeiebcz");

  words = {"cedefifgstkyxfcuajfa",
           "ooncedefifgstkyxfcua",
           "assqjfwarvjcjedqtoz",
           "fcuajfassqjfwarvjc",
           "fwarvjcjedqtozctcd",
           "zppedxfumcfsngp",
           "kyxfcuajfassqjfwa",
           "fumcfsngphjyfhhwkqa",
           "fassqjfwarvjcjedq",
           "ppedxfumcfsngphjyf",
           "dqtozctcdk"};
  ans = Solution().shortestSuperstring(words);
  assert(ans ==
         "ooncedefifgstkyxfcuajfassqjfwarvjcjedqtozctcdkzppedxfumcfsngphjyf"
         "hhwkqa");

  // code here...
  return 0;
}

