package com.github.fhgrings.college.grafos;

public class Main {


    public static int eixoX = 5;
    public static int eixoy = 5;
    public static int matriz[][] =  { {0, 1, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 1, 1, 0,0}, {0, 0, 1, 0, 0} };
    public static int[][] matrizCaminho = new int[(int)Math.pow(matriz.length,2)][2];
    public static int k = 0;

    private static EncontrarCaminho encontrarCaminho = new EncontrarCaminho();
    private static MatrizService matrizService = new MatrizService();

    public static void main(String[] args) {

        System.out.println(matriz.length);

        matrizService.printMatriz();
        matrizService.mostrarCaminhos();

        System.out.println(matriz.length);


        System.out.println(encontrarCaminho.execute(1,5));
        matrizService.mostrarCaminhos();
        System.out.println(encontrarCaminho.execute(1,5));



    }
}
