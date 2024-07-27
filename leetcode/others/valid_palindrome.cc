#include <bits/stdc++.h>

using namespace std;


class Solution {
 public:
  bool isPalindrome(const string& s) {
    int i = 0, j = s.length()-1;
    while (i < j) {
      while (i < j && !isalnum(s[i])) i++;
      while (j > i && !isalnum(s[j])) j--;
      if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
    return true;
  }
};



int main(void) {
  int T = 0;
  scanf("%d\n", &T);
  for (int t = 0; t < T; ++t) {
    string line;
    getline(cin, line);
    cout << line << endl;
    bool ans = Solution().isPalindrome(line);
    cout << ans << endl;
  }

  return 0;
}
