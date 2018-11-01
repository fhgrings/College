package com.github.fhgrings.college.grafos;

import java.util.Scanner;

public class Main {

    private static int matriz[][] = new int[2][2];
    private static int matrizCaminho[][] = new int[2][2];
    private static int eixoX = 2;
    private static int eixoy = 2;
    private static int k=0;

    public static void main (String[] args) {


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
                if(matriz[i][j]>0) {
                    System.out.println(i + 1 + "--->" + (j + 1));
                    matrizCaminho[k][0]=i+1;
                    matrizCaminho[k][1]=j+1;
                    k++;
                }
            }
        }
    }


    public String execute(int saida, int chegada){
        int tentativas = matriz.length;

        while (tentativas>0) {
            //fazer tentantiva por cada caminho possivel ainda nao desenvolvi a logica
        }
    }

}
