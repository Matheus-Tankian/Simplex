#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, char const *argv[]) {


	bool ilimit = false;
	int multiplas = 0;
	int l = 3, c = 5;//mude oas valores aq pra funcionar
	int vetMultA [0];
	int vetMultB [0];
	
	//ordem 
	//z
	//a
	//b
	// 
	// float matA[3][5] ={-4,-1,0,0,0,
	// 					2,3,1,0,12,
	// 					2,1,0,1,8};
					multiplas slucoes
					float matA[3][5] =	
					{-2, -4, 0, 0, 0,
					1, 2, 1, 0, 4,
					-1, 1, 0, 1, 1,};
					
					//ilimitado
					// 	float matA[3][5] =	
					// {-1, -3, 0, 0, 0,
					// 1, -2, 1, 0, 4,
					// -1, 1, 0, 1, 3,};
			
					// float matA[3][5] = {
					// 	-2000,-4000,0,0,0,
					// 	1,1,1,0,10,
					// 	15,25,0,1,200,
					// };




	system("cls");
	printf("|=====================TABLEAU SIMPLEX========================|\n");
	
	for(int i = 0; i < l; i++) 
	{
	
		for(int j = 0; j < c; j++) {
			printf("%.2f\t", matA[i][j]);
		
		}
		printf("\n");
	}
//====================================
	int auxS = 0;
	for(int i=0;i<c;i++){
	
		if(matA[0][i]!=0){
			//printf("\n %d \n",i);
			vetMultA[auxS] = i;
			auxS++;
		}
	}
 //    for(int i=0;i<auxS;i++){
	// 	printf("VetorA %d tam  %d \n",vetMultA[i],auxS);
	// }


	int newInt = 0;

	do
	{

	float menor1 = matA[0][0];
	int colunapivo = 0;

	//descobre quem eh o menor na linha Z ,escolhendo a coluna pivo
	for(int j = 0; j < c; j++) 
	{
		if(matA[0][j] < menor1)
		{
			menor1 = matA[0][j];
			colunapivo = j;
		}
		
	}
		//printf("Pivo coluna %d ", colunapivo);
		

    //======================ilimitado===============
    
    float vetaux[l-1];
    int contaux = 1;
    int verificailimite =  0;
    for(int i=0; i< l;i++){
	
         vetaux[i] = matA[contaux][colunapivo];
			
		 //printf("contuax %d ", contaux);
		
		contaux++;
	}
	
	
	for(int i=0;i<l-1;i++){
		if(vetaux[i]<0){
			verificailimite++;
		}
		//printf("\nVetor aux: %.2f %d \n",vetaux[i], verificailimite);
	}
	
	if(verificailimite == l-1){
		printf("\nILIMITADO\n");
		ilimit = true;
		exit(0);
	}
	
//===============================================
	

	float menor2 = 999999999.99999;


	int linhapivo = 1;

// escolhendo a linha pivo
	for(int i = 1; i < l; i++) {

		if(matA[i][colunapivo] == 0)
			continue;

		float aux = (matA[i][c - 1] / matA[i][colunapivo]);

		if(aux < 0)
			continue;

		if(aux < menor2) 
		{
			menor2 = aux;
			linhapivo = i;
		}
	}


	//salva a linha pivoh
	float linha[l];

	
	

	for(int i = 0; i < l; i++) 
		linha[i] = matA[i][colunapivo];


	

	//salva o elemento pivoh
	float elempivo = matA[linhapivo][colunapivo];

	for(int j = 0; j < c; j++) 
		matA[linhapivo][j] = matA[linhapivo][j] / elempivo;
	

	//salva a coluna pivoh
	float coluna[c];
		

	for(int j = 0; j < c; j++) 
		coluna[j] = (matA[linhapivo][j]);
	


//atualiza as novas linha
	for(int i = 0; i < l; i++)
	{
		if(i == linhapivo) 
			i++;
		

		if(i == l)
			break;

		for(int j = 0; j < c; j++) 
			matA[i][j] = (matA[i][j] - ((linha[i]) * (coluna[j])));
		
	}


	
	printf("\n");
	for(int i = 0; i < l; i++) 
	{


		for(int j = 0; j < c; j++) 
			printf("%.2f\t", matA[i][j]);
		
		printf("\n");
	}
	

	printf("|------------------------------------------------------------|\n");
	
	
	//verifica se tem que fazer uma nova interacao
	for(int j = 0; j < c; j++)
	{
		if((matA[0][j]) < 0) 
		{
			newInt = 1;
			break;
		}
		else
		{
			newInt = 0;
		}
	}
	
	} while (newInt == 1);
	
	
	//===========Multiplas==================
	
	
	
	int auxB = 0;

	int matB[c/2];
	for(int i=0;i<c/2;i++){
		matB[i] = matA[0][i];
		
	}
	
    	for(int i=0;i<c/2;i++){
    	//	printf("VetB %d \n",matB[i]);
		 if(matB[i]==0){
			multiplas++;
		}
	}
    
    
    
  
	
	
	//====================================
	
	printf("\n Solucao: \n");
	
	if(multiplas==auxS){
		printf("\n Multiplas Solucoes\n");
	}
	

	for(int i = 0; i < l; i++) {
		printf(" %.2f", matA[i][c - 1]);
		printf("\n");
	}
	

	return 0;
}