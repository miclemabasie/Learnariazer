public
package com.abasie.utils;

public class Helper {
    // Helper function to calculate the GCD of 2 numbers a&b
    public static void euclids_GCD_regular(int a, int b) {
        int a1 = a;
        int b1 = b;
        int r;
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        do {
            System.out.println("************");
            r = a % b;
            a = b;
            b = r;
            System.out.println("r = " + r);
            System.out.println("a = " + a);
            System.out.println("r = " + a);
        } while (r != 0);
        System.out.println("The GCD(" + a1 + " " + b1 + ") is: " + a);
        System.out.println("Thanks");
    }
}
