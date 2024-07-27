#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void addOperators(const string& num, const string& expression, vector<string>& ans, long sum, long last, char op, int target) {
    int n = num.length();
    if (n == 0) {
      if (sum == target) ans.push_back(expression);
      // cout << expression << " = " << sum << endl;
    } else {
      for (int i = 1; i <= n; ++i) {
        string prefix = num.substr(0, i);
        string suffix = num.substr(i);
        if (prefix.length() > 1 && prefix[0] == '0') continue;
        long val = stol(prefix);
        addOperators(suffix, expression + "+" + prefix, ans, sum + val, val, '+', target);
        addOperators(suffix, expression + "-" + prefix, ans, sum - val, val, '-', target);
        if (op == '+') {
          addOperators(suffix, expression + "*" + prefix, ans, sum - last + val * last, val * last, '+', target);
        } else {
          addOperators(suffix, expression + "*" + prefix, ans, sum + last - val * last, val * last, '-', target);
        }
      }
    }
  }


  vector<string> addOperators(const string& num, int target) {
    int n = num.length();
    vector<string> ans;
    for (int i = 1; i <= n; ++i) {
      string prefix = num.substr(0, i);
      string suffix = num.substr(i);
      if (prefix.length() > 1 && prefix[0] == '0') continue;
      long val = stol(prefix);
      addOperators(suffix, prefix, ans, val, val, '+', target);
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string line;
    int target = 0;
    cin >> line >> target;
    cout << line << ": " << target << endl;

    auto ans = Solution().addOperators(line, target);
    for (string a : ans) cout << a << " ";
    cout << endl;
  }
  return 0;
}
