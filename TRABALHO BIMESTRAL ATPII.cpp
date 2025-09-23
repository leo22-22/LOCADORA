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
char Menu(void);
char MenuCadastro(void);
char MenuExcluir(void);
char MenuAlterar(void);
char MenuExibir(void);
char MenuListagem(void);

/* buscas */
int BuscaCliente(TpCliente Cliente[TF], int TL, char CPFAux[15]);
int buscaCarro(TpCarro Car[TF], int TL, int Aux);
int BuscaLocacaoInt(TpLocacao Loc[TF], int TL, int Aux);
int BuscaLocacao(TpLocacao Loc[TF], int TL, char CPFAux[15]);
int BuscaCarroSentinela(TpCarro Carro[TF], int TC, int AuxCar);

/* exibição e cadastros */
void ExibeCliente(TpCliente Cliente[TF], int TL);
void ExibeCarro(TpCarro Carro[TF], int TL);
void ExibeLocacao(TpLocacao Loc[TF], int TL);

void CadastroCliente(TpCliente Cliente[TF], int *TL);
void CadastroCarro(TpCarro Carro[TF], int *TC);
void CadastroLocacao(TpLocacao Loc[TF], int *TL, TpCliente Cliente[TF], int TC, TpCarro Carro[TF], int TP);
void CadastroAuto(TpCliente Cli[TF], TpCarro Car[TF], TpLocacao Loc[TF], int *TC, int *TP, int *TL);

/* alterações */
void AlterarCliente(TpCliente Cli[TF], TpLocacao Loc[TF], int TC, int TL);
void AlterarCarro(TpCarro Car[TF], TpLocacao Loc[TF], int TP, int TL);


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

