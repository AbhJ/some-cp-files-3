class ZeroEvenOdd {
    private int n;
    private int ind = 0;
    
    public ZeroEvenOdd(int n) {
        this.n = n * 2;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void zero(IntConsumer printNumber) throws InterruptedException {
        while (ind < n) {
            while (ind % 2 != 0) {
                wait();
            }
            if (ind / 2 + 1 <= n / 2)
                printNumber.accept(0);
            ind++;
            notifyAll();
        }
    }

    public synchronized void even(IntConsumer printNumber) throws InterruptedException {
        while (ind < n) {
            while (ind % 4 != 3) {
                wait();
            }
            if (ind / 2 + 1 <= n / 2)
                printNumber.accept(ind / 2 + 1);
            ind++;
            notifyAll();
        }
    }

    public synchronized void odd(IntConsumer printNumber) throws InterruptedException {
        while (ind < n) {
            while (ind % 4 != 1) {
                wait();
            }
            if (ind / 2 + 1 <= n / 2)
                printNumber.accept(ind / 2 + 1);
            ind++;
            notifyAll();
        }
    }
}