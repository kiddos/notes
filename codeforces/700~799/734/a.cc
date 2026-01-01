#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int anton = 0, danik = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      anton++;
    } else if (s[i] == 'D') {
      danik++;
    }
  }
  if (anton > danik) {
    cout << "Anton" << endl;
  } else if (danik > anton) {
    cout << "Danik" << endl;
  } else {
    cout << "Friendship" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
