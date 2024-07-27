#include <bits/stdc++.h>

using namespace std;


class Solution1 {
 public:
  string shortestPalindrome(const string& s) {
    string rev(s);
    reverse(rev.begin(), rev.end());

    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s.substr(0, n-i) == rev.substr(i)) {
        return rev.substr(0, i) + s;
      }
    }
    return "";
  }
};


class Solution2 {
 public:
  string shortestPalindrome(const string& s) {
    int n = s.length();
    int i = 0;
    for (int j = n-1; j >= 0; --j) {
      if (s[i] == s[j]) i++;
    }
    if (i == n) return s;

    string rev(s.substr(i));
    reverse(rev.begin(), rev.end());
    return rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string line;
    cin >> line;
    cout << Solution1().shortestPalindrome(line) << endl;
    cout << Solution2().shortestPalindrome(line) << endl;
  }

  return 0;
}
