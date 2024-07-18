// purpose: Subtracting Squares
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
#include <sstream>

using namespace std;

// function to display the menu and get user's choice
int menu()
{
    int choice;
    while (true)
    {
        cout << "Choose how you want to play:" << endl;
        cout << "1) Random number" << endl;
        cout << "2) Choose the number of coins" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        if (choice == 1 || choice == 2)
        {
            return choice;
        }
        else
        {
            cout << "\nInvalid choice! Please choose between 1 or 2\n"
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// function to check if a number is positive
bool checkPositive(int num)
{
    if (num <= 0)
    {
        cout << "Please enter a positive number.\n"
             << endl;
        return false;
    }
    else if (sqrt(num) == floor(sqrt(num)))
    {
        cout << "Square numbers are not allowed! Try again\n"
             << endl;
        return false;
    }
    else
    {
        cout << "Remaining coins : " << num << endl
             << endl;
        return true;
    }
}

// function to check if a string is a valid integer
bool isInteger(const std::string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    {
        return false;
    }
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

// function to check if a number is a square
bool checkSquare(int num)
{
    if (num <= 0)
    {
        return true;
    }
    if (sqrt(num) == floor(sqrt(num)))
    {
        return true;
    }
    else
    {
        cout << "Not a square number.\n"
             << endl;
        return false;
    }
}

// function to start the game
void game()
{
    int choice = menu();
    int num = 0;

    if (choice == 1)
    {
        // Computer chooses a random number
        srand(time(NULL));
        num = rand() % 991 + 10; // Random number between 10 and 1000
        cout << "Random number is " << num << endl
             << endl;
    }
    else if (choice == 2)
    {
        // Player chooses the number of coins
        while (true)
        {
            string input;
            cout << "Choose a positive number: ";
            cin >> input;
            cout << endl;
            if (isInteger(input))
            {
                num = stoi(input);
                if (checkPositive(num))
                {
                    break;
                }
            }
            else
            {
                cout << "Invalid input! Please enter an integer." << endl;
            }
        }
    }

    while (num > 0)
    {
        int player1_num, player2_num;
        try
        {
            cout << "Player 1's turn: ";
            string input1;
            cin >> input1;
            cout << endl;
            if (isInteger(input1))
            {
                player1_num = stoi(input1);
                if (!checkSquare(player1_num))
                {
                    throw invalid_argument("Please enter a square number\n");
                }
                if (player1_num > num)
                {
                    cout << "You cannot subtract more than the remaining coins! Please try again.\n"
                         << endl;
                    continue;
                }
                num -= player1_num;
                cout << "Remaining coins: " << num << endl
                     << endl;
                if (num == 0)
                {
                    cout << "Player 1 wins!" << endl;
                    break;
                }

                cout << "Player 2's turn: ";
                do
                {
                    string input2;
                    cin >> input2;
                    cout << endl;
                    if (isInteger(input2))
                    {
                        player2_num = stoi(input2);
                        if (!checkSquare(player2_num))
                        {
                            cout << "Please enter a square number: ";
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        cout << "Invalid input! Please enter an integer." << endl;
                    }
                } while (true);

                if (player2_num > num)
                {
                    cout << "You cannot subtract more than the remaining coins! Please try again.\n"
                         << endl;
                    continue;
                }
                num -= player2_num;
                cout << "Remaining coins: " << num << endl
                     << endl;
                if (num == 0)
                {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
            }
            else
            {
                cout << "Invalid input! Please enter an integer." << endl;
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Please enter a valid integer!\n"
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main()
{
    cout << "\nWelcome to the Subtracting Squares game!\n"
         << endl;
    game();
    return 0;
}