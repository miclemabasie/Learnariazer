class Person:
    def __init__(self, name, role):
        self.name = name
        self.role = role
        self.__salary = None

    def get_salary(self, other):
        if other.role == "Manager":
            print(f"Salary is: {self.__salary}")

    def set_salary(self, amount, other):
        if other.role != "Manager":
            print("You do not have permissions to change this salary")
        else:
            self.__salary = amount
            print("Salary done!")
