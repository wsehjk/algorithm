import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class stack<Type> {
    private Type[] s;
    private int N = 0;
    @SuppressWarnings("unchecked")
    public stack() {
        s = (Type[]) new Object[1];
    }  
    private boolean isEmpty() {
        return N == 0;
    }
    @SuppressWarnings("unchecked")
    private void resize(int len) {
        Type[] copy = (Type[]) new Object[len];
        for(int i = 0; i < N; ++i){
            copy[i] = s[i];
        }
        s = copy;
        return;
    }
    public void push(Type item) {
        if(N == s.length)
            resize(2*s.length);
        s[N++] = item;
        return;
    }
    public Type pop() {
        if(isEmpty())
            return null;
        Type item = s[--N];
        s[N] = null;
        if(N > 0 && N == s.length/4)
            resize(s.length/2);
        return item;
    }
    public static void main(String[] args) {
        stack<String> stack = new stack<String>();
        while(!StdIn.isEmpty()) {
            String s = StdIn.readString();
            if(s.equals("-"))
                StdOut.printf("%s\n", stack.pop());
            else    
                stack.push(s);
        }
    } 
}
