#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  int pos = 0, neg = 0;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    if (a > 0) pos++;
    else neg++;
  }

  int a = pos, b = neg;
  for (int i = 0, likes = 0; i < n; ++i) {
    if (a > 0) {
      a--;
      likes++;
    } else {
      b--;
      likes--;
    }
    cout << likes << " ";
  }
  cout << endl;

  a = pos, b = neg;
  for (int i = 0, likes = 0; i < n; ++i) {
    if (likes > 0 && b > 0) {
      b--;
      likes--;
    } else {
      a--;
      likes++;
    }
    cout << likes << " ";
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
