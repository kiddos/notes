#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n < 5) {
    cout << "Too weak" << endl;
    return;
  }
  bool has_digit = false, has_upper = false, has_lower = false;
  for (int i = 0; i < n; ++i) {
    if (isdigit(s[i])) {
      has_digit = true;
    }
    if (isupper(s[i])) {
      has_upper = true;
    }
    if (islower(s[i])) {
      has_lower = true;
    }
  }

  if (has_digit && has_upper && has_lower) {
    cout << "Correct" << endl;
  } else{
    cout << "Too weak" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
