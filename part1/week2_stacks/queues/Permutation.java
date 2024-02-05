import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
public class Permutation {
    public static void main(String[] args) {
    if (args.length != 1) 
        throw new IllegalArgumentException("one argument of integer required");
    int k = 0;
    try {
        k = Integer.parseInt(args[0]);
    }
    catch (NumberFormatException e) {
        System.err.println("Uable convert parameter to int");
    }
    RandomizedQueue<String> ranque = new RandomizedQueue<String>();
    int num = 0;
    while (!StdIn.isEmpty()) {
        String s = StdIn.readString();
        ranque.enqueue(s);
        num++;
    }
    if (num < k || k < 0)
        System.err.println("invalid k");
    while (k != 0) {
        StdOut.printf("%s\n", ranque.dequeue());
        k--;
    } 
    return;
    }
 }
