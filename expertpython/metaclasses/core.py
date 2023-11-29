from library import Base


# What to do to make sure the code doesn't break at runtime
# run a test to make sure that the foo method is present
# assert hasattr on the base class to make sure the foo method is present
# User level enforcing constriansts on the Base level

# assert hasattr(Base, "foo")  # You broke if you fool...


class Derived(Base):
    def bar(self):
        return "bar"
