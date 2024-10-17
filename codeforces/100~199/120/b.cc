#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  int n = 0, k = 0;
  input >> n >> k;
  vector<int> a(n+1);
  for (int i = 1; i <= n;++i) {
    input >> a[i];
  }

  while (a[k] == 0) {
    k++;
    if (k > n) {
      k = 1;
    }
  }

  output << k << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
