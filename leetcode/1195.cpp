class FizzBuzz {
    
    private int n;
    private int ind = 1;
    
    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        while (ind <= n) {
            if (ind % 3 != 0 || ind % 5 == 0) {
                wait();
                continue;
            }
            printFizz.run();
            ind += 1;
            notifyAll();
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        while (ind <= n) {
            if (ind % 5 != 0 || ind % 3 == 0) {
                wait();
                continue;
            }
            printBuzz.run();
            ind += 1;
            notifyAll();
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (ind <= n) {
            if (ind % 15 != 0) {
                wait();
                continue;
            }
            printFizzBuzz.run();
            ind += 1;
            notifyAll();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        while (ind <= n) {
            if (ind % 3 == 0 || ind % 5 == 0) {
                wait();
                continue;
            }
            printNumber.accept(ind);
            ind += 1;
            notifyAll();
        }
    }
}