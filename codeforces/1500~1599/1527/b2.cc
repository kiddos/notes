#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_palindrome(const string& s) {
  int l = 0, r = s.length()-1;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }
  return true;
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (is_palindrome(s)) {
    int zeros = 0;
    for (char ch : s) {
      zeros += ch == '0';
    }
    if (zeros == 0) {
      cout << "DRAW" << endl;
      return;
    }

    if (n % 2 == 1 && s[n/2] == '0' && zeros > 1) {
      cout << "ALICE" << endl;
    } else {
      cout << "BOB" << endl;
    }
  } else {
    // if not palindrom,
    // bob has to make 10 pair to 11
    // and the middle 0 -> 1 if the middle is 0
    // and alice will make the 1st 00 pair to 11 to make it palindrome
    // and bob will make the 2nd 00 pair to 11 to make it palindrome
    // since alice goes first
    // if she knows bob will win, she can start removing 01 to win
    // only way to draw is the middle is 0 and there is one 01 pair
    int diff = 0, same = 0;
    for (int l = 0, r = n-1; l < r; ++l, --r) {
      if (s[l] != s[r]) {
        diff++;
      } else {
        if (s[l] == '0' && s[r] == '0') {
          same++;
        }
      }
    }

    int middle = 0;
    if (n % 2 == 1 && s[n/2] == '0') {
      middle++;
    }
    if (middle == 1 && diff == 1 && same == 0) {
      cout << "DRAW" << endl;
    } else {
      cout << "ALICE" << endl;
    }
  }
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
