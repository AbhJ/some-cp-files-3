class FooBar {
    private int n;
    private boolean isFooPrinted = false;

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (isFooPrinted == true) {
                this.wait();
            }
            isFooPrinted = true;
            this.notifyAll();
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (isFooPrinted == false) {
                this.wait();
            }
            isFooPrinted = false;
            this.notifyAll();
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
        }
    }
}