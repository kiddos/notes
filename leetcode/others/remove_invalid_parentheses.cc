#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> removeInvalidParentheses(const string& s) {
    vector<string> ans;
    remove(s, 0, 0, '(', ')', ans);
    return ans;
  }

 private:
  void remove(const string& s, int m, int n, char left, char right, vector<string>& ans) {
    int count = 0;
    int len = s.length();
    for (int i = m; i < len; ++i) {
      if (s[i] == left) count++;
      else if (s[i] == right) count--;
      if (count >= 0) continue;
      for (int j = n; j <= i; ++j) {
        if (s[j] == right && (j == n || s[j-1] != right)) {
          remove(s.substr(0, j) + s.substr(j+1), i, j, left, right, ans);
        }
      }
      return;
    }
    string r(s);
    reverse(r.begin(), r.end());
    if (left == '(') {
      remove(r, 0, 0, right, left, ans);
    } else {
      ans.push_back(r);
    }
  }
};

int main(void) {
  string line;
  cin >> line;
  int T = stoi(line);
  for (int t = 0; t < T; ++t) {
    cin >> line;
    cout << "input: " << line << endl;
    vector<string> ans = Solution().removeInvalidParentheses(line);
    cout << "[";
    for (string a : ans) {
      cout << a << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}
