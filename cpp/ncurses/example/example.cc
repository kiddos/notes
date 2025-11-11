#include <locale.h>
#include <ncurses.h>

void setup_ncurses() {
  // Initialize the Curses screen (mandatory call)
  initscr();

  // Disable line buffering and make characters immediately available to the program
  cbreak();

  // Don't echo user input back to the screen
  noecho();

  // Enable special keys (like F1, F2, arrows) to be interpreted as single values
  keypad(stdscr, TRUE);

  // Hide the terminal cursor
  curs_set(0);

  // Optional: Set a timeout for getch() so the screen can refresh even without input
  timeout(100);
}

// Function to restore the terminal to its normal state
void cleanup_ncurses() {
  // End the ncurses session
  endwin();
}

int main() {
  setup_ncurses();

  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  // Initial position of the character
  int y = max_y / 2;
  int x = max_x / 2;

  int ch = 0;

  while ((ch = getch()) != 'q') {
    // Clear the screen for redrawing
    clear();

    mvprintw(0, 0, "Use Arrows or W/A/S/D to move. Press 'q' to quit.");

    // Handle user input (movement)
    switch (ch) {
      case KEY_UP:
      case 'w':
      case 'W':
        if (y > 1) y--;
        break;
      case KEY_DOWN:
      case 's':
      case 'S':
        if (y < max_y - 1) y++;
        break;
      case KEY_LEFT:
      case 'a':
      case 'A':
        if (x > 0) x--;
        break;
      case KEY_RIGHT:
      case 'd':
      case 'D':
        if (x < max_x - 1) x++;
        break;
      case KEY_RESIZE:
        getmaxyx(stdscr, max_y, max_x);
        if (y >= max_y) y = max_y - 1;
        if (x >= max_x) x = max_x - 1;
        break;
      default:
        break;
    }

    mvprintw(y, x, "@");
    refresh();
  }

  cleanup_ncurses();
  return 0;
}
