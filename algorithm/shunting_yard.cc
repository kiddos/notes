#include <bits/stdc++.h>

using namespace std;

bool is_func(const string& op) {
  return op == "sin" || op == "cos" || op == "tan";
}

int order(const string& op) {
  if (op == "+" || op == "-") return 1;
  if (op == "*" || op == "/") return 2;
  if (is_func(op)) return 3;
  return 0;
}

double compute(double v1, double v2, const string& op) {
  if (op == "+") return v1+v2;
  else if (op == "-") return v1-v2;
  else if (op == "*") return v1*v2;
  else if (op == "/") return v1/v2;
  return 0;
}

void eval(stack<double>& operands, stack<string>& ops) {
  string op = ops.top();
  ops.pop();
  if (op == "sin") {
    operands.top() = sin(operands.top());
  } else if (op == "cos") {
    operands.top() = cos(operands.top());
  } else if (op == "tan") {
    operands.top() = tan(operands.top());
  } else {
    double v2 = operands.top();
    operands.pop();
    double v1 = operands.top();
    operands.top() = compute(v1, v2, op);
  }
}

double shunting_yard(const string& s) {
  stack<double> operands;
  stack<string> ops;

  int i = 0;
  int n = s.length();
  while (i < n) {
    if (isdigit(s[i])) {
      string v;
      while (i < n && (isdigit(s[i]) || s[i] == '.')) {
        v += s[i++];
      }
      operands.push(stod(v));
    } else if (order(string(1, s[i])) > 0) {
      while (!ops.empty() && order(ops.top()) >= order(string(1, s[i]))) {
        eval(operands, ops);
      }
      ops.push(string(1, s[i++]));
    } else if (s[i] == '(') {
      ops.push(string(1, s[i++]));
    } else if (s[i] == ')') {
      while (!ops.empty() && ops.top() != "(") {
        eval(operands, ops);
      }
      if (!ops.empty() && ops.top() == "(") ops.pop();
      i++;
    } else {
      i++;
    }
  }

  while (!ops.empty()) {
    eval(operands, ops);
  }
  if (operands.empty()) return 0;
  return operands.top();
}


int main(void) {
  int T = 0;
  cin >> T;
  string empty;
  getline(cin, empty);
  for (int t = 0; t < T; ++t) {
    string line;
    getline(cin, line);

    double ans = shunting_yard(line);
    cout << line << " = " << ans << endl;
  }
  return 0;
}
