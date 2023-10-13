#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//para a entrada de arquivos
#define TAMANHO_MAXIMO 20 


void funcao(FILE* arquivo, char regra[]) {
    char caractere;
    char aux[1000];

    // abrindo arquivo para ler o axioma e copiar para "aux"
    arquivo = fopen("saida.txt", "r"); 
    int i = 0;
    while((caractere = fgetc(arquivo)) != EOF){
        aux[i] = caractere;
        i++ ;
    }
    aux[i] = '\0';
    fclose(arquivo);

    //colocar a alteração resposta no arquivo
    arquivo = fopen("saida.txt", "w");
    for (int j = 1; aux[j] != '\0' ; j++) {
        if (aux[j] != '+' && aux[j] != '-') {
            fprintf(arquivo,"%s", regra);
        } 
        else {
            fprintf(arquivo,"%c", aux[j]);
        }
    }
    fclose(arquivo);
}

int main() {
    char resposta;

    // do {


        // arquivo de entrada
        FILE* arquivo = fopen("entrada.txt", "r");
        if (arquivo == NULL) {
            printf("ERRO AO ABRIR ARQUIVO DE ENTRADA\n");
            return 1;
        } else {
            printf("arquivo de entrada aberto com sucesso \n");
        }

        char axioma[TAMANHO_MAXIMO] = "";
        int angulo = 0;
        char regra[TAMANHO_MAXIMO] = "";

        // lendo o arquivo
        char caractere;
        int i = 0;
        int linha = 1;
        while ((caractere = fgetc(arquivo)) != EOF) {
            if (caractere == '\n') {
                linha++;
                i = 0;
                continue;
            }
            if (linha == 1) {
                axioma[i] = caractere;
                i++;
                axioma[i] = '\0';
            } else if (linha == 2) {
                if ((caractere - '0') >= 0) {
                    angulo = (angulo * 10) + (caractere - '0');
                }
            } else if (linha == 3) {
                regra[i] = caractere;
                i++;
                regra[i] = '\0';
            }
        }
        fclose(arquivo);        

        
        int iteracoes = 0;
        printf("axioma: %s\n", axioma);
        printf("angulo: %d\n", angulo);
        printf("regra: %s\n", regra);
        printf("Quantidade de estágios: \n");
        scanf("%d", &iteracoes);

        if (iteracoes == 0){
            printf("%s", axioma);
        }
        else{
            // arquivo de saida
            arquivo = fopen("saida.txt", "w");
            if (arquivo == NULL) {
                printf("ERRO AO ABRIR ARQUIVO DE SAIDA\n");
                return 1;
            } 

            char destino[TAMANHO_MAXIMO];
            strcpy(destino, regra);  

            if(iteracoes == 1) {
                fprintf(arquivo, "%s", regra);
            } else {
                // tem que fazer para o est 3 e 4.
                do {
                    iteracoes--;
                    for (int i = 0; i < TAMANHO_MAXIMO; i++) {
                        if(regra[i] == ' ' ) return 0
                        else {
                            if(regra[i] == 'F') {
                                fprintf(arquivo, "%s", regra);
                            } else {
                                fprintf(arquivo, "%c", regra[i]);
                            }
                        }
                        }           
                }  while(iteracoes > 0); 
            } 

           //fecha arquivo.
            fclose(arquivo);


            
            // while(iteracoes > 0) {
            //     iteracoes--;

            //     // começa de fato
            //     funcao(arquivo, regra);
            // }

            
            // imprimindo a resposta:
            arquivo = fopen("saida.txt", "r");
            while ((caractere = fgetc(arquivo)) != EOF){
                printf("%c", caractere);
            }
            fclose(arquivo);
        }

        // loop do codigo
        // printf("\n Quer repetir o processo? [s/n]\n");
        // scanf(" %c", &resposta);
    // } while (resposta == 's' || resposta == 'S');

    return 0;
}