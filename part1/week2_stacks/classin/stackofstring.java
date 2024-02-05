import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

// public class stackofstring {
//     private class Node {
//         String item;
//         Node next;
//     }
//     private Node first = null;
//     public boolean isEmpty(){
//         return first == null;
//     }
//     public void push(String s) {
//         Node oldfirst = first;
//         first = new Node();
//         first.item = s;
//         first.next = oldfirst;
//     }
//     public String pop() {
//         if(isEmpty())
//             return "";
//         String s = first.item;
//         first = first.next;
//         return s;
//     }
//     public static void main(String[] args) {
//         stackofstring stack = new stackofstring();
//         while(!StdIn.isEmpty()) {
//             String s = StdIn.readString();
//             if(s.equals("-"))
//                 StdOut.printf("%s\n", stack.pop());
//             else    
//                 stack.push(s);
//         }
//     }
// }
public class stackofstring {
    private String[] s;
    private int N = 0;
    public boolean isEmpty() {
        return N == 0;
    }
    public stackofstring() {
        s = new String[1];
    }
    private void resize(int capacity) {
        String[] copy = new String[capacity];
        for(int i = 0; i < N; ++i){
            copy[i] = s[i];
        }
        s = copy;
        return;
    }
    public void push(String item) {
        if(N == s.length)
            resize(2*s.length);
        s[N++] = item;
        return;
    }
    public String pop() {
        if(isEmpty())
            return "";
        String item = s[--N];
        s[N] = null;
        if(N == s.length/4)
            resize(s.length/2);
        return item;
    }
    public static void main(String[] args) {
        stackofstring stack = new stackofstring();
        while(!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if(s.equals("-"))
                StdOut.printf("%s\n", stack.pop());
            else    
                stack.push(s);
        }
    } 
}
