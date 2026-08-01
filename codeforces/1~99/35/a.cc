#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  int n = 0;
  input >> n;
  int current = n;

  for (int i = 0; i < 3; ++i) {
    int a = 0, b = 0;
    input >> a >> b;
    if (a == current) {
      current = b;
    } else if (b == current) {
      current = a;
    }
  }

  output << current << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
