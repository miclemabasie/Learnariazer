package com.abasie.utils;

public class GCD {
    public static int euclids_GCD_recursion(int a, int b) {
        /*
         * This method finds and simply returns the GCD(a, b) but does not display the
         * value to the user,
         * using recursion;
         */
        if (b == 0) {
            return a;
        }
        return euclids_GCD_recursion(b, a % b);
    }

    public static int euclids_GCD_regular(int a, int b) {
        int a1 = a;
        int b1 = b;
        int r;
        // swap operation
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        do {
            r = a % b;
            a = b;
            b = r;

        } while (r != 0);
        System.out.println("The GCD(" + a1 + " " + b1 + ") is: " + a);
        return a;
    }

    public static int euclids_GCD_extended(int a, int b) {
        int a1 = a;
        int b1 = b;
        do {
            a1 = Math.max(b1, a1 - b1);
            b1 = Math.min(b1, a1 - b1);
        } while (a1 != b1);

        return a1;
    }

}
