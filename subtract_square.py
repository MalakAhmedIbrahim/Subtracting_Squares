################################## done
# file: CS112_A1_T2_3_20230412
"""purpose: Subtract a square. This is a two-player mathematical game of strategy. It is played by two
people with a pile of coins (or other tokens) between them. The players take turns removing
coins from the pile, always removing a non-zero square number of coins (1, 4, 9, 16, ...).
The player who removes the last coin wins.
Example of this game is at"""
# Author: Malak Ahmed ibrahim Ali
# ID : 20230412

# menu to choose how to play
def menu():
    while True:
        try:
            print("Choose how you want to play:")
            print("1) Random number")
            print("2) Choose the number of coins")
            choice = int(input("Enter your choice (1 or 2): "))
            if choice in [1, 2]:
                return choice
            else:
                print("\nInvalid choice! Please choose between 1 or 2\n")
        except ValueError:
            print("\nInvalid input! Please enter an integer.\n")
# Function:enter positive number and check if true
def check_positive(num):
    if num <= 0:
        print("Please enter a positive number.\n")
        return False
    elif math.sqrt(num).is_integer():
        print("square numbers are not allowed! try again\n")
        return False
    else:
        print("remaining coins : ", num)
        print("")
        return True
# computer choose random number
# Function:check if num square or not
import math
def check_sqrt(num):
    if num <= 0:  # No need to check squareness for non-positive numbers
        return True
    try:
        sqrt_num = math.sqrt(num)
        if sqrt_num.is_integer():
            return True
        else:
            print("Not a square number.\n")
            return False
    except ValueError:
        print("Please enter a valid integer.\n")

def game():
    choice = menu()
    num = 0
    if choice == 1:
        # computer choose randem number
        import random
        num = random.randint(10, 1000)
        print("Random number is", num)
        print("")
    elif choice == 2:
        # take postivie number from playpr
        while True:
            try:
                num = int(input("Choose a positive number: "))
                print("")
                if check_positive(num):
                    break
            except ValueError:
                print("Please enter a valid integer.\n")
    while num > 0:
        try :
            player1_num = int(input("Player 1's turn: "))
            print("")
            if not check_sqrt(player1_num):
                raise ValueError("Not a square number\n")
            if player1_num > num:
                print("You cannot subtract more than the remaining coins! Please try again.\n")
                continue
            num -= player1_num
            print("Remaining coins:", num)
            print("")
            if num == 0:
                print("Player 1 wins!")
                break
            while True:
                try:
                    player2_num = int(input("Player 2's turn: "))
                    print("")
                    if not check_sqrt(player2_num):
                        raise ValueError("Not a square number.\n")
                    if player2_num > num:
                        print("You cannot subtract more than the remaining coins! Please try again.\n")
                        continue
                    num -= player2_num
                    print("Remaining coins:", num)
                    print("")
                    if num == 0:
                        print("Player 2 wins!\n")
                        break
                    break  # Exit the loop if player 2's input is valid
                except ValueError:
                    print("Please enter a valid integer!\n")
        except ValueError:
                print("Please enter a valid integer!\n")
                
#start the game
print("\nWelcome to the Subtracting Squares game!\n")
game()