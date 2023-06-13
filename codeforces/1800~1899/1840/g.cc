#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int move(const string& d, int k) {
  cout << d << " " << k << endl;
  int ans = 0;
  cin >> ans;
  return ans;
}

void answer(int n) {
  cout << "! " << n << endl;
}

constexpr int MAX_VAL = 1000000 + 7;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

int get_random() {
  int r = gen() % MAX_VAL;
  return r;
}

void solve() {
  int start = 0;
  cin >> start;

  int K = 200;
  int n0 = start;
  ll total_k = 0;
  for (int i = 0; i < K; ++i) {
    int k = get_random(); 
    int result = move("+", k);
    n0 = max(n0, result);
    total_k += k;
  }

  vector<int> pos(MAX_VAL+1);

  move("-", total_k);
  total_k = n0-1;

  int result = move("+", n0-1);
  pos[result] = n0;

  const int D = (1000 - K) / 2;
  for (int i = 0; i < D; ++i) {
    result = move("+", 1);
    pos[result] = n0+ i + 1;
    total_k++;
    if (result == start) {
      answer(n0+i);
      return;
    }
  }

  move("-", total_k);

  int ans = 0;
  while (true) {
    result = move("-", D);
    ans += D;
    if (pos[result]) {
      answer(ans + pos[result] - 1);
      return;
    }
  }

  answer(-1);
}

int main(void) {
  solve();
  return 0;
}
