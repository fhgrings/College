#include<stdio.h>
#include<math.h>

int binario(int n, int i)
{
    int k;
    for (i--; i >= 0; i--)
   {
      k = n >> i;
      if (k & 1)
          printf("1");
      else
         printf("0");
    }
}

int test(int n) {
    int k;
      k = n >> 24;
      if (k & 1)
          return 1;
      else
         return 0;
    }



typedef union {
	float f;
	struct {
		unsigned int mantissa : 23;
		unsigned int exponente : 8;
		unsigned int sinal : 1;
	} field;
} unionfloat;

int main() {
while(1){
	unionfloat var, var2, resultBin;
	int temp;

    printf("Entre com um ponto flutuante: ");
    scanf("%f",&var.f);

    printf("Entre com outro ponto flutuante: ");
    scanf("%f",&var2.f);

    printf("%d ",var.field.sinal);
    binario(var.field.exponente, 8);
    printf(" ");
    binario(var.field.mantissa, 23);
    printf("\n");

    printf("%d ",var2.field.sinal);
    binario(var2.field.exponente, 8);
    printf(" ");
    binario(var2.field.mantissa, 23);
    printf("\n");

    printf("numero reconstituido var  : %f", pow(-1,(var.field.sinal)) * ( 1.0 + var.field.mantissa / pow(2,23)) * pow(2,(var.field.exponente - 127)));
    printf("\n");

    printf("numero reconstituido var2 : %f", pow(-1,(var2.field.sinal)) * ( 1.0 + var2.field.mantissa / pow(2,23)) * pow(2,(var2.field.exponente - 127)));
    printf("\n");

    /* --------- Soma ---------- */

    printf("\nSoma\n");

    unsigned int store;
    unsigned int store2;
    unsigned int result;

    if(var.field.exponente > var2.field.exponente){

        store = var.field.mantissa + 1.0 * pow(2,23);
        store2 = var2.field.mantissa + 1.0 * pow(2,23);

        printf("\n");

        store2 = store2 >> (var.field.exponente - var2.field.exponente);

        binario(store, 32);
        printf("\n");
        binario(store2, 32);
        printf("\n");


        resultBin.field.exponente = var.field.exponente;
        resultBin.field.mantissa = store + store2;

        binario(resultBin.field.mantissa,32);
        printf("\n");


    }else if(var.field.exponente < var2.field.exponente){

        var2.field.mantissa = var2.field.mantissa + 1.0 * pow(2,23);
        var.field.mantissa = var.field.mantissa + 1.0 * pow(2,23);

        store = store >> (var2.field.exponente - var.field.exponente);

        binario(var.field.mantissa, 23);
        printf("\n");
        binario(var2.field.mantissa, 23);
        printf("\n");
        printf("\n");

        result = var2.field.exponente;
        result = store + store2;
    }else{

        store = var.field.mantissa + 1.0 * pow(2,23);
        store2 = var2.field.mantissa + 1.0 * pow(2,23);

        store2 = store2 << 1;


        printf("\n");

        binario(store, 32);
        printf("\n");
        binario(store2, 32);
        printf("\n");
        printf("\n");

        resultBin.field.exponente = var.field.exponente+1;
        resultBin.field.mantissa = store + store2;

    }

//    if(test()){
        resultBin.field.exponente +1;
        resultBin.field.mantissa >> -1;
    //}

    printf("%d ",var2.field.sinal);
    binario(resultBin.field.exponente, 8);
    printf(" ");
    binario(resultBin.field.mantissa, 23);
    printf("\n");

    printf("resultado Soma 2: %f", pow(-1,(resultBin.field.sinal)) * ( 1.0 + resultBin.field.mantissa / pow(2,23)) * pow(2,(resultBin.field.exponente - 127)));
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");


}
    return 0;
}
