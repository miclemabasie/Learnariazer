# Trying to hook into the creation process of classes using the builtins


# The new way -> Meta classes
class BaseMeta(type):
    def __new__(cls, name, bases, body):
        print("BaseMeta.__new__", cls, name, bases, body)
        print(body)
        name = body["__qualname__"]

        if name != "Base" and "bar" not in body:
            raise TypeError(
                "Bad code, Check and make sure you class has the bar method"
            )

        return super().__new__(cls, name, bases, body)


class Base(metaclass=BaseMeta):
    def foo(self):
        return self.bar


# This is used to enforce constraints when creating classes inheriting the base class

# old_bc = __build_class__


# def my_bc(fun, name, base=None, **kw):
#     if base is Base:
#         print(fun)
#         if hasattr(fun, "bar"):
#             print("The base has bar method")
#         print("Check if the bar method is defined")
#     if base is not None:
#         return old_bc(fun, name, base, *kw)
#     return old_bc(fun, name, *kw)


# import builtins

# builtins.__build_class__ = my_bc
