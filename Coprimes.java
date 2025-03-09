
import java.io.*;
import java.util.*;

public class Coprimes {
    static class FastIO {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int pos, bytesRead;
        
        public FastIO(InputStream in) {
            this.in = in;
        }

        private void fillBuffer() throws IOException {
            bytesRead = in.read(buffer, 0, buffer.length);
            pos = 0;
            if (bytesRead == -1) buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (pos >= bytesRead) fillBuffer();
            return buffer[pos++];
        }

        public int nextInt() throws IOException {
            int num = 0;
            byte c = read();
            while (c <= ' ') c = read();
            boolean neg = (c == '-');
            if (neg) c = read();
            do {
                num = num * 10 + (c - '0');
                c = read();
            } while (c >= '0' && c <= '9');
            return neg ? -num : num;
        }
    }
    
    static final int MAX_VALUE = (int) 1e6 + 10;
    public static void main(String[] args) throws IOException {
        FastIO in = new FastIO(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int n = in.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = in.nextInt();
        }
        
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

        out.println(totalNumberOfPairs - validPairs);
        out.flush();
    }
}
