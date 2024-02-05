import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private double []trialp;
    private static final double confidence = 1.96;
    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0)
            throw new IllegalArgumentException("n and trials should be positive");
        trialp = new double[trials];
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(trialp);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(trialp);
    }
    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        double mean = mean();
        double stddev = stddev();
        int t = trialp.length;
        
        return mean - Math.sqrt(stddev)*confidence/Math.sqrt(t);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        double mean = mean();
        double stddev = stddev();
        int t = trialp.length;
        
        return mean + Math.sqrt(stddev)*confidence/Math.sqrt(t);
    }

   // test client (see below)
    public static void main(String[] args) {
        if (args.length < 2) 
            StdOut.print("error: two arguments required\n");
        int len = Integer.parseInt(args[0]); 
        int trials = Integer.parseInt(args[1]);
        PercolationStats mantc = new PercolationStats(len, trials);
        for (int i = 0; i < trials; ++i) {
            Percolation perc = new Percolation(len);
            while (!perc.percolates()) {
                int index = StdRandom.uniform(0, len*len);
                perc.open(index/len+1, index % len+1);
            }
            double fract = perc.numberOfOpenSites() * 1.0 / (len*len);
            mantc.trialp[i] = fract;
        }
        StdOut.printf("mean                    = %f\n", mantc.mean());
        StdOut.printf("stddev                  = %f\n", mantc.stddev()); 
        StdOut.printf("95%% confidence interval = [%f, %f]\n", mantc.confidenceLo(), mantc.confidenceHi());
    }
    
}
