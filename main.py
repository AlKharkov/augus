from random import randint


def is_valid(s):
    if s.isdigit():
        return True
    return False


secret_number = randint(1, 101)
while True:
    inlet = input()
    if is_valid(inlet):
        inlet = int(inlet)
        if inlet < secret_number:
            print('The entered number is less than the desired one')
        elif inlet > secret_number:
            print('The entered number is greater than the desired one')
        else:
            print('Congratulations! You have found the hidden number')
            break
