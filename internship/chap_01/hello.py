class Shape:
    def __init__(self, color) -> None:
        self.color = color


class Rectangle(Shape):
    def __init__(self, color, l, w) -> None:
        self.l = l
        self.w = w
        super().__init__(color)

    def get_area(self):
        return self.l * self.w


class Circle(Shape):
    def __init__(self, color, radius):
        self.raduis = radius
        super().__init__(color)

    def get_area(self):
        return 3.142 * (self.raduis* self.raduis)
    

class Box(Rectangle):
    def __init__(self, color, l, w, h) -> None:
        super().__init__(color, l, w)
        self.h = h

    def get_volume(self):
        return self.w * self.h * self.l
    


c = Circle("red", 5)
print(c.get_area())


b = Box("BLACK", 3, 4, 5)
print(b.get_volume())