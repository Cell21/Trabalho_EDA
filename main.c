/**
 * @file Header.h
 * @author Celestino Machado (a21190@alunos.ipca.pt)
 * @brief ficheiro principal trata de chamar as funçoes
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "header.h"

void main()
{
    trabalho* headTr = NULL;
    operacao* op = NULL;
    maquina* mq = NULL;
    
    int idTr, idOp, idMq, tMq;
    printf("Id Trabalho:\n");
    scanf("%d", &idTr);

    addtr(headTr, idTr);

    printf("id Operacao:\n");
    scanf("%d", &idOp);

    addOp(headTr, idTr, idOp);

    printf("id Maquina");
    scanf("%d", &idMq);

    printf("Tempo da maquina");
    scanf("%d", &tMq);
    
    addMq(headTr, idTr, idOp, idMq, tMq);

    //escreve os trabalhos e operacoes que la existem
    printf("Trabalho:\n\t%d\n", headTr->idTr);
    op = headTr->headOp;
    printf("Operacao:\n\t%d\n", op->idOp);
    mq = op->headMq;
    printf("Maquina:\n\tid: %d\n\ttempo: %d", mq->id, mq->tempEx);
}