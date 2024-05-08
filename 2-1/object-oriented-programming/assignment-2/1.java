public class Sample{ 

    public static void main(String[] args) { 
    {
    try {
              int[] numbers = {100, 20, 65,46};
              System.out.println(numbers[0] / 0);
        } catch (ArrayIndexOutOfBoundsException e) { 
            System.out.println("Array index out of bounds!"); 
        } catch (ArithmeticException e) { 
            System.out.println("Arithmetic exception occurred!"); 
        } catch (Exception e) { 
            System.out.println("An exception occurred!"); 
        }
    }
}
}