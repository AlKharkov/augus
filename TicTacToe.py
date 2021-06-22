# version 1.0
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


def end_game(event):
    sys.exit(0)


def moving(event):
    global move, field, in_game, win_game
    if not in_game:
        new_game()
        return 0
    x, y = event.x // square_size * square_size, event.y // square_size * square_size
    if field[y // square_size][x // square_size] == 3:
        field[y // square_size][x // square_size] = move
        if move == 1:
            canvas.create_line(x + 5, y + 5, x + 195, y + 195, fill='red', width=2)
            canvas.create_line(x + 195, y + 5, x + 5, y + 195, fill='red', width=2)
            move = 0
        else:
            canvas.create_oval(x + 5, y + 5, x + 195, y + 195, outline='red', width=2)
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
            if win_game == 0:
                result = 'Победили нолики!'
            elif win_game == 1:
                result = 'Победили крестики!'
            else:
                result = 'Ничья!'
            winner = Toplevel()
            winner.title('Игра закончена!')
            winner.geometry('+700+420')
            winner.grab_set()
            lbl = Label(winner, height=5, width=20, font=('Times New Roman', 20), text=result)
            lbl.pack()
            winner.mainloop()


# Main
root = Tk()
root.title('Tic Tac Toe')
root.geometry('+550+200')
canvas = Canvas(root, width=600, height=600, bg='#003300')
new_game()
canvas.grid()
canvas.focus_set()
canvas.bind('<ButtonPress>', moving)
canvas.bind('q', end_game)
root.mainloop()
