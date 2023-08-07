#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> digits(n);
  for (int i = 0; i < n; ++i) {
    char ch = '\0';
    cin >> ch;
    digits[i] = ch -'0';
  }
  
  vector<int> output;
  if (digits[0] != 9) {
    for (int i = 0; i < n; ++i) {
      output.push_back(9 - digits[i]);
    }
  } else {
    vector<int> result = {1};
    for (int i = 1; i < n; ++i) result.push_back(8);
    result.push_back(1);

    reverse(digits.begin(), digits.end());
    for (int i = 0; i < result.size(); ++i) {
      int d1 = result[i];
      int d2 = i < digits.size() ? digits[i] : 0;
      if (d1 < d2) {
        d1 += 10;
        result[i+1]--;
      }
      output.push_back(d1 - d2);
    }
    while (output.back() == 0) output.pop_back();
    reverse(output.begin(), output.end());
  }

  for (int d : output) {
    cout << d;
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
