#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string binary(int x, size_t width) {
  string b;
  while (x > 0) {
    b.push_back((x % 2) + '0');
    x /= 2;
  }
  reverse(b.begin(), b.end());
  if (b.length() < width) {
    b = string(width - b.length(), '0') + b;
  }
  return b;
}

void solve() {
  int n = 0;
  cin >> n;
  int m = 1<<n;
  vector<int> gray;
  for (int i = 0; i < m; ++i) {
    gray.push_back(i ^ (i>>1));
  }
  for (int g : gray){
    cout << binary(g, n) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
