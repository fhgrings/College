#include<stdio.h>
#include<math.h>

typedef union {
	float f;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponente : 8;
		unsigned int sinal : 1;
	} field;
} unionfloat;

int binario(int n, int i)
{
    int k;
    int contador =0;
    for (i--; i >= 0; i--)
   {
    contador++;

    k = n >> i;
    if(contador == 8)
        printf("-");
    if (k & 1)
        printf("1");
    else
        printf("0");
    if(contador == 8)
        printf("-");
    }
}

int testeParaDeslocarMantissa(int n,int i) {
    int k;
    int contador =0;
    for (i--; i >= 0; i--)
   {
        contador++;

        k = n >> i;
        if(contador == 8){
            if (k & 1)
                return 1;
            return 0;
        }
    }
}

int deslocarMantissaPelaDiferencaExpoente(int value, unionfloat expoenteMenor, unionfloat expoenteMaior) {
    value = value >> (expoenteMaior.field.exponente - expoenteMenor.field.exponente);
    return value;
}

unionfloat calcular(unionfloat var, unionfloat var2){
    unionfloat result;
    unsigned int store;
    unsigned int store2;

    store = var.field.mantissa + 1.0 * pow(2,23);
    store2 = var2.field.mantissa + 1.0 * pow(2,23);

    printf("Primeiro Valor: ");
    binario(store,32);
    printf("\n");

    printf("Primeiro Valor: ");
    binario(store2,32);
    printf("\n");

    if(var.field.exponente != var2.field.exponente){

        if (var.field.exponente > var2.field.exponente){
            store2 = deslocarMantissaPelaDiferencaExpoente(store2,var2,var);
            result.field.exponente = var.field.exponente;
        }

        if(var2.field.exponente > var.field.exponente){
            store = deslocarMantissaPelaDiferencaExpoente(store,var,var2);
            result.field.exponente = var2.field.exponente;
        }
    }
    else
        result.field.exponente = var.field.exponente;

    printf("Valores Deslocados: \n");

        binario(store,32);
        printf("\n");
        binario(store2,32);
        printf("\n");

    int resultado;
    if(var.field.exponente ==0){
        resultado = store2;
    } else if (var2.field.exponente ==0) {
        resultado = store;
    } else
        resultado = store2 + store;

    binario(resultado,32);

    if(testeParaDeslocarMantissa(resultado,32)){
        resultado = resultado >> 1;
        printf("\n Resultado deve pular 1 \n");
        binario(resultado,32);
        result.field.exponente++;
    }



    printf("\nResultado da mantissa final: ");
    result.field.mantissa = resultado;
    binario(result.field.mantissa,23);

    //result.field.exponente++;

    printf("\n");
    binario(result.field.exponente,8);




    printf("resultado Soma 2: %f", pow(-1,(result.field.sinal)) * ( 1.0 + result.field.mantissa / pow(2,23)) * pow(2,(result.field.exponente - 127)));

}

//unionfloat intTo23Bits(int valor) {
    //return
//}

int main() {
while(1){
	unionfloat var, var2, result;
    printf("Entre com um ponto flutuante: ");
    scanf("%f",&var.f);

    printf("%d ",var.field.sinal);
    binario(var.field.exponente, 8);
    printf(" ");
    binario(var.field.mantissa, 23);
    printf("\n");

    printf("Entre com outro ponto flutuante: ");
    scanf("%f",&var2.f);

    printf("%d ",var2.field.sinal);
    binario(var2.field.exponente, 8);
    printf(" ");
    binario(var2.field.mantissa, 23);
    printf("\n");

    printf("numero reconstituido  : %f", pow(-1,(var.field.sinal)) * ( 1.0 + var.field.mantissa / pow(2,23)) * pow(2,(var.field.exponente - 127)));
    printf("\n");




    //------------------- SOMA -------------------

    calcular(var,var2);


    printf("\n");
    printf("\n");
    printf("\n");
}
    return 0;
}
