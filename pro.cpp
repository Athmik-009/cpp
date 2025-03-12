#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif
using namespace std;

class BattleShips
{
public:
    static const int rows = 7;
    static const int elements = 9;
    static const int maxships = 5;
    static int ship[5];
    int score = 0;
    static int max_score;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ;
    char matrix[rows][elements];
    char matrixAttackedPlaces[rows][elements];

    void Clear()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < elements; j++)
            {
                matrix[i][j] = '*';
                matrixAttackedPlaces[i][j] = '*';
            }
        }
    }

    void Show()
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < elements; j++)
            {
                if (j == 0)
                {
                    display(i, j);
                }
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void ShowAttackedPlaces()
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < elements; j++)
            {
                if (j == 0)
                {
                    display(i, j);
                }
                cout << matrixAttackedPlaces[i][j] << " ";
            }
            cout << endl;
        }
    }
    void display(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            cout << "  ";
            for (int k = 0; k < elements; k++)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        if (j == 0)
        {
            cout << i << " ";
        }
    }
    void SetShips()
    {
        char s1;
        int s = 0;
        while (s < maxships)
        {
            int c = 0;
            int x = rand() % rows;

            int y = rand() % elements;
            int z = rand() % 2;
            if (z == 0)
            {
                s1 = 'h';
            }
            else
            {
                s1 = 'v';
            }
            if (s1 == 'v')
            {
                for (int i = x; i < x + ship[s]; i++)
                {
                    if (i >= rows)
                    {
                        c = 1;
                        break;
                    }
                    if (matrix[i][y] == 'S')
                    {
                        c = 1;
                        break;
                    }
                }
            }
            else if (s1 == 'h')
            {
                for (int j = y; j < y + ship[s]; j++)
                {
                    if (j >= elements)
                    {
                        c = 1;
                        break;
                    }
                    if (matrix[x][j] == 'S')
                    {
                        c = 1;
                        break;
                    }
                }
            }
            if (c == 0)
            {
                if (s1 == 'v')
                {
                    for (int k = x; k < x + ship[s]; k++)
                    {
                        matrix[k][y] = 'S';
                    }
                    s++;
                }
                else
                {
                    for (int l = y; l < y + ship[s]; l++)
                    {
                        matrix[x][l] = 'S';
                    }
                    s++;
                }
            }
        }
    }

    void SetShips2()
    {
        char s1;
        int s = 0;
        while (s < maxships)
        {
            int c = 0;
            int x = 0, y = 0;
            cout << "enter the coordinates where you want to place the ship";
            cin >> x >> y;
            cout << "enter v for vertical(downward) or h for horizontal(left to right) placement";
            cin >> s1;
            if (s1 == 'v')
            {
                for (int i = x; i < x + ship[s]; i++)
                {
                    if (i >= rows)
                    {
                        c = 2;
                        break;
                    }
                    if (matrix[i][y] == 'S')
                    {
                        c = 1;
                        break;
                    }
                }
            }
            else if (s1 == 'h')
            {
                for (int j = y; j < y + ship[s]; j++)
                {
                    if (j >= elements)
                    {
                        c = 2;
                        break;
                    }
                    if (matrix[x][j] == 'S')
                    {
                        c = 1;
                        break;
                    }
                }
            }
            if (c == 0)
            {
                if (s1 == 'v')
                {
                    for (int k = x; k < x + ship[s]; k++)
                    {
                        matrix[k][y] = 'S';
                    }
                    s++;
                }
                else
                {
                    for (int l = y; l < y + ship[s]; l++)
                    {
                        matrix[x][l] = 'S';
                    }
                    s++;
                }
                Show();
            }
            else if (c == 1)
            {
                cout << "a ship is already present in the location choose another spot" << endl;
            }
            else
            {
                cout << "cannot place a ship here as it is out of bounds" << endl;
            }
        }
    }
    bool alreadyattacked(int x, int y)
    {
        if (matrix[x][y] == 'X' || matrix[x][y] == 'O' || matrixAttackedPlaces[x][y] == 'X' || matrixAttackedPlaces[x][y] == 'O')
        {
            return true;
        }
        return false;
    }

    int Attack(int x, int y)
    {
        if (!alreadyattacked(x, y))
        {
            if (matrix[x][y] == 'S')
            {
                matrixAttackedPlaces[x][y] = 'O';
                ++score;
                return 0;
            }
            else
            {
                matrixAttackedPlaces[x][y] = 'X';
                return 1;
            }
        }
        return 2;
    }
    int Attack2(int x, int y)
    {
        if (!alreadyattacked(x, y))
        {
            if (matrix[x][y] == 'S')
            {
                matrix[x][y] = 'O';
                ++score;
                return 0;
            }
            else
            {
                matrix[x][y] = 'X';
                return 1;
            }
        }
        return 2;
    }
};
int BattleShips::ship[5]={2,3,3,4,5};
int BattleShips::max_score=0;
void DrawSeparationLine(int x, char c)
{
    for (int i = 0; i < x; i++)
    {
        cout << c << " ";
    }
    cout << endl;
}
void Rule()
{
    int choice;
    DrawSeparationLine(137, '-');
    cout << "\n";
    cout << "\t\t\t\t\t  WELCOME TO BATTLESHIP\n";
    DrawSeparationLine(137, '-');
    cout << "\n";


    cout << "\t\t\t\t   * GAME OBJECTIVE *\n";
    cout << "\t\t\t\t  - Sink all of your opponent's ships.\n";
    cout << "\t\t\t\t  - Protect your ships and avoid being sunk by placing your ships strategically.\n";
    DrawSeparationLine(137, '-');

    cout << "\n\t\t\t\t   * GAME SETUP *\n";
    cout << "\t\t\t\t  - The board is 7x9, with 7 rows and 9 columns.\n";
    cout << "\t\t\t\t  - You have 5 ships of varying lengths: 2, 3, 3, 4, and 5 units.\n";
    cout << "\t\t\t\t  - Ships can be placed either horizontally or vertically.\n";
    cout << "\t\t\t\t  - Players take turns attacking the opponent’s ships.\n";
    DrawSeparationLine(137, '-');

    cout << "\n\t\t\t\t   * WINNING CONDITION *\n";
    cout << "\t\t\t\t  1. Player's turn: Choose a row and column (e.g., 3 5).\n";
    cout << "\t\t\t\t  2. If you hit a ship, it’s marked with 'O'; if you miss, it’s 'X'.\n";
    cout << "\t\t\t\t  3. After your turn, the CPU will attack your base if you have chosen single player.\n";
    cout << "\t\t\t\t  4. Continue until one player sinks all the opponent's ships.\n";
    DrawSeparationLine(137, '-');
    cout << "  Choose your next action:" << endl;
    cout << "   1. Start the game" << endl;
    cout << "   2. Exit";
    cin >> choice;
    if (choice == 2)
    {
        exit(0);
    }
}

