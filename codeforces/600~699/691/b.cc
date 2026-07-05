#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;

  string middle = "AHIMOoTUVvWwXxY";
  string left = "bdpq";
  string right = "dbqp";
  int n = s.length();

  auto find_opposite = [&](char c) -> char {
    for (char ch : middle) {
      if (c == ch) {
        return ch;
      }
    }
    for (int i = 0; i < (int)left.length(); ++i) {
      if (left[i] == c) {
        return right[i];
      }
    }
    return '\0';
  };

  int size = (n+1) / 2;
  for (int i = 0; i < size; ++i) {
    int j = n-i-1;
    if (i == j) {
      auto m = middle.find(s[i]);
      if (m == string::npos) {
        cout << "NIE" << endl;
        return;
      }
    } else {
      char opposite = find_opposite(s[i]);
      if (s[j] != opposite) {
        cout << "NIE" << endl;
        return;
      }
    }
  }
  cout << "TAK" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
