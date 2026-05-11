#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  int player_cards = n / k;
  int max_joker = min(player_cards, m);
  int joker_left = max(m - max_joker, 0);
  int bucket = k - 1;
  int distribute_joker = (joker_left + bucket - 1) / bucket;
  int max_points = max_joker - distribute_joker;
  cout << max_points << endl;
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