char MenuCarro(void){
	clrscr();
	printf("\n# # # MENU CARRO # # #\n");
	printf("\n[A] CADASTRAR CARRO POR CODIGO");
	printf("\n[B]CADASTRAR CARRO POR MODELO");
	printf("\n[C] VOLTAR");
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
	while(I<F && Car[TL].Cod!=Aux){
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

void BubbleSortLocacao(TpLocacao Loc[TF], int TL){
	TpLocacao Aux;
	int i;
	while(TL>1){
		for(i=0;i<TL-1;i++){
			if(strcmp(Loc[i].CPF,Loc[i+1].CPF)>0){
				Aux=Loc[i];
				Loc[i]=Loc[i+1];
				Loc[i+1]=Aux;
			}
		}
		TL--;
	}
}

void BubbleSortCliente(TpCliente Cliente[TF], int TL){
	TpCliente Aux;
	int i;
	while(TL>1){
		for(i=0;i<TL-1;i++){
			if(strcmp(Cliente[i].CPF,Cliente[i+1].CPF)>0){
				Aux=Cliente[i];
				Cliente[i]=Cliente[i+1];
				Cliente[i+1]=Aux;
			}
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
	int i;
	BubbleSortCliente(Cliente,TL);
	if(TL == 0)
		printf("Vetor Vazio!!!\n");
	else
		for(i=0;i<TL;i++)
			printf(" %s  %s %s \n",Cliente[i].CPF,Cliente[i].Nome,Cliente[i].fone);
	getch();
}

void ExibeCarro(TpCarro Carro[TF], int TL)
{
	int i;
	BubbleSortModelo(Carro,TL);
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
		pos = BuscaIndexadaCPF(Cliente,TL,AuxCPF);
		if(pos==-1){
			strcpy(Cliente[TL].CPF,AuxCPF);
			printf("NOME: "); fflush(stdin);
			gets(Cliente[TL].Nome);
			printf("TELEFONE(EX:(XX) XXXXX-XXXX): "); fflush(stdin);
			gets(Cliente[TL].fone);
			BubbleSortCliente(Cliente,TL);
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

void CadastroCarroModelo(TpCarro Carro[TF], int &TC){
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
			BubbleSortModelo(Carro,TC);
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

void CadastroCarroCodigo(TpCarro Carro[TF], int &TC){
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
			BubbleSortModelo(Carro,TC);
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

void ExibeLocacao(TpLocacao Loc[TF], int TL)
{
	int i;
	BubbleSortLocacao(Loc,TL);
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
	strcpy(Cli[TC].CPF,"123.456.789-10");
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

	printf("\n DADOS CADASTRADOS");
	getch();
	
}

void AlterarCliente(TpCliente Cli[TF], TpLocacao Loc[TF], int TC, int TL)
{
	clrscr();
    char NovoCPF[15], NovoNome[TF], NovoFone[16], AuxCPF[15], CPF_Antigo[15];
    int pos;

    printf("Digite o CPF para Alterar os Dados:\n");
    fflush(stdin);
    gets(AuxCPF);

    while (TC < TF && strlen(AuxCPF) > 0)
    {
        pos = BuscaCliente(Cli, TC, AuxCPF);
        if (pos == -1)
        {
            printf("Usuario Nao Cadastrado!\n");
        }
        else
        {
            printf("\n--- Dados encontrados! ---\n");
            printf("CPF: %s  | Nome: %s  | Telefone: %s\n", Cli[pos].CPF, Cli[pos].Nome, Cli[pos].fone);

            strcpy(CPF_Antigo, Cli[pos].CPF);

            printf("\n--- Coloque os novos Dados (ou deixe vazio para manter) ---\n");

            printf("CPF: ");
            gets(NovoCPF);
            if(strlen(NovoCPF) > 0) {
                strcpy(Cli[pos].CPF, NovoCPF);
            } else {
                strcpy(NovoCPF, Cli[pos].CPF); 
            }

            printf("Nome: ");
            gets(NovoNome);
            if(strlen(NovoNome) > 0) {
                strcpy(Cli[pos].Nome, NovoNome);
            }

            printf("Telefone: ");
            gets(NovoFone);
            if(strlen(NovoFone) > 0) {
                strcpy(Cli[pos].fone, NovoFone);
            }

            if(strcmp(CPF_Antigo, NovoCPF) != 0) {
                for (int i = 0; i < TL; i++)
                {
                    if (strcmp(Loc[i].CPF, CPF_Antigo) == 0)
                    {
                        strcpy(Loc[i].CPF, NovoCPF);
                    }
                }
            }

            printf("Dados Alterados!!! (Cliente e locações atualizados)\n");
        }

        printf("\nDigite o CPF para Alterar os Dados (ou Enter para sair):\n");
        fflush(stdin);
        gets(AuxCPF);
    }
}



void AlterarCarro(TpCarro Car[TF], TpLocacao Loc[TF], int TP, int TL)
{
    clrscr();
    int AuxCod, pos, codAntigo;
    int novoCod;
    char novoModelo[TF], novaCategoria[TF];
    float novoPreco;

    printf("Digite o Codigo para alterar Dados (0 = sair)\n");
    scanf("%d", &AuxCod);

    while (TP < TF && AuxCod != 0)
    {
        pos = buscaCarro(Car, TP, AuxCod);
        if (pos == -1)
        {
            printf("Dados Nao Encontrado!!!\n");
        }
        else
        {
            printf("Dados Encontrados!!!\n");
            printf("%d   %s   %s   %.2f\n", Car[pos].Cod, Car[pos].Modelo, Car[pos].Categoria, Car[pos].Preco);
            printf("Insira os novos Dados (0 para manter o mesmo codigo)\n");

            codAntigo = Car[pos].Cod;

            printf("Novo Codigo: ");
            scanf("%d", &novoCod);
            fflush(stdin);
            printf("Modelo: ");
            gets(novoModelo);
            printf("Categoria: ");
            gets(novaCategoria);
            printf("Preco: ");
            scanf("%f", &novoPreco);

            if (novoCod > 0)
                Car[pos].Cod = novoCod;
            if (strlen(novoModelo) > 0)
                strcpy(Car[pos].Modelo, novoModelo);
            if (strlen(novaCategoria) > 0)
                strcpy(Car[pos].Categoria, novaCategoria);
            Car[pos].Preco = novoPreco;

            for (int i = 0; i < TL; i++)
            {
                if (Loc[i].Codigo == codAntigo)
                {
                    Loc[i].Codigo = Car[pos].Cod;
                    Loc[i].ValorLocacao = Loc[i].Dias * Car[pos].Preco;
                }
            }

            printf("Dados Alterados!!! (Carro e locacoes atualizados)\n");
        }

        printf("Digite o Codigo para alterar Dados (0 = sair)\n");
        scanf("%d", &AuxCod);
    }
}


void AlterarLocacao(TpLocacao Loc[TF], int TL)
{
    clrscr();
    char AuxCPF[15];
    int pos, novosDias;

    printf("Digite o CPF da locacao que deseja alterar (ENTER = sair):\n");
    fflush(stdin);
    gets(AuxCPF);

    while (TL < TF && strlen(AuxCPF) > 0)
    {
        pos = BuscaLocacao(Loc, TL, AuxCPF); // busca por CPF
        if (pos == -1)
        {
            printf("Locacao nao encontrada para este CPF!\n");
        }
        else
        {
            printf("Locacao encontrada:\n");
            printf("Codigo: %d | CPF: %s | Dias: %d | Valor: %.2f\n",
                   Loc[pos].Codigo, Loc[pos].CPF, Loc[pos].Dias, Loc[pos].ValorLocacao);

            printf("Digite o novo total de dias (0 para manter o mesmo): ");
            scanf("%d", &novosDias);

            if (novosDias > 0)
            {
                Loc[pos].Dias = novosDias;
                Loc[pos].ValorLocacao = (Loc[pos].ValorLocacao / (float)Loc[pos].Dias) * novosDias;
                printf("Dias alterados e ValorLocacao atualizado!\n");
            }
            else
            {
                printf("Nenhuma alteracao realizada.\n");
            }
        }

        printf("\nDigite o CPF da locacao que deseja alterar (ENTER = sair):\n");
        fflush(stdin);
        gets(AuxCPF);
    }
}



//EX1
void ListaClientes3Locacoes(TpCliente Cliente[TF], int TC, TpLocacao Locacao[TF], int TL){
	clrscr();
    int i, j, cont;

    printf("\n--- CLIENTES COM 3 OU MAIS LOCACOES ---\n");
    for(i=0; i<TC; i++){
        cont = 0;
        for(j=0; j<TL; j++){
            if(strcmp(Cliente[i].CPF, Locacao[j].CPF) == 0){
                cont++;
            }
        }
        if(cont >= 3){
            printf("\nCliente: %s", Cliente[i].Nome);
            printf("\nCPF: %s", Cliente[i].CPF);
            printf("\nFone: %s", Cliente[i].fone);
            printf("\nQuantidade de locacoes: %d\n", cont);
        }
    }
    if(cont==0){
        printf("\nNenhum cliente possui 3 ou mais locacoes.\n");
    }
    getch();
}


//EX2
void ListagemDeCarroPorCategoria(TpCarro Car[TF], int TP){
	clrscr();
	char AuxCat[TF];
	int i,pos;
	printf("\nLISTAGEM POR CATEGORIA\n");
	printf("\nDIGITE A CATEGORIA DE UM CARRO: ");
	gets(AuxCat);
	pos = buscaCarroCategoria(Car,TP,AuxCat);
	if(pos == -1)
		printf("\nCATEGORIA NAO ENCONTRADA\n");
	else{
		for(i=0;i<TP;i++){
			if(strcmp(Car[i].Categoria,AuxCat)==0){
				printf("\n%d %s %s %.2f\n",Car[i].Cod,Car[i].Modelo,Car[i].Categoria,Car[i].Preco);
			}
		}
	}
	getch();
}

//EX3
void LocacaoMaiorLimite(TpLocacao Loc[TF], int TL){
	clrscr();
	int i,pos;
	float Limite;
	printf("\nLOCACAO MAIOR QUE O LIMITE INFORMADO\n");
	printf("\nINFORME UM LIMITE(0 PARA SAIR): ");
	scanf("%f",&Limite);
	while(Limite>0){
		pos = BuscaLocacaoLimite(Loc,TL,Limite);
		if(pos==-1){
			printf("\nLOCACAO IGUAL A 0\n");
		}else{
			for(i=0;i<TL;i++){
				if(Loc[i].ValorLocacao>Limite){
					printf("\n%s | %d | %d | %.2f\n",Loc[i].CPF,Loc[i].Codigo,Loc[i].Dias,Loc[i].ValorLocacao);
				}
			}
		}
		printf("\nINFORME UM LIMITE(0 PARA SAIR): ");
		scanf("%f",&Limite);
	}
	getch();
}

//EX4
void RelatorioCompleto(TpLocacao Loc[TF], int TL, TpCarro Car[TF], int TP){
	
	
}

void ExclusaoCliente(TpCliente Cli[TF], int &TC, TpLocacao Loc[TF], int &TL){
	int i,j,pos;
	char CPF[15];
	
	printf("\nEXCLUSAO DE CLIENTE\n");
	printf("\nDIGITE UM CPF PARA BUSCAR E EXCLUIR\n");
	gets(CPF);
	pos = BuscaCliente(Cli,TC,CPF);
	if(pos == -1){
		printf("\nCPF INCEXISTENTE\n");
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
					}
				}
				printf("\nCLIENTE E LOCACAO EXCLUÍDOS\n");
			}
		}
	}
	getch();
}

void ExclusaoCarro(TpCarro Car[TF], int TP, TpLocacao Loc[TF], int TL){
	int i,j,Cod,pos;
	printf("\nEXCLUSAO DE CARRO\n");
	printf("\nDIGITE UM CODIGO PARA BUSCAR E EXCLUIR\n");
	scanf("%d",&Cod);
	pos = BuscaCarroSentinela(Car,TP,Cod);
	if(pos == -1){
		printf("\nCODIGO INCEXISTENTE\n");
	}else{
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
					}
				}
				printf("\nCARRO E LOCACAO EXCLUÍDOS\n");
			}
		}
	}
	getch();
}

