package com.github.fhgrings.college.grafos;

public class Main {

//  Essa area de public static int é a declaração das variaveis, o que tem varias coisas é a matriz recebendo direto na declaração
    public static int eixoX = 5;
    public static int eixoy = 5;
    public static int matriz[][] =  { {0, 1, 0, 1, 0}, {0, 0, 0, 0, 0}, {0, 1, 0, 1, 1}, {0, 1, 1, 0,0}, {0, 0, 1, 0, 0} };
    public static int[][] matrizCaminho = new int[(int)Math.pow(matriz.length,2)][2];
    public static int k = 0;

    // Declaracao das outras casses pra poder usar os metodos(funções) delas
    private static EncontrarCaminho encontrarCaminho = new EncontrarCaminho();
    private static MatrizService matrizService = new MatrizService();


    //Inicio do programa principal (faz a chmada e organiza a ordem de execuçã)
    public static void main(String[] args) {



        //System.out.println é a função pra printar na tela,
        //Ele mostra o tamanho da matriz que o programa recebeu
        System.out.println(matriz.length);

        //Metodo para printar a matriz em seu formato original
        matrizService.printMatriz();

        //Metodo para mostrar as ligações em grafos
        matrizService.mostrarCaminhos();


//      System.out.println vai executar o metodo(função) que encontra o caminho mais rapido de 1 à 5 e mostrar na tela
        //System.out.println(encontrarCaminho.execute(1,5));




    }
}
