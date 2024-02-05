import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] que;
    private int n;
    private int front;
    private int rear;
    // construct an empty randomized queue
    //@SuppressWarnings("unchecked")
    public RandomizedQueue() {
        que = (Item[]) new Object[1];
        n = 0;
        front = 0;
        rear = 0;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return n == 0;
    }
   
    // return the number of items on the randomized queue
    public int size() {
        return n;
    }
   // @SuppressWarnings("unchecked") 
    private void resize(int capacity) {
        Item[] copy = (Item[]) new Object[capacity];
        int k = front;
        for (int i = 0; i < n; ++i) {
            copy[i] = que[k];
            k = (k+1) % (que.length);
        }
        front = 0;
        rear = n;
        que = copy;
        return;
    }
    // add the item
    public void enqueue(Item item) {
        if (item == null)
            throw new IllegalArgumentException("argument is null");
        if (n == que.length) // full 
            resize(2*n);
        que[rear] = item;
        rear = (rear+1) % que.length;
        n++;
       // StdOut.printf("the que length is %d\nthe number of elements is %d\n", quelength(), size());
        return;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("empty deque");
        int index = StdRandom.uniform(0, n);
        index = (front+index) % que.length;
        Item data = que[index];
        rear = (rear-1) % que.length;
        if (rear == -1)
            rear = que.length - 1;
        que[index] = que[rear];
        n--;
        if (n > 0 && n == que.length/4)
            resize(que.length/2);
        // StdOut.printf("the que length is %d\nthe number of elements is %d\n", quelength(), size());
        // StdOut.printf("the element deleted is %d\n", data);
        return data;
    }
    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty())
            throw new java.util.NoSuchElementException("empty deque");
        int index = StdRandom.uniform(0, n);
        index = (front+index) % que.length;
        return que[index]; 
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
       return new QueIte();
    }
    private class QueIte implements Iterator<Item> {
        private int curIndex = front;
        private int num = 0;
        public boolean hasNext() {
            return num != n; 
        }
        public void remove() {
            throw new  UnsupportedOperationException("remove() not support for client code");
        }
        public Item next() {
            if (!hasNext())
                throw new java.util.NoSuchElementException("empty deque"); 
            Item data = que[curIndex++];
            num++;
            return data;
        }
    }
    // unit testing (required)
    public static void main(String[] args) {
        RandomizedQueue<Integer> ranque = new RandomizedQueue<Integer>();
        ranque.enqueue(1);
        ranque.enqueue(5);
        ranque.enqueue(13);
        ranque.enqueue(19);
        // ranque.enqueue(25);
        ranque.dequeue();
        Iterator<Integer> it = ranque.iterator();
        while (it.hasNext()) {
            StdOut.printf("%d ", it.next());
        }
        StdOut.printf("\n");
        ranque.dequeue();
        ranque.dequeue();
        it = ranque.iterator();
        while (it.hasNext()) {
            StdOut.printf("%d ", it.next());
        }
        StdOut.printf("\n");
    }

}