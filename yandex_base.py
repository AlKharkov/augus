data = {'1000': 'M', '500': 'D', '100': 'C', '50': 'L', '10': 'X', '5': 'V', '1': 'I'}
one, two = 80, 8


def roman():
    print(f'{to_ryms(one)} + {to_ryms(two)} = {to_ryms(one + two)}')


def to_ryms(a):
    s = str(a)
    i = len(s) - 1
    adp = ''
    if i != 0:
        adp = to_ryms(int(s[1:]))
    c = int(s[0])
    if c < 4:
        return data[str(10 ** i)] * int(s[0]) + adp
    if c == 4:
        return data[str(10 ** i)] + data[str(5 * 10 ** i)] + adp
    if c < 9:
        return data[str(5 * 10 ** i)] + data[str(10 ** i)] * (int(s[0]) - 5) + adp
    if c == 9:
        return data[str(10 ** i)] + data[str(10 ** (i + 1))] + adp
