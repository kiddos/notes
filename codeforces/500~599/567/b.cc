#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<int,int>> events;
  for (int i = 0; i < n; ++i) {
    char ch = '\0';
    int ri = 0;
    cin >> ch >> ri;
    if (ch == '+') {
      events.push_back({1, ri});
    } else if (ch == '-') {
      events.push_back({-1, ri});
    }
  }

  set<int> before;
  set<int> in_room;
  for (auto [event_type, ri] : events) {
    if (event_type == 1) {
      in_room.insert(ri);
    } else if  (event_type == -1) {
      if (in_room.count(ri)) {
        in_room.erase(ri);
      } else {
        before.insert(ri);
      }
    }
  }

  int ans = before.size();
  in_room = before;
  for (auto [event_type, ri] : events) {
    if (event_type == 1) {
      in_room.insert(ri);
    } else if  (event_type == -1) {
      in_room.erase(ri);
    }
    int size = in_room.size();
    ans = max(ans, size);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
