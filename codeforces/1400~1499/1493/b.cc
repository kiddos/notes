#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string format(int h, int m) {
  stringstream ss;
  ss << setfill('0') << setw(2) << h;
  ss << ":";
  ss << setfill('0') << setw(2) << m;
  return ss.str();
}

void solve() {
  int h = 0, m = 0;
  cin >> h >> m;
  string s;
  cin >> s;

  auto is_correct_reflection = [&](int t, int max_t) {
    string digits = to_string(t);
    if (digits.length() < 2) {
      digits = "0" + digits;
    }
    int n = digits.length();
    string reverse_digits;
    for (int i = n-1; i >= 0; --i) {
      char ch = digits[i];
      if (ch == '3' || ch == '4' || ch == '6' || ch == '7' || ch == '9') {
        return false;
      }
      if (ch == '2') {
        reverse_digits.push_back('5');
      } else if (ch == '5') {
        reverse_digits.push_back('2');
      } else if (ch == '0') {
        reverse_digits.push_back('0');
      } else if (ch == '1') {
        reverse_digits.push_back('1');
      } else if (ch == '8') {
        reverse_digits.push_back('8');
      }
    }
    // cout << "reverse:" << reverse_digits << endl;

    int reverse_t = stoi(reverse_digits);
    if (reverse_t >= max_t) {
      return false;
    }
    return true;
  };

  int current_h = stoi(s.substr(0, 2));
  int current_m = stoi(s.substr(3));
  int t = current_h * m + current_m;
  string ans;
  int min_diff = numeric_limits<int>::max();
  for (int h2 = 0; h2 < h; ++h2) {
    if (is_correct_reflection(h2, m)) {
      for (int m2 = 0; m2 < m; ++m2) {
        if (is_correct_reflection(m2, h)) {
          int t2 = h2 * m + m2;
          int diff = t2 - t;
          if (diff < 0) diff += m * h;
          if (diff < min_diff) {
            min_diff = diff;
            ans = format(h2, m2);
          }
        }
      }
    }
  }
  cout << ans << endl;
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
