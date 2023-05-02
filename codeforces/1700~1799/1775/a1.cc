#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
  int n = s.length();
  char first = s[0], last = s.back();
  if (first == last) {
    cout << first << " " << s.substr(1, n-2) << " " << last << endl;;
  } else {
    string mid = s.substr(1, n-2);
    if (mid == string(mid.length(), 'a')) {
      if (first == 'a') {
        cout << mid << " " << first << " " << last << endl;
      } else {
        cout << first << " " << last << " " << mid << endl;
      }
    } else {
      auto index = mid.find('a');
      if (index != string::npos) {
        // make xxx a xxx
        cout << s.substr(0, index+1) << " " << 'a' << " " << s.substr(index+2)  << endl;
      } else {
        // all b
        cout << first << " " << mid << " " << last << endl;
      }
    }
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
    solve(s);
  }
  return 0;
}