void GameEndScreen()
{
    system(CLEAR_SCREEN);
    DrawSeparationLine(9, 'x');
    DrawSeparationLine(9, '-');
    DrawSeparationLine(9, 'x');
    cout << "\nG A M E   O V E R \n\n";
    DrawSeparationLine(9, 'x');
    DrawSeparationLine(9, '-');
    DrawSeparationLine(9, 'x');
}

void customSleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main()
{
    srand(time(NULL));
    int choice, choice2;
    DrawSeparationLine(60, '*');

    cout << endl;
    cout << "\t\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t   *                                                 *" << endl;
    cout << "\t\t\t\t   *      W E L C O M E  T O  B A T T L E S H I P    *" << endl;
    cout << "\t\t\t\t   *                                                 *" << endl;
    cout << "\t\t\t\t   *    Prepare your strategy, aim carefully, and    *" << endl;
    cout << "\t\t\t\t   *     outwit your opponent to claim victory!      *" << endl;
    cout << "\t\t\t\t   *                                                 *" << endl;
    cout << "\t\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t   * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl
         << endl
         << endl;
    DrawSeparationLine(60, '*');
    cout << endl;
    cout << "  Choose your next action:" << endl;
    cout << "   1. Read the rules" << endl;
    cout << "   2. Start the game" << endl;
    cout << "   3. Exit";
    cin >> choice;
    if (choice == 1)
    {
        Rule();
    }
    if (choice == 3)
    {
        exit(0);
    }
    system(CLEAR_SCREEN);
    cout << "  Choose your next action:" << endl;
    cout << "   1. SINGLE PLAYER" << endl;
    cout << "   2. MULTIPLAYER";
    cin >> choice2;
    BattleShips player1;
    BattleShips player2;

    player1.Clear();
    if (choice2 == 2)
    {
        cout << "\nits player 1's turn" << endl<<endl;
        player1.Show();
        player1.SetShips2();
        system(CLEAR_SCREEN);
        cout << "its player 2's turn" << endl<<endl;
    }
    else
    {
        player1.SetShips();
    }

    player2.Clear();
    player2.Show();
    player2.SetShips2();
    int pos1, pos2, pos11, pos22;
    char prompt;
    for(int p=0;p<player1.maxships;p++)
    {
        player1.max_score+=player1.ship[p];
    }
    while (true)
    {
        system(CLEAR_SCREEN);
        if (choice2 == 2)
            cout << "    PLAYER 1 BASE" << endl;
        else if (choice2 == 1)
            cout << "    OPPONENT BASE" << endl;
        player1.ShowAttackedPlaces();
        if (choice2 == 2)
        {
            cout << "\nScore: " << player2.score << endl;
        }
        DrawSeparationLine(player1.elements + 1, '-');
        DrawSeparationLine(player1.elements + 1, '-');
        if (choice2 == 1)
        {
            cout << "      YOUR BASE" << endl;
            player2.Show();
        }
        else
        {
            cout << "    PLAYER 2 BASE" << endl;
            player2.ShowAttackedPlaces();
        }
        if (player1.score == player1.max_score || player2.score == player1.max_score)
        {
            GameEndScreen();
            if (player1.score == player1.max_score)
            {
                if (choice2 == 1)
                    cout << "\n---- YOU WON----\n\n";
                else
                    cout << "\n ----PLAYER 2 WINS----\n\n";
            }
            else
            {
                if (choice2 == 1)
                    cout << "\n\n---- YOU LOST ----\n\n";
                else
                    cout << "\n---- PLAYER 1 WINS----\n\n";
            }
            DrawSeparationLine(9, 'x');
            DrawSeparationLine(9, '-');
            DrawSeparationLine(9, 'x');
            break;
        }

        cout << "\nScore: " << player1.score << endl
             << endl;
        if (choice2 == 2)
            cout << "PLAYER 2'S TURN TO ATTACK"<<endl<<endl;
        else
            cout << "ITS YOUR TURN TO ATTACK"<<endl;
        cout << "Please input location (row column) to attack enemy base:\n";
        cin >> pos1 >> pos2;
        if (pos1 < 0 || pos1 >= player1.rows || pos2 < 0 || pos2 >= player1.elements)
        {
            cout << "You chose a field outside the map.\n";
            continue;
        }
        int k = player1.Attack(pos1, pos2);
        if (k == 0)
        {
            cout << "You hit the target" << endl;
            customSleep(2000);
            continue;
        }
        else if (k == 1)
        {
            cout << "Sorry, no ship at that position!" << endl;
        }
        else
        {
            cout << "YOU HAVE ALREADY ATTACKED THAT POSITION...TRY AGAIN" << endl;
            customSleep(3000);
            continue;
        }

        if (choice2 == 1)
        {
            cout << "It's time for CPU player.";
            customSleep(1000);
            cout << " .";
            customSleep(1000);
            cout << " .";
            customSleep(1000);
            cout << endl;
        }

        while (true)
        {
            if (choice2 == 1)
            {
                pos1 = rand() % player1.rows;
                pos2 = rand() % player1.elements;
                if (player2.matrixAttackedPlaces[pos1][pos2] != 'X' || player2.matrixAttackedPlaces[pos1][pos2] != 'O')
                {
                    int result = player2.Attack2(pos1, pos2);
                    if (result == 2)
                    {
                        continue;
                    }
                    cout << "CPU player attacked your base at positions: " << pos1 << ", " << pos2 << "\n";
                    if (result == 0)
                    {
                        cout << "\nCPU hit the target" << endl;
                        customSleep(3000);
                        if(player2.score==player1.max_score)
                        {
                            break;
                        }
                        system(CLEAR_SCREEN);
                        player1.ShowAttackedPlaces();
                        DrawSeparationLine(player1.elements, '-');
                        player2.Show();
                    }
                    else if (result == 1)
                    {
                        cout << "CPU missed the target" << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "IT'S PLAYER 1'S TURN TO ATTACK" << endl<<endl;
                cout << "Please input location (row column) to attack enemy base:\n";
                cin >> pos11 >> pos22;
                if (pos11 < 0 || pos11 >= player1.rows || pos22 < 0 || pos22 >= player2.elements)
                {
                    cout << "You chose a field outside the map.\n";
                    continue;
                }
                int k2 = player2.Attack(pos11, pos22);
                if (k2 == 0)
                {
                    cout << "You hit the target" << endl;
                    customSleep(2000);
                    if(player2.score==player1.max_score)
                    {
                        break;
                    }
                    system(CLEAR_SCREEN);
                    cout << "    PLAYER 1 BASE" << endl;
                    player1.ShowAttackedPlaces();
                    cout << "\nScore: " << player2.score << endl;
                    DrawSeparationLine(player1.elements + 1, '-');
                    DrawSeparationLine(player1.elements + 1, '-');
                    cout << "    PLAYER 2 BASE" << endl;
                    player2.ShowAttackedPlaces();
                }
                else if (k2 == 1)
                {
                    cout << "Sorry, no ship at that position!" << endl;
                    break;
                }
                else
                {
                    cout << "YOU HAVE ALREADY ATTACKED THAT POSITION...TRY AGAIN" << endl;
                    customSleep(3000);
                }
            }
        }
        if (choice2 == 1&&player2.score!=player1.max_score)
        {
            cout << "\nDo you want to surrender (y/n)? ";
            cin >> prompt;
            if (prompt == 'y')
            {
                GameEndScreen();
                cout << "\n---- YOU LOST----\n\n";
                DrawSeparationLine(9, 'x');
                DrawSeparationLine(9, '-');
                DrawSeparationLine(9, 'x');
                break;
            }
        }
        if(choice2==2&&player2.score!=player1.max_score)
        {
            cout<<"\nenter y to exit the game";
            cin>>prompt;
            if(prompt=='y')
            {
                GameEndScreen();
            }
        }
    }
    return 0;
}