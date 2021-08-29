#include <bits/stdc++.h>

using namespace std;

struct Pair {
  unsigned int c1;
  unsigned int c2;

  bool operator==(const Pair& p2) const { return c1 == p2.c1 && c2 == p2.c2; }
};

ostream& operator<<(ostream& os, const Pair& p) {
  os << p.c1 << ", " << p.c2;
  return os;
}

struct PairHash {
  size_t operator()(const Pair& p) const {
    return hash<unsigned int>()(p.c1) ^ hash<unsigned int>()(p.c2);
  }
};

using PairCounter = unordered_map<Pair, int, PairHash>;
using WordCounter = unordered_map<unsigned int, int>;

struct Merge {
  Pair p;
  int pair_count;
  unordered_set<int> word_index_to_update;

  Merge(const Pair& p, int pair_count, unordered_set<int>& to_update)
      : p{p.c1, p.c2},
        pair_count(pair_count),
        word_index_to_update(to_update) {}
};

struct CompareMerge {
  bool operator()(const Merge& m1, const Merge& m2) {
    return m1.pair_count < m2.pair_count;
  }
};

struct Change {
  Pair p;
  int change;
};

class Word {
 public:
  Word() = default;

  void add(unsigned int c, int len) {
    for (int i = 0; i < len; ++i) symbol_.push_back(c);
  }

  vector<Change> merge(unsigned int c1, unsigned int c2,
                       unsigned int replacement) {
    vector<Change> changes;
    int i = 0;
    while (true) {
      if (i == symbol_.size()) break;
      if (i + 1 < symbol_.size() && symbol_[i] == c1 && symbol_[i + 1] == c2) {
        if (i > 0) {
          changes.push_back(Change{{symbol_[i - 1], symbol_[i]}, -1});
        }
        changes.push_back(Change{{symbol_[i], symbol_[i + 1]}, -1});

        symbol_.erase(symbol_.begin() + i);
        symbol_.erase(symbol_.begin() + i);
        symbol_.insert(symbol_.begin() + i, replacement);

        if (i > 0) {
          changes.push_back(Change{{symbol_[i - 1], symbol_[i]}, 1});
        }
        if (i + 1 < symbol_.size()) {
          changes.push_back(Change{{symbol_[i], symbol_[i + 1]}, 1});
        }
      }
      i++;
    }
    return changes;
  }

  vector<unsigned int>& symbol() { return symbol_; }

  size_t length() const { return symbol_.size(); }

 private:
  std::vector<unsigned int> symbol_;
};

vector<string> split_words(const string& text) {
  unordered_set<string> words;
  string word;
  for (char c : text) {
    if (static_cast<unsigned char>(c) > 127) continue;
    if (c == ' ' || c == '\t' || c == '\n') {
      if (word.length()) words.insert(word);
      word.clear();
    } else {
      word.push_back(c);
    }
  }
  if (word.length()) words.insert(word);
  return vector<string>(words.begin(), words.end());
}

void replace_alphabet(vector<string>& text,
                      unordered_map<string, unsigned int>& word2id,
                      unordered_map<unsigned int, string>& id2word,
                      vector<Word>& words) {
  for (string& word : text) {
    Word w;
    for (char c : word) {
      string s(1, c);
      if (!word2id.count(s)) {
        auto id = word2id.size();
        word2id[s] = id;
        id2word[id] = s;
      }
      w.add(word2id[s], 1);
    }
    words.push_back(w);
  }
}

void debug(PairCounter& pair_count,
           unordered_map<unsigned int, string>& id2word) {
  vector<pair<Pair, int>> count(pair_count.begin(), pair_count.end());
  sort(count.begin(), count.end(),
       [&](auto& p1, auto& p2) { return p1.second > p2.second; });

  for (auto p : count) {
    string s = id2word[p.first.c1] + id2word[p.first.c2];
    cout << s << ": " << p.second << endl;
  }
}

