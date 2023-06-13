#include <bits/stdc++.h>

using namespace std;

void solve() {
  string correct = "Timur";
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  sort(correct.begin(), correct.end());
  sort(s.begin(), s.end());

  if (correct == s) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
