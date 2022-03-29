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



/**
 * @brief 
 * 
 * @param h -> a head dos trabalhos
 * @param id -> id do trabalho a adicionar
 */
int addtr(struct trabalho* h, int id)
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
    add->idTr = id;
    add->next = NULL;

    if(h == NULL)
        h = add;
    else//Se nao for o primeiro vamos procurar o ultimo node para adicionar
    {
        aux = h;

        while(aux->next != NULL)//leva me até ao último node
            aux = aux->next;

        aux->next = add;
    }

    return  1;
}

/**
 * @brief esta funcao serve para procurar a head da operacao no trabalho desejado
 * 
 * @param h 
 * @param id 
 * @return struct operacao* 
 */
operacao* procuraCabecaOp(struct trabalho* h, int id)
{
    trabalho* auxTr = NULL;
    operacao* auxOp = NULL;
    
    auxTr = h;

    /**
     * @brief este if verifica se existe um trabalho 
     *        caso nao exista retorna NULL
     */
    if(auxTr == NULL) 
        return auxOp;

    /**
     * @brief Este ciclo verifica se existe o trabalho
     *        que procuramos caso nao exista o valor de
     *        auxOp = NULL
     */
    while(auxTr->next != NULL)
    {
        if(auxTr->idTr == id)
            auxOp = auxTr->headOp;

        auxTr = auxTr->next;
    }

    return auxOp;
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
        while(aux->next != NULL)
            aux = aux->next;

        aux->next = add;
        
    }

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

    if(auxMq == NULL)
        return 3;//msg erro n ha maquinas
    else
    {
        while(auxMq->next != NULL)
            auxMq = auxMq->next;

        auxMq = add;
    }
}



/**
 * @brief esta funcao serve para procurar a head da operacao no trabalho desejado
 * 
 * @param h 
 * @param id 
 * @return struct operacao* 
 */
maquina* procuraCabecaMq(struct operacao* hOp, int idOp)
{
    operacao* auxOp = NULL;
    maquina* auxMq = NULL;
    
    auxOp = hOp;

    /**
     * @brief este if verifica se existe um trabalho 
     *        caso nao exista retorna NULL
     */
    if(auxOp == NULL) 
        return auxMq;

    /**
     * @brief Este ciclo verifica se existe o trabalho
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


