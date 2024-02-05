import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;
public class Deque<Item> implements Iterable<Item> {
    private class Node {
        Item data;
        Node next;
        Node pre;
        public Node(Item data, Node next, Node pre) {
            this.data = data;
            this.next = next;
            this.pre = pre;
        }
    } 
    private Node first = null;
    private Node last = null;
    private int n;
    // construct an empty deque
    public Deque() {
    }

    // is the deque empty?
    public boolean isEmpty() {
        return first == null;
    }

    // return the number of items on the deque
    public int size() {
        return n;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null)
            throw new IllegalArgumentException("parameter null");
        Node oldfirst = first;
        first = new Node(item, oldfirst, null);
        if (last == null)
            last = first;
        else 
            oldfirst.pre = first;
        n++;
        return;
    }

    //  add the item to the back
    public void addLast(Item item) {
        if (item == null)
            throw new IllegalArgumentException("parameter null");
        Node oldlast = last;
        last = new Node(item, null, oldlast);
        if (first == null)
            first = last;
        else
            oldlast.next = last;
        n++;
        return;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("empty deque");
        Item it = first.data;
        first = first.next;
        if (first == null) {
            last = first;
        }
        else {
            first.pre = null;
        }
        n--;
        return it;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("empty deque");
        Item it = last.data;
        last = last.pre;
        if (last == null)
            first = last;
        else 
            last.next = null;
        n--;
        return it;
    }
    private class DeLinkListIte implements Iterator<Item> {
        private Node current = first;
        public boolean hasNext() {
            return current != null;
        }
        public Item next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException("empty deque"); 
            Item it = current.data;
            current = current.next;
            return it;
        }
        public void remove() {
            throw new UnsupportedOperationException("remove() not supported for client code");
        }
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new DeLinkListIte();
    }
    // unit testing (required)
    public static void main(String[] args) {
        Deque<Integer> de = new Deque<Integer>();
        de.addFirst(1);
        de.addLast(2);
        de.addLast(3);
        de.addFirst(4);
        Iterator<Integer> it = de.iterator();
        while (it.hasNext()) {
            StdOut.printf("%d ", it.next());
        }
        StdOut.printf("\nnumber of elements is %d\n", de.size());
        de.removeFirst();
        de.addFirst(8);
        de.removeLast();
        de.removeLast();
        de.addLast(14);
        it = de.iterator();
        while (it.hasNext()) {
            StdOut.printf("%d ", it.next());
        } 
        StdOut.printf("\nnumber of elements is %d\n", de.size()); 
    }
}