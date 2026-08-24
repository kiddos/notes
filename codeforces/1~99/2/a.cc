#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<string,int>> event;
  for (int i = 0; i < n; ++i) {
    string name;
    int score = 0;
    cin >> name >> score;
    event.emplace_back(name, score);
  }

  unordered_map<string, int> total_score;
  for (auto [name, score] : event) {
    total_score[name] += score;
  }

  int best = numeric_limits<int>::min();
  for (auto [name, score] : total_score) {
    best = max(best, score);
  }

  unordered_set<string> candidates;
  for (auto [name, score] : total_score) {
    if (score == best) {
      candidates.insert(name);
    }
  }

  string ans;
  total_score.clear();
  for (auto [name, score] : event) {
    total_score[name] += score;
    if (total_score[name] >= best && candidates.count(name)) {
      ans = name;
      break;
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
