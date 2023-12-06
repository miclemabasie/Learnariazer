from faker import Faker
import random
from itertools import permutations, combinations, groupby

names = []

num_of_students = 100
faker = Faker()
for i in range(num_of_students):
    names.append(faker.name())


enum_names = list(enumerate(names))


indexes = []


def creat_group(names, person_per_group):
    if len(names) < person_per_group:
        return names
    number_of_groups = len(names) / person_per_group
    group_list = []
    for i in range(int(number_of_groups)):
        group_list.append([])

    done = True
    while done:
        for i in range(len(names)):
            # Create random index for a name on the list
            random_index = random.randint(0, len(names) - 1)

            for i in range(int(number_of_groups)):
                if len(group_list[i]) < person_per_group:
                    if not enum_names[random_index][0] in indexes:
                        group_list[i].append(enum_names[random_index][1])
                        indexes.append(enum_names[random_index][0])
                    else:
                        print("name already in use")
                else:
                    print("group is full")

        for i in range(int(number_of_groups)):
            done = False
            if len(group_list[i]) < person_per_group:
                done = True
    print(group_list, "this is the group list")


creat_group(names, 10)


print(list(enum_names))

print(indexes)
# creat_group(names, 4)

[
    [
        "Ashlee Erickson",
        "Anthony Warren",
        "Cynthia James MD",
        "Erika Sullivan",
        "Christopher Mcdonald",
        "Kevin Waller",
        "Ronald Lewis",
        "Stephanie Williams",
        "Linda Simmons",
        "Dana Gallegos",
    ],
    [
        "Joseph Huang",
        "Hailey Curtis",
        "Brandy Scott",
        "Kevin Hurst",
        "Mark Wilson",
        "Danny Hubbard",
        "Carlos Johnson",
        "Monica Clark",
        "Joseph Harvey",
        "Tonya Alvarez",
    ],
    [
        "Jeffrey Taylor",
        "Richard Clark",
        "Catherine Berg",
        "Richard Conner",
        "John Dyer",
        "Jack Rodriguez",
        "Natasha Williams",
        "Marissa Long",
        "Dana Robinson",
        "Wendy Wells",
    ],
    [
        "Tony Reyes",
        "Vanessa Le",
        "Bailey Williams",
        "Nicholas Jenkins",
        "Julie Klein",
        "Laura Arnold",
        "Brian Miller",
        "Erica Nash",
        "Danielle Lane",
        "Michael Thompson",
    ],
    [
        "Bianca Wilson",
        "Hailey Cooper",
        "Jason Pena",
        "Donna Sanders",
        "Marissa Adams",
        "Jenny Kirk",
        "Nicole Lawrence",
        "Devin Estrada",
        "Stephanie Jones",
        "Melissa Brennan",
    ],
    [
        "Brenda Mcdonald",
        "Eric Warren",
        "Jonathan Sanders",
        "Paula Harrison",
        "Michael Olson",
        "Jason Ortiz",
        "Kathleen Griffin",
        "William Jenkins",
        "Courtney Martinez",
        "Mary Weber",
    ],
    [
        "Latasha Monroe",
        "Daniel Espinoza",
        "Ellen Cook",
        "Lisa Lara",
        "Kevin Mcbride",
        "Mary Riley",
        "Andrea Andrews",
        "Jason Luna",
        "Dr. Deborah Mora",
        "Michael Harris",
    ],
    [
        "Sarah Davis DDS",
        "Jasmine Garza",
        "Andrea Leon",
        "Jenna Brown",
        "Juan Nguyen",
        "Lori Molina",
        "Robert Smith",
        "Kevin Atkinson",
        "Samantha Willis",
        "Dawn Ball",
    ],
    [
        "Carolyn Davis",
        "Kenneth Gonzalez",
        "Jacob Hamilton Jr.",
        "Andrew Woodard",
        "Madison Davis",
        "Ian Cruz",
        "Brad Brooks",
        "Jane Wilson",
        "Tiffany Luna",
        "Lawrence Johnson",
    ],
    [
        "Holly Parker",
        "Joel Rodriguez",
        "Olivia Alexander",
        "Caroline Deleon",
        "Scott Hebert",
        "Andrew Davidson",
        "Michael Garcia MD",
        "Gary Quinn",
        "Kimberly Taylor",
        "Kristi Clark",
    ],
]
