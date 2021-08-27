#include <bits/stdc++.h>

using namespace std;

// Valid Number
//
// this parsing might be useful when creating compiler tokenizer
// might want to remember this
//
// idea is to check with flag
// 1. if E appear:
//  if we already encounter E or we dont have a number, return false
// 2. if dot appear:
//  if we already have a dot or E, return false
// 3. if +/- appear:
//  if its not the first character or not after an E return false
// 4. else we only want numbers, and if other weird stuff appear, return false

class Solution {
 public:
  bool is_number(string s) {
    int n = s.length();
    bool has_dot = false, has_number = false, has_e = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        has_number = true;
      } else if (s[i] == 'e' || s[i] == 'E') {
        if (has_e || !has_number) return false;
        has_number = false;
        has_e = true;
      } else if (s[i] == '.') {
        if (has_dot || has_e) return false;
        has_dot = true;
      } else if (s[i] == '-' || s[i] == '+') {
        if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
      } else {
        return false;
      }
    }
    return has_number;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ifstream f("./test_case.txt", ios::in);
  string line;
  while (getline(f, line)) {
    // cout << line << endl;
    bool ans = Solution().is_number(line);
    cout << (ans ? "true" : "false") << endl;
  }

  return 0;
}
