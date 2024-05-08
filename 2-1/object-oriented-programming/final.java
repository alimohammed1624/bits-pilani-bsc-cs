import java.util.Scanner;
import java.io.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] fruits = new String[n];
        for(int i = 0; i < n; i++) {
            fruits[i] = sc.next();
        }
        try {
            BufferedWriter weightWriter = new BufferedWriter(new FileWriter("weight.txt"));
            BufferedWriter dozenWriter = new BufferedWriter(new FileWriter("dozen.txt"));

            for(String fruit : fruits) {
                if(fruit.equals("Plum") || fruit.equals("Melon") || fruit.equals("Grapes")){
                    weightWriter.write(fruit);
                    weightWriter.newLine();
                } 
                if(fruit.equals("Apple") || fruit.equals("Banana") || fruit.equals("Orange")){
                    dozenWriter.write(fruit);
                    dozenWriter.newLine();
                }
            }

        } catch (IOException e) {
            System.out.println("An error occurred while creating the files.");
            e.printStackTrace();
        }
        try {
            BufferedReader weightReader = new BufferedReader(new FileReader("weight.txt"));
            BufferedReader dozenReader = new BufferedReader(new FileReader("dozen.txt"));
            System.out.println("Fruits sold by weight:");
            String line;
            while ((line = weightReader.readLine()) != null) {
                System.out.println(line);
            }
            System.out.println("Fruits sold by dozen:");
            while ((line = dozenReader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("An error occurred while reading the files.");
            e.printStackTrace();
        }
    }
}