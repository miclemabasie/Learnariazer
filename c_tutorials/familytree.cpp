#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(void) {

    struct FamilyTree{
        string name;
        struct FamilyTree *mother;
        struct FamilyTree *father;
    };

    // initialize the first child
    string child_name;
    cout << "Enter Your Name: ";
    cin >> child_name;


    struct FamilyTree *child = NULL;

    struct FamilyTree mother;
    struct FamilyTree father;

    mother.mother = NULL;
    mother.father = NULL;
    father.mother = NULL;
    father.father = NULL;

    mother.name = "IRENE";
    father.name = "MUNJUNG";

    child->mother = &mother;
    child->father = &father;
    
    // string name = child->father->name;

    // cout << name;

    return 0;
}