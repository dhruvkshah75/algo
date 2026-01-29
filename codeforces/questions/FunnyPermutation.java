import java.util.*;

public class FunnyPermutation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int[] p = new int[n+1];

            if(n == 3 || n == 1){
                System.out.println(-1);
                continue;
            }

            if(n == 5){
                System.out.println("3 4 5 1 2");
                continue;
            }

            int mid1 = n/2;
            int mid2 = mid1 + 1;
            int curr1 = mid2 + 1;
            if(n%2 == 0){
                for(int i=1; i<mid1; i++){
                    p[i] = curr1;
                    curr1++; 
                }
                p[mid1] = mid2;
                p[mid2] = mid1;

                int curr2 = mid1 - 1;
                for(int i=mid2+1; i<=n; i++){
                    p[i] =curr2;
                    curr2--;
                }
            }
            else{
                for(int i=1; i<mid1; i++){
                    p[i] = curr1;
                    curr1++; 
                }
                p[mid1] = n;
                p[mid2] = mid1;
                p[mid2+1] = mid2;

                int curr2 = mid1 - 1;
                for(int i=mid2+2; i<=n; i++){
                    p[i] =curr2;
                    curr2--;
                }
            }

            for(int i=1; i<=n; i++){
                System.out.print(p[i] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
