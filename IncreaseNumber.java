import java.util.Scanner;

public class IncreaseNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i=0;i<n;i++) a[i] = sc.nextInt();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(a[i] >= a[i-1]) continue;
            else{
                ans += a[i-1] - a[i];
                a[i] = a[i-1];
            }
        }
        System.out.println(ans);
    }
}
