class Polynomial:
    def __init__(self, *args, **kwargs):
        self.coeffs = args

    def __repr__(self):
        return f"Polynomial X{self.coeffs}"

    def __add__(self, other):
        x = tuple(zip(self.coeffs, other.coeffs))  # ((1,4), (2,3), (3,5))
        c = [x + y for x, y in x]
        print(c)
        return Polynomial(*c)

    def __mul__(self, other):
        string = ""
        x = tuple(zip(self.coeffs, other.coeffs))  # ((1,4), (2,3), (3,5))
        c = [x * y for x, y in x]
        print(c)

    def __len__(self):
        return self.coeffs[0]

    def __call__(self):
        print("this is calling the polynomial")


p1 = Polynomial(1, 2, 3)  # x²
p2 = Polynomial(4, 3, 5)


print(p1.coeffs, p2.coeffs)
print(p1)
print(p1 + p2)
print(len(p1))

p1()
