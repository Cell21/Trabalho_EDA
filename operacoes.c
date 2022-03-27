/**
 * @file Header.h
 * @author Celestino Machado (a21190@alunos.ipca.pt)
 * @brief ficheiro que trata das operaçoes de que tem de ser executadas
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"header.h"

//FALTA RECEBER O INPUT NEM SEI SE E NECESSARIO WTF!!!!!!!!!!!!!
//PRECISA DE RECEBER O ID DO TRABALHO E PROCURAR PARA ADICIONAR UMA OPERAÇAO NO TRABALHO PROCURADO

void addOp()//ESTA VERSAO DE ADD ESTA HORRIVEL!!!!!!
{
    struct operacao* aux = NULL;

    struct operacao* add = malloc(sizeof(struct operacao));
    
    add->idOp = 1;
    add->next = NULL;
    

    if(headTr != NULL)
    {
        if(headTr->headOp == NULL)//se n existir nenhum trabalho o nosso novo passa a ser a head
            headTr->headOp == add;
        else
        {   //se ja existe vamos procurar ate ao ultimo e adicionar no final


            //o nosso auxiliar vai igualar à primeira operaçao do primeiro trabalho
            aux = headTr->headOp;

            //Após ser igual à primeira operaçao vai iterar até a ultima operaçao
            while(aux->next != NULL)
                aux = aux->next;

            //aqui atribuimos a última operação
            aux->next = add;
        }
    }
    
    

}

int removerOp(int idTr, int idOp)
{
    #pragma region VAR
    
    int flagTr = 0, flagOp = 0;

    struct trabalho* auxTrabalho = NULL;

    struct operacao* auxOperacao = NULL;

    struct operacao* auxOpAnt = NULL; 
    
    #pragma endregion


    if(headTr == NULL)
        return 1;//este return vai dizer que nao ha trabalhos
    else//Aqui vamos percorrer os trabalhos que temos e ver se o procurado existe
    {
         auxTrabalho = headTr;
        
        /**
         * @brief este ciclo verifica se existe o id do trabalho que procuramos
         * se de facto existir entao ele fica na posiçao em que esse id se encontra
         */
        while(auxTrabalho->next != NULL && flagTr != 1)
        {
            if(auxTrabalho->idTr == idTr)
                flagTr = 1;
            else
                auxTrabalho = auxTrabalho->next;  
        }


        //este return diz que apesar de existirem trabalhos o que identificamos esta errado
        if(flagTr == 0)
            return 2;


        auxOperacao = auxTrabalho->headOp; 

        /**
         * @brief este ciclo verifica se existe o id da operaçao que procuramos
         * se de facto existir entao ele fica na posiçao em que esse id se encontra
         */
        while(auxOperacao->next != NULL && flagOp != 1)
        {
            if(auxOperacao->idOp == idOp)
                flagOp = 1;
            else
            {
                auxOpAnt = auxOperacao;
                auxOperacao = auxOperacao->next;  
            }
        }

        //este return diz que apesar de existirem operacoes a que identificamos esta errada
        if(flagOp == 0)
            return 3;

        //Para remover se for o ultimo e so eliminar e o anterior ser igual a NULL
        if(auxOperacao->next == NULL)
        {
            auxOpAnt->next = NULL;
            //NAO SEI REMOVER A MEMORIA URGENTE AHHHHHHHHHHH!!!!!!
            free(auxOperacao);

        }else//Se for a meio entao tenho de ligar o anterior ao next antes de eliminar
        {
            auxOpAnt->next = auxOperacao->next;
            //ELIMINEI MAS ELIMINEI DA MEMORIA AHHHHHHHHHHHH!!!!!!
            free(auxOperacao);
        }


    }




    //desligar todas as flags de modo a manter o programa sem bugs
    flagTr = 0;
    flagOp = 0;
}



int addTr()
{
    struct trabalho* aux = NULL;
    int id = 1;
    struct trabalho* add = malloc(sizeof(struct trabalho));


    /**Estes dois tem de ser null porque:
     * ->Como isto se vai adicionar no fim o next tem de ser null porque n esta a apontar para nada
     * 
     * ->O headOp tem de ser Null porque ainda n definimos as operaçoes para o trabalho novo
    */
    add->headOp = NULL;
    add->next = NULL;

    //Utilizo o aux para n correr o risco de alterar o head dos trabalhos
    aux = headTr;

    //Este if verifica se existe ou nao algum trabalho
    if(aux == NULL)
    {
        add->idTr = 1;
        headTr = add;
    }
    else//Se ja existir algum trabalho vamos procurar o ultimo e adicionar o novo 
    {
        while(aux != NULL)//este ciclo trata de chegar ao ultimo node da lista ligada e conta os ids para identificar o novo trabalho
        {
            aux = aux->next;
            id++;
        }
        

        add->idTr = id;
        aux->next = add;
        
    }

}