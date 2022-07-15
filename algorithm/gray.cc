#include <bits/stdc++.h>

using namespace std;

// 000 001 010 011 100 101 110 111
// 000 001 011 010 110 111 101 100
// g(n) ith bit is 1
// if n ith bit is 1 and i+1th bit is 0
// or if ith bit i 0 and i+1th bit is 1

int g(int n) {
  return n ^ (n >> 1);
}

int rev_g(int g) {
  int n = 0;
  while (g) {
    n ^= g;
    g >>= 1;
  }
  return n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 6;
  int m = 1 << n;
  for (int i = 0; i < m; ++i) {
    cout << g(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < m; ++i) {
    cout << rev_g(g(i)) << " ";
  }
  cout << endl;
  return 0;
}
