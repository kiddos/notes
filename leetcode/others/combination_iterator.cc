#include <bits/stdc++.h>

using namespace std;

class CombinationIterator {
 public:
  CombinationIterator(const string& characters, int size) : index_(0) {
    generate(characters, "", 0, size);
  }

  string next() {
    return combinations_[index_++];
  }

  bool has_next() {
    return index_ < combinations_.size();
  }

 private:
  void generate(const string& characters, const string& expr, int start, int size) {
    if (expr.length() == size) {
      combinations_.push_back(expr);
      return;
    }
    if (start < characters.length()) {
      generate(characters, expr + characters[start], start+1, size);
      generate(characters, expr, start+1, size);
    }
  }

  vector<string> combinations_;
  int index_;
};


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string line;
    int n = 0;
    cin >> line >> n;
    cout << line << ": " << n << endl;
    CombinationIterator it(line, n);
    while (it.has_next()) {
      cout << it.next() << " ";
    }
    cout << endl;
  }
  return 0;
}
