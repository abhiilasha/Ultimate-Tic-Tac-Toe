#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

using namespace std;

class Board
{
private:
    char subgrid[3][3];
public:
    Board(){}
    void set(int x,int y,char cell)
    {
        subgrid[x][y]=cell;
    }
    char get(int x,int y)
    {
        return subgrid[x][y];
    }
};

class UltimateTicTacToe
{
private:
    Board grid[3][3];
    char player;
    int cur;

public:
    UltimateTicTacToe();
    void display();
    void gamefunc();
    void input(int& g);
    bool subgridWinner(Board grid);

};

UltimateTicTacToe::UltimateTicTacToe()  //a function to indicate the grid in which the
//player has to input his move using arrow heads
{
    for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 3; ++k)
    for (int l = 0; l < 3; ++l)
    {
        grid[i][j].set(k, l, '_');
    }
player = 'x';
    cur = 0;
}

void UltimateTicTacToe::display()
{
    system("cls");
    cout<< "\n\n-----------------ULTIMATE TIC TAC TOE------------------"<<endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            cout << "\n";
            char left, right;
            left = right = ' ';
            for (int j = 0; j < 3; ++j)
            {
                if (k == 1)
                {
                    if (3*i + j + 1  == cur) {
                        left = '>';
                        right = '<';
                    }
                    else {
                        left = right = ' ';
                    }
                }
                cout << "  " << left << " ";
                for (int l = 0; l < 3; ++l) {
                    cout << grid[i][j].get(k, l) << " ";
                }
                cout << right;
            }
        }
        cout << "\n\n";
    }
    cout << "\n";

}
inline int X (int pos){
return pos/3; }
inline int Y (int pos) {
    return pos % 3 - 1;
}
void UltimateTicTacToe::gamefunc()
{
    int subg,s;
    display();
    while(1)
    {
        cout<< "\nplayer "<<player<< "-enter subgrid.";
        cin>>subg;
        if (subg > 0 && subg < 10) {
            break;
        }
        display();
cout << "\n  Try again.";
        cin.get();
    }
    s=subg;
        while(1)
        {
            display();
            if (subgridWinner(grid[X(cur)][Y(cur)])) {
            display();
            cout << "\n  Player " << player << " won!\n\n";
            cin.get();
            cout<< "press any key to continue....";
            _getch();
            break;
        }
        player = player == 'x' ? 'o' : 'x';
        cur = subg;
        input(subg);
        }


}


void UltimateTicTacToe::input(int& g)
{
    int cell;
    while (1) {
        display();
        cout << "\n  Player " << player << " - Enter cell: ";
        cin >> cell;
        if (cell > 0 && cell < 10)
        {
            if (grid[X(g)][Y(g)].get(X(cell), Y(cell)) == '_') {
                break;
            }
        }
        display();
        cout << "\n  Try again.";
        cin.ignore();
        cin.get();
    }
    grid[X(g)][Y(g)].set(X(cell), Y(cell), player);
    g = cell;
}
bool UltimateTicTacToe::subgridWinner(Board board){
char p = player;
    int row = 1, col = 1, maind = 1, antid = 1;
    for (int i = 0; i < 3; ++i)
    {
        row = col = 1;
        if (board.get(i, 3-1-i) != p) {
            antid = 0;
        }
        if (board.get(i, i) != p) {
            row = col = maind = 0;
        }

        else {
            for (int j = 0; j < 3; ++j)
            {
                if (board.get(i, j) != p) {
                    row = 0;
                }
                if (board.get(j, i) != p) {
                    col = 0;
                }
            }
        }

        if (row || col) {
            return 1;
        }
    }

    if (maind || antid) {
        return 1;
    }
    return 0;
}


void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void start()
{
   system("cls");
   gotoxy(33,9);
   cout<< "*****************************";
   gotoxy(37,11);
   cout<< "ULTIMATE TIC TAC TOE ";
   gotoxy(36,14);
   cout<< "By: Abhilasha(19103003)";
    gotoxy(33,16);
      cout<< "*****************************"<<endl;
     gotoxy(33,17);

     gotoxy(33,19);

cout<< "press any key to continue";
_getch();
}
void rules()
{
    system("cls");
    cout<<"1.The game consists of a lage 3 X 3 grid containing smaller 3X3 grids in each column.\n";
    cout<<"2.The game is played by 2 players(using symbols X and 0).Players take turns putting marks in empty squares.\n";
    cout<<"3.The first player to get 3 of his/her marks in a row (up, down, across, or diagonally) is the winner of that subgrid.\n";
    cout<<"4.The player who wins a subgrid first is the winner of the game.\n\n";
    cout<< "Press any key to continue....";
    _getch();
}
int main()
{
   UltimateTicTacToe game;
   start();
  int choice;
  while(1)
  {
      system("cls");
      cout<<"Choose Option\n1.Start New Game\n2.How To Play\n3.Quit";
      cin>>choice;
      if (choice==1)
      {
          system("cls");
           game.display();
           game.gamefunc();
      }
      if(choice==2)
      {
       rules();
       continue;
      }
      if(choice==3)
      break;

  }

}
