package com.github.fhgrings.college.grafos;

import java.util.Scanner;

import static com.github.fhgrings.college.grafos.Main.*;

public class MatrizService {


    //Nao é usado ainda pq declaramos os valores da matriz no inicio do programa
    public void receberMatriz() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                matriz[i][j] = sc.nextInt();
            }
        }
    }


    //Recebe a matriz e mostra na tela em formato 5x5
    public void printMatriz() {
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                System.out.print(matriz[i][j] + "     |     ");
            }
            System.out.println();
        }
    }



    // Busca as conexoes diretas (1 para 1) da matriz
    public void mostrarCaminhos() {
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                if (matriz[i][j] > 0) {
                    System.out.println(i + 1 + "--->" + (j + 1));
                    matrizCaminho[k][0] = i + 1;
                    matrizCaminho[k][1] = j + 1;
                    k++;
                }
            }
        }
    }


    // Da mesma maneira que passamos por todos os  pontos das matrizes como nos metodos anteriores
    // Nesse metodo Guardamos uma primeira variavel de valor alto, para que seja substituido pelas proximas
    // A medida que for encontrando caminhos com pesos menores
    public void encontrarMenorValor() {
        int menorValor = 100000;
        String valor = "Primeiro valor é o menor";
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                if (matriz[i][j] < menorValor && matriz[i][j] > 0) {
                    menorValor = matriz[i][j];
                    valor = i + 1 + "--->" + (j + 1) + " = " +menorValor;
                }
            }
        }
        System.out.println(valor);
    }



    // Da mesma maneira que passamos por todos os  pontos das matrizes como nos metodos anteriores
    // Nesse metodo Guardamos uma primeira variavel de valor 0, para que seja substituido pelas proximas
    // A medida que for encontrando caminhos com pesos MAIORES
    public void encontrarMaiorValor() {
        int maiorValor = matriz[0][0];
        String valor = "Primeiro valor é o maior";
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                //Caso o valor encontrado seja maior que o anterior salvo
                //Gera uma nova String com a aresta e o peso do mesmo
                if (matriz[i][j] > maiorValor) {
                    maiorValor = matriz[i][j];
                    valor = (i + 1) + "--->" + (j + 1) + " = " + maiorValor;
                }
            }
        }

        //Ao sair de todos os loops, printa o ultimo resultado gravado, sendo o maior
        System.out.println(valor);

    }

}
