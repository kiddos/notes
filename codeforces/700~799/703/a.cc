#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int mishka = 0, chris = 0;
  for (int i = 0; i < n; ++i) {
    int m = 0, c = 0;
    cin >> m >> c;
    if (m > c) {
      mishka++;
    } else if (c > m) {
      chris++;
    }
  }
  if (mishka > chris) {
    cout << "Mishka" << endl;
  } else if (chris > mishka) {
    cout << "Chris" << endl;
  } else {
    cout << "Friendship is magic!^^" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
