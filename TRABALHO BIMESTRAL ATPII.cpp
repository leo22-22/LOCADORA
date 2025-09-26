
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

void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		
		
		gotoxy(i,LF);
		printf("%c",205);
	}
	
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		
		
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void ExibeTelao()
{
	clrscr();
	textcolor(2);
	gotoxy(30,3);
	printf("TRABALHO DE ATP II");
	Moldura(1,1,80,25,2,7);
	Moldura(2,2,79,4,5,6);
	Moldura(2,5,79,21,10,7);
	Moldura(2,22,79,24,11,4);

}
void ExibeTelaoResp()
{
	clrscr();
	textcolor(2);
	gotoxy(30,3);
	printf("TRABALHO DE ATP II");
	Moldura(1,1,80,25,2,7);
	Moldura(2,2,79,4,5,6);
	Moldura(2,5,79,24,10,7);
	
	
}
void ExibeTelaoResp2()
{
	clrscr();
	textcolor(2);
	gotoxy(30,3);
	printf("TRABALHO DE ATP II");
	Moldura(1,1,85,25,2,7);
	Moldura(2,2,84,4,5,6);
	Moldura(2,5,84,24,10,7);
	
	
}
void ExibeTelaoRela()
{
	clrscr();
	textcolor(2);
	gotoxy(42,3);
	printf("TRABALHO DE ATP II");
	Moldura(1,1,120,60,2,7);
	Moldura(2,2,119,4,5,6);
	Moldura(2,5,119,59,10,7);
	
	
}




char MenuExcluir(void){
	ExibeTelao();
	gotoxy(28,6);
	textcolor(2);
	printf("### MENU EXCLUIR ### ");
	gotoxy(25,10);
	printf("[A] Excluir Vetor Clientes");
	gotoxy(25,11);
	printf("[B] Excluir Vetor Carro");
	gotoxy(25,12);
	printf("[C] Excluir Vetor Locacao");	
	gotoxy(25,13);
	printf("[D] Voltar");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getch());
	
}

char MenuAlterar(void){
	ExibeTelao();
	textcolor(2);
	gotoxy(28,7);
	printf("### MENU EXCLUIR ### ");
	gotoxy(25,10);
	printf("[A] Alterar Vetor Clientes");
	gotoxy(25,11);
	printf("[B] Alterar Vetor Carro");
	gotoxy(25,12);
	printf("[C] Alterar Vetor Locacao");	
	gotoxy(25,13);
	printf("[D] Voltar");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getch());
	
}



char MenuExibir(void)
{
	ExibeTelao();
	textcolor(2);
	gotoxy(28,7);
	printf("### MENU EXIBIR ###");
	gotoxy(25,10);
	printf("[A] Exibir Vetor Clientes");
	gotoxy(25,11);
	printf("[B] Exibir Vetor Carro");
	gotoxy(25,12);
	printf("[C] Exibir Vetor Locacao");	
	gotoxy(25,13);
	printf("[D] Voltar");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getch());
}


char MenuListagem(void){
	ExibeTelao();
	textcolor(2);
	gotoxy(28,7);
	printf("### MENU lISTAGEM ###");
	gotoxy(25,10);
	printf("[A] 3 locacoes");
	gotoxy(25,11);
	printf("[B] Categoria Escolhida");
	gotoxy(25,12);
	printf("[C] Valor Acima");
	gotoxy(25,13);
	printf("[D] Voltar");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getche());
}


char MenuCadastro(void){
	ExibeTelao();
	textcolor(2);
	gotoxy(28,7);
	printf("### MENU CADASTRO ###");
	gotoxy(25,10);
	printf("[A] CLIENTE");
	gotoxy(25,11);
	printf("[B] CARROS");
	gotoxy(25,12);
	printf("[C] LOCACAO");
	gotoxy(25,13);
	printf("[D] CADASTRO AUTOMATICO");
	gotoxy(25,14);
	printf("[E] voltar");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getche());
}

char MenuCarro(void){
	ExibeTelao();
	textcolor(2);
	gotoxy(28,7);
	printf("### MENU CARRO ###");
	gotoxy(25,10);
	printf("[A] CADASTRAR CARRO POR CODIGO");
	gotoxy(25,11);
	printf("[B] CADASTRAR CARRO POR MODELO");
	gotoxy(25,12);
	printf("[C] VOLTAR");
	gotoxy(4,23);
	printf("ESCOLHA A OPCAO: ");
	return toupper(getche());
}

