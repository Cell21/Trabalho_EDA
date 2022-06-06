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
    int flagsair = 0, escolha = 0, idt = 0, ido = 0, idmq = 0, tempex = 0, msg = 0;
    
    headTr = lerFicheiro(headTr);

    //aqui tem um pequeno menu para gestao dos trabalhos, operacoes e maquinas
    while(flagsair = 0)
    {
        printf("O que pretende fazer?\n(1)->Adicionar Trabalho\n(2)->Adicionar Operacao\n(3)->Adicionar Maquina\n(4)->Remover Operacao\n(5)->Alterar Operacao\n(6)->Calculo do tempo maximo\n");
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1:
                printf("Qual o id do trabalho?");
                scanf("%d", &idt);
                msg = addtr(headTr, idt);
                break;
            case 2:
                printf("Qual o id do trabalho e o da operacao que quer adicionar?");
                scanf("%d %d", &idt, &ido);
                msg = addOp(headTr, idt, ido);
                break;
            case 3:
                printf("Qual o id do trabalho, da operacao e da maquina que quer adicionar? E o seu tempo de execucao.");
                scanf("%d %d %d %d", &idt, &ido, &idmq, &tempex);
                msg = addMq(headTr, idt, ido, idmq, tempex);
                break;
            case 4:
                printf("Qual o id do trabalho e o da operacao que quer remover?");
                scanf("%d %d", &idt, &ido);
                msg = removerOperacao(headTr, idt, ido);
                break;
            case 5:
                printf("Qual o id do trabalho e o da operacao que quer alterar? E o id novo.");
                scanf("%d %d %d", &idt, &ido, &idmq);
                msg = alterarOperacao(headTr, idt, ido);
                break;
            case 6:
                printf("Qual o trabalho que pretende calcular o tempo?");
                scanf("%d", &idt);
                msg = escreveTempoMax(headTr, idt);
                break;
        }
    }




    escreveFicheiro(headTr);
}