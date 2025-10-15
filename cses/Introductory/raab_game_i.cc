#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, b = 0;
  cin >> n >> a >> b;
  if (a + b > n) {
    cout << "NO" << endl;
    return;
  }
  vector<int> player1(n);
  iota(player1.begin(), player1.end(), 1);

  int tie = n - (a + b);
  vector<int> player2(n);
  for (int i = 0; i < tie; ++i) {
    player2[i] = i+1;
  }

  // shift by a
  int card = n;
  for (int i = n-a-1; i >= tie; --i) {
    player2[i] = card--;
  }
  for (int i = n-1; i > n-a-1; --i) {
    player2[i] = card--;
  }

  int win1 = 0, win2 = 0;
  for (int i = 0; i < n; ++i) {
    if (player1[i] > player2[i]) {
      win1++;
    } else if (player2[i] > player1[i]) {
      win2++;
    }
  }
  if (win1 != a || win2 != b) {
    cout << "NO" << endl;
    return;
  } 

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << player1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << player2[i] << " ";
  }
  cout << endl;
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
