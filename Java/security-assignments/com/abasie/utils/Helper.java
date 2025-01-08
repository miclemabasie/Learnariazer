package com.abasie.utils;

public class Helper {
    public static void first_euclids_GCD(int a, int b) {
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
            System.out.print("r = " + r + "\na = " + a + "\nb = " + b + "\n");
        } while (r != 0);
        System.out.print("************\nThe GCD(" + a1 + " " + b1 + ") is: " + a);
        System.out.println("Thanks");
    }

    public static void extended_euclids_GCD(int a, int b) {
        System.out.println("Findind the GCD(" + a + ", " + b + ") ...");
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int ak = a;
        int bk = b;
        int diff; // used to temporaly calculate the difference of a and b in every iteration
        do {

            diff = ak;
            System.out.println("#################");
            System.out.println("Max(" + bk + ", " + diff + "-" + bk + ")" + "=" + find_max(bk, (diff - bk)));
            System.out.println("Min(" + bk + ", " + diff + "-" + bk + ")" + "=" + find_min(bk, (diff - bk)));

            ak = find_max(bk, (diff - bk));
            bk = find_min(bk, (diff - bk));
        } while (ak != bk);
        System.out.print("#################\nThe GCD(" + a + " " + b + ") is: " + ak);
    }

    public static int find_min(int a, int b) {
        return a < b ? a : b;
    }

    public static int find_max(int a, int b) {
        return a < b ? b : a;
    }

    public static void find_invertible_elements(int a, int n) {

    }

    public static int find_gcd_recursion(int a, int b) {
        if (b == 0) {
            return a;
        }
        return find_gcd_recursion(b, a % b);
    }

    public static void find_invertible_elements(int n) {
        int invertible_elements[] = new int[n - 1];
        // find the all values from 0 - a
        // where gcd(n, ai) = 1
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (find_gcd_recursion(n, i) == 1) {
                invertible_elements[index] = i;
                index++;
            }
        }
        for (int a : invertible_elements) {
            if (a != 0) {
                // find all valid k, from 0 to 4
                System.out.println("#####################################");
                int display_cont = 0;
                for (int k = 0; k < 50; k++) {
                    double x = find_x_using_k(a, n, k);
                    if (x != -1) {
                        if (display_cont < 5) {
                            System.out.println("This is the value of a=" + a + ", x=" + (int) x + ", k=" + k);
                            display_cont++;
                        }
                    }
                }
            }
        }
    }

    public static double find_x_using_k(int a, int n, int k) {
        // Using aX = 1 + nk;
        // Ensure double arithmetic by casting
        double x = (1.0 + (n * (double) k)) / a;
        int v = (int) x;
        if ((x - v) != 0) {
            return -1;
        }
        return x;
    }
}
