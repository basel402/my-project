# File: CS112_A1_T2_ONE_20230085.py
# purpose: 2 players choosing a number alternatively from 1 to 10 and add it to a counter if any one reached 100 he wins
# Author: basel mohamed abd elmoneim mohamed holaiel
# ID: 20230085
# problem: 100 game (task2)


# this function is the game menu and explains the game rules
def game_menu():
    print(' ')
    print("""##################################### 100 game ##################################################""")
    print("                Two players start from zero and alternatively add a number")
    print("        this number is from 1 to 10 added to a counter,the player who reaches 100 wins")
    print(' ')
    print("""############### this is the start of 100 game ############## """)

# this function checks the validity of the number added


def num_validity(num):
    while int(num) < 1 or int(num) > 10:
        num = input("please enter a number between 1 and 10: ")
        while not num.isdigit():
            num = input("please enter a valid number: ")
    return num


# this is the counter which the 2 players add their numbers to
counter = 0

# game menu and explanation
game_menu()
# infinite loop until counter = 100
while True:
    # the first player enters his number
    num1 = input("player 1 enter your number: ")

    # checking that the number is an integer
    while not (num1.isdigit()):
        num1 = input("please enter a valid number: ")

    # number validity checking function
    num1 = num_validity(num1)

    # adding the first player number to the counter
    counter += int(num1)

    # if the counter exceeds 100 the input is retaken from the user to not make counter>100
    while counter > 100:
        counter -= int(num1)
        num1 = input("counter exceeded 100,choose a number to not exceed 100: ")
        # checking validity of the input
        while not (num1.isdigit()):
            num1 = input("please enter a valid number: ")
        num1 = num_validity(num1)
        counter += int(num1)

    # displaying the counter to the users
    print("now the counter =", counter)

    # if the counter=100 player 1 wins
    if counter == 100:
        print("player 1 you are the winner")
        break

    # the second player enters his number
    num2 = input("player 2 enter your number: ")

    # checking that the number is an integer
    while not (num2.isdigit()):
        num2 = input("please enter a valid number: ")

    # number validity checking function
    num2 = num_validity(num2)

    # adding the second player number to the counter
    counter += int(num2)

    # if the counter exceeds 100 the input is retaken from the user to not make counter>100
    while counter > 100:
        counter -= int(num2)
        num2 = input("counter exceeded 100,choose a number to not exceed 100: ")
        # checking validity of the input
        while not (num2.isdigit()):
            num2 = input("please enter a valid number: ")
        num2 = num_validity(num2)
        counter += int(num2)

    # displaying the counter to the users
    print("now the counter =", counter)

    # if the counter=100 player 2 wins
    if counter == 100:
        print("player 2 you are the winner")
        break
        