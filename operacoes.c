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


#pragma region Funções de Adicionar
/**
 * @brief 
 * 
 * @param hTr -> a head dos trabalhos
 * @param id -> id do trabalho a adicionar
 */
int addtr(struct trabalho* hTr, int idTr)
{
    trabalho* aux = NULL;

    trabalho* add = malloc(sizeof(struct trabalho));


    /**
     * @brief aqui estou a criar o novo node da lista de trabalhos
     * esta funçao pode ser chamada por comando ou reutilizada para 
     * ler ficheiros.
     * 
     */
    add->headOp = NULL;
    add->idTr = idTr;
    add->next = NULL;

    aux = procuraTrabalho(hTr, idTr);//objetivo devolver NULL

    if(aux != NULL)
        return 1;//ja existe esse trabalho

    if(hTr == NULL)
        hTr = add;
    else//Se nao for o primeiro vamos procurar o ultimo node para adicionar
    {
        aux = hTr;

        while(aux->next != NULL)//leva me até ao último node
            aux = aux->next;

        aux->next = add;
    }

    return  2;//adicionou com sucesso
}









/**
 * @brief esta funcao adiciona uma operacao
 * 
 * @param ht  -> recebe a head dos trabalhos que vai ser usada numa funcao
 * @param idt -> recebe o id do trabalho que procuramos para ser usado na mesma funcao que o hT
 * @param ido -> recebe o id das operacoes de modo a procurar o id dentro daquela lista de operacoes
 * @return struct operacao* 
 */
int addOp(struct trabalho* ht, int idt, int ido)
{
    operacao* aux = NULL;

    operacao* add = malloc(sizeof(struct operacao));

    add->headMq = NULL;
    add->idOp = ido;
    add->next = NULL;

    if(ht == NULL)//Nao existem trabalhos
        return 1;


    /**
     * @brief esta variavel toma o valor da cabeca que procuramos
     *        no trabalho desejado 
     */
    aux = procuraCabecaOp(ht, idt);


    
    /**
     * @brief este if verifica se existe algum node se nao existir adicionamos no inicio
     * 
     */
    if(aux == NULL)
        aux = add;
    else
    {
        if(procuraOperacao(aux, ido) != NULL)
            return 2;//Ja existe essa operaçao

        while(aux->next != NULL)
            aux = aux->next;

        aux->next = add;
        
    }


    return 3;//adicionou com sucesso
}









/**
 * @brief esta funcao deve 
 * 
 * @param ht 
 * @param idTr 
 * @param idOp 
 * @param idMq 
 * @return struct maquina* 
 */
int addMq(struct trabalho* ht, int idTr, int idOp, int idMq, int TmpMq)
{
    maquina* auxMq = NULL;

    maquina* add = malloc(sizeof(struct maquina));

    operacao* auxOp = NULL;

    add->id = idMq;
    add->tempEx = TmpMq;
    add->next = NULL;

    if(ht == NULL)
        return 1;//msg de erro n ha trabalhos


    auxOp = procuraCabecaOp(ht, idTr);//Esta funcao obtem a head das operacoes num trabalho
    
    if(auxOp == NULL)
        return 2;//msg erro n ha operacoes

    auxMq = procuraCabecaMq(auxOp, idOp);//Esta funcao obtem a head das maquinas nesta operacao 

    if(procuraMaquina(auxMq, idMq) != NULL)
        return 4;//Essa maquina ja existe


    if(auxMq == NULL)
        auxMq = add;
    else
    {
        while(auxMq->next != NULL)
            auxMq = auxMq->next;

        auxMq->next = add;
    }
}

#pragma endregion






#pragma region Funções de remoção


/**
 * @brief Esta funcao remove uma operacao 
 * 
 * @param headTr -> cabeca da lista dos trabalhos
 * @param idTr -> Id do trabalho que procuramos
 * @param idOp -> id da operacao que procuramos para remover
 * @return int -> retorna ints de forma a saber se foi bem sucedido ou como msg de erro
 */
int removerOperacao(trabalho* headTr, int idTr, int idOp)
{
    operacao* opAnterior = NULL;
    operacao* opPretendida = NULL;
    trabalho* auxTr = NULL;


    int flagRem = 0;


    if(headTr == NULL)
        return 1;    
    
    opPretendida = procuraCabecaOp(headTr, idTr);
    
    //ao igualar o anterior a pretendida aqui estou a preservar o valor da head para uma comparação
    opAnterior = opPretendida;
    
    
    
    if(opPretendida == NULL)
        return 2;
    else
    {
        while(opPretendida->next != NULL || flagRem == 1)//procurar a operacao que pretendo remover e a anterior
        {
            if(opPretendida->idOp == idOp)
                flagRem = 1;
            else
            {
                opAnterior = opPretendida;

                opPretendida = opPretendida->next;
            }

        }

        //Agora pretendo remover a operacao
        
        if(opAnterior == opPretendida)//Este if verifica se o pretendido e o primeiro SO ACONTECE SE FOR O PRIMEIRO
        {
            auxTr = procuraTrabalho(headTr, idTr);

            auxTr->headOp = opPretendida->next;

            free(opPretendida);//libertar o espaco de memoria utilizado pela operacao pretendida
        
        
        }
        else if(opPretendida->next == NULL)//vou verificar se e o ultimo node
        {
            opAnterior->next = NULL;

            free(opPretendida);//libertar o espaco de memoria utilizado pela operacao pretendida
        }
        else//se for um node no meio da lista 
        {
            opAnterior->next = opPretendida->next;

            free(opPretendida);//libertar o espaco de memoria utilizado pela operacao pretendida
        }
    }
}
#pragma endregion







