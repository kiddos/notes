#include <bits/stdc++.h>

using namespace std;

// Basic Calculator
//
// shunting yard algorithm

class Solution {
 public:
  int calculate(const string& s) {
    stack<char> ops;
    stack<int> operands;
    int i = 0;
    int n = s.length();
    while (i < n) {
      if (isdigit(s[i])) {
        int val = 0;
        while (isdigit(s[i])) {
          val = val * 10 + (s[i++] - '0');
        }
        operands.push(val);
      } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
          int val2 = operands.top();
          operands.pop();
          int val1 = operands.top();
          operands.top() = compute(ops.top(), val1, val2);
          ops.pop();
        }
        ops.push(s[i++]);
      } else if (s[i] == '(') {
        ops.push(s[i++]);
      } else if (s[i] == ')') {
        while (!ops.empty() && ops.top() != '(') {
          char op = ops.top();
          ops.pop();
          int val2 = operands.top();
          operands.pop();
          int val1 = operands.top();
          operands.top() = compute(op, val1, val2);
        }
        if (!ops.empty() && ops.top() == '(') ops.pop();
        i++;
      } else {
        i++;
      }
    }
    while (!ops.empty()) {
      char op = ops.top();
      ops.pop();
      int val2 = operands.top();
      operands.pop();
      int val1 = operands.top();
      operands.top() = compute(op, val1, val2);
    }
    return operands.top();
  }

 private:
  int compute(char op, int val1, int val2) {
    if (op == '+') {
      return val1 + val2;
    } else if (op == '-') {
      return val1 - val2;
    } else if (op == '*') {
      return val1 * val2;
    } else if (op == '/') {
      return val1 / val2;
    }
    return 0;
  }

  int precedence(char op) {
    if (op == '+' || op == '-') {
      return 10;
    } else if (op == '*' || op == '/') {
      return 20;
    }
    return 0;
  }
};

int main(void) {
  // string input = "1 + 2";
  // string input = "1 + (2 - 3) * 5";
  // string input = "1 + (2 - 10) * 5 / 3 + 9 * 7";
  string input = "3 * 2 / (9 + 9 * 100) + (2 - 10) * 5 / 3 + 9 * 7";
  int ans = Solution().calculate(input);
  cout << input << " = " << ans << endl;
  return 0;
}
