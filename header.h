/**
 * @file Header.h
 * @author Celestino Machado (a21190@alunos.ipca.pt)
 * @brief ficheiro que trata de guardar variaveis e estruturas 
 *        usadas ao longo do programa
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include<stdbool.h>

/**
 * @brief estrutura que guarda informaçao acerca de cada trabalho
 * 
 */
struct trabalho
{
    int idTr;
    //head das operaçoes deste trabalho
    struct operacoes* headOp = NULL;
    //apontador para o proximo trabalho
    struct trabalho* next = NULL;
};

struct trabalho* headTr = NULL;


/**
 * @brief guarda as operacoes e maquinas que sao necessarias para tal
 * 
 */
struct operacao
{
    char idOp;
    //apontador para o head das maquinas(??)

    //apontador para a proxima operaçao
    struct operacao* next = NULL;
};