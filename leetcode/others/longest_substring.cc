#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  int lengthOfLongestSubstring(const string& s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      unordered_set<int> have;
      for (int j = i; j < n; ++j) {
        if (have.count(s[j])) break;
        have.insert(s[j]);
        ans = max(ans, j-i+1);
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int lengthOfLongestSubstring(const string& s) {
    int i = 0, j = 0;
    int n = s.length();
    int ans = 0;
    unordered_set<int> have;
    while (i < n && j < n) {
      if (!have.count(s[j])) {
        have.insert(s[j++]);
        ans = max(ans, j-i);
      } else {
        have.erase(s[i++]);
      }
    }
    return ans;
  }
};

class Solution3 {
 public:
  int lengthOfLongestSubstring(const string& s) {
    int i = -1;
    int ans = 0;
    unordered_map<int, int> have;
    int n = s.length();
    for (int j = 0; j < n; ++j) {
      if (have.count(s[j])) {
        i = max(i, have[s[j]]);
      }
      ans = max(ans, j-i);
      have[s[j]] = j;
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;

    cout << "string: " << s << endl;
    int ans = Solution1().lengthOfLongestSubstring(s);
    cout << "solution1: " << ans << endl;
    ans = Solution2().lengthOfLongestSubstring(s);
    cout << "solution2: " << ans << endl;
    ans = Solution3().lengthOfLongestSubstring(s);
    cout << "solution3: " << ans << endl;
  }
  return 0;
}
