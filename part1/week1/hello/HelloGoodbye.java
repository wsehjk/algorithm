// import edu.princeton.cs.algs4.StdIn;
// import edu.princeton.cs.algs4.StdOut;
// import edu.princeton.cs.algs4.StdRandom;
public class HelloGoodbye {
    public static void main(String [] arg) {
        if (arg.length != 2) {
            System.out.printf("%d\n", arg.length);
            System.out.println("Two arguments required"); 
        }
        String name1 = arg[0];
        String name2 = arg[1];
        System.out.printf("Hello %s and %s\n", name1, name2);
        System.out.printf("Goodbye %s and %s\n", name2, name1);
    }
}