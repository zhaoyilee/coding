package com.luwei;

import java.util.Scanner;

public class GCD {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            int N = scanner.nextInt();
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int p = scanner.nextInt();
            int[] A = new int[N + 1];

            System.out.println(sumOfA(A,N,n,m,p));

            }
    }



    public static int sumOfA(int[] A, int N,int n,int m,int p) {

        int sum=0;
        A[1] = p;
        for (int i = 2; i < A.length; i++)
          A[i] = (A[i - 1] + 153) % p;

//        for (int i = 1; i <A.length ; i++) {
//            System.out.print(A[i]+" ");
//        }
//        System.out.println();



        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=m ; j++) {
                sum += A[gcd(i, j)];
            }
        }
        return sum;
    }


    public static int gcd(int m, int n) {

        if (m>=n)
            return n == 0 ? m : gcd(n, m % n);

        else
            return m == 0 ? n : gcd(n % m, m);
    }
}
