#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<conio2.h>
#include <windows.h>
#define TF 100
struct TpCliente{
	char CPF[15],Nome[TF],fone[16];
};

struct TpCarro{
	int Cod;
	float Preco;
	char Modelo[TF],Categoria[TF];
};

struct TpLocacao{
	int Codigo,Dias;
	char CPF[15];
	float ValorLocacao;
};

//FUNCOES A SEREM INICIALIZADA
char Menu();
char MenuCadastro();
char MenuListagem();


char MenuExcluir(void){
	clrscr();
	printf("\n ### MENU EXCLUIR ###\n ");
	printf("\n [A] Excluir Vetor Clientes");
	printf("\n [B] Excluir Vetor Carro");
	printf("\n [C] Excluir Vetor Locacao");	
	printf("\n [D] Voltar");
	printf("\nESCOLHA A OPCAO: ");
	return toupper(getch());
	
}

char MenuAlterar(void){
	clrscr();
	printf("\n ### MENU EXCLUIR ###\n ");
	printf("\n [A] Alterar Vetor Clientes");
	printf("\n [B] Alterar Vetor Carro");
	printf("\n [C] Alterar Vetor Locacao");	
	printf("\n [D] Voltar");
	printf("\nESCOLHA A OPCAO: ");
	return toupper(getch());
	
}



char MenuExibir(void)
{
	clrscr();
	printf("\n ### MENU EXIBIR ###\n ");
	printf("\n [A] Exibir Vetor Clientes");
	printf("\n [B] Exibir Vetor Carro");
	printf("\n [C] Exibir Vetor Locacao");	
	printf("\n [D] Voltar");
	printf("\nESCOLHA A OPCAO: ");
	return toupper(getch());
}


char MenuListagem(void){
	clrscr();
	printf("\n ### MENU lISTAGEM ### \n");
	printf("\n[A] 3 loca??es");
	printf("\n[B] Categoria Escolhida");
	printf("\n[C] Valor Acima");
	printf("\n[D] Voltar");
	printf("\nESCOLHA A OPCAO: ");
	return toupper(getche());
}


char MenuCadastro(void){
	clrscr();
	printf("\n# # # MENU CADASTRO # # #\n");
	printf("\n[A] CLIENTE");
	printf("\n[B] CARROS");
	printf("\n[C] LOCACAO");
	printf("\n[D] CADASTRO AUTOMATICO");
	printf("\n[E] voltar");
	printf("\nESCOLHA A OPCAO: ");
	return toupper(getche());
}

char Menu(void){
		clrscr();
		printf("\n# # # LOCA?AO DE CARROS # # #\n");
		printf("\n[A] CADASTRO");
		printf("\n[B] EXCLUSAO");
		printf("\n[C] ALTERA?AO");
		printf("\n[D] EXIBIR TABELAS");
		printf("\n[E] LISTAGEM/RELATORIOS");
		printf("\n[F] RELAT?RIO COMPLETO");
		printf("\nESCOLHA A OP?AO: ");
		return toupper(getche());
}

int BuscaCliente(TpCliente Cliente[TF], int TL,char CPFAux[15]){
	int i=0;
	while(i<TL && strcmp(CPFAux,Cliente[i].CPF)!=0)
		i++;
	
	if(i<TL)
		return i;
	else
		return -1;
}

