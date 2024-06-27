#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

enum Chess {
  EMPTY = 0,
  WHITE_PAWN = 1,
  WHITE_ROOK = 2,
  WHITE_KNIGHT = 3,
  WHITE_BISHOP = 4,
  WHITE_QUEEN = 5,
  WHITE_KING = 6,
  BLACK_PAWN = 7,
  BLACK_ROOK = 8,
  BLACK_KNIGHT = 9,
  BLACK_BISHOP = 10,
  BLACK_QUEEN = 11,
  BLACK_KING = 12,
};

vector<vector<i64>> table(8 * 8, vector<i64>(6 * 2 + 1));
i64 black_to_move = 0;

void init_zobrist() {
  mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

  for (int i = 0; i < 64; ++i) {
    for (int j = 1; j <= 12; ++j) {
      table[i][j] = gen();
    }
  }
  black_to_move = gen();
}

i64 zobrist(vector<vector<Chess>> board, bool is_black) {
  i64 hash = 0;
  if (is_black) {
    hash ^= black_to_move;
  }
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (board[i][j] != EMPTY) {
        int piece = (int)board[i][j];
        hash ^= table[i * 8 + j][piece];
      }
    }
  }
  return hash;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  init_zobrist();
  vector<vector<Chess>> board = {
    {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
    {BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN},
    {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK},
  };

  i64 hash = zobrist(board, true);
  cout << "hash = " << hash << endl;

  assert(zobrist(board, true) == zobrist(board, true));
  assert(zobrist(board, false) != zobrist(board, true));

  return 0;
}
