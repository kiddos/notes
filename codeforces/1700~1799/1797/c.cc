#include <bits/stdc++.h>

using namespace std;

int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int ans = 0;
  cin >> ans;
  return ans;
}

void answer(int x, int y) {
  printf("! %d %d\n", x, y);
  fflush(stdout);
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  int ans1 = query(1, 1);
  if (ans1 >= n) {
    int ans2 = query(1, ans1+1);
    answer(ans2+1, ans1+1);
  } else if(ans1 >= m) {
    int ans2 = query(ans1+1, 1);
    answer(ans1+1, ans2+1);
  } else {
    int ans2 = query(ans1+1, 1);
    int ans3 = query(1, ans1+1);
    if (ans1 == ans2 && ans1 == ans3) {
      answer(ans1+1, ans1+1);
    } else if (ans2 == ans1) {
      answer(ans3+1, ans1+1);
    } else {
      answer(ans1+1, ans2+1);
    }
  }
}

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
