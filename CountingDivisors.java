
import java.io.*;

public class CountingDivisors {
    static class FastIO {
        private InputStream in;
        private byte[] buffer = new byte[1 << 16];
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

        public String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            byte c = read();
            while (c <= ' ') c = read();
            do {
                sb.append((char) c);
                c = read();
            } while (c > ' ');
            return sb.toString();
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = nextInt();
            return arr;
        }
    }

    public static void main(String[] args) throws IOException {
        FastIO io = new FastIO(System.in);
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int T = io.nextInt();
        while (T-- > 0) {
            int n = io.nextInt();
            int count = 0;
            for(int i=1;i*i<=n;i++) {
                if (n % i == 0) {
                    if (i == n / i) count += 1;
                    else count += 2;
                }
            }
            pw.println(count);
        }
        pw.close();
    }
}