int buscaCarro(TpCarro Car[TF], int TL, int Aux)
{
	int i=0;
	while(i<TL && Aux!=Car[i].Cod)
		i++;
	
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaLocacaoInt(TpLocacao Loc[TF],int TL,int Aux)
{
	int i=0;
	while(i<TL && Aux!=Loc[i].Codigo)
		i++;
	
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaLocacao(TpLocacao Loc[TF], int TL,char CPFAux[15])
{
	int i=0;
	while(i<TL && strcmp(CPFAux,Loc[i].CPF)!=0)
		i++;
	
	if(i<TL)
		return i;
	else
		return -1;
}

int BuscaCarroSentinela(TpCarro Carro[TF], int TC, int AuxCar){
	int i=0;
	Carro[TC].Cod = AuxCar;
	while(AuxCar!=Carro[i].Cod)
		i++;
	
	if(i<TC)
		return i;
	else
		return -1;
}

int BuscaIndexada(){
	
}

int BuscaBinaria()
{
	
	
}
int ExibeClientes(TpCliente Cliente[TF], int TL)
{
	int i;
	if(TL == 0)
		printf("Vetor Vazio!!!\n");
	else
		for(i=0;i<TL;i++)
			printf(" %s  %s %s \n",Cliente[i].CPF,Cliente[i].Nome,Cliente[i].fone);
	getch();
}

int ExibeCarro(TpCarro Carro[TF], int TL)
{
	int i;
	if(TL == 0)
		printf("Vetor Vazio!!!\n");
	else
		for(i=0;i<TL;i++)
			printf("\n %d  %s %s %.2f ",Carro[i].Cod,Carro[i].Modelo,Carro[i].Categoria,Carro[i].Preco);
	getch();
}
int ValidaCPF(TpCliente[TF], int TL){
	
}
 
void CadastroCliente(TpCliente Cliente[TF], int &TL){
	char AuxCPF[15];
	int pos;
	clrscr();
	printf("\n# # # CADASTRO CLIENTE # # #\n");
	printf("CPF(EX: XXX.XXX.XXX-XX): "); fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0){
		pos = BuscaCliente(Cliente,TL,AuxCPF);
		if(pos==-1){
			strcpy(Cliente[TL].CPF,AuxCPF);
			printf("NOME: "); fflush(stdin);
			gets(Cliente[TL].Nome);
			printf("TELEFONE(EX:(XX) XXXXX-XXXX): "); fflush(stdin);
			gets(Cliente[TL].fone);
			TL++;
		}else{
			printf("\nCPF J? CADASTRADO!\n");
			getch();
		}
		clrscr();
		printf("CPF(EX: XXX.XXX.XXX-XX): "); fflush(stdin);
		gets(AuxCPF);
	}
	
}

void CadastroCarro(TpCarro Carro[TF], int &TC){
	int AuxC;
	int pos;
	clrscr();
	printf("\n# # # CADASTRO DE CARROS # # #\n");
	printf("CODIGO: "); 
	scanf("%d",&AuxC);
	while(TC<TF && AuxC>0){
		pos = BuscaCarroSentinela(Carro,TC,AuxC);
		if(pos==-1){
			Carro[TC].Cod=AuxC;
			printf("MODELO: "); fflush(stdin);
			gets(Carro[TC].Modelo);
			printf("CATEGORIA: "); fflush(stdin);
			gets(Carro[TC].Categoria);
			printf("VALOR DA DIARIA: ");
			scanf("%f",&Carro[TC].Preco);
			TC++;
		}else{
			printf("\nCODIGO J? CADASTRADO!");
			getch();
		}
		clrscr();
		printf("CODIGO: "); 
		scanf("%d",&AuxC);
	}
	
}

void CadastroLocacao(TpLocacao Loc[TF], int &TL, TpCliente Cliente[TF], int TC, TpCarro Carro[TF], int TP){
    clrscr();
    int AuxCod, pos;
    char AuxCPF[15];
    
    printf("\n# # # CADASTRO DE LOCA?OES # # #\n");
    printf("DIGITE UM CPF PARA INICIAR: "); fflush(stdin);
    gets(AuxCPF);

    while(strcmp(AuxCPF,"\0")!=0){
        pos = BuscaCliente(Cliente, TC, AuxCPF);
        if(pos != -1){  
            strcpy(Loc[TL].CPF, AuxCPF);
            printf("\nCPF ENCONTRADO\n");

            printf("\nDIGITE O CODIGO DO CARRO: ");
            scanf("%d", &AuxCod);

            pos = BuscaCarroSentinela(Carro, TP, AuxCod);
            if(AuxCod > 0 && pos != -1){   // Carro encontrado
                Loc[TL].Codigo = AuxCod;
                printf("\nCODIGO ENCONTRADO!\n");

                printf("\nQUANTOS DIAS DE LOCA?AO: ");
                scanf("%d", &Loc[TL].Dias);

                Loc[TL].ValorLocacao = Loc[TL].Dias * Carro[pos].Preco;
                printf("%.2f",Loc[TL].ValorLocacao);
                getch();
                TL++;
            } else {
                printf("\nCODIGO NAO ENCONTRADO!\n");
                getch();
            }
        } else {
            printf("\nCPF NAO ENCONTRADO!\n");
            getch();
        }
        printf("DIGITE UM CPF PARA INICIAR: "); fflush(stdin);
        gets(AuxCPF);
    }
}

int ExibeLocacao(TpLocacao Loc[TF], int TL)
{
	int i;
	if(TL == 0)
		printf("Vetor Vazio!!!\n");
	else
		for(i=0;i<TL;i++)
			printf("%s   %d   %d   %.2f \n",Loc[i].CPF,Loc[i].Codigo,Loc[i].Dias,Loc[i].ValorLocacao);
	getch();
}

void CadastroAuto(TpCliente Cli[TF], TpCarro Car[TF],TpLocacao Loc[TF],int &TC, int &TP, int &TL)
{
	strcpy(Cli[TC].CPF,"459.012.948-58");
	strcpy(Cli[TC].Nome,"Andre Augusto De Souza Lopes");
	strcpy(Cli[TC].fone, "(18) 99741-3195");
	TC++;
	strcpy(Cli[TC].CPF,"478.308.728-80");
	strcpy(Cli[TC].Nome,"Ana Julia Perdomo Alves");
	strcpy(Cli[TC].fone, "(18) 99758-1127");
	TC++;
	strcpy(Cli[TC].CPF,"102.123.614-49");
	strcpy(Cli[TC].Nome,"Clarice Yasmin Evelyn da Mota");
	strcpy(Cli[TC].fone, "(11) 98745-3021");
	TC++;
	strcpy(Cli[TC].CPF,"423.572.400-24");
	strcpy(Cli[TC].Nome,"Jose Carlor da silva");
	strcpy(Cli[TC].fone, "(21) 99612-7843");
	TC++;	
	strcpy(Cli[TC].CPF,"030.650.446-41");
	strcpy(Cli[TC].Nome,"Thomas Vicente Nicolas da Conceição");
	strcpy(Cli[TC].fone, "(31) 98420-6597");
	TC++;
	strcpy(Cli[TC].CPF,"428.971.955-41");
	strcpy(Cli[TC].Nome,"Mariane Isabela Campos");
	strcpy(Cli[TC].fone, "(41) 99583-1420");
	TC++;	
	strcpy(Cli[TC].CPF,"302.310.402-61");
	strcpy(Cli[TC].Nome,"Calebe Jorge Bryan da Rosa");
	strcpy(Cli[TC].fone, "(51) 99107-4386");
	TC++;
	strcpy(Cli[TC].CPF,"745.110.933-00");
	strcpy(Cli[TC].Nome,"Sabrina Esther Elza Viana");
	strcpy(Cli[TC].fone, "(61) 98892-7504");
	TC++;	
	
	
	Car[TP].Cod = 115;
	strcpy(Car[TP].Modelo,"SW4");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 800.00;
	TP++;	
	
	Car[TP].Cod = 105;
	strcpy(Car[TP].Modelo,"Cruze");
	strcpy(Car[TP].Categoria,"Hatch");
	Car[TP].Preco = 300.00;
	TP++;
	
		Car[TP].Cod = 130;
	strcpy(Car[TP].Modelo,"Captur");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 350.00;
	TP++;		
	
	Car[TP].Cod = 125;
	strcpy(Car[TP].Modelo,"City");
	strcpy(Car[TP].Categoria,"Sedan");
	Car[TP].Preco = 320.00;
	TP++;	
	
	Car[TP].Cod = 120;
	strcpy(Car[TP].Modelo,"Civic");
	strcpy(Car[TP].Categoria,"Hatch");
	Car[TP].Preco = 380.00;
	TP++;	
	Car[TP].Cod = 100;
	strcpy(Car[TP].Modelo,"HRV");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 500.00;
	TP++;	
	
	Car[TP].Cod = 110;
	strcpy(Car[TP].Modelo,"Versa");
	strcpy(Car[TP].Categoria,"Sedan");
	Car[TP].Preco = 350.00;
	TP++;
	
	strcpy(Loc[TL].CPF,"459.012.948-58"); // 3
	Loc[TL].Codigo = 100;
	Loc[TL].Dias = 10;
	Loc[TL].ValorLocacao =5000.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"459.012.948-58"); // 3
	Loc[TL].Codigo = 105;
	Loc[TL].Dias = 2;
	Loc[TL].ValorLocacao = 600.00;
	TL++;
	
	
	strcpy(Loc[TL].CPF,"459.012.948-58"); //3
	Loc[TL].Codigo = 120;
	Loc[TL].Dias = 1;
	Loc[TL].ValorLocacao = 380.00;
	TL++;
	
	
	strcpy(Loc[TL].CPF,"478.308.728-80"); // 2
	Loc[TL].Codigo = 105;
	Loc[TL].Dias = 3;
	Loc[TL].ValorLocacao = 900.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"478.308.728-80");// 2
	Loc[TL].Codigo = 115;
	Loc[TL].Dias = 7;
	Loc[TL].ValorLocacao = 5600.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"102.123.614-49"); // safe
	Loc[TL].Codigo = 120;
	Loc[TL].Dias = 1;
	Loc[TL].ValorLocacao = 380.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"423.572.400-24"); //safe
	Loc[TL].Codigo = 125;
	Loc[TL].Dias = 3;
	Loc[TL].ValorLocacao = 960.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"428.971.955-41"); //safe
	Loc[TL].Codigo = 100;
	Loc[TL].Dias = 5;
	Loc[TL].ValorLocacao = 2500.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"302.310.402-61"); //safe
	Loc[TL].Codigo = 130;
	Loc[TL].Dias = 2;
	Loc[TL].ValorLocacao = 700.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"745.110.933-00");
	Loc[TL].Codigo = 100;
	Loc[TL].Dias = 9;
	Loc[TL].ValorLocacao = 4500.00;
	TL++;
	
	strcpy(Loc[TL].CPF,"478.308.728-80");
	Loc[TL].Codigo = 125;
	Loc[TL].Dias = 7;
	Loc[TL].ValorLocacao = 2240.00;
	TL++;

	printf("\n DADOS CADASTRADOS");
	Sleep(2500);
	
}


