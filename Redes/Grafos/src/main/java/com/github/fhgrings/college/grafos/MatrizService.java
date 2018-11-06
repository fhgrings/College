package com.github.fhgrings.college.grafos;

import java.util.Scanner;

import static com.github.fhgrings.college.grafos.Main.*;

public class MatrizService {

    public void receberMatriz() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                matriz[i][j] = sc.nextInt();
            }
        }
    }

    public void printMatriz() {
        for (int i = 0; i < eixoX; i++) {
            for (int j = 0; j < eixoy; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }


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
}
