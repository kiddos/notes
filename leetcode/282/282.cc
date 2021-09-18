#include <bits/stdc++.h>

using namespace std;

// Expression Add Operators
//
// recursive:
// for i from index to n
//  find num[index:i] + generate(i+1, n) = target
//
// the tricky part is the multiplication
// we need to store the last value for recursion
// for addition the last value = val
// for subtraction the last value = -val
// for multiplication the last value = last value * val

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    int n = num.length();
    function<void(int, long, long, const string&)> generate =
        [&](int index, long sum, long last, const string& s) {
          if (index == n) {
            if (sum == target) ans.push_back(s);
            return;
          }

          for (int i = index; i < n; ++i) {
            string prefix = num.substr(index, i - index + 1);
            long val = stol(prefix);
            if (prefix.length() == 1 || prefix[0] != '0') {
              generate(i + 1, sum + val, val, s + "+" + prefix);
              generate(i + 1, sum - val, -val, s + "-" + prefix);
              generate(i + 1, sum - last + last * val, last * val,
                       s + "*" + prefix);
            }
          }
        };
    for (int i = 0; i < n; ++i) {
      string prefix = num.substr(0, i + 1);
      long val = stol(prefix);
      if (prefix.length() == 1 || prefix[0] != '0')
        generate(i + 1, val, val, prefix);
    }
    return ans;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> ans = Solution().addOperators("3456237490", 9159);
  for (string a : ans) cout << a << endl;
  cout << endl;

  ans = Solution().addOperators("123", 6);
  for (string a : ans) cout << a << endl;
  cout << endl;

  ans = Solution().addOperators("232", 8);
  for (string a : ans) cout << a << endl;
  cout << endl;
  return 0;
}
