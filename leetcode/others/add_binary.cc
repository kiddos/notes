#include <bits/stdc++.h>

using namespace std;


class Solution {
 public:
  string addBinary(const string& a, const string& b) {
    int i = a.length()-1, j = b.length()-1;
    int carry = 0;
    string ans;
    while (i >= 0 || j >= 0 || carry) {
      int ai = i >= 0 ? a[i--] - '0' : 0;
      int bj = j >= 0 ? b[j--] - '0' : 0;
      int bit = ai + bj + carry;
      carry = bit / 2;
      bit %= 2;
      ans += (bit + '0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};


int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string a, b;
    cin >> a >> b;

    string ans = Solution().addBinary(a, b);
    cout << a << " + " << b << " = " << ans << endl;
  }
  return 0;
}
