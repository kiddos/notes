#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> count(26);
  for (char ch : s) {
    int c = ch - 'a';
    count[c]++;
  }
  int zeros = count.back();
  string z = "zero";
  for (char ch : z) {
    count[ch-'a'] -= zeros;
  }
  int one = count['o'-'a'];
  for (int k = 0; k < one; ++k) {
    cout << "1 ";
  }
  for (int k = 0; k < zeros; ++k) {
    cout << "0 ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
