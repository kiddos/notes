#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string removeDuplicateLetter(const string& s) {
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    stack<char> ans;
    vector<bool> used(256);
    for (char c : s) {
      count[c]--;
      if (used[c]) continue;
      while (!ans.empty() && ans.top() > c && count[ans.top()] > 0) {
        used[ans.top()] = false;
        ans.pop();
      }
      ans.push(c);
      used[c] = true;
    }

    string output;
    while (!ans.empty()) {
      output += ans.top();
      ans.pop();
    }
    reverse(output.begin(), output.end());
    return output;
  }
};

int main(void) {
  vector<string> tests = {
    "bcabc",
    "abab",
    "cbacdcbc",
    "cbacdcbcaaa",
  };

  for (string& test : tests) {
    string ans = Solution().removeDuplicateLetter(test);
    cout << ans << endl;
  }
  return 0;
}
