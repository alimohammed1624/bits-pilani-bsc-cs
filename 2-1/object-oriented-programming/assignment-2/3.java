import java.io.*; 

public class FileAppend { 

    public static void main(String[] args) { 
    try { 
            FileWriter fileWriter = new FileWriter("data.txt", true);

            fileWriter.write("Hello, "); 
            fileWriter.write("World!");

            fileWriter.close(); 

        } catch (IOException e) { 
            e.printStackTrace(); 
        } 
    }
} 