char Menu(void){
		clrscr();
		ExibeTelao();
		gotoxy(28,7);
		textcolor(2);
		printf("### LOCACAO DE CARROS ###");
		gotoxy(25,10);
		printf("[A] CADASTRO");
		gotoxy(25,11);
		printf("[B] EXCLUSAO");
		gotoxy(25,12);
		printf("[C] ALTERACAO");
		gotoxy(25,13);
		printf("[D] EXIBIR TABELAS");
		gotoxy(25,14);
		printf("[E] LISTAGEM/RELATORIOS");
		gotoxy(25,15);
		printf("[F] RELATORIO COMPLETO");
		gotoxy(4,23);
		printf("ESCOLHA A OPCAO: ");
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

int buscaCarroCategoria(TpCarro Car[TF], int TL, char Aux[15])
{
	int i=0;
	while(i<TL && strcmp(Aux,Car[i].Categoria)!=0)
		i++;
	
	if(i<TL)
		return i;
	else
		return -1;
}

int buscaCarroModelo(TpCarro Car[TF], int TL, char Aux[15])
{
	int i=0;
	while(i<TL && strcmp(Aux,Car[i].Modelo)!=0)
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

int BuscaLocacaoLimite(TpLocacao Loc[TF], int TL,float Aux)
{
	int i=0;
	while(i<TL && Loc[i].ValorLocacao<=Aux)
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

int BuscaIndexadaCPF(TpCliente Cli[TF], int TC, char Elem[15]){
	int i=0;
	while(i<TC && strcmp(Elem,Cli[i].CPF)!=0)
		i++;
		
	if(i<TC && strcmp(Elem,Cli[i].CPF)==0)
		return i;
	else
		return -1;
}

int BuscaBinariaCarroCodigo(TpCarro Car[TF], int TL, int Aux)
{
	int I=0,M,F=TL-1;
	M=F/2;
	while(I<F && Car[M].Cod!=Aux){
		if(Car[M].Cod>Aux)
			F=M+1;
		else
			I=M-1;
		M = (F+I)/2;
	}
	if(Car[M].Cod==Aux)
		return M;
	else
		return -1;
}

int BuscaBinariaLocacaoCPF(TpLocacao Loc[TF], int TL, char Aux[TF])
{
	int I=0,M,F=TL-1;
	M=F/2;
	while(I<F && strcmp(Loc[TL].CPF,Aux)!=0){
		if(strcmp(Loc[M].CPF,Aux)>0)
			F=M+1;
		else
			I=M-1;
		M = (F+I)/2;
	}
	if(strcmp(Loc[M].CPF,Aux)==0)
		return M;
	else
		return -1;
}

void InsertionSortCli(TpCliente Cli[TF], int TL){
	TpCliente Aux;
	int i=TL-1;
	while(i>0 && strcmp(Cli[i].CPF,Cli[i-1].CPF)<0){
		Aux=Cli[i];
		Cli[i]=Cli[i-1];
		Cli[i-1]=Aux;
		i--;
	}	
}

int PosicaoMaior(TpCarro Car[TF], int TL){
	int PosMaior,Maior,i;
	Maior=Car[0].Cod;
	PosMaior=0;
	for(i=1;i<TL;i++)
		if(Maior<Car[i].Cod){
			Maior=Car[i].Cod;
			PosMaior=i;
		}
		return PosMaior;
}

void SelectionSortCod(TpCarro Car[TF], int TL){
	int PosM;
	TpCarro Aux; 
	while(TL > 0){
		PosM = PosicaoMaior(Car, TL);
		if(PosM < TL-1){
			Aux = Car[PosM];
			Car[PosM] = Car[TL-1];
			Car[TL-1] = Aux;
		}
		TL--;
	}
}
void BubbleSortModelo(TpCarro Car[TF], int TL){
	TpCarro Aux;
	int i;
	while(TL>1){
		for(i=0;i<TL-1;i++){
			if(strcmp(Car[i].Modelo,Car[i+1].Modelo)>0){
				Aux=Car[i];
				Car[i]=Car[i+1];
				Car[i+1]=Aux;
			}
		}
		TL--;
	}	
}

int ExibeClientes(TpCliente Cliente[TF], int TL)
{
	int i, x=9;
	ExibeTelaoResp2();
	gotoxy(27,6);
	printf("### Exibe Clientes ###");
	if(TL == 0)
		printf("Vetor Vazio!!!\n");
	else
		for(i=0;i<TL;i++)
			{
				gotoxy(13,8);
				printf(" CPF   ||                Nome                  ||     FONE");
				gotoxy(5,x);
				printf(" %s ", Cliente[i].CPF);
				gotoxy(20,x);
				printf("||");
				gotoxy(22,x);
				printf(" %s ", Cliente[i].Nome);
				gotoxy(60,x);
				printf("||");
				gotoxy(64,x);
				printf(" %s ", Cliente[i].fone);
				
				x++;
			}
	getch();
}

void ExibeCarro(TpCarro Carro[TF], int TL)
{
	int i, x=9;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### Exibe CARRO ###");
	if(TL == 0){
		gotoxy(4,8);
		printf("Vetor Vazio!!!");
	}
	else
		for(i=0;i<TL;i++)
		{
			gotoxy(13,8);
			printf("Carro ||    Modelo     ||     Categoria     ||      Preco");
			gotoxy(13,x);
			printf(" %d  || ",Carro[i].Cod);
			gotoxy(24,x);
			printf(" %s  ",Carro[i].Modelo); 
			gotoxy(36,x);
			printf("||");
			gotoxy(44,x);
			printf(" %s  ",Carro[i].Categoria); 
			gotoxy(57,x);
			printf("||");
			gotoxy(64,x);
			printf(" %.2f  ",Carro[i].Preco); 
			x++;
			
		}
		getch();		
}

int ValidaCPF(char AuxCPF[15]){
	int i, pos =10, soma = 0,resto, divisao, divisao2, iguais = 1;
	
	if (AuxCPF[3] != '.' || AuxCPF[7] != '.' || AuxCPF[11] != '-') 
		return -1;
	for (i = 0; i < 14; i++)
	{
	    if (i != 3 && i != 7 && i != 11 && AuxCPF[i] != AuxCPF[0])
	        iguais = 0;
	}
	if (iguais == 1) 
		return -1;
	for(i=0;i<11;i++)
	{
		if(i!=3 && i!= 7 && i!= 11 )
		{
			soma += (AuxCPF[i] - '0') * pos;
			pos--;
		}
	}
	resto = (soma%11);
	if (resto < 2)
    	divisao = 0;
	else
    	divisao = 11 - resto;
	soma = 0;	
	pos = 11;	
	for(i=0;i<13;i++)
	{
		if(i!=3 && i!= 7 &&i!= 11 )
		{
			soma += (AuxCPF[i] - '0') * pos;
			pos--;
		}
	}
	resto = (soma%11);
	if (resto < 2)
    	divisao2 = 0;
	else
    	divisao2 = 11 - resto;
	if(divisao == (AuxCPF[12] - '0') && divisao2 == (AuxCPF[13] - '0'))
	{
		return 1;
	}
	else
		return -1;
}
 
void CadastroCliente(TpCliente Cliente[TF], int &TL){
	char AuxCPF[15];
	int pos, Valido,y=10;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### CADASTRO CLIENTE ###");
	gotoxy(4,8);
	printf("CPF(EX: XXX.XXX.XXX-XX): ");
	fflush(stdin);
	gets(AuxCPF);
	while(TL<TF && strcmp(AuxCPF,"\0")!=0)	
	{	
		Valido = ValidaCPF(AuxCPF);
		if(Valido == 1)
		{
			pos = BuscaIndexadaCPF(Cliente,TL,AuxCPF);
			if(pos==-1)
			{
				strcpy(Cliente[TL].CPF,AuxCPF);
				gotoxy(4,9);
				printf("NOME: "); 
				fflush(stdin);
				gets(Cliente[TL].Nome);
				while (strlen(Cliente[TL].Nome) == 0) 
				{
					gotoxy(4,y);
					y++;
					printf("Nome Vazio");
					gotoxy(4,y);
    				printf("Digite Novamente: ");
    				y++;
    				gets(Cliente[TL].Nome);
				}
				gotoxy(4,y);
				printf("TELEFONE: ");
				y++;
				fflush(stdin);
				gets(Cliente[TL].fone);
				while (strlen(Cliente[TL].fone) == 0)
				{
					gotoxy(4,y);
					printf("Telefone Vazio!");
					y++;
					gotoxy(4,y);
					printf("DIGITE NOVAMENTE: ");
					gets(Cliente[TL].fone);
				}
				TL++;
				InsertionSortCli(Cliente, TL);
				ExibeTelaoResp();
				gotoxy(27,6);
				printf("### CADASTRO CLIENTE ###");
				gotoxy(27,11);
				printf("Usuario Cadastrado");
				Sleep(2000);
			}
			else
			{
				ExibeTelaoResp();
				gotoxy(27,6);
				printf("### CADASTRO CLIENTE ###");
				gotoxy(27,11);
				printf("CPF VALIDO POREM JA CADASTRADO!");
				Sleep(3000);
			}
		}
		else
		{
			ExibeTelaoResp();
			gotoxy(27,6);
			printf("### CADASTRO CLIENTE ###");
			gotoxy(27,11);
			printf("CPF Invalidado!!!");
			Sleep(3500);
		}
		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### CADASTRO CLIENTE ###");
		gotoxy(4,8);
		printf("CPF(EX: XXX.XXX.XXX-XX): "); fflush(stdin);
		gets(AuxCPF);		
	}	
}


void CadastroCarroCodigo(TpCarro Carro[TF], int &TC){
    int AuxC;
    int pos, y;

    ExibeTelaoResp();
    gotoxy(27,6);
    printf("### CADASTRO DE CARROS CODIGO ###");
    gotoxy(4,8);
    printf("CODIGO: "); 
    scanf("%d",&AuxC);

    while(TC < TF && AuxC > 0){
        y = 10;
        pos = BuscaCarroSentinela(Carro, TC, AuxC);

        if(pos == -1){ 
            Carro[TC].Cod = AuxC;

            gotoxy(4,9);
            printf("MODELO: "); 
            fflush(stdin);
            gets(Carro[TC].Modelo);
            while(strlen(Carro[TC].Modelo) == 0){
                gotoxy(4,y);
                y++;
                printf("Modelo Vazio");
                gotoxy(4,y);
                printf("Digite Novamente: ");
                y++;
                gets(Carro[TC].Modelo);
            }

            gotoxy(4,y);
            printf("CATEGORIA: ");
            y++;
            fflush(stdin);
            gets(Carro[TC].Categoria);
            while(strlen(Carro[TC].Categoria) == 0){
                gotoxy(4,y);
                y++;
                printf("Categoria Vazia");
                gotoxy(4,y);
                printf("Digite Novamente: ");
                y++;
                gets(Carro[TC].Categoria);
            }

            gotoxy(4,y);
            printf("VALOR DA DIARIA: ");
            scanf("%f",&Carro[TC].Preco);

            SelectionSortCod(Carro, TC+1); 

            TC++; 

            ExibeTelaoResp();
            gotoxy(27,6);
            printf("### CADASTRO CARRO ###");
            gotoxy(27,11);
            printf("CARRO CADASTRADO!!!");
            Sleep(3000);

        } else { 
            ExibeTelaoResp();
            gotoxy(27,6);
            printf("### CADASTRO CARRO ###");
            gotoxy(27,11);
            printf("CODIGO JA CADASTRADO!");
            Sleep(3000);
        }

        ExibeTelaoResp();
        gotoxy(27,6);
        printf("### CADASTRO DE CARROS ###");
        gotoxy(4,8);
        printf("CODIGO: "); 
        scanf("%d",&AuxC);
    }
}


void CadastroCarroModelo(TpCarro Carro[TF], int &TC){
	int AuxC;
	int pos, y;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### CADASTRO DE CARROS Modelo ###");
	gotoxy(4,8);
	printf("CODIGO: "); 
	scanf("%d",&AuxC);
	while(TC<TF && AuxC>0){
		y=10;
		pos = BuscaCarroSentinela(Carro,TC,AuxC);
		if(pos==-1){
			Carro[TC].Cod=AuxC;
			gotoxy(4,9);
			printf("MODELO: "); 
			fflush(stdin);
			gets(Carro[TC].Modelo);
			while (strlen(Carro[TC].Modelo) == 0) 
				{
					gotoxy(4,y);
					y++;
					printf("Modelo Vazio");
					gotoxy(4,y);
    				printf("Digite Novamente: ");
    				y++;
    				gets(Carro[TC].Modelo);
				}
			gotoxy(4,y);
			printf("CATEGORIA: ");
			y++;
			fflush(stdin);
			gets(Carro[TC].Categoria);
			while (strlen(Carro[TC].Categoria) == 0) 
				{
					gotoxy(4,y);
					y++;
					printf("Categoria Vazia");
					gotoxy(4,y);
    				printf("Digite Novamente: ");
    				y++;
    				gets(Carro[TC].Categoria);
				}
			gotoxy(4,y);
			printf("VALOR DA DIARIA: ");
			y++;
			scanf("%f",&Carro[TC].Preco);
			BubbleSortModelo(Carro,TC+1); 
			TC++;
			ExibeTelaoResp();
			gotoxy(27,6);
			printf("### CADASTRO CARRO ###");
			gotoxy(27,11);
			printf("CARRO CADASTRADO!!!");
			Sleep(3000);
		}else{
			ExibeTelaoResp();
			gotoxy(27,6);
			printf("### CADASTRO CARRO ###");
			gotoxy(27,11);
			printf("CODIGO JA CADASTRADO!");
			Sleep(3000);
			
		}
		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### CADASTRO DE CARROS ###");
		gotoxy(4,8);
		printf("CODIGO: "); 
		scanf("%d",&AuxC);
	}
	
}


void CadastroLocacao(TpLocacao Loc[TF], int &TL, TpCliente Cliente[TF], int TC, TpCarro Carro[TF], int TP){
    int i,AuxCod, posCliente, posCarro;
    char AuxCPF[15];

    ExibeTelaoResp();
    gotoxy(27,6);
    printf("### CADASTRO DE LOCACOES ###");
    gotoxy(4,8);
    printf("DIGITE UM CPF PARA INICIAR: ");
    fflush(stdin);
    gets(AuxCPF);

    while(strcmp(AuxCPF,"\0") != 0){
        posCliente = BuscaCliente(Cliente, TC, AuxCPF);
        if(posCliente != -1){
            gotoxy(4,9);
            printf("CPF ENCONTRADO");

            gotoxy(4,10);
            printf("DIGITE O CODIGO DO CARRO: ");
            scanf("%d", &AuxCod);

            posCarro = BuscaCarroSentinela(Carro, TP, AuxCod);

            if(AuxCod > 0 && posCarro != -1){

                i = 0;
                while(i < TL && !(strcmp(Loc[i].CPF, AuxCPF) == 0 && Loc[i].Codigo == AuxCod)){
                    i++;
                }

                if(i == TL){
                    strcpy(Loc[TL].CPF, AuxCPF);
                    Loc[TL].Codigo = AuxCod;
                    gotoxy(4,11);
                    printf("CODIGO ENCONTRADO!");
                    gotoxy(4,12);
                    printf("QUANTOS DIAS DE LOCACAO: ");
                    scanf("%d", &Loc[TL].Dias);
                    Loc[TL].ValorLocacao = Loc[TL].Dias * Carro[posCarro].Preco;
                    printf("%.2f", Loc[TL].ValorLocacao);
                    TL++;

                    ExibeTelaoResp();
                    gotoxy(27,6);
                    printf("### CADASTRO DE LOCACOES ###");
                    gotoxy(27,11);
                    printf("LOCACAO CADASTRADA");
                    Sleep(3000);
                } else {
                    ExibeTelaoResp();
                    gotoxy(27,6);
                    printf("### CADASTRO DE LOCACOES ###");
                    gotoxy(27,11);
                    printf("LOCACAO JÁ EXISTE PARA ESTE CPF E CARRO!");
                    Sleep(2000);
                }

            } else {
                ExibeTelaoResp();
                gotoxy(27,6);
                printf("### CADASTRO DE LOCACOES ###");
                gotoxy(27,11);
                printf("CODIGO NAO ENCONTRADO!");
                Sleep(2000);
            }

        } else {
            ExibeTelaoResp();
            gotoxy(27,6);
            printf("### CADASTRO DE LOCACOES ###");
            gotoxy(27,11);
            printf("CPF NAO ENCONTRADO!");
            Sleep(2000);
        }

        ExibeTelaoResp();
        gotoxy(27,6);
        printf("### CADASTRO DE LOCACOES ###");
        gotoxy(4,8);
        printf("DIGITE UM CPF PARA INICIAR: ");
        fflush(stdin);
        gets(AuxCPF);
    }
}




void ExibeLocacao(TpLocacao Loc[TF], int TL)
{
	int i, x=10;
	ExibeTelaoResp();
	gotoxy(27,6);
    printf("### Exibir Locacao ###");
	if(TL == 0){
		gotoxy(27,11);
		printf("Vetor Vazio!!!");
		Sleep(2000);
	}
	else
		for(i=0;i<TL;i++)
		{
			gotoxy(4,8);
			printf("       CPF     ||     CODIGO     ||     DIAS     ||     VALOR    ");
			gotoxy(4,9);
			printf("               ||                ||              ||        ");
			gotoxy(4,x);
			printf("%s ||     %d        ||      %d       ||     %.2f \n",Loc[i].CPF,Loc[i].Codigo,Loc[i].Dias,Loc[i].ValorLocacao);
			x++;
			
			
		}
	getch();
}

void CadastroAuto(TpCliente Cli[TF], TpCarro Car[TF],TpLocacao Loc[TF],int &TC, int &TP, int &TL)
{

	strcpy(Cli[TC].CPF,"030.650.446-41");
	strcpy(Cli[TC].Nome,"Thomas Vicente Nicolas da Conceicao");
	strcpy(Cli[TC].fone, "(31) 98420-6597");
	TC++;
	
	strcpy(Cli[TC].CPF,"102.123.614-49");
	strcpy(Cli[TC].Nome,"Clarice Yasmin Evelyn da Mota");
	strcpy(Cli[TC].fone, "(11) 98745-3021");
	TC++;
	
	strcpy(Cli[TC].CPF,"123.456.789-10");
	strcpy(Cli[TC].Nome,"Mariane Isabela Campos");
	strcpy(Cli[TC].fone, "(41) 99583-1420");
	TC++;	
	
	strcpy(Cli[TC].CPF,"302.310.402-61");
	strcpy(Cli[TC].Nome,"Calebe Jorge Bryan da Rosa");
	strcpy(Cli[TC].fone, "(51) 99107-4386");
	TC++;
	
	strcpy(Cli[TC].CPF,"423.572.400-24");
	strcpy(Cli[TC].Nome,"Jose Carlor da silva");
	strcpy(Cli[TC].fone, "(21) 99612-7843");
	TC++;	
	
	strcpy(Cli[TC].CPF,"459.012.948-58");
	strcpy(Cli[TC].Nome,"Andre Augusto De Souza Lopes");
	strcpy(Cli[TC].fone, "(18) 99741-3195");
	TC++;
	
	strcpy(Cli[TC].CPF,"478.308.728-80");
	strcpy(Cli[TC].Nome,"Ana Julia Perdomo Alves");
	strcpy(Cli[TC].fone, "(18) 99758-1127");
	TC++;
	
	strcpy(Cli[TC].CPF,"745.110.933-00");
	strcpy(Cli[TC].Nome,"Sabrina Esther Elza Viana");
	strcpy(Cli[TC].fone, "(61) 98892-7504");
	TC++;
	
	
	Car[TP].Cod = 100;
	strcpy(Car[TP].Modelo,"HRV");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 500.00;
	TP++;
	
	Car[TP].Cod = 105;
	strcpy(Car[TP].Modelo,"Cruze");
	strcpy(Car[TP].Categoria,"Hatch");
	Car[TP].Preco = 300.00;
	TP++;
	
	Car[TP].Cod = 110;
	strcpy(Car[TP].Modelo,"Versa");
	strcpy(Car[TP].Categoria,"Sedan");
	Car[TP].Preco = 350.00;
	TP++;
	
	Car[TP].Cod = 115;
	strcpy(Car[TP].Modelo,"SW4");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 800.00;
	TP++;
	
	Car[TP].Cod = 120;
	strcpy(Car[TP].Modelo,"Civic");
	strcpy(Car[TP].Categoria,"Hatch");
	Car[TP].Preco = 380.00;
	TP++;
	
	Car[TP].Cod = 125;
	strcpy(Car[TP].Modelo,"City");
	strcpy(Car[TP].Categoria,"Sedan");
	Car[TP].Preco = 320.00;
	TP++;
	
	Car[TP].Cod = 130;
	strcpy(Car[TP].Modelo,"Captur");
	strcpy(Car[TP].Categoria,"SUV");
	Car[TP].Preco = 350.00;
	TP++;

	strcpy(Loc[TL].CPF,"459.012.948-58"); // 3
	Loc[TL].Codigo = 100;
	Loc[TL].Dias = 9;
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
	
	strcpy(Loc[TL].CPF,"123.456.789-10"); //safe
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
	InsertionSortCli(Cli, TC);
    SelectionSortCod(Car, TP);
	ExibeTelaoResp();
	gotoxy(26,6);
	printf("### Cadastro Automatico ###");
	gotoxy(27,11);
	printf(" DADOS CADASTRADOS");
	Sleep(3000);
}

void AlterarCliente(TpCliente Cli[TF],TpLocacao Loc[TF],int TC, int TL)
{
	char AuxCPF[15], aux2[15];
	int pos, aux, i, Valida, y=13,resp,resp2;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### Altera Cliente ###");
	gotoxy(4,8);
	printf("Digite o CPF para Alterar os Dados: ");
	fflush(stdin);
	gets(AuxCPF);
	while(TC<TF && strcmp(AuxCPF,"\0")!=0)
	{	
		pos = BuscaCliente(Cli,TC,AuxCPF);
		if(pos == -1)
		{
		
			gotoxy(27,11);
			printf("Usuario Nao Cadastrado!");
			Sleep(2000);
		}
		else
			{
				strcpy(aux2,Cli[pos].CPF);
				gotoxy(4,9);
				printf("Dados encontrados!");
				gotoxy(4,10);
				printf("%s  %s  %s",Cli[pos].CPF,Cli[pos].Nome,Cli[pos].fone);
				gotoxy(4,11);
				printf("Coloque os novos Dados!!!");
				gotoxy(4,12);
				printf("CPF: ");
				gets(AuxCPF);
				Valida = ValidaCPF(AuxCPF);
				if(Valida == 1)
				{
					strcpy(Cli[pos].CPF,AuxCPF);
					gotoxy(4,y);
					printf("Deseja Alterar o Nome? 1-S/2-N: ");
					y++;
					scanf("%d",&resp);
					fflush(stdin);
					y++;
					if(resp == 1)
					{
						gotoxy(4,y);
						printf("NOME: "); 
						y++;
						fflush(stdin);
						gets(Cli[pos].Nome);
						while (strlen(Cli[pos].Nome) == 0) 
						{
							gotoxy(4,y);
							y++;
							printf("Nome Vazio");
							gotoxy(4,y);
	    					printf("Digite Novamente: ");
	    					y++;
	    					gets(Cli[pos].Nome);
						}
					}
					gotoxy(4,y);
					printf("Deseja Alterar o Telefone? 1-S/2-N");
					y++;
					scanf("%d",&resp2);
					fflush(stdin);
					if(resp2 == 1)
					{
						gotoxy(4,y);
						printf("TELEFONE: "); 
						y++;
						fflush(stdin);
						gets(Cli[pos].fone);
						while(strlen(Cli[pos].fone) == 0)
						{
						    gotoxy(4,y);
						    printf("Telefone Vazio!");
						    y++;
						    gotoxy(4,y);
						    printf("DIGITE NOVAMENTE: ");
						    gets(Cli[pos].fone);
						}
					
					}
					aux = BuscaLocacao(Loc,TL,aux2);
					if(aux == -1)
					{
						printf("Dados Alterados 2!!!");
						Sleep(3000);
					}
					else
					{
						for(i=aux;i<TL;i++)
						{
							if(strcmp(Loc[i].CPF,aux2) == 0)
								strcpy(Loc[i].CPF,Cli[pos].CPF);
						}
						ExibeTelaoResp();
						gotoxy(27,6);
						printf("### Altera Cliente ###");
						gotoxy(27,11);
						printf("Dados Alterados");
						Sleep(3000);
					}	
				
				}
				else
					{
						gotoxy(4,13);
						printf("CPF NOVO INVALIDO");
						Sleep(3000);
					}
			}
		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### Altera Cliente ###");
		gotoxy(4,8);
		printf("Digite o CPF para Alterar os Dados: ");
		fflush(stdin);
		gets(AuxCPF);
	}
}

void AlterarCarro(TpCarro Car[TF], TpLocacao Loc[TF], int TP, int TL)
{
    clrscr();
    int novoCod, i,AuxCod, pos, codAntigo;
    char novoModelo[TF], novaCategoria[TF];
    float novoPreco;
    ExibeTelaoResp();
	gotoxy(27,6);
	printf("### Altera Carro ###");
	gotoxy(4,8);
    printf("Digite o Codigo para alterar Dados (0 = sair): ");
    scanf("%d", &AuxCod);

    while (TP < TF && AuxCod != 0)
    {
        pos = buscaCarro(Car, TP, AuxCod);
        if (pos == -1)
        {	
        	ExibeTelaoResp();
			gotoxy(27,6);
			printf("### Altera Carro ###");
        	gotoxy(27,11);
			printf("Dados Nao Encontrado!!!");			
			Sleep(3000);
        }
        else
        {
        	gotoxy(4,9);
            printf("Dados Encontrados!!!");
            gotoxy(4,10);
            printf("%d   %s   %s   %.2f", Car[pos].Cod, Car[pos].Modelo, Car[pos].Categoria, Car[pos].Preco);
            gotoxy(4,11);
            printf("Insira os novos Dados (0 para manter o mesmo codigo)");
            codAntigo = Car[pos].Cod;

            do {
                gotoxy(4,12);
                printf("Novo Codigo: ");
                scanf("%d", &novoCod);

                if (novoCod == Car[pos].Cod && novoCod != 0) {
                    gotoxy(4,18);
                    printf("!!! O novo codigo nao pode ser igual ao antigo !!!");
                    Sleep(2000);
                    gotoxy(4,18); printf("                                                        "); 
                }
                else if (novoCod != 0 && buscaCarro(Car, TP, novoCod) != -1) {
                    gotoxy(4,18);
                    printf("!!! Esse codigo ja esta cadastrado !!!");
                    Sleep(2000);
                    gotoxy(4,18); printf("                                                        "); 
                    novoCod = Car[pos].Cod; 
                }
            } while (novoCod != 0 && (novoCod == Car[pos].Cod || buscaCarro(Car, TP, novoCod) != -1));

            fflush(stdin);

            do {
                gotoxy(4,13);
                printf("Modelo: ");
                gets(novoModelo);

                if (strcmp(novoModelo, Car[pos].Modelo) == 0 && strlen(novoModelo) > 0) {
                    gotoxy(4,18);
                    printf("!!! O novo modelo nao pode ser igual ao antigo !!!");
                    Sleep(2000);
                    gotoxy(4,18); printf("                                                         "); 
                }
                else if (strlen(novoModelo) > 0 && buscaCarroModelo(Car, TP, novoModelo) != -1) {
                    gotoxy(4,18);
                    printf("!!! Esse modelo ja esta cadastrado !!!");
                    Sleep(2000);
                    gotoxy(4,18); printf("                                                          "); 
                    strcpy(novoModelo, Car[pos].Modelo); 
                }
            } while ((strcmp(novoModelo, Car[pos].Modelo) == 0 && strlen(novoModelo) > 0) 
                     || (strlen(novoModelo) > 0 && buscaCarroModelo(Car, TP, novoModelo) != -1));

            gotoxy(4,14);
            printf("Categoria: ");
            gets(novaCategoria);

            gotoxy(4,15);
            printf("Preco: ");
            scanf("%f", &novoPreco);

            if (novoCod > 0)
                Car[pos].Cod = novoCod;
            if (strlen(novoModelo) > 0)
                strcpy(Car[pos].Modelo, novoModelo);
            if (strlen(novaCategoria) > 0)
                strcpy(Car[pos].Categoria, novaCategoria);
            Car[pos].Preco = novoPreco;

            for (i = 0; i < TL; i++)
            {
                if (Loc[i].Codigo == codAntigo)
                {
                    Loc[i].Codigo = Car[pos].Cod;
                    Loc[i].ValorLocacao = Loc[i].Dias * Car[pos].Preco;
                }
            }

            SelectionSortCod(Car,TP);
			ExibeTelaoResp();
			gotoxy(27,6);
			printf("### Altera Carro ###");
			gotoxy(22,11);
            printf("Dados Alterados!!! (Carro e locacoes atualizados)");
            Sleep(3000);
        }

		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### Altera Carro ###");
		gotoxy(4,8);
        printf("Digite o Codigo para alterar Dados (0 = sair): ");
        scanf("%d", &AuxCod);
    }
}


void AlterarLocacao(TpLocacao Loc[TF], TpCarro Car[TF], TpCliente Cli[TF], int TL, int TP, int TC)
{
    clrscr();
    char AuxCPF[15], novoCPF[15];
    int pos, i, novosDias, novoCodigo, codEscolhido;
    int linha; 

    ExibeTelaoResp();
    gotoxy(27,6);
    printf("### ALTERA LOCACAO ###");
    gotoxy(4,8);
    printf("Digite o CPF da locacao que deseja alterar (ENTER = sair):");
    fflush(stdin);
    gets(AuxCPF);

    while (TL < TF && strlen(AuxCPF) > 0)
    {
        pos = BuscaLocacao(Loc, TL, AuxCPF); 
        if (pos == -1)
        {
            gotoxy(4,9);
            printf("!!! Locacao nao encontrada para este CPF !!!");
            Sleep(2000);
        }
        else
        {
            linha = 9;
            gotoxy(4,linha++);
            printf("Locacoes encontradas:");
            
            for (i = 0; i < TL; i++) {
                if (strcmp(Loc[i].CPF, AuxCPF) == 0) {
                    gotoxy(4,linha++);
                    printf("Codigo: %d | CPF: %s | Dias: %d | Valor: %.2f", 
                           Loc[i].Codigo, Loc[i].CPF, Loc[i].Dias, Loc[i].ValorLocacao);
                }
            }

            gotoxy(4,linha++);
            printf("Digite o CODIGO da locacao que deseja alterar: ");
            scanf("%d", &codEscolhido);

            pos = BuscaLocacaoInt(Loc, TL, codEscolhido);

            if (pos == -1 || strcmp(Loc[pos].CPF, AuxCPF) != 0) {
                gotoxy(4,linha++);
                printf("!!! Codigo nao pertence a este CPF !!!");
                Sleep(2000);
            }
            else
            {
                do {
                    gotoxy(4,linha++);
                    printf("Novo CPF (ENTER para manter o mesmo): ");
                    fflush(stdin);
                    gets(novoCPF);

                    if (strlen(novoCPF) == 0) 
                        strcpy(novoCPF, Loc[pos].CPF);
                    else if (strcmp(novoCPF, Loc[pos].CPF) == 0) {
                        gotoxy(4,linha++);
                        printf("!!! O novo CPF nao pode ser igual ao antigo !!!");
                        Sleep(2000);
                        novoCPF[0] = '\0'; 
                    }
                    else if (BuscaCliente(Cli, TC, novoCPF) == -1) {
                        gotoxy(4,linha++);
                        printf("!!! Esse CPF nao esta cadastrado na tabela Cliente !!!");
                        Sleep(2000);
                        novoCPF[0] = '\0'; 
                    }
                } while (strlen(novoCPF) == 0 || BuscaCliente(Cli, TC, novoCPF) == -1);

                strcpy(Loc[pos].CPF, novoCPF);

                do {
                    gotoxy(4,linha++);
                    printf("Novo Codigo do carro (0 para manter o mesmo): ");
                    scanf("%d", &novoCodigo);

                    if (novoCodigo == Loc[pos].Codigo && novoCodigo != 0) {
                        gotoxy(4,linha++);
                        printf("!!! O novo codigo nao pode ser igual ao antigo !!!");
                        Sleep(2000);
                    }
                    else if (novoCodigo != 0 && BuscaBinariaCarroCodigo(Car, TP, novoCodigo) == -1) {
                        gotoxy(4,linha++);
                        printf("!!! Esse codigo nao existe no cadastro de carros !!!");
                        Sleep(2000);
                        novoCodigo = Loc[pos].Codigo; 
                    }
                } while (novoCodigo != 0 && 
                         (novoCodigo == Loc[pos].Codigo || BuscaBinariaCarroCodigo(Car, TP, novoCodigo) == -1));

                if (novoCodigo > 0) {
                    Loc[pos].Codigo = novoCodigo;
                }

                gotoxy(4,linha++);
                printf("Digite o novo total de dias (0 para manter o mesmo): ");
                scanf("%d", &novosDias);

                if (novosDias > 0)
                    Loc[pos].Dias = novosDias;

                int posCar = BuscaBinariaCarroCodigo(Car, TP, Loc[pos].Codigo);
                if (posCar != -1) {
                    Loc[pos].ValorLocacao = Loc[pos].Dias * Car[posCar].Preco;
                }

                gotoxy(4,linha++);
                printf("Locacao atualizada com sucesso!");
                gotoxy(4,linha++);
                printf("Novo CPF: %s | Novo Codigo: %d | Dias: %d | Valor: %.2f", 
                       Loc[pos].CPF, Loc[pos].Codigo, Loc[pos].Dias, Loc[pos].ValorLocacao);

                Sleep(3000);
            }
        }

        ExibeTelaoResp();
        gotoxy(27,6);
        printf("### ALTERA LOCACAO ###");
        gotoxy(4,8);
        printf("Digite o CPF da locacao que deseja alterar (ENTER = sair):");
        fflush(stdin);
        gets(AuxCPF);
    }
}

//EX1
void ListaClientes3Locacoes(TpCliente Cliente[TF], int TC, TpLocacao Locacao[TF], int TL){
    int i, j, cont, x=8;
	ExibeTelaoResp();
	gotoxy(27,6);
    printf("--- CLIENTES COM 3 OU MAIS LOCACOES ---");
    for(i=0; i<TC; i++){
        cont = 0;
        for(j=0; j<TL; j++){
            if(strcmp(Cliente[i].CPF, Locacao[j].CPF) == 0){
                cont++;
            }
        }
        if(cont >= 3){
        	gotoxy(4,x);
            printf("Cliente: %s", Cliente[i].Nome);
            x++;
            gotoxy(4,x);
            printf("CPF: %s", Cliente[i].CPF);
            x++;
            gotoxy(4,x);
            printf("Fone: %s", Cliente[i].fone);
            x++;
            gotoxy(4,x);
            printf("Quantidade de locacoes: %d", cont);
            x = x+2;
        }
    }
    getch();
    if(cont==0){
    	gotoxy(27,11);
        printf("Nenhum cliente possui 3 ou mais locacoes");
        Sleep(3000);
    }
}


//EX2
void ListagemDeCarroPorCategoria(TpCarro Car[TF], int TP){
	clrscr();
	char AuxCat[TF];
	int i,pos,x=10;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### LISTAGEM POR CATEGORIA ###");
	gotoxy(4,8);
	printf("DIGITE A CATEGORIA DE UM CARRO: ");
	gets(AuxCat);
	pos = buscaCarroCategoria(Car,TP,AuxCat);
	if(pos == -1)
	{
		gotoxy(27,11);
		printf("CATEGORIA NAO ENCONTRADA");
		Sleep(3000);
	}
	else{
		for(i=0;i<TP;i++){
			if(strcmp(Car[i].Categoria,AuxCat)==0){
				gotoxy(13,9);
				printf("Carro ||    Modelo     ||     Categoria     ||      Preco");
				gotoxy(13,x);
				printf(" %d  || ",Car[i].Cod);
				gotoxy(24,x);
				printf(" %s  ",Car[i].Modelo); 
				gotoxy(36,x);
				printf("||");
				gotoxy(44,x);
				printf(" %s  ",Car[i].Categoria); 
				gotoxy(57,x);
				printf("||");
				gotoxy(64,x);
				printf(" %.2f  ",Car[i].Preco); 
				x++;	
			}
		}
	}
	getch();
}

//EX3
void LocacaoMaiorLimite(TpLocacao Loc[TF], int TL){
	int i,pos, x=10;
	float Limite;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### LOCACAO MAIOR QUE O LIMITE INFORMADO ###");
	gotoxy(4,8);
	printf("INFORME UM LIMITE(0 PARA SAIR): ");
	scanf("%f",&Limite);
	while(Limite>0){
		pos = BuscaLocacaoLimite(Loc,TL,Limite);
		if(pos==-1){
			gotoxy(27,11);
			printf("LOCACAO IGUAL A 0");
			Sleep(3000);
		}else{
			for(i=0;i<TL;i++){
				if(Loc[i].ValorLocacao>Limite){
					gotoxy(4,9);
					printf("       CPF     ||     CODIGO     ||     DIAS     ||     VALOR    ");
					gotoxy(4,x);
					printf("%s ||     %d        ||      %d       ||     %.2f \n",Loc[i].CPF,Loc[i].Codigo,Loc[i].Dias,Loc[i].ValorLocacao);
					x++;
				}
			}
			getch();
		}
		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### LOCACAO MAIOR QUE O LIMITE INFORMADO ###");
		gotoxy(4,8);
		printf("INFORME UM LIMITE(0 PARA SAIR): ");
		scanf("%f",&Limite);
	}
}

//EX4
void RelatorioCompleto(TpCliente Cli[], int TC,TpLocacao Loc[], int TL, TpCarro Car[], int TP) {
    int i, j, posCar, codCarro, x=8;
    ExibeTelaoRela();
    gotoxy(42,6);
    printf("#### RELATORIO COMPLETO ####");
    for (i = 0; i < TC; i++) {
    	gotoxy(4,x);
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        x++;
        gotoxy(4,x);
        printf("CPF: %s | Nome: %s | Fone: %s\n",Cli[i].CPF, Cli[i].Nome, Cli[i].fone);
        x++;
        for (j = 0; j < TL; j++){
            if (strcmp(Cli[i].CPF, Loc[j].CPF) == 0) 
			{ 
                codCarro = Loc[j].Codigo;
                posCar = buscaCarro(Car, TP, codCarro);
                if (posCar != -1) {
                	gotoxy(4,x);
                    printf("  Carro: %d - %s - %s - R$ %.2f\n",Car[posCar].Cod,Car[posCar].Modelo,Car[posCar].Categoria,Car[posCar].Preco);
                    x++;
                    gotoxy(4,x);
                    printf("  Dias: %d | Valor Locacao: R$ %.2f\n\n", Loc[j].Dias, Loc[j].ValorLocacao);
                    x=x+2;
                }
            }
        }
    }
    getch();
}
void ExclusaoCliente(TpCliente Cli[TF], int &TC, TpLocacao Loc[TF], int &TL){
	int i,j,pos;
	char CPF[15];
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### EXCLUI CLIENTE ###");
	gotoxy(4,8);
	printf("DIGITE UM CPF PARA BUSCAR E EXCLUIR: ");
	gets(CPF);
	pos = BuscaCliente(Cli,TC,CPF);
	if(pos == -1){
		gotoxy(4,9);
		printf("CPF INCEXISTENTE");
		Sleep(3000);;
	}else{
		for(i=0;i<TC;i++){
			if(strcmp(Cli[i].CPF,CPF)==0){
				for(j=i;j<TC-1;j++){
					Cli[j]=Cli[j+1];
				}
				TC--;
				
				for(i=0;i<TL;i++){
					if(strcmp(Loc[i].CPF,CPF)==0){
						for(j=i;j<TL-1;j++){
							Loc[j]=Loc[j+1];
						}
						TL--;
						i--;
						InsertionSortCli(Cli, TC);
					}
				}
				ExibeTelaoResp();
				gotoxy(27,6);
				printf("### EXCLUI CARRO ###");
				gotoxy(27,11);
				printf("CLIENTE E LOCACAO EXCLUIDOS");
				Sleep(3000);
			}
		}
	}
}

void ExclusaoCarro(TpCarro Car[TF], int &TP, TpLocacao Loc[TF], int TL){
	int i,j,Cod,pos;
	char resp;
	ExibeTelaoResp();
	gotoxy(27,6);
	printf("### EXCLUI CARRO ###");
	gotoxy(4,8);
	printf("DIGITE UM CODIGO PARA BUSCAR E EXCLUIR: ");
	scanf("%d",&Cod);
	pos = BuscaCarroSentinela(Car,TP,Cod);
	if(pos == -1){
		ExibeTelaoResp();
		gotoxy(27,6);
		printf("### EXCLUI CARRO ###");
		gotoxy(27,11);
		printf("CODIGO INCEXISTENTE");
		Sleep(2500);
	}
	else
	{
		gotoxy(4,9);
		printf("Dados Encontrados");
		gotoxy(4,10);
		printf("%d || %s || %s || %.2f ", Car[pos].Cod,Car[pos].Modelo,Car[pos].Categoria,Car[pos].Preco);
		gotoxy(4,11);
		printf("Deseja Excluir os dados? S/N ");
		scanf(" %c",&resp);
		if(resp== 's' || resp== 'S')
		{
			for(i=0;i<TP;i++){
			if(Car[i].Cod==Cod){
				for(j=i;j<TP-1;j++){
					Car[j]=Car[j+1];
				}
				TP--;
				
				for(i=0;i<TL;i++){
					if(Loc[i].Codigo==Cod){
						for(j=i;j<TL-1;j++){
							Loc[j]=Loc[j+1];
						}
						TL--;
						i--;
						SelectionSortCod(Car,TP);
					}
				}
				ExibeTelaoResp();
				gotoxy(27,6);
				printf("### EXCLUI CARRO ###");
				gotoxy(27,11);
				printf("CARRO E LOCACAO EXCLUIDOS");
				Sleep(3000);
			}
		}
		}
		
	}
}

void ExclusaoLocacao(TpLocacao Loc[TF], int &TL){
    int i, pos, AuxCod,linha;
    char Aux[15];

    ExibeTelaoResp();
    gotoxy(27,6);
    printf("### EXCLUI LOCACAO ###");
    gotoxy(4,8);
    printf("Digite um CPF para excluir a Locacao (ou ENTER para sair): ");
    fflush(stdin);
    gets(Aux); 

    while(strlen(Aux) > 0){
        pos = BuscaLocacao(Loc, TL, Aux); 
        if(pos == -1){
            gotoxy(4,10);
            printf("!!! Nenhuma locacao encontrada para este CPF !!!");
            Sleep(2000);
        } 
        else {
            ExibeTelaoResp();
            gotoxy(27,6);
            printf("### EXCLUI LOCACAO ###");
            gotoxy(4,8);
            printf("Locacoes encontradas para o CPF %s:", Aux);

            linha = 10;
            for(i = 0; i < TL; i++){
                if(strcmp(Loc[i].CPF, Aux) == 0){
                    gotoxy(4,linha++);
                    printf("Codigo: %d | Dias: %d | Valor: %.2f", 
                           Loc[i].Codigo, Loc[i].Dias, Loc[i].ValorLocacao);
                }
            }

            gotoxy(4,linha+1);
            printf("Digite o Codigo da locacao que deseja excluir: ");
            scanf("%d", &AuxCod);

            while(BuscaLocacaoInt(Loc, TL, AuxCod) == -1 || strcmp(Loc[BuscaLocacaoInt(Loc, TL, AuxCod)].CPF, Aux) != 0){
                gotoxy(4,linha+3);
                printf("!!! Codigo nao pertence a este CPF !!!");
                Sleep(2000);

                gotoxy(4,linha+1);
                printf("Digite novamente o Codigo da locacao que deseja excluir: ");
                scanf("%d", &AuxCod);
            }

            pos = BuscaLocacaoInt(Loc, TL, AuxCod);

            for(i = pos; i < TL-1; i++){
                Loc[i] = Loc[i+1];
            }
            TL--;
            gotoxy(4,linha+3);
            printf(">>> Locacao excluida com sucesso! <<<");
            Sleep(2000);
        }

        ExibeTelaoResp();
        gotoxy(27,6);
        printf("### EXCLUI LOCACAO ###");
        gotoxy(4,8);
        printf("Digite um CPF para excluir a Locacao (ou ENTER para sair): ");
        fflush(stdin);
        gets(Aux); 
    }
    getch();
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
							do{
								opcao = MenuCarro();
								switch(opcao){
									case'A':
										CadastroCarroCodigo(Carro,TP);
									break;
									
									case'B':
										CadastroCarroModelo(Carro,TP);
									break;
								} 
							}while(opcao!='C');
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
							ExclusaoCliente(Cliente,TC,Locacao,TL);
							break;
						case 'B':
							ExclusaoCarro(Carro,TP,Locacao,TL);
							break;
						case 'C':
							ExclusaoLocacao(Locacao,TL);
							break;	
					}
				}while(opcao!='D');
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
								AlterarLocacao(Locacao,Carro,Cliente,TL,TP,TC);
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
							ListaClientes3Locacoes(Cliente,TC,Locacao,TL);
							break;
						case 'B':
							ListagemDeCarroPorCategoria(Carro,TP);
							break;
						case 'C':
							LocacaoMaiorLimite(Locacao,TL);
					}
				}while(opcao!= 'D');
				break;		
			//RELATORIO COMPLETO
			case 'F':
				RelatorioCompleto(Cliente,TC,Locacao,TL,Carro,TP);
				break;
		}
	}while(opcao!=27);
}




int main(void){
	Executar();
	
	return 0;
}

