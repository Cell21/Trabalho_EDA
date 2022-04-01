/**
 * @file Header.h
 * @author Celestino Machado (a21190@alunos.ipca.pt)
 * @brief ficheiro que trata das operaçoes de que tem de ser executadas para o ficheiro
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "header.h"



ficheiro* constroiStructFicheiro(trabalho* headTr)
{
    trabalho* auxTr = NULL;
    operacao* auxOp = NULL;
    maquina* auxMq = NULL;    
    

    ficheiro* headFile = NULL;
    ficheiro* addFile = malloc(sizeof(ficheiro));
    
    auxTr = headTr;



    /**
     * @brief esta funcao trata de construir uma estrutura com a seguinte base 
     * 
     *  ID do trabalho
     *  ID da operacao
     *  ID da maquina
     *  Tempo de execucao da maquina
     * 
     */
    while(auxTr->next != NULL)////Ciclo que trata de percorrer os trabalhos
    {
        
        auxOp = auxTr->headOp;
        
        while(auxOp->next != NULL)//Ciclo que trata de percorrer as operaçoes
        {
            auxMq = auxOp->headMq;

            while(auxMq != NULL)//Ciclo que trata de percorrer as maquinas
            {
                addFile->idTr = auxTr->idTr;
                addFile->idOp = auxOp->idOp;
                addFile->idMq = auxMq->id;
                addFile->tempoExec = auxMq->tempEx;
                addFile->next = NULL;

                if(headFile == NULL)
                    headFile = addFile;
                else
                {
                    while(addFile != NULL)
                        addFile = addFile->next;

                    addFile->next = addFile;

                }
                
                auxMq = auxMq->next;
            }

            auxOp = auxOp->next;

        }

        auxTr = auxTr->next;
    }


    return headFile;
}





bool escreveFicheiro(trabalho* headTr)
{
    ficheiro* auxficheiro = NULL;

    FILE* fp;

    if(headTr == NULL)
        return false;

    if(fp = fopen("Maquinetas.bin", "wb") == NULL);
        return false;

    
    auxficheiro = constroiStructFicheiro(headTr);

    while(auxficheiro != NULL)
    {
        fwrite(&auxficheiro, sizeof(ficheiro), 1, fp);

        auxficheiro = auxficheiro->next;
    }

    fclose(fp);

    return true;

}





trabalho* lerFicheiro(trabalho* headTr)
{
    FILE* fp;

    ficheiro* auxFile = NULL;

    headTr = NULL;

    if(fp = fopen("Maquinetas.bin", "wb") == NULL);
        return NULL;

    while(fread(&auxFile, sizeof(ficheiro), 1, fp) != NULL)
    {
        
        //primeiro os trabalhos
        if(headTr == NULL)
            addtr(headTr, auxFile->idTr);
        else if (procuraTrabalho(headTr, auxFile->idTr) != NULL)
        {
            
        }
            
            
    }
    
    
    
    //BASTANTES IFS????


    //Primeiro verifica se o id do trabalho ja existe se nao existir cria esse trabalho

}