int AlterarCliente(TpCliente Cli[TF],TpLocacao Loc[TF],int TC, int TL)
{
	char AuxCPF[15];
	int pos, aux;
	printf("Digite o CPF para Alterar os Dados\n");
	fflush(stdin);
	gets(AuxCPF);
	while(TC<TF && strcmp(AuxCPF,"\0")!=0)
	{
		pos = BuscaCliente(Cli,TC,AuxCPF);
		if(pos == -1)
			printf("Usuario Nao Cadastrado!\n");
		else
		{
			printf("Dados encontrados!\n");
			printf("%s  %s  %s",Cli[pos].CPF,Cli[pos].Nome,Cli[pos].fone);
			printf("Coloque os novos Dados!!!\n");
			printf("CPF: ");
			gets(Cli[pos].CPF);
			printf("Nome: ");
			gets(Cli[pos].Nome);
			printf("Telefone: ");
			gets(Cli[pos].fone);
			aux = BuscaLocacao(Loc,TL,AuxCPF);
			{
				if(aux == -1)
					printf("Dados Alterados!!!\n");
				else
				{
					strcpy(Loc[aux].CPF,Cli[pos].CPF);
					printf("Dados Alterados\n");
				}	
			}
			
		}
		printf("Digite o CPF para Alterar os Dados\n");
		fflush(stdin);
		gets(AuxCPF);
	}
	
	
}


