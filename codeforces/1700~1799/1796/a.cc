#include <bits/stdc++.h>

using namespace std;

unordered_set<string> valid;

void precompute() {
  int k = 1000;
  string fb;
  for (int i = 1; i < k; ++i) {
    if (i % 3 == 0) {
      fb.push_back('F');
    }
    if (i % 5 == 0) {
      fb.push_back('B');
    }
  }
  for (int len = 1; len <= 10; ++len) {
    for (int i = 0; i <= fb.length()-len; ++i) {
      valid.insert(fb.substr(i,len));
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    if (valid.count(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
