#include <bits/stdc++.h>
using namespace std;

pair<int, int> place(char pos, char c, char tablep[3][3]) {
  switch (pos) {
  case '1':
    tablep[0][0] = c;
    return make_pair(0, 0);
    break;
  case '2':
    tablep[0][1] = c;
    return make_pair(0, 1);
    break;
  case '3':
    tablep[0][2] = c;
    return make_pair(0, 2);
    break;
  case '4':
    tablep[1][0] = c;
    return make_pair(1, 0);
    break;
  case '5':
    tablep[1][1] = c;
    return make_pair(1, 1);
    break;
  case '6':
    tablep[1][2] = c;
    return make_pair(1, 2);
    break;
  case '7':
    tablep[2][0] = c;
    return make_pair(2, 0);
    break;
  case '8':
    tablep[2][1] = c;
    return make_pair(2, 1);
    break;
  case '9':
    tablep[2][2] = c;
    return make_pair(2, 2);
    break;
  }
  return make_pair(-1, -1);
}

void print_table(char table[3][3]) {
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (y == 0)
        cout << " ";
      cout << table[x][y];
      if (y != 2)
        cout << " | ";
    }
    cout << endl;
    if (x != 2)
      cout << "-----------" << endl;
  }
}

bool check_horizontal(int x, char table[3][3]) {
  if (table[x][0] != ' ')
    if (table[x][0] == table[x][1] && table[x][1] == table[x][2])
      return true;
  return false;
}

bool check_vertical(int y, char table[3][3]) {
  if (table[0][y] != ' ')
    if (table[0][y] == table[1][y] && table[1][y] == table[2][y])
      return true;
  return false;
}

bool check_diagonal(char table[3][3]) {
  if (table[1][1] != ' ') {
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2])
      return true;
    if (table[0][2] == table[1][1] && table[1][1] == table[2][0])
      return true;
  }
  return false;
}

bool check_win(pair<int, int> pos_pair, char table[3][3]) {
  bool v = check_vertical(pos_pair.second, table);
  bool h = check_horizontal(pos_pair.first, table);
  bool d = check_diagonal(table);
  if (v || h || d)
    return true;
  return false;
}

int main() {
  char table[3][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'},
  };
  print_table(table);

  while (true) {
    char pos;
    cout << "X turn" << endl << "> ";
    cin >> pos;
    pair<int, int> pos_index = place(pos, 'X', table);
    print_table(table);
    if (check_win(pos_index, table)) {
      cout << "X wins" << endl;
      break;
    }
    cout << "\n";
    cout << "O turn" << endl << "> ";
    cin >> pos;
    pos_index = place(pos, 'O', table);
    print_table(table);
    if (check_win(pos_index, table)) {
      cout << "O wins" << endl;
      break;
    }
    cout << "\n";
  }
}
