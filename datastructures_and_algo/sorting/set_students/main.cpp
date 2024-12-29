#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Function to randomly shuffle the students
void shuffleStudents(std::vector<std::string> &students) {
    std::srand(std::time(0));
    std::random_shuffle(students.begin(), students.end());
}

// Function to divide students into groups
// Parameters:
// - students: Vector containing the names of students
// - numGroups: Number of groups to divide the students into
void divideIntoGroups(const std::vector<std::string> &students, int numGroups) {
    if (students.empty()) {
        std::cout << "No students available for grouping." << std::endl;
        return;
    }

    // Calculate the number of students per group and any extra students
    int studentsPerGroup = students.size() / numGroups;
    int extraStudents = students.size() % numGroups;

    int currentIndex = 0;
    for (int i = 0; i < numGroups; ++i) {
        // Determine the size of the current group
        int groupSize = studentsPerGroup + (i < extraStudents ? 1 : 0);

        // Print the group number
        std::cout << "Group " << i + 1 << ": ";

        // Print the names of students in the current group
        for (int j = 0; j < groupSize; ++j) {
            std::cout << students[currentIndex++] << ", ";
        }

        // Move to the next line for the next group
        std::cout << std::endl;
    }
}

int main() {
    // Sample list of student names
    std::vector<std::string> students = {
        "Abasie", "Tom", "Miclem", "David", "Eva",
        "Frank", "Grace", "Hank", "Hilary", "Jack",
        "John", "Leo", "Edison", "Nathan", "Olivia",
        "Paul", "Quinn", "Rachel", "Sam", "Elvis",
        "Marie", "Victor", "Melvis", "Sandra", "Yvette"
    };

    // Number of groups
    int numGroups = 5;

    // Shuffle the students randomly
    shuffleStudents(students);

    // Divide students into groups and print the result
    divideIntoGroups(students, numGroups);

    return 0;
}
