class Foo {
    private int stage = 0;

    public Foo() {
        
    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        while (stage != 0) {
            this.wait();
        }
        stage = 1;
        this.notifyAll();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while (stage != 1) {
            this.wait();
        }
        stage = 2;
        this.notifyAll();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while (stage != 2) {
            this.wait();
        }
        stage = 0;
        this.notifyAll();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}