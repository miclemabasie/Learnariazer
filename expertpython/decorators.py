from time import time


def div(x, y):
    return x / y


# assuming that we can't modify the div function


def smartdivision(func):
    def wraps(*args, **kwargs):
        start = time()
        value = func(*args, **kwargs)
        stop = time()
        print("elapsed:", stop - start)
        # print("This are the args", args, "This are the kwargs", kwargs)
        return value

    return wraps


new_div = smartdivision(div)


def deco(n):
    def inner(func):
        def wrapper(*args, **kwargs):
            for _ in range(n):
                rv = func(*args, **kwargs)
            return rv

        return wrapper

    return inner


@deco(3)
def test():
    print("calling function")
