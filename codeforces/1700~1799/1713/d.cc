#include <bits/stdc++.h>

using namespace std;

int query(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int ans = -1;
  cin >> ans;
  return ans;
}

int query(vector<int>& P) {
  int ans = query(P[0], P[2]);
  if (ans == 0) {
    ans = query(P[1], P[3]);
    return ans == 1 ? P[1] : P[3];
  } else if (ans == 1) {
    ans = query(P[0], P[3]);
    return ans == 1 ? P[0] : P[3];
  } else {
    ans = query(P[1], P[2]);
    return ans == 1 ? P[1] : P[2];
  }
}

void output(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    int ans = query(1, 2);
    output(ans);
    return;
  }

  int m = 1 << n;
  vector<int> players(m);
  iota(players.begin(), players.end(), 1);

  function<int(vector<int>&)> divide = [&](vector<int>& P) {
    int size = P.size();
    if (size == 2) {
      int ans = query(P[0], P[1]);
      return ans == 1 ? P[0] : P[1];
    }
    if (size == 4) {
      return query(P);
    }
    vector<int> next_round;
    for (int i = 0; i < size; i += 4) {
      vector<int> group(P.begin() + i, P.begin() + i + 4);
      next_round.push_back(divide(group));
    }
    return divide(next_round);
  };

  int ans = divide(players);
  output(ans);
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
