#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> maxNumOfSubstrings(const string& s) {
    int n = s.length();
    vector<int> left(n, numeric_limits<int>::max());
    vector<int> right(n, numeric_limits<int>::min());
    for (int i = 0; i < n; ++i) {
      left[s[i]-'a'] = min(left[s[i]-'a'], i);
      right[s[i]-'a'] = max(right[s[i]-'a'], i);
    }

    vector<string> ans;
    int last = -1;
    for (int i = 0; i < n; ++i) {
      int r = find_right(s, i, left, right);
      if (r >= 0) {
        if (i > last) {
          ans.push_back("");
        }
        last = r;
        ans.back() = s.substr(i, r-i+1);
      }
    }
    return ans;
  }

 private:
  int find_right(const string& s, int i, vector<int>& left, vector<int>& right) {
    int r = right[s[i]-'a'];
    for (int j = i; j <= r; ++j) {
      if (left[s[j]-'a'] < i) return -1;
      r = max(r, right[s[j]-'a']);
    }
    return r;
  }
};

int main(void) {
  string s = "adefaddaccc";
  vector<string> ans = Solution().maxNumOfSubstrings(s);
  for (string a : ans) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
