package com.github.fhgrings.college.grafos;

import java.util.ArrayList;
import java.util.List;

import static com.github.fhgrings.college.grafos.Main.matrizCaminho;

public class EncontrarCaminho {


    public String execute(int saida, int chegada) {
        List<Integer> conexoes;
        int tentativas = 0;

        StringBuffer sb = new StringBuffer();
        sb.append(saida);
        sb.append(" -> ");

        conexoes = encontrarConexoes(saida);

        while (tentativas < 100) {
            for (Integer opcao : conexoes) {
                if (conexoes.contains(chegada)) {
                    excluirConexao(opcao,chegada);
                    return sb.toString() + chegada;
                }

                sb.append(conexoes.toString());
                sb.append(" -> ");


                conexoes = encontrarConexoes(opcao);
                tentativas++;
            }
        }
        return "Caminho nao encontrado";
    }
    public List<Integer> encontrarConexoes(int saida ) {
        List<Integer> chegadas = new ArrayList<>();
        for (int i = 0; i < matrizCaminho.length; i++) {
            if (matrizCaminho[i][0] == saida){
                chegadas.add(matrizCaminho[i][1]);
            }
        }
        return chegadas;
    }

    public void excluirConexao(int opcao, int chegada) {
        for(int i =0; i <matrizCaminho.length; i++) {
            if(matrizCaminho[i][0] == 3)
                if(matrizCaminho[i][1] == 5){
                    System.out.println(matrizCaminho[i][1]);
                    matrizCaminho[i][1]=0;
                    System.out.println(matrizCaminho[i][1]);
                }
        }
    }

}
