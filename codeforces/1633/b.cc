#include <bits/stdc++.h>

using namespace std;

int solve(const string& s) {
  int ones = 0, zeros = 0;
  for (char c : s) {
    zeros += c == '0';
    ones += c == '1';
  }
  if (zeros == ones) {
    return zeros-1;
  } else {
    return min(zeros, ones);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;
    cin >> s;

    cout << solve(s) << endl;
  }
  return 0;
}
