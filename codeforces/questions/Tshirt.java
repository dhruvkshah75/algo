import java.util.*;

public class Tshirt{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int tt = sc.nextInt();
        while(tt-- > 0){
            String a = sc.next(); 
            String b = sc.next();

            int len1 = a.length();
            int len2 = b.length();
            char c1 = a.charAt(len1-1), c2 = b.charAt(len2-1);
    
            if(c1 == 'S' && c2 == 'S'){
                if(len1 < len2) System.out.println(">");
                else if(len2 < len1) System.out.println("<");
                else System.out.println("=");
                continue;
            }
            if(c1 == 'L' && c2 == 'L'){
                if(len1 > len2) System.out.println(">");
                else if(len1 < len2) System.out.println("<");
                else System.out.println("=");
                continue;
            }
            if(c1 == 'M' && c2 == 'M'){
                System.out.println("="); 
                continue;
            }
                


            if((c1 == 'S' && (c2 == 'M' || c2 == 'L'))){
                System.out.println("<");
                continue;
            }    
            if((c2 == 'S' && (c1 == 'M' || c1 == 'L'))){
                System.out.println(">");
                continue;
            }
                


            if(c1 == 'L'){
                System.out.println(">");
                continue;
            }     
            if(c2 == 'L'){
                System.out.println("<");
                continue;
            }
                  
            if(c2 == 'M'){
                if(c1 == 'S') System.out.println("<");
                else if(c1 == 'L') System.out.println(">");
                continue;
            }
            if(c1 == 'M'){
                if(c2 == 'S') System.out.println(">");
                else if(c2 == 'L') System.out.println("<");
            }
        }
        sc.close();
    }
}