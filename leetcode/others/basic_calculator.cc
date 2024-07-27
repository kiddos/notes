#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int calculate(const string& s) {
    int ans = 0, sign = 1, val = 0;
    stack<int> ss;
    for (int i = 0; i < s.length(); ++i) {
      if (isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
      } else if (s[i] == '-' || s[i] == '+') {
        ans += sign * val;
        sign = s[i] == '+' ? 1 : -1;
        val = 0;
      } else if (s[i] == '(') {
        ss.push(ans);
        ss.push(sign);
        ans = 0;
        sign = 1;
      } else if (s[i] == ')') {
        ans += sign * val;
        ans *= ss.top();
        ss.pop();
        ans += ss.top();
        ss.pop();
        val = 0;
      }
    }
    return ans + sign * val;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  string empty;
  getline(cin, empty);
  for (int t = 0; t < T; ++t) {
    string line;
    getline(cin, line);
    int ans = Solution().calculate(line);
    cout << line << " = " << ans << endl;
  }
  return 0;
}