int AlterarCarro(TpCarro Car[TF],TpLocacao Loc[TF], int TP, int TL)
{
	int AuxCod, pos, aux;
	printf("Digite o Codigo para alterar Dados\n");
	scanf("%d",&AuxCod);
	while(TP<TF && AuxCod!=0)
	{
		pos = buscaCarro(Car,TP,AuxCod);
		if(pos == -1)
			printf("Dados Nao Encontrado!!!\n");
		else
		{
			printf("Dados Encontrados!!!\n");
			printf("%d   %s   %s   %.2f\n",Car[pos].Cod,Car[pos].Modelo,Car[pos].Categoria,Car[pos].Preco);	
			printf("Insira os novos Dados!!!\n");
			printf("CodCarro: ");
			scanf("%d",&Car[pos].Cod);
			fflush(stdin);
			printf("Modelo: ");
			gets(Car[pos].Modelo);
			printf("Categoria: ");
			gets(Car[pos].Categoria);
			printf("Preço: ");
			scanf("%f",&Car[pos].Preco);
			aux = BuscaLocacaoInt(Loc,TL,AuxCod);
			if(aux == -1)
				printf("Dados Alterados!!!\n");
			else
			{
				Loc[pos].Codigo = Car[aux].Cod;
				printf("Dados Cadastrados!!!\n"); 
			}
			
		}
		printf("Digite o Codigo para alterar Dados\n");
		scanf("%d",&AuxCod);
	}
}

