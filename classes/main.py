class Person:
    def __init__(self, first_name, surname, last_name, dob):
        self.first_name = first_name
        self.surname = surname
        self.last_name = last_name
        self.dob = dob

    def display_name(self):
        print(f"{self.first_name} {self.last_name}")

    def display_all(self):
        list_of_students = []
        print("This displays a list containing all the students")


class Student(Person):
    def __init__(
        self, first_name, surname, last_name, dob, level, matricule, departement
    ):
        self.level = level
        self.matricule = matricule
        self.department = departement
        return super().__init__(first_name, surname, last_name, dob)

    def get_course(self):
        print("all courses taken by this student")


class Teacher(Person):
    def __init__(self, first_name, surname, last_name, dob, course, teacher_id):
        self.course = course
        self.teacher_id = teacher_id
        return super().__init__(first_name, surname, last_name, dob)


miclem = Person("miclem", "abasie", "45-54-34")
