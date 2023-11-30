from time import sleep


def add(x, y):
    return x + y


class Adder:
    def __init__(self):
        self.z = 3

    def __call__(self, x, y):
        return x + y / self.z


add2 = Adder()


def load_data():
    rv = []
    for i in range(10):
        sleep(0.5)
        print(i)
        rv.append(i)
    return rv


def compute_func():
    for i in range(10):
        sleep(0.5)
        yield i


class Compute:
    def __iter__(self):
        self.last = 0
        return self

    def __next__(self):
        rv = self.last
        self.last += 1
        if self.last > 10:
            raise StopIteration()
        sleep(0.5)
        return rv
