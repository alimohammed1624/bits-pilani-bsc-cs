class Test {
    static int max = 10;
    int min = 5;   
}

class Main {
    public static void main(String[] args) {
        Test obj = new Test();
        System.out.println("min + 1" + Test.min + 1);
        System.out.println("max + 1" + Test.max + 1);
    }
}