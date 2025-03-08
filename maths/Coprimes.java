package maths;
import java.util.*;
 
//this code will give tle because of Scanner(slow IO)
public class Coprimes {
    static final int MAX_VALUE = (int) 1e6 + 10;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }
        sc.close();
 
        List<Integer>[] divisorsOf = new ArrayList[MAX_VALUE];
        for (int i = 0; i < MAX_VALUE; i++) {
            divisorsOf[i] = new ArrayList<>();
        }
        
        for (int i = 2; i < MAX_VALUE; i++) {
            if (divisorsOf[i].isEmpty()) {
                divisorsOf[i].add(i);
                for (int j = 2 * i; j < MAX_VALUE; j += i) {
                    divisorsOf[j].add(i);
                }
            }
        }
 
        int[] valuesDivisibleBy = new int[MAX_VALUE];
        int[] primeDivisorsOf = new int[MAX_VALUE];
 
        for (int i = 0; i < n; i++) {
            int value = values[i];
            int size = divisorsOf[value].size();
            for (int mask = 1; mask < (1 << size); mask++) {
                int combination = 1;
                int primeDivisors = 0;
                for (int pos = 0; pos < size; pos++) {
                    if ((mask & (1 << pos)) != 0) {
                        combination *= divisorsOf[value].get(pos);
                        primeDivisors++;
                    }
                }
                valuesDivisibleBy[combination]++;
                primeDivisorsOf[combination] = primeDivisors;
            }
        }
 
        long totalNumberOfPairs = ((long) n * (n - 1)) / 2;
        long validPairs = 0;
 
        for (int i = 0; i < MAX_VALUE; i++) {
            if (primeDivisorsOf[i] % 2 == 1) {
                validPairs += ((long) valuesDivisibleBy[i] * (valuesDivisibleBy[i] - 1)) / 2;
            } else {
                validPairs -= ((long) valuesDivisibleBy[i] * (valuesDivisibleBy[i] - 1)) / 2;
            }
        }
 
        System.out.println(totalNumberOfPairs - validPairs);
    }
