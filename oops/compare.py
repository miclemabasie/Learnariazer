# python


class Car:
    def __init__(self, make: str, model: str) -> None:
        self.make = make
        self.model = model

    def compare(self, other):
        if self.model == other.model and self.make == other.make:
            return True
        return False

    def __eq__(self, other) -> bool:
        if self.make == other.make:
            return True
        return False

    def __add__(self, other):
        return "adding cars together"

    def __iter__(self):
        l = (self.make, self.model)
        for i in l:
            print(i)
        return l
