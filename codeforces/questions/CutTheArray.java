import java.util.*;

public class CutTheArray {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            Vector<Integer> a = new Vector<>();
            long sum = 0;
            for(int i=0; i<n; i++){
                int x = sc.nextInt();
                a.add(x);
                sum += x*1L;
            } 

            if(sum % 3 == 0){
                System.out.println("1 2");
            }
            else{
                System.out.println("0 0");
            }

        }
        sc.close();
    }
}
