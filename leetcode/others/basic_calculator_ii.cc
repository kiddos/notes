#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  int calculate(const string& s) {
    stack<int> nums;
    char ops = '+';
    int val = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (isdigit(s[i])) val = val * 10 + (s[i]-'0');
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.length()-1) {
        if (ops == '+') nums.push(val);
        else if (ops == '-') nums.push(-val);
        else if (ops == '*') {
          int v = nums.top();
          nums.pop();
          nums.push(v * val);
        } else if (ops == '/') {
          int v = nums.top();
          nums.pop();
          nums.push(v / val);
        }

        ops = s[i];
        val = 0;
      }
    }
    int ans = 0;
    while (!nums.empty()) {
      ans += nums.top();
      nums.pop();
    }
    return ans;
  }
};


class Solution2 {
 public:
  int calculate(const string& s) {
    vector<int> operand;
    stack<int> ops;
    int i = 0;
    while (i < s.length()) {
      if (isdigit(s[i])) {
        int val = 0;
        while (i < s.length() && isdigit(s[i])) {
          val = val * 10 + (s[i++] - '0');
        }
        operand.push_back(val);
      } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        while (!ops.empty() && order(ops.top()) >= order(s[i])) {
          int v = operand.back();
          operand.pop_back();
          operand.back() = compute(operand.back(), v, ops.top());
          ops.pop();
        }
        ops.push(s[i++]);
      } else {
        ++i;
      }
    }
    while (!ops.empty()) {
      int v = operand.back();
      operand.pop_back();
      operand.back() = compute(operand.back(), v, ops.top());
      ops.pop();
    }
    return operand.back();
  }

  int order(char op) {
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    return 0;
  }

  int compute(int v1, int v2, char op) {
    if (op == '+') return v1+v2;
    else if (op == '-') return v1-v2;
    else if (op == '*') return v1*v2;
    else if (op == '/') return v1/v2;
    return 0;
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

    int ans = Solution1().calculate(line);
    cout << line << " = " << ans << endl;

    ans = Solution2().calculate(line);
    cout << line << " = " << ans << endl;
  }
  return 0;
}
