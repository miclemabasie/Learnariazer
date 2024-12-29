## Data Types

### Integers -> byte, short, int long
Float -> double, float
Character -> char, String
Boolean -> boolean

### Integers:
    byte -> 1byte
    short -> 2bytes
    int -> 4bytes
    long -> 8bytes

---

### Floats: 
    float -> 4bytes // float x = 5.6f;
    double -> 8bytes // double x = 5.6;

---

### Character: 
    char -> 2bytes
    Unicode

---
### Boolean:
    boolean -> true or false

---
### CASTING
 

### SWITCH STATEMENTS
``` java
switch (n % 2) {
            case 0:
                System.out.println("n is even");
                break;

            default:
                System.out.println("n is not even");
                break;
        }
```

For Loops
```java
for(int i = 0; i < 10; i++;){
    System.out.println("Hi");
}
```

### Method Overloading
methods with the same name but accepting different number/types of params
```java
class Calculator {
    public int add(int x, int y) {
        return x + y;
    }

    public int add(int x, int y, int z) {
        return x + y;
    }
} 
```

### ARRAYS IN JAVA
```java

public class Hello {
    public static void main(String[] args) {
        System.out.println("Learning arrays in Java");

        int nums[] = new int[67];
        generate(nums);
        // for (int i = 0; i < nums.length; i++) {
        // System.out.println(nums[i]);
        // }
        int xnums[][] = new int[3][3]; // regular arrays
        // int marks[][] = new int[3][]; // jagged array
        // marks[0] = new int[3];
        // marks[0] = new int[2];
        // marks[0] = new int[4];
        generate_3d(xnums);
        show_3d(xnums);
    }

    public static void generate(int array[]) {
        for (int i = 0; i < array.length; i++) {
            array[i] = i + 1;
        }
    }

    public static void show_arary_1d(int array[]) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static void generate_3d(int array[][]) {

        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                array[i][j] = (int) (Math.random() * 10);
            }
        }
    }

    public static void show_3d(int array[][]) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.print("\n");
        }
    }

    public static void show_advance_3d(int array[][]) {
        for (int n[] : array) {
            for (int m : n) {
                System.out.print(m);
            }
        }
    }

}


public static void main(String[] args) {
        System.out.println("Learning arrays in Java");
        Student students[] = new Student[2];
        students[0] = new Student();
        students[1] = new Student();

        students[0].name = "abasie";

        for (Student s : students) {
            System.out.print(s.name + ",");
            System.out.print(s.marks + ",");
            System.out.print(s.klass);
            System.out.println("");
        }


    }
```

### STRINGS
```java

public class Hello {
    public static void main(String[] args) {
        String name = "Miclem";
        // String constant pool
        // checks if string with same content already exists in memory before actually
        // creating them
        // in the following case, s1 and s2 are actually just referring to the same obj
        // in memory
        String s1 = "Mic";
        String s2 = "Mic";
        // System.out.println(name.length());

        // Working with immutable strings using stringbuffers
        StringBuffer sb = new StringBuffer("Miclem"); // give a buffer of 16 byes -> totaling to 22
        sb.append(" abasie");
        System.out.println(sb);
    }
}
```