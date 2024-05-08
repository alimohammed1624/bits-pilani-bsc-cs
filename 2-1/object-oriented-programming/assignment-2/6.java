public class TypeInquiryExample { 
    public static void main(String[] args) { 
        Object obj = "Hello"; 

        if (obj instanceof String) { 

            String str = (String) obj; 

            System.out.println(str.toUpperCase());
            
        } else { 
            System.out.println("Object is not of type String");
        }
    }
}