class H2O {
    private int counter = 0;
    public H2O() {
        
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        synchronized (this) {
            while (counter == 2) {
                this.wait();
            }
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            this.notifyAll();
            releaseHydrogen.run();
            counter++;
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        synchronized (this) {
            while (counter != 2) {
                this.wait();
            }
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            this.notifyAll();
            releaseOxygen.run();
            counter = 0;
        }
    }
}