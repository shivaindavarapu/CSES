package maths;
import java.util.*;

public class CountingDivisors {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int count = 0;
            for(int i=1;i*i<=n;i++){
                if(n % i == 0){
                    if(i == n/i){
                        count += 1;
                    }
                    else{
                        count +=2;
                    }
                }
            }
            System.out.println(count);
        }

    }
}
