#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;
  transform(a.begin(), a.end(), a.begin(),
            [&](char ch) { return std::tolower(ch); });
  transform(b.begin(), b.end(), b.begin(),
            [&](char ch) { return std::tolower(ch); });
  if (a < b) {
    cout << "-1" << endl;
  } else if (a == b) {
    cout << "0" << endl;
  } else {
    cout << "1" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
