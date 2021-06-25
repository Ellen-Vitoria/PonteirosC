//       ****************     GRUPO 13 - Ellen Vitória e Marcella Santos     ****************

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Struct de Produtos:
struct dados{
    char nome[20];
    int qtAtual;
    int qtMin;
    char dtValidade[8];
};

//Funções do Menu:
inserirProdutos(struct dados *prod);
listarProdutos(struct dados *prod);
int pesquisarProdutos(struct dados *prod);
pesquisarLetra(struct dados *prod);
pesquisarDtValidade(struct dados *prod);
listarEstoqueMinimo(struct dados *prod);
movimentarEstoque(struct dados *prod);
alterarProdutos(struct dados *prod);
excluirProdutos(struct dados *prod);
sair();

//Ponteiro para Manipulação de Arquivo:
FILE *file;

//Função Principal:
main()
{
    setlocale(LC_ALL, "Portuguese");
    struct dados produtos; //Variável do Struct


    int opcao;

    for( ; ; )
    {
        system("color B");
        printf("\t\t***********************************************************************\n");
        printf("\t\t*                CONTROLE   DE   ESTOQUE   DE   PRODUTOS              *\n");
        printf("\t\t***********************************************************************\n\n");
        printf("\t\t         1   -   Entrada de Produtos                                   \n");
        printf("\t\t         2   -   Listar os Produtos na Tela                            \n");
        printf("\t\t         3   -   Pesquisar um Produto pelo Nome                        \n");
        printf("\t\t         4   -   Pesquisar um Produto pela 1º Letra do Nome            \n");
        printf("\t\t         5   -   Pesquisar Data de Validade (mês/ano)                  \n");
        printf("\t\t         6   -   Listar os Produtos abaixo do Estoque Mínimo           \n");
        printf("\t\t         7   -   Movimentar Quantidade em Estoque                      \n");
        printf("\t\t         8   -   Alterar Produto pesquisado pelo Nome Completo         \n");
        printf("\t\t         9   -   Excluir Produto pesquisado pelo Nome Completo         \n");
        printf("\t\t         10  -   Sair do Sistema                                       \n\n");
        printf("\t\t***********************************************************************\n");
        printf("\t\t                      Escolha uma Função: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            //Inserir Produtos
            case 1:
                system("cls");
                system("color F");
                inserirProdutos(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Lista de Produtos
            case 2:
                system("cls");
                system("color F");
                listarProdutos(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Pesquisar de Produtos
            case 3:
                system("cls");
                system("color F");
                pesquisarProdutos(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Pesquisar 1ª Letra do Produto
            case 4:
                system("cls");
                system("color F");
                pesquisarLetra(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Pesquisar Data de Validade
            case 5:
                system("cls");
                system("color F");
                pesquisarDtValidade(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Listar Produtos abaixo do Estoque Mínimo
            case 6:
                system("cls");
                system("color F");
                listarEstoqueMinimo(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Movimentar Quantidade em Estoque
            case 7:
                system("cls");
                system("color F");
                movimentarEstoque(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Alterar Produtos
            case 8:
                system("cls");
                system("color F");
                alterarProdutos(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Excluir Produtos
            case 9:
                system("cls");
                system("color F");
                excluirProdutos(&produtos); //Passando Strcut de Produtps por Parâmetro

                break;

            //Sair do Sistema
            case 10:
                system("cls");
                system("color F");
                sair();

                break;

            //Caso seja digitado um Valor que não está no Menu
            default:
                system("cls");
                continue;
        }

        printf("\n\n\t\t\t**********************************************************\n\n");
        printf("\n\t\t                Pressione 'Enter' para voltar ao Menu  >>");
        getch();
        system("cls");
    }
}

inserirProdutos(struct dados *prod) //prod = &produtos
{
    file = fopen("Estoque.txt","a"); //Abrindo arquivo

    getchar();
    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*                    Inserir Produtos                    *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {
        printf("\t\t\t     Nome do Produto: ");
        gets(prod->nome);

        printf("\t\t\t     Quantidade Atual: ");
        scanf("%d", &prod->qtAtual);

        printf("\t\t\t     Quantidade de Estoque Mínimo: ");
        scanf("%d", &prod->qtMin);

        getchar();
        printf("\t\t\t     Data de Validade: ");
        gets(prod->dtValidade);

        //Escrevendo no Arquivo
        fwrite(prod, sizeof(*prod), 1, file); //Se fosse  sizeof(prod), o número de bytes seria !=
        fclose(file); //Fechando arquivo
    }
}

listarProdutos(struct dados *prod)
{
    file = fopen("Estoque.txt","r"); //Abrindo arquivo

    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*                    Lista de Produtos                   *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {
        while(fread(prod, sizeof(*prod), 1, file))
        {
            if((*prod).nome[0] != '\0')
            {
                printf("\n\t\t\t     Nome do Produto: %s\n", prod->nome);
                printf("\t\t\t     Quantidade Atual: %d\n", prod->qtAtual);
                printf("\t\t\t     Quantidade de Estoque Mínimo: %d\n", prod->qtMin);
                printf("\t\t\t     Data de Validade: %s\n\n", prod->dtValidade);
            }
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

int pesquisarProdutos(struct dados *prod)
{
    file = fopen("Estoque.txt","r"); //Abrindo arquivo

    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*               Pesquisar Produto pelo Nome              *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {
        char nm[20];
        int x=0, qt=0, qtStr=0, dado=-1, achou=0;

        printf("\t\t\t\t Digite o Nome Completo: ");
        getchar();
        gets(nm);

        while(fread(prod, sizeof(*prod), 1, file))
        {
            dado++; //Para saber o Nº do Produto
            for(x=0; nm[x] != '\0'; x++)
            {
                if(nm[x] != '\0' || (*prod).nome[x] != '\0')
                {
                    qtStr++;
                    //printf("\n\n\t\t\t\t%d     %c    %c", qtStr, nm[x], (*prod).nome[x]);
                    if(nm[x] == (*prod).nome[x])
                    {
                        qt++;
                    }
                }
            }
            if(qtStr == qt)
            {
                printf("\n\n\t\t\t     Nome do Produto: %s\n", prod->nome);
                printf("\t\t\t     Quantidade Atual: %d\n", prod->qtAtual);
                printf("\t\t\t     Quantidade de Estoque Mínimo: %d\n", prod->qtMin);
                printf("\t\t\t     Data de Validade: %s\n\n\n", prod->dtValidade);
                achou++; //Caso tenha encontrado o Produto

                fclose(file); //Fechando arquivo
                return dado;

            }
            qt=0;
            qtStr=0;

        }
        if(achou==0)
        {
            //Caso Produto não seja encontrado
            system("color C");
            printf("\n\n\t\t\t\t     Esse Produto não foi encontrado!\n");
            fclose(file); //Fechando arquivo
            return -1;
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

pesquisarLetra(struct dados *prod)
{
    file = fopen("Estoque.txt","r"); //Abrindo arquivo

    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*             Pesquisar Produto pela 1ª Letra            *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {
        char letra;
        int achou=0;

        printf("\t\t\t\t\t   Digite uma Letra: ");
        getchar();
        letra = getchar();

        while(fread(prod, sizeof(*prod), 1, file))
        {
            if((*prod).nome[0] != '\0' && (letra == (*prod).nome[0] || (letra+32) == (*prod).nome[0] || (letra-32) == (*prod).nome[0]))
            {
                printf("\n\n\t\t\t     Nome do Produto: %s\n", prod->nome);
                printf("\t\t\t     Quantidade Atual: %d\n", prod->qtAtual);
                printf("\t\t\t     Quantidade de Estoque Mínimo: %d\n", prod->qtMin);
                printf("\t\t\t     Data de Validade: %s\n\n", prod->dtValidade);
                achou++;
            }
        }
        if(achou==0)
        {
            //Caso Produto com essa Letra não seja encontrado
            system("color C");
            printf("\n\n\t\t\t        Nenhum Produto com essa Letra foi inserido!");
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

pesquisarDtValidade(struct dados *prod)
{
    file = fopen("Estoque.txt","r"); //Abrindo arquivo

    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*         Pesquisar Produto pela Data de Validade        *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {
        char dt[8];
        int x=0, qt=0, qtStr=0, achou=0;

        printf("\t\t\t\t   Digite uma Data de Validade: ");
        getchar();
        gets(dt);

        while(fread(prod, sizeof(*prod), 1, file))
        {
            for(x=0; dt[x] != '\0'; x++)
            {
                if(dt[x] != '\0' || (*prod).dtValidade[x] != '\0')
                {
                    qtStr++;
                    if(dt[x] == (*prod).dtValidade[x])
                    {
                        qt++;
                    }
                }
            }
            if(qtStr == qt && (*prod).nome[0] != '\0')
            {
                printf("\n\n\t\t\t     Nome do Produto: %s\n", prod->nome);
                printf("\t\t\t     Quantidade Atual: %d\n", prod->qtAtual);
                printf("\t\t\t     Quantidade de Estoque Mínimo: %d\n", prod->qtMin);
                printf("\t\t\t     Data de Validade: %s\n\n", prod->dtValidade);

                achou++;
            }
            qt=0;
            qtStr=0;

        }
        if(achou==0)
        {
            //Caso Produto com essa Dt de Validade não seja encontrado
            system("color C");
            printf("\n\n\t\t\t        Não há Produtos com essa Data de Validade!");
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

listarEstoqueMinimo(struct dados *prod)
{
    file = fopen("Estoque.txt","r"); //Abrindo arquivo

    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*       Lista de Produtos abaixo do Estoque Mínimo       *\n");
    printf("\t\t\t**********************************************************\n\n");

    //Se arquivo existir
    if(file != NULL)
    {

        int achou=0;

        while(fread(prod, sizeof(*prod), 1, file))
        {
            if((*prod).qtAtual < (*prod).qtMin)
            {
                printf("\n\n\t\t\t     Nome do Produto: %s\n", prod->nome);
                printf("\t\t\t     Quantidade Atual: %d\n", prod->qtAtual);
                printf("\t\t\t     Quantidade de Estoque Mínimo: %d\n", prod->qtMin);
                printf("\t\t\t     Data de Validade: %s\n\n", prod->dtValidade);
                achou++;
            }
        }
        if(achou==0)
        {
            //Caso Estoque esteja em dia
            system("color A");
            printf("\n\t\t\t       Todos os Produtos estão com o Estoque em Dia!\n");
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

movimentarEstoque(struct dados *prod)
{
    int achou, qt, y;
    achou = pesquisarProdutos(prod);

    file = fopen("Estoque.txt","r+"); //Abrindo arquivo

    //Se arquivo existir
    if(file != NULL)
    {
        if(achou != -1)
        {
            printf("\n\n\t\t\t***********   Movimentar Quantidade em Estoque   *********\n\n\n");
            printf("\t\t\t\t\t     Quantidade: ");
            scanf("%d", &qt);

            //fseek
            (*prod).qtAtual = (*prod).qtAtual + qt;

            y = achou*sizeof(*prod);
            fseek(file, y, 0);

            //Escrevendo no Arquivo
            fwrite(prod, sizeof(*prod), 1, file);
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

alterarProdutos(struct dados *prod)
{
    int achou, y;
    achou = pesquisarProdutos(prod);

    //Se arquivo existir
    file = fopen("Estoque.txt","r+"); //Abrindo arquivo

    if(file == NULL)
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
        return;
    }

        if(achou != -1)
        {
            printf("\n\n\t\t\t*******************   Alterar Produtos   *****************\n\n\n");


            //getchar();
            printf("\t\t\t     Nome do Produto: ");
            gets(prod->nome);

            printf("\t\t\t     Quantidade Atual: ");
            scanf("%d", &prod->qtAtual);

            printf("\t\t\t     Quantidade de Estoque Mínimo: ");
            scanf("%d", &prod->qtMin);

            getchar();
            printf("\t\t\t     Data de Validade: ");
            gets(prod->dtValidade);

            y = achou*sizeof(*prod);
            fseek(file, y, 0);

            //Escrevendo no Arquivo
            fwrite(prod, sizeof(*prod), 1, file);

        }

    fclose(file); //Fechando arquivo
}

excluirProdutos(struct dados *prod)
{
    int achou, opcao, x, y;
    achou = pesquisarProdutos(prod);

    file = fopen("Estoque.txt","r+"); //Abrindo arquivo

    //Se arquivo existir
    if(file != NULL)
    {
        if(achou != -1)
        {
            printf("\n\n\t\t\t*******************   Excluir Produtos   *****************\n\n\n");

            printf("\t\t\t\t        [1] - Sim   //   [0] - Não\n");
            printf("\t\t\t      Tem certeza que deseja excluir esse Produto? ");
            scanf("%d", &opcao);

            if(opcao==1)
            {
                for(x=0; x<20; x++)
                {
                    (*prod).nome[x] = '\0';
                }
                x=0;
                for(x=0; x<8; x++)
                {
                    (*prod).dtValidade[x] = '\0';
                }

                (*prod).qtAtual = 0;
                (*prod).qtMin = 0;

                y = achou*sizeof(*prod);
                fseek(file, y, 0);

                //Escrevendo no Arquivo
                fwrite(prod, sizeof(*prod), 1, file);
            }
        }
    }
    else
    {
        //No caso do Arquivo não existir
        system("color C");
        printf("\t\t\t\t       Nenhum Produto foi inserido!\n");
        printf("\t\t\t      Por favor, retorne ao Menu e escolha a Opção 1.");
    }

    fclose(file); //Fechando arquivo
}

sair()
{
    printf("\t\t\t**********************************************************\n");
    printf("\t\t\t*                     Sair do Sistema                    *\n");
    printf("\t\t\t**********************************************************\n\n");

    int op;

    printf("\t\t\t\t       [1] - Sim   //   [0] - Não\n\n");
    printf("\t\t\t\t        Deseja realmente sair? ");
    scanf("%d", &op);

    if(op == 1)
    {
        system("color B");
        printf("\n\n\t\t\t**********************************************************\n");
        printf("\t\t\t\t             OBRIGADA  USUÁRIO!\n\n");
        exit(0);
    }
}
