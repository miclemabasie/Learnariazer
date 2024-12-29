
public class Main {
    public static void main(String[] args) {
        int x = euclids_GCD_extended(48, 18);
        System.out.println(x);

    }

    public static int euclids_GCD_extended(int a, int b) {
        int a1 = a;
        int b1 = b;
        do {
            a1 = find_max(b1, a1 - b1);
            b1 = find_min(b1, a1 - b1);
        } while (b1 != 0);

        return a1;
    }

    public static int find_min(int a, int b) {
        int res = a < b ? a : b; // ternary operation
        return res;
    }

    public static int find_max(int a, int b) {
        int res = a > b ? a : b;
        return res;
    }

}
