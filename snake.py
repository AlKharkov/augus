# version 1.0

# Глобальные переменные
N = 8  # количество строк
M = N * 2  # количество столбцов
IN_GAME = True
ACTS = ['up', 'down', 'left', 'right', 'w', 's', 'a', 'd', 'end']  # список возможных действий
FIELD = [[' ' for _ in range(M)] for _ in range(N)]
Y_HEAD, X_HEAD = N // 2, M // 2  # координаты головы змейки


# 0------>x
# | - - -
# | - - -
# | - - -
# ↓y
# Вспомогательные функции
# Задаём поле
def create_field():
    global FIELD, X_HEAD, Y_HEAD
    FIELD = [['-' for _ in range(M)] for _ in range(N)]
    Y_HEAD, X_HEAD = N // 2, M // 2
    FIELD[Y_HEAD][X_HEAD] = '*'  # задаём змейку


# Очищаем чат путём перевода строк
def clear_chat():
    print('\n' * 15)


# Начинаем игру
create_field()
while IN_GAME:
    clear_chat()
    # Выводим поле
    for i in range(N):
        print(''.join(FIELD[i]))
    # Считываем действие пока не будет введено корректное
    act = ''
    while act.lower() not in ACTS:
        act = input('Введите в какую сторону хотите пойти: ')
    act = act.lower()
    if act == 'end':
        break
    elif act in ('up', 'w'):
        Y_HEAD -= 1
    elif act in ('down', 's'):
        Y_HEAD += 1
    elif act in ('left', 'a'):
        X_HEAD -= 1
    elif act in ('right', 'd'):
        X_HEAD += 1
    X_HEAD %= M  # если выходим за границы поля, то появляемся с другой стороны
    Y_HEAD %= N
    # Если врезались, то игра заканчивается и предлагает выйти или перезапустить игру
    if FIELD[Y_HEAD][X_HEAD] == '*':
        IN_GAME = False
        clear_chat()
        FIELD[Y_HEAD][X_HEAD] = 'X'
        for i in range(N):
            print(''.join(FIELD[i]))
        print('Вы проиграли!')
        act = input('Чтобы продолжить введите "YES" иначе вы закончите игру: ')
        if act.lower() == 'yes':
            IN_GAME = True
            print('Создание чистого поля...')
            create_field()
    FIELD[Y_HEAD][X_HEAD] = '*'

# Прощание с игроком
clear_chat()
print('----------------')
print('До новых встреч!')
print('----------------')
