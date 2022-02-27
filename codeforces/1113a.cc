#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, v;
  cin >> n >> v;
  int current = 0, cost = 0, total = 0, require = n-1;
  for (int i = 1; i < n; ++i) {
    int fill = min(v-current, require);
    current += fill;
    total += fill;
    cost += fill * i;
    require -= fill;
    current --;
  }
  cout << cost << endl;
  return 0;
}
