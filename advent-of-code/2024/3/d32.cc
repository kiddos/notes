#include <bits/stdc++.h>
#include <regex>

using namespace std;

using i64 = long long;

enum EventType {
  DO, DONT, MUL
};

struct Event {
  int index;
  int x, y;
  EventType type;
};

vector<Event> find_events(const string text) {
  regex p1("mul\\((\\d{1,3}),(\\d{1,3})\\)");
  auto start = std::sregex_iterator(text.begin(), text.end(), p1);
  auto end = std::sregex_iterator();
  vector<Event> events;
  for (auto it = start; it != end; ++it) {
    string d1 = it->str(1);
    string d2 = it->str(2);
    int x = stoi(d1), y = stoi(d2);
    int idx = it->position();
    events.push_back({idx, x, y, MUL});
  }

  regex do_pattern("do\\(\\)");
  start = std::sregex_iterator(text.begin(), text.end(), do_pattern);
  end = std::sregex_iterator();

  for (auto it = start; it != end; ++it) {
    int idx = it->position();
    events.push_back(Event{idx, 0, 0, DO});
  }

  regex dont_pattern("don't\\(\\)");
  start = std::sregex_iterator(text.begin(), text.end(), dont_pattern);
  end = std::sregex_iterator();
  for (auto it = start; it != end; ++it) {
    int idx = it->position();
    events.push_back(Event{idx, 0, 0, DONT});
  }
  sort(events.begin(), events.end(), [&](auto& e1, auto& e2) {
    return e1.index < e2.index;
  });
  return events;
}

void solve() {
  ifstream input("./input.txt");

  ostringstream buffer;
  buffer << input.rdbuf();

  string text = buffer.str();
  vector<Event> events = find_events(text);
  bool add = true;
  i64 total = 0;
  for (auto e : events) {
    if (e.type == DO) {
      add = true;
    } else if (e.type == DONT) {
      add = false;
    } else if (e.type == MUL) {
      if (add) {
        total += e.x * e.y;
      }
    }
  }
  cout << total << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
