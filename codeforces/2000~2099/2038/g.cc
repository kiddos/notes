#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(const string& t) {
  cout << "1 " << t << endl;
  int result = 0;
  cin >> result;
  return result;
}

void solve() {
  int n = 0;
  cin >> n;
  int ends_zero = query("00");
  int ends_one = query("01");
  int zeros = query("0");
  // 0010011
  if (zeros == ends_zero + ends_one) {
    // the last digit is not zero
    cout << "0 " << n << " 1" << endl;
  } else {
    cout << "0 " << n << " 0" << endl;
  }

  int result = 0;
  cin >> result;
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
