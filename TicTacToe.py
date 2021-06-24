# version 1.1
# Tic Tac Toe
from tkinter import *

# Global
move = 1
win_game = 3
in_game = True
square_size = 200
field = [[3 for _ in range(3)] for _ in range(3)]


# Helper function
def new_game(event=1):
    global move, in_game, field, win_game
    move = 1
    win_game = 3
    in_game = True
    field = [[3 for _ in range(3)] for _ in range(3)]
    canvas.delete('all')
    canvas.create_line(200, 0, 200, 600, fill='white', width=2)
    canvas.create_line(400, 0, 400, 600, fill='white', width=2)
    canvas.create_line(0, 200, 600, 200, fill='white', width=2)
    canvas.create_line(0, 400, 600, 400, fill='white', width=2)


def end_game(event=1):  # тут этот event вообще не неужен
    sys.exit(0)


def moving(event):
    global move, field, in_game, win_game, canvas
    if not in_game:
        new_game()
        return 0
    x, y = event.x // square_size * square_size, event.y // square_size * square_size
    if field[y // square_size][x // square_size] == 3:  # если на эту клетку ещё не ходили
        field[y // square_size][x // square_size] = move
        if move == 1:
            imgx = PhotoImage(file='TicTacToeMoveX.png')
            canvas.create_image(x, y, image=imgx, anchor=NW)
            # canvas.create_line(x + 5, y + 5, x + 195, y + 195, fill='red', width=2)
            # canvas.create_line(x + 195, y + 5, x + 5, y + 195, fill='red', width=2)
            move = 0
        else:
            img0 = PhotoImage(file='TicTacToeMove0.png')
            canvas.create_image(x, y, image=img0, anchor=NW)
            # canvas.create_oval(x + 5, y + 5, x + 195, y + 195, outline='red', width=2)
            move = 1
        if field[0][0] != 3 and (field[0][0] == field[0][1] == field[0][2] or
                                 field[0][0] == field[1][0] == field[2][0] or
                                 field[0][0] == field[1][1] == field[2][2]):
            win_game = field[0][0]
        elif field[1][1] != 3 and (field[1][0] == field[1][1] == field[1][2] or
                                   field[0][1] == field[1][1] == field[2][1] or
                                   field[0][2] == field[1][1] == field[2][0]):
            win_game = field[1][1]
        elif field[2][2] != 3 and (field[2][2] == field[2][1] == field[2][0] or
                                   field[2][2] == field[1][2] == field[0][2]):
            win_game = field[2][2]
        elif field[0].count(3) + field[1].count(3) + field[2].count(3) == 0:
            win_game = 2
        if win_game < 3:
            in_game = False
            winner = Toplevel()
            winner.title('Игра закончена!')
            winner.geometry('+680+400')
            winner.grab_set()
            result_canvas = Canvas(winner, width=420, height=120)
            if win_game == 0:
                img = PhotoImage(file='TicTacToe0.png')
            elif win_game == 1:
                img = PhotoImage(file='TicTacToeX.png')
            else:
                img = PhotoImage(file='TicTacToeNotWin.png')
            result_canvas.create_image(10, 10, anchor=NW, image=img)
            result_canvas.pack()
            winner.mainloop()


# Main
root = Tk()
root.title('Tic Tac Toe')
root.geometry('+550+150')
root.resizable(False, False)
canvas = Canvas(root, width=600, height=600, bg='#003300')
new_game()
canvas.pack()
canvas.focus_set()
canvas.bind('<ButtonPress>', moving)
canvas.bind('q', end_game)
root.mainloop()
