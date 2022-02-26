#include <bits/stdc++.h>

using namespace std;

// Tag Validator
//
// implementation practice

bool is_upper(const string& s) {
  for (char c : s)
    if (c < 'A' || c > 'Z') return false;
  return true;
}

class Solution {
 public:
  bool isValid(string code) {
    int n = code.length();
    stack<string> tags;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && tags.empty()) return false;
      if (code.find("<![CDATA[", i) == i) {
        int j = code.find("]]>", i);
        if (j == string::npos) return false;
        i = j + 2;
      } else if (code.find("</", i) == i) {
        int j = code.find(">", i);
        if (j == string::npos) return false;
        string tag = code.substr(i + 2, j - i - 2);
        if (tags.empty() || tags.top() != tag) return false;
        tags.pop();
        i = j;
      } else if (code.find("<", i) == i) {
        int j = code.find(">", i);
        if (j == string::npos) return false;
        string tag = code.substr(i + 1, j - i - 1);
        if (!is_upper(tag)) return false;
        if (tag.length() < 1 || tag.length() > 9) return false;
        tags.push(tag);
        i = j;
      }
    }
    return tags.empty();
  }
};

int main(void) {
  string s = "<AAAAAAAAAA></AAAAAAAAAA>";
  bool ans = Solution().isValid(s);
  assert(!ans);

  s = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
  ans = Solution().isValid(s);
  assert(ans);

  s = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
  ans = Solution().isValid(s);
  assert(ans);

  s = "<A>  <B> </A>   </B>";
  ans = Solution().isValid(s);
  assert(!ans);

  s = "<A<></A<>";
  ans = Solution().isValid(s);
  assert(!ans);

  s = "<DIV><></></DIV>";
  ans = Solution().isValid(s);
  assert(!ans);

  s = "<A></A><B></B>";
  ans = Solution().isValid(s);
  assert(!ans);

  s = "<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>";
  ans = Solution().isValid(s);
  assert(!ans);
  return 0;
}
