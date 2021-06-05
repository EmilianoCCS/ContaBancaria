#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

struct Cliente
{
    int cpf[11];
    char nome[80];
    
};

struct Conta
{
    int numero_conta;
    struct Cliente cliente;
    float saldo;
};

struct Conta abrirConta( char nome[80]){

	srand(time(NULL));
	struct Conta conta;
    conta.numero_conta = rand();
    conta.saldo = 0.0; 
    strcpy(conta.cliente.nome, nome);	
    printf("numero da conta: %d\n", conta.numero_conta);
    printf("saldo: %.2f\n", conta.saldo);
    printf("nome: %s", conta.cliente.nome);
    printf("\n**********\n");

    return conta;
}

    float deposito(float saldo, float valor){
        if(valor > 0 ){
            saldo = saldo + valor;
            printf("\n**********\n");
            printf("Deposito realizado!.\n");
            printf("Saldo da conta: R$ %.2f", saldo);
            printf("\n**********\n");
            return saldo;
        }else{
            printf("Erro ao realizar depósito");
            return (saldo);
        }
    }
    
    float saque(float saldo, float valor){
        if(valor <= saldo ){
            saldo = saldo - valor;
            printf("\n*****************\n");
            printf("Saque realizado!.\n");
            printf("Saldo da conta: R$ %.2f", saldo);
            printf("\n*****************\n");
            return saldo;
        }else{
            printf("Saldo insuficiente\n");
            return (saldo);
        }
    }

int main ()
{
	char aux[11];
	int auxiliaratoi;
    int cpf [11];
    char nome[80] = {0};
    struct Conta conta;
    float valor_deposito;
    float valor_saque;
    int opcao;

    printf("\n*************************\n");
    printf("   CADASTRO DE CONTA\n");
    printf("\n*************************\n");
    printf("Digite seu nome:\n");
    fgets(nome, 80, stdin);
    printf("\nDigite seu CPF:\n");
	for (int i= 0; i<11; i++)
		{
	        do 
			{ 
	            aux[0] = getch();
	        	if ( aux[0] >= '0' && aux[0] <= '9') 
				{
	            	printf("%c", aux[0]);
	            	auxiliaratoi = atoi (aux);
	        	}
			}
		while (aux[0] < '0' || aux[0] > '9');
		conta.cliente.cpf[i] = auxiliaratoi;
		}
		
	printf("\n\n\n\n\n");
	printf ("CPF: ");
	for (int i= 0; i<11; i++)
	{
		printf("%d", conta.cliente.cpf[i]);
	}
	/*printf("\n\n\n\n");
	printf("%d", conta.cliente.cpf[10]);*/
	printf("\n");
    conta = abrirConta(nome);
    system("pause");
    system("cls");

    do{
        printf("\n*******************\n");
        printf("   MENU PRINCIPAL\n");
        printf("\n*******************\n");
        printf("\nSaldo em conta: %.2f\n\n", conta.saldo);
        printf("1. Deposito:\n");
        printf("2. Saque:\n");
        printf("3. Sair:\n");
        printf("\n Escolha a opcao que deseja realizar: \n");
        scanf("%d",&opcao);
        system("cls");

        switch(opcao){
            case 1:
                printf("Digite o valor do deposito:\n");
                scanf("%f",&valor_deposito);
                conta.saldo = deposito(conta.saldo, valor_deposito);
                system("pause");
                system("cls");
                break;
            case 2:
                printf("Digite o valor do saque:\n");
                scanf("%f",&valor_saque);
                conta.saldo = saque(conta.saldo, valor_saque);
                system("pause");
                system("cls");
                break;
        }
    }while(opcao!= 3);
}
