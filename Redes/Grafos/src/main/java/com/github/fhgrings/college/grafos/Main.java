package com.github.fhgrings.college.grafos;

import java.util.Scanner;

public class Main {

    public static void main (String[] args) {
        int matriz[][] = new int[2][2];
        int eixoX = 2;
        int eixoy = 2;

        Scanner sc = new Scanner(System.in);

        for(int i=0;i < eixoX;i++) {
            for(int j=0;j < eixoy;j++){
                matriz[i][j] =sc.nextInt();
            }
        }

        for(int i=0;i< eixoX;i++) {
            for(int j=0;j< eixoy;j++){
                System.out.print(matriz[i][j]+" ");
            }
            System.out.println();
        }



        for(int i=0;i< eixoX;i++) {
            for(int j=0;j< eixoy;j++){
                if(matriz[i][j]>0)
                    System.out.println(i+1 + "--->" + (j+1) );
            }
        }
    }



}
