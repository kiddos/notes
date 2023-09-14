#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int rating = 0;
  cin >> rating;
  if (rating <= 1399) {
    cout << "Division 4" << endl;
  } else if (rating <= 1599) {
    cout << "Division 3" << endl;
  } else if (rating <= 1899) {
    cout << "Division 2" << endl;
  } else {
    cout << "Division 1" << endl;
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
