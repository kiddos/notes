#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<i64> digits(n);
  for (int i = 0; i < n; ++i) {
    digits[i] = s[i] - '0';
  }

  i64 sum = 0;
  for (int i = 0; i < n; ++i) {
    i64 add = sum;
    sum += digits[i];
    digits[i] += add;
  }

  i64 c = 0;
  for (int i = n-1; i >= 0; --i) {
    if (digits[i] >= 10) {
      c = digits[i] / 10;
      digits[i] %= 10;
      if (i-1 >= 0) {
        digits[i-1] += c;
      } else {
        if (c) {
          digits.insert(digits.begin(), c);
        }
      }
    } else {
      break;
    }
  }

  int i = 0;
  while (i < (int)digits.size() && digits[i] == 0) {
    i++;
  }
  for (; i < (int)digits.size(); ++i) {
    cout << digits[i];
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
