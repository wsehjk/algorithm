import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private final int n;
    private boolean[][] openSite;
    private final WeightedQuickUnionUF quf; 
    private int opensitesNum;
    // creates n-by-n openSite, with all sites initially blocked
    public Percolation(int nP) {
        if (nP <= 0)
        throw new IllegalArgumentException("parameter should be positive");
        n = nP;
        openSite = new boolean[n+1][n+1];
        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                openSite[i][j] = false;
            }
        }
        quf = new WeightedQuickUnionUF(n*n+2);
        opensitesNum = 0;
    }
    private int map(int row, int col) {
        return (row-1)*n + col-1;
    }
    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("index out of range");
        int index = map(row, col); 
        if (!isOpen(row, col)) {
            openSite[row][col] = true;
            opensitesNum++;
            if (row - 1 >= 1 && isOpen(row-1, col))
                quf.union(index, index - n);
            if (row + 1 <= n  && isOpen(row+1, col)) 
                quf.union(index, index + n); 
            if (col - 1 >= 1 && isOpen(row, col-1))
                quf.union(index, index - 1);
            if (col + 1 <= n && isOpen(row, col+1))
                quf.union(index, index + 1);
            if (row == 1) // top row open site connected with upper virtual site
                quf.union(index, n*n);
            if (row == n)
                quf.union(index, n*n+1);
        }  
        return;
         
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("index out of range");
        return openSite[row][col]; 
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("index out of range"); 
        if (isOpen(row, col)) // open sites check whether connected to top row open sites
            return quf.find(map(row, col)) == quf.find(n*n);
        else // not open sites 
            return false; 
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return opensitesNum;
    }

    // does the system percolate?
    public boolean percolates() {
        return quf.find(n*n) == quf.find(n*n+1);
    }

    // test client (optional)
    public static void main(String[] args) {
        // main method not used
    }
    
}