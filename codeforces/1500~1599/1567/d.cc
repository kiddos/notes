#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_digits(int x) {
  vector<int> digits;
  while (x > 0) {
    digits.push_back(x % 10);
    x /= 10;
  }
  return digits;
}

void solve() {
  int s = 0, n = 0;
  cin >> s >> n;
  vector<int> digits = get_digits(s);
  int total_digit = accumulate(digits.begin(), digits.end(), 0);
  int d = digits.size();

  vector<int> ans;
  if (total_digit >= n) {
    int last = s;
    for (int i = 0, p10 = 1; i < d; ++i, p10 *= 10) {
      while (digits[i] > 0 && n > 1) {
        digits[i]--;
        last -= p10;
        ans.push_back(p10);
        n--;
      }
    }
    if (last > 0) {
      ans.push_back(last);
    }
  } else {
    int missing = n - total_digit;
    // cout << "missing=" << missing << endl;
    while (missing > 0) {
      for (int i = 1; i < d; ++i) {
        if (digits[i] > 0) {
          digits[i]--;
          digits[i-1] += 10;
          missing -= 9;
          break;
        }
      }
    }
    // for (int i = 0; i < d; ++i) {
    //   cout << digits[i] << " ";
    // }
    // cout << endl;

    for (int i = 0, p10 = 1; i < d; ++i, p10 *= 10) {
      for (int c = 0; c < digits[i]; ++c) {
        ans.push_back(p10);
      }
    }
    reverse(ans.begin(), ans.end());
    while ((int)ans.size() > n) {
      int last1 = ans.back();
      ans.pop_back();
      int last2 = ans.back();
      ans.pop_back();
      ans.push_back(last1 + last2);
    }
  }

  for (int ai : ans) {
    cout << ai << " ";
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
