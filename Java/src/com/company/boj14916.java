package com.company;
import java.util.Scanner;
public class boj14916 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        int total = 0;
        if(num < 5) {
            if(num%2 == 0) {
                total = num/2;
            }else {
                total = -1;
            }

        } else {
            if(num % 5 == 0) {
                total = num/5;
            }
            else {
                int div =  num/5;
                int rest = num%5;
                if(rest%2 == 0) {
                    total +=div;
                    total +=rest/2;

                }else {
                    total += div-1;
                    total += (rest+5)/2;
                }

            }

        }

        System.out.println(total);



    }
}
