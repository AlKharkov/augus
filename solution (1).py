class ClassicalMechanics:
    def __init__(self, v):
        self.v = v

    def __call__(self, vr):
        return self.v + vr

    def __str__(self):
        return f'Object {self.__class__.__name__}, velocity {self.v} c'


class SpecialTheoryRelativity(ClassicalMechanics):
    def __call__(self, vr):
        if self.v < 0.1:
            super().__call__(vr)
        return (self.v + vr) / (1 + self.v * vr)
