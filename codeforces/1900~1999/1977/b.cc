#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;
  vector<int> digits;
  while (x > 0) {
    digits.push_back(x % 2);
    x >>= 1;
  }

  vector<int> ans;
  int n = digits.size();
  for (int i = 0; i < (int)digits.size(); ++i) {
    if (digits[i] == 0) {
      ans.push_back(0);
    } else {
      if (i+1 < n && digits[i] == 1 && digits[i+1] == 1) {
        // add 1
        digits[i] = 0;
        int j = i+1;
        for (; j < (int)digits.size() && digits[j] == 1; ++j) {
          digits[j] = 0;
        }
        if (j < (int)digits.size()) {
          digits[j] = 1;
        } else {
          digits.push_back(1);
        }

        // subtract 1
        ans.push_back(-1);
      } else {
        ans.push_back(1);
      }
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