void debug(unordered_map<unsigned int, string>& id2word) {
  for (auto p : id2word) {
    cout << p.second << ": " << p.first << endl;
  }
}

string read_file(const string& filename) {
  ifstream fs(filename, ios::in);
  stringstream ss;
  ss << fs.rdbuf();
  return ss.str();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // string data = "the quick brown fox jumps over the lazy dog the dog";
  cout << "reading data" << endl;
  string data = read_file("./wiki.train.tokens");
  // string data =
  //     "The game began development in 2010 , carrying over a large "
  //     "lportion of the work done on Valkyria Chronicles II . While it retained "
  //     "the "
  //     "standard features of the series , it also underwent multiple "
  //     "adjustments , "
  //     "such as making the game more <unk> for series newcomers . Character "
  //     "designer <unk> Honjou and composer Hitoshi Sakimoto both returned from "
  //     "previous entries , along with Valkyria Chronicles II director Takeshi "
  //     "Ozawa "
  //     ". A large team of writers handled the script . The game 's opening "
  //     "theme "
  //     "was sung by May 'n . It met with positive sales in Japan , and was "
  //     "praised "
  //     "by both Japanese and western critics . After release , it received "
  //     "downloadable content , along with an expanded edition in November of "
  //     "that "
  //     "year . It was also adapted into manga and an original video animation "
  //     "series . Due to low sales of Valkyria Chronicles II , Valkyria "
  //     "Chronicles "
  //     "III was not localized , but a fan translation compatible with the game "
  //     "'s "
  //     "expanded edition was released in 2014 . Media.Vision would return to "
  //     "the "
  //     "franchise with the development of Valkyria : Azure Revolution for the "
  //     "PlayStation 4";
  // string data = "aaabdaaabac";
  vector<string> text = split_words(data);
  cout << "number of words: " << text.size() << endl;

  unordered_map<string, unsigned int> word2id;
  unordered_map<unsigned int, string> id2word;
  vector<Word> words;
  cout << "replace alphabets to numerics..." << endl;
  replace_alphabet(text, word2id, id2word, words);

  cout << "counting pairs..." << endl;
  unordered_map<Pair, unordered_set<int>, PairHash> where_to_update;
  PairCounter pair_count;
  for (int i = 0; i < words.size(); ++i) {
    Word& word = words[i];
    int n = word.length();
    for (int j = 0; j < n - 1; ++j) {
      Pair p{word.symbol()[j], word.symbol()[j + 1]};
      pair_count[p]++;
      where_to_update[p].insert(i);
    }
  }

  cout << "initial number of tokens: " << id2word.size() << endl;

  priority_queue<Merge, vector<Merge>, CompareMerge> pq;
  for (auto w : where_to_update) {
    unordered_set<int> indices = w.second;
    pq.push(Merge(w.first, pair_count[w.first], indices));
  }

  cout << "number of merges: " << pq.size() << endl;

  const int token_size = 50000;
  while (!pq.empty() && pq.top().pair_count >= 1 &&
         id2word.size() <= token_size) {
    Merge merge = pq.top();
    pq.pop();

    string most_pair_text = id2word[merge.p.c1] + id2word[merge.p.c2];
    auto id = word2id.size();
    word2id[most_pair_text] = id;
    id2word[id] = most_pair_text;

    unordered_map<Pair, int, PairHash> all_changes;
    for (int index : merge.word_index_to_update) {
      vector<Change> changes = words[index].merge(merge.p.c1, merge.p.c2, id);
      for (auto c : changes) {
        all_changes[c.p] += c.change;
      }
    }

    for (auto change : all_changes) {
      pair_count[change.first] += change.second;
      if (change.second > 0 && pair_count[change.first] > 0) {
        pq.push(Merge{change.first, pair_count[change.first],
                      merge.word_index_to_update});
      }
    }
  }
  cout << "tokens: " << endl;
  for (auto p : word2id) {
    cout << p.first << ": " << p.second << endl;
  }
  return 0;
}
