from itertools import chain


class OpticSystem:
    def __init__(self, args):
        self.array = args[:]

    def __cmp__(self, other):
        return sum(self.array) - sum(other.array)

    def __len__(self):
        return len(self.array)

    def __delitem__(self, key):
        self.array.pop(key)

    def __getitem__(self, item):
        return self.array[item]

    def __setitem__(self, key, value):
        self.array[key] = value

    def __add__(self, other):
        return OpticSystem([i for i in chain(iter(self.array), iter(other.array))])

    def __iadd__(self, other):
        for item in other.array:
            self.array.append(item)
        return self

    def __call__(self, d):
        try:
            return round(1 / (sum(self.array) - (1 / d)), 4)
        except ZeroDivisionError:
            return None

    def __rshift__(self, n):
        n %= len(self.array)
        self.array = self.array[-n:] + self.array[:-n]
        return self

    def __lshift__(self, n):
        n %= len(self.array)
        self.array = self.array[n:] + self.array[:n]
        return self

    def append(self, item):
        self.array.append(item)


os_1 = OpticSystem([1, 2.5, 3])
os_2 = OpticSystem([4, 2.5])
print(os_2 > os_1)
print(os_2 == os_1)
