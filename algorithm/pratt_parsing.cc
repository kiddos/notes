#include <bits/stdc++.h>

using namespace std;

enum TokenType {
  NUMERICS_TOKEN,
  OP_TOKEN,
  EOF_TOKEN,
};

unordered_set<char> OPS = {'+', '-', '*', '/', '&', '|'};

class Lexer {
 public:
  Lexer(const string& expr) : expr_(expr), idx_(0) {}

  TokenType GetToken() {
    token_.clear();

    int n = expr_.length();
    while (isspace(expr_[idx_])) {
      idx_++;
    }

    if (isdigit(expr_[idx_])) {
      while (idx_ < n && isdigit(expr_[idx_])) {
        token_.push_back(expr_[idx_++]);
      }
      return NUMERICS_TOKEN;
    } else if (OPS.count(expr_[idx_])){
      token_ = expr_[idx_++];
      return OP_TOKEN;
    }
    return EOF_TOKEN;
  }

  TokenType GetNextToken() {
    return current_ = GetToken();
  }

  string GetCurrentToken() {
    return token_;
  }

  TokenType GetCurrentTokenType() {
    return current_;
  }

 private:
  string expr_;
  int idx_;
  string token_;
  TokenType current_;
};

unordered_map<string, int> OPS_PRECEDENCE = {{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"&", '4'}, {"|", '3'}};

int evaluate(int a, int b, const string& op) {
  if (op == "+") return a + b;
  else if (op == "-") return a - b;
  else if (op == "*") return a * b;
  else if (op == "/") return a / b;
  
  cerr << "invalid op" << endl;
  return 0;
}

int parse(Lexer& lexer, int min_precedence) {
  TokenType t = lexer.GetNextToken();
  if (t != NUMERICS_TOKEN) {
    cerr << "expects a numeric token here" << endl;
    return 0;
  }
  int lhs = stoi(lexer.GetCurrentToken());

  lexer.GetNextToken();
  while (true) {
    auto token_type = lexer.GetCurrentTokenType();
    if (token_type == EOF_TOKEN) {
      break;
    }

    if (token_type != OP_TOKEN) {
      cerr << "expects an operator here" << endl;
      break;
    }
    string op = lexer.GetCurrentToken();

    auto token = lexer.GetCurrentToken();
    int precedence = OPS_PRECEDENCE[token];
    if (precedence < min_precedence) {
      break;
    }

    int rhs = parse(lexer, precedence);

    lhs = evaluate(lhs, rhs, op);
  }

  return lhs;
}

int parse(const string& expr) {
  Lexer lexer(expr);

  // while (tokenizer.GetNextToken() != EOF_TOKEN) {
  //   cout << "token: " << tokenizer.GetCurrentTokenType() << " -> " << tokenizer.GetCurrentToken() << endl;
  // }

  return parse(lexer, 0);
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // string e = "10 + 3 * 4 + 6 / 3";
  // int result = parse(e);
  // cout << "ans= " << result << endl;

  assert(parse("10 + 3 * 4 - 6 / 3") == 20);
  assert(parse("10 + 6 * 3") == 28);

  return 0;
}