void ExclusaoLocacao(TpLocacao Loc[TF], int &TL){
    int i, pos, AuxCod;
    char Aux[15];

    printf("\nDigite um CPF para excluir a Locacao (ou ENTER para sair): ");
    fflush(stdin);
    gets(Aux); 

    while(strcmp(Aux, "\0") != 0){
        pos = BuscaLocacao(Loc, TL, Aux);
        if(pos == -1){
            printf("\nCPF NAO ENCONTRADO\n");
        } else {
            printf("\nCPF ENCONTRADO\n");
            printf("\n%s %d %d %.2f\n", Loc[pos].CPF, Loc[pos].Codigo, Loc[pos].Dias, Loc[pos].ValorLocacao);

            printf("\nDigite o Codigo para confirmar exclusao: ");
            scanf("%d", &AuxCod);

            if(Loc[pos].Codigo == AuxCod){
                for(i = pos; i < TL-1; i++){
                    Loc[i] = Loc[i+1]; 
                }
                TL--;
                printf("\nLOCACAO EXCLUIDA\n");
            } else {
                printf("\nCODIGO NAO CONFERE, EXCLUSAO CANCELADA\n");
            }
        }

        printf("\nDigite outro CPF (ou ENTER para sair): ");
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
								AlterarLocacao(Locacao,TL);
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
				break;
		}
	}while(opcao!=27);
}




int main(void){
	
	Executar();
	
	return 0;
}
