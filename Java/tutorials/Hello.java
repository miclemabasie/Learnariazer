
class Mobile {
    static String name;
    int price;
    String brand;

    static {
        // Static block is called only on class loading
        // initiated by the (class loader)
        name = "SmartPhone";
        System.out.println("Running the static block");
    }

    public Mobile() {
        // Object instantiation, happens everytime an object is created
        price = 299;
        brand = "Samsung";
        System.out.println("Running the constructor");
    }
}

public class Hello {
    public static void main(String[] args) throws ClassNotFoundException {
        Class.forName("Mobile");
        // System.out.println("Learning 'static' keyword in java");
        // Mobile m1 = new Mobile();
        // Mobile m2 = new Mobile();
        // System.out.println(Mobile.name + " " + m1.brand + " " + m1.price);
        // System.out.println(Mobile.name + " " + m2.brand + " " + m2.price);
    }
}