#pragma region Funções de procura



/**
 * @brief esta funcao serve para procurar um trabalho em especifico
 * 
 * @param h -> head dos trabalhos 
 * @param id -> id do trabalho que procuramos
 * @return struct operacao* 
 */
trabalho* procuraTrabalho(trabalho* hTr, int idTr)
{
    trabalho* auxTr = NULL;
    
    int flagTr = 0;
    
    auxTr = hTr;

    /**
     * @brief este if verifica se existe um trabalho 
     *        caso nao exista retorna NULL
     */
    if(auxTr == NULL) 
        return auxTr;

    /**
     * @brief Este ciclo verifica se existe o trabalho
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxTr->next != NULL || flagTr == 1)
    {
        if(auxTr->idTr == idTr)
            flagTr = 1;
        else
            auxTr = auxTr->next;
    }


    /**
     * @brief Se a flag estiver ativada entao encontramos o trabalho e vamos devolve-lo
     *        se nao encontrarmos vamos devolver NULL
     * 
     */
    if(flagTr == 1)
        return auxTr;
    else    
        return NULL;
}







/**
 * @brief esta funcao serve para procurar uma operacao em especifico 
 * 
 * @param h -> head das operacoes 
 * @param id -> id da operacao que procuramos
 * @return struct operacao* 
 */
operacao* procuraOperacao(operacao* hOp, int idOp)
{
    operacao* auxOp  = NULL;
    
    int flagOp = 0;
    
    auxOp = hOp;

    /**
     * @brief este if verifica se existe um trabalho 
     *        caso nao exista retorna NULL
     */
    if(auxOp == NULL) 
        return auxOp;

    /**
     * @brief Este ciclo verifica se existe a operacao
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxOp->next != NULL || flagOp == 1)
    {
        if(auxOp->idOp == idOp)
            flagOp = 1;
        else
            auxOp = auxOp->next;
    }


    /**
     * @brief Se a flag estiver ativada entao encontramos a operacao e vamos devolve-la
     *        se nao encontrarmos vamos devolver NULL
     * 
     */
    if(flagOp == 1)
        return auxOp;
    else    
        return NULL;
}






/**
 * @brief esta funcao serve para procurar a head da operacao no trabalho desejado
 * 
 * @param h -> head dos trabalhos 
 * @param id -> id do trabalho que procuramos
 * @return struct operacao* 
 */
operacao* procuraCabecaOp(trabalho* hTr, int idTr)
{
    trabalho* auxTr = NULL;
    operacao* auxOp = NULL;
    
    auxTr = hTr;

    /**
     * @brief este if verifica se existe um trabalho 
     *        caso nao exista retorna NULL
     */
    if(auxTr == NULL) 
        return auxOp;

    /**
     * @brief Este ciclo verifica se existe a operacao
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxTr->next != NULL)
    {
        if(auxTr->idTr == idTr)
            auxOp = auxTr->headOp;

        auxTr = auxTr->next;
    }

    return auxOp;
}





/**
 * @brief esta funcao serve para procurar uma operacao em especifico 
 * 
 * @param h -> head das maquinas 
 * @param id -> id da maquina que procuramos
 * @return struct operacao* 
 */
maquina* procuraMaquina(maquina* hMq, int idMq)
{
    maquina* auxMq  = NULL;
    
    int flagMq = 0;
    
    auxMq = hMq;

    /**
     * @brief este if verifica se existe uma maquina 
     *        caso nao exista retorna NULL
     */
    if(auxMq == NULL) 
        return auxMq;

    /**
     * @brief Este ciclo verifica se existe a maquina
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxMq->next != NULL || flagMq == 1)
    {
        if(auxMq->id == idMq)
            flagMq = 1;
        else
            auxMq = auxMq->next;
    }


    /**
     * @brief Se a flag estiver ativada entao encontramos a maquina e vamos devolve-la
     *        se nao encontrarmos vamos devolver NULL
     * 
     */
    if(flagMq == 1)
        return auxMq;
    else    
        return NULL;
}





/**
 * @brief esta funcao serve para procurar a head da maquina na operacao desejada
 * 
 * @param h -> Cabeca da operação
 * @param id -> Id da operação
 * @return struct operacao* 
 */
maquina* procuraCabecaMq(struct operacao* hOp, int idOp)
{
    operacao* auxOp = NULL;
    maquina* auxMq = NULL;
    
    auxOp = hOp;

    /**
     * @brief este if verifica se existe uma operacao 
     *        caso nao exista retorna NULL
     */
    if(auxOp == NULL) 
        return auxMq;

    /**
     * @brief Este ciclo verifica se existe a operacao
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxOp->next != NULL)
    {
        if(auxOp->idOp == idOp)
            auxMq = auxOp->headMq;

        auxOp = auxOp->next;
    }

    return auxMq;
}

#pragma endregion


#pragma region Funções de alteração

int alterarOperacao(trabalho* headTr, int idTr, int idOp, int idMq)
{
    operacao* auxOp = NULL;
    maquina* auxMq = NULL;


    //Primeiro procurar a operaçao pretendida 
    auxOp = procuraOperacao(headTr, idOp);

    auxMq = procuraMaquina(auxOp, idMq);

    

    //apos encontrar a operaçao mostrar as maquinas e perguntar o que pretende mudar
}
#pragma endregion


#pragma region Contas




#pragma endregion