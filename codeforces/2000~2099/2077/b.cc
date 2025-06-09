#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 query(int n) {
  cout << n << endl;
  i64 result = 0;
  cin >> result;
  return result;
}

void answer(int x, int y) {
  cout << "!" << endl;
  int m = 0;
  cin >> m;
  cout << (m | x) + (m | y) << endl;
}

void solve() {
  int n0 = 0, n1 = 0;
  for (int i = 0; i < 30; ++i) {
    if (i % 2 == 0) {
      n0 |= (1<<i);
    } else {
      n1 |= (1<<i);
    }
  }
  i64 result1 = query(n0);
  int result2 = query(n1);
  vector<int> bits(32);
  for (int i = 0; i < 30; i += 2) {
    int b1 = result2 & (1<<i);
    int b2 = result2 & (1<<(i+1));
    if (i == 0) {
      if (!b1 && !b2) {
        // zero bits
        continue;
      } else if (b2 && !b1) {
        // both bit 1
        bits[i] += 2;
      } else if (!b2 && b1) {
        // only bit
        bits[i] ++;
      }
    } else {
      // remember the carry
      if (!b2 && b1) {
        // both bit zero
        continue;
      } else if (b2 && !b1) {
        // 1 bit
        bits[i]++;
      } else if (b2 && b1) {
        // 2 bits
        bits[i] += 2;
      }
    }
  }

  for (int i = 1; i < 30; i += 2) {
    int b1 = result1 & (1<<i);
    int b2 = result1 & (1<<(i+1));
    if (!b2 && b1) {
      // both bit zero
      continue;
    } else if (b2 && !b1) {
      // 1 bit
      bits[i]++;
    } else if (b2 && b1) {
      // 2 bits
      bits[i] += 2;
    }
  }

  int x = 0, y = 0;
  for (int i = 0; i < 32; ++i) {
    if (bits[i] == 2) {
      x |= (1<<i);
      y |= (1<<i);
    } else if (bits[i] == 1) {
      x |= (1<<i);
    }
  }

  answer(x, y);
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