void Executar(){
	TpCliente Cliente[TF];
	TpCarro Carro[TF];
	TpLocacao Locacao[TF];
	int TC=0,TP=0,TL=0;
	char opcao,AuxCPF[15];
	do{
		opcao = Menu();
			switch(opcao){
			//CADASTRO
			case 'A':
				do{
					opcao = MenuCadastro();
					switch(opcao){
						case 'A':
							CadastroCliente(Cliente,TC);
							break;
						case 'B':
							CadastroCarro(Carro,TP);
							break;
						case 'C':
							CadastroLocacao(Locacao, TL, Cliente, TC, Carro, TP);
							break;
						case 'D':CadastroAuto(Cliente,Carro,Locacao,TC,TP,TL);
							clrscr();
							break;	
					}
				}while(opcao!='E');
				break;
			//EXCLUSAO
			case 'B':
					do{
						opcao = MenuExcluir();
						switch(opcao){
							case 'A':
								break;
							case 'B':
								break;
							case 'C':
								break;
							case 'D':
								break;	
						}
					}while(opcao!='E');
					break;
			//ALTERA?AO
			case 'C':
					do{
						opcao = MenuAlterar();
						switch(opcao){
							case 'A':
								AlterarCliente(Cliente,Locacao,TC,TL);
								break;
							case 'B':
								AlterarCarro(Carro,Locacao,TP,TL);
								break;
							case 'C':
								break;
							case 'D':
								break;	
						}
					}while(opcao!='D');
					break;
			case 'D':
					do{
						opcao = MenuExibir();
						switch(opcao){
							case 'A':
								clrscr();
								ExibeClientes(Cliente,TC);
								break;
							case 'B':
								clrscr();
								ExibeCarro(Carro,TP);
								break;
							case 'C':
								clrscr();
								ExibeLocacao(Locacao,TL);
								break;
						}
					}while(opcao!='D');
					break;
			//LISTAGEM 
			case 'E':
				do{
					opcao = MenuListagem();
					switch(opcao){
						case 'A':
							printf("\nLeo gay\n");
							getch();
							break;
					}
				}while(opcao!= 'D');
				break;		
			//RELATORIO COMPLETO
			case 'F':
				break;
		}
	}while(opcao!=27);
}




int main(void){
	
	Executar();
	
	return 0;
}
