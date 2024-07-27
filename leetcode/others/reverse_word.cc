#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  string reverseWords(string& s) {
    string copy = s;
    stringstream ss(copy);
    stack<string> st;
    string x;
    while (ss >> x) {
      st.push(x);
    }
    bool first = true;
    string ans;
    while (st.size() > 0) {
      if (!first) ans += ' ';
      ans += st.top();
      st.pop();
      first = false;
    }
    return ans;
  }
};

class Solution2 {
 public:
  string reverseWords(string& s) {
    string copy = s;
    reverse(copy.begin(), copy.end());

    int n = copy.length();
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
      if (copy[i] != ' ') copy[end++] = copy[i];
      else if (i > 0 && copy[i-1] != ' ') {
        reverse(copy.begin()+start, copy.begin()+end);
        copy[end++] = ' ';
        start = end;
      }
    }
    reverse(copy.begin()+start, copy.begin()+end);
    if (end > 0 && copy[end-1] == ' ') end = end -1;
    return copy.substr(0, end);
  }
};

class Solution3 {
 public:
  string reverseWords(string& s) {
    string copy = s;
    stack<string> st;
    while (copy.length() > 0) {
      auto index = copy.find(' ');
      if (index != string::npos) {
        string word = copy.substr(0, index);
        if (word.length()) st.push(word);
        copy = copy.substr(index+1);
      } else {
        if (copy.length()) st.push(copy);
        copy = "";
      }
    }

    string ans;
    while (st.size() > 0) {
      ans += st.top() + " ";
      st.pop();
    }
    ans.pop_back();
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  string empty;
  getline(cin, empty);
  for (int t = 0; t < T; ++t) {
    string s;
    getline(cin, s);
    // cout << s << endl;

    string reversed = Solution1().reverseWords(s);
    cout << reversed << endl;

    reversed = Solution2().reverseWords(s);
    cout << reversed << endl;

    reversed = Solution3().reverseWords(s);
    cout << reversed << endl;
  }
  return 0;
}
