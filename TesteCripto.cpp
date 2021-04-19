#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>


using namespace std;

char v[21][5500];			//Vetor em hexadecimal
int c[21][20100];			//Vetor em binario
char lixo[2];				//Vetor para armazenar os \n do arquivo de chaves
int reMonoBit[21];			//Resultado do monobit
int rePokerTest[21][16];	//resultado do pokertest

//Resutados dos testes de Runtest
int reRunTest1[21][2];
int reRunTest2[21][2];
int reRunTest3[21][2];
int reRunTest4[21][2];
int reRunTest5[21][2];
int reRunTest6[21][2];

//Resultados do teste longrunteste
int reLongRunTest[21][2];

//Funcao de leitura do arquivo "Chaves.txt"
void input(){
	FILE * sc = fopen("Chaves.txt","r");
	for(int i = 0 ; i<20; i++){
		fgets(v[i],5003,sc);
		fgets(lixo,2,sc);
		//printf("\n chave %d = %s",i,v[i]);
	}	
		fclose(sc);
}

//Funcao de print de hexadecimal
void printHEX(){
	for(int i=1;i<=5000;i++){
		printf("%c",v[0][i]);
	}
}

//Funcao de print de binario
void printBIN(){
	
	for(int j=0; j<20;j++){
			printf("\nChave %d = \n",j+1);
		for(int i=0;i<20000;i++){
			printf("%d",c[j][i]);
		}
	}			
}

//Funcao de converter hexadecimal para binario
void convert(){
	for(int j = 0 ; j<20 ; j++){
		int ctv = 0;
		
		for(int i = 1; i <= 5000 ; i++)
	 	{
		    if(v[j][i] == '0')
		    {
		        c[j][ctv] = 0;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 0;
		    	ctv = ctv + 4;
		    }
		    else if(v[j][i] == '1')
		    {
		        c[j][ctv] = 0;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '2')
		    {
		        c[j][ctv] = 0;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '3')
		    {
		       	c[j][ctv] = 0;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '4')
		    {
		       	c[j][ctv] = 0;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '5')
		    {
		    	c[j][ctv] = 0;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '6')
		    {
		    	c[j][ctv] = 0;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '7')
		    {
		    	c[j][ctv] = 0;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '8')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == '9')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'A')
		    {
		        c[j][ctv] = 1;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'B')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 0;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'C')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'D')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 0;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'E')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 0;
		        ctv = ctv + 4;
		    }
		    else if(v[j][i] == 'F')
		    {
		    	c[j][ctv] = 1;
		        c[j][ctv+1] = 1;
		        c[j][ctv+2] = 1;
		        c[j][ctv+3] = 1;
		        ctv = ctv + 4;
		    }
	  	}
	  	//printf("contador %d", ctv);
	}
}

//Funcao de teste MonoBot
void monobit(){
	FILE * re = fopen("Resultados MonoBit.txt","w");
	fprintf(re,"========== Resultados MonoBit ==========");
	for(int j=0; j<20;j++){		
		for(int i=0;i<20000;i++){
			if(c[j][i] == 1){
				reMonoBit[j] = reMonoBit[j] + 1;
			}
		}
		

		
		//printf("\n Na chave %d existem %d numeros 1 ",j+1,reMonoBit[j]);
		fprintf(re,"\n-Na chave %d existem %d numeros 1",j+1,reMonoBit[j]);
		if(reMonoBit[j] > 9654 && reMonoBit[j] < 10346){
			fprintf(re,"\nA chave %d foi aprovada no teste\n",j+1);
		}
		else{
			fprintf(re,"\nA chave %d foi reprovada no teste\n",j+1);
		}
	}		
		fclose(re);
}

//Funcao de teste PokerTest
void pokerTest(){
	FILE * re = fopen("Resultados PokerTest.txt","w");
	fprintf(re,"========== Resultados PokerTest ==========");
  for(int i=0;i<20;i++){
  	
    for(int j=1; j<=5000; j++){
      if(v[i][j] == '0'){
        rePokerTest[i][0] = rePokerTest[i][0]+1;
      }  
      if(v[i][j] == '1'){
        rePokerTest[i][1] = rePokerTest[i][1]+1;
      }  
      if(v[i][j] == '2'){
        rePokerTest[i][2] = rePokerTest[i][2]+1;
      }  
      if(v[i][j] == '3'){
        rePokerTest[i][3] = rePokerTest[i][3]+1;
      }  
      if(v[i][j] == '4'){
        rePokerTest[i][4] = rePokerTest[i][4]+1;
      }  
      if(v[i][j] == '5'){
        rePokerTest[i][5] = rePokerTest[i][5]+1;
      }  
      if(v[i][j] == '6'){
        rePokerTest[i][6] = rePokerTest[i][6]+1;
      }  
      if(v[i][j] == '7'){
        rePokerTest[i][7] = rePokerTest[i][7]+1;
      }  
      if(v[i][j] == '8'){
        rePokerTest[i][8] = rePokerTest[i][8]+1;
      }  
      if(v[i][j] == '9'){
        rePokerTest[i][9] = rePokerTest[i][9]+1;
      }  
      if(v[i][j] == 'A'){
        rePokerTest[i][10] = rePokerTest[i][10]+1;
      }  
      if(v[i][j] == 'B'){
        rePokerTest[i][11] = rePokerTest[i][11]+1;
      }  
      if(v[i][j] == 'C'){
        rePokerTest[i][12] = rePokerTest[i][12]+1;
      }  
      if(v[i][j] == 'D'){
        rePokerTest[i][13] = rePokerTest[i][13]+1;
      }  
      if(v[i][j] == 'E'){
        rePokerTest[i][14] = rePokerTest[i][14]+1;
      }  
      if(v[i][j] == 'F'){
        rePokerTest[i][15] = rePokerTest[i][15]+1;
      }  
    }
   }
   /*
   for(int i = 0 ; i<20; i++){
   	printf("\n Chave %d",i);
   	printf("\n Qtd de 0 = %d",rePokerTest[i][0]);
	printf("\n Qtd de 1 = %d",rePokerTest[i][1]);
	printf("\n Qtd de 2 = %d",rePokerTest[i][2]);
	printf("\n Qtd de 3 = %d",rePokerTest[i][3]);
	printf("\n Qtd de 4 = %d",rePokerTest[i][4]);
	printf("\n Qtd de 5 = %d",rePokerTest[i][5]);
	printf("\n Qtd de 6 = %d",rePokerTest[i][6]);
	printf("\n Qtd de 7 = %d",rePokerTest[i][7]);
	printf("\n Qtd de 8 = %d",rePokerTest[i][8]);
	printf("\n Qtd de 9 = %d",rePokerTest[i][9]);
	printf("\n Qtd de A = %d",rePokerTest[i][10]);
	printf("\n Qtd de B = %d",rePokerTest[i][11]);
	printf("\n Qtd de C = %d",rePokerTest[i][12]);
	printf("\n Qtd de D = %d",rePokerTest[i][13]);
	printf("\n Qtd de E = %d",rePokerTest[i][14]);					
	printf("\n Qtd de F = %d",rePokerTest[i][15]);	   
   }
  
   for(int i = 0 ; i<20; i++){
   	fprintf(re,"\n-Chave %d",i);
   	fprintf(re,"\nQtd de 0 = %d",rePokerTest[i][0]);
	fprintf(re,"\nQtd de 1 = %d",rePokerTest[i][1]);
	fprintf(re,"\nQtd de 2 = %d",rePokerTest[i][2]);
	fprintf(re,"\nQtd de 3 = %d",rePokerTest[i][3]);
	fprintf(re,"\nQtd de 4 = %d",rePokerTest[i][4]);
	fprintf(re,"\nQtd de 5 = %d",rePokerTest[i][5]);
	fprintf(re,"\nQtd de 6 = %d",rePokerTest[i][6]);
	fprintf(re,"\nQtd de 7 = %d",rePokerTest[i][7]);
	fprintf(re,"\nQtd de 8 = %d",rePokerTest[i][8]);
	fprintf(re,"\nQtd de 9 = %d",rePokerTest[i][9]);
	fprintf(re,"\nQtd de A = %d",rePokerTest[i][10]);
	fprintf(re,"\nQtd de B = %d",rePokerTest[i][11]);
	fprintf(re,"\nQtd de C = %d",rePokerTest[i][12]);
	fprintf(re,"\nQtd de D = %d",rePokerTest[i][13]);
	fprintf(re,"\nQtd de E = %d",rePokerTest[i][14]);					
	fprintf(re,"\nQtd de F = %d",rePokerTest[i][15]);	   
   }
  */
    
  	float teste [21];
	for(int i = 0; i < 20; i++){
	   	float somatoria = 0;
	    for(int j = 0; j <= 15; j++){	
	       somatoria = somatoria + pow(rePokerTest[i][j],2);
	     }
     teste[i] = 16.0/5000.0 * somatoria;
     teste[i] = teste[i] - 5000;
     
     //printf("\n\n A chave %d  resultou em: %f",i,teste[i]);
     fprintf(re,"\n-A chave %d  resultou em: %f",i+1,teste[i]);
     
     if(1.03 < teste[i] && teste[i] <57.7){
     	fprintf(re,"\nChave Aprovada");
	 }
	 else{
	 	fprintf(re,"\nChave Reprovada");
	 }
   }
   
	fclose(re);
}
	 /*
void pokerTest2(){
	int cont[21][15];
	for(int i=0;i<20;i++){
    	for(int j=0; j<19996; j= j+ 4){
    		if(c[i][j] == 0 && c[i][j+1] == 0 && c[i][j+2] == 0 && c[i][j+3] == 0){
			 	cont[i][0]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 0 && c[i][j+2] == 0 && c[i][j+3] == 1){
				cont[i][1]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 0 && c[i][j+2] == 1 && c[i][j+3] == 0){
				cont[i][2]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 0 && c[i][j+2] == 1 && c[i][j+3] == 1){
				cont[i][3]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 0 && c[i][j+3] == 0){
				cont[i][4]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 0 && c[i][j+3] == 1){
				cont[i][5]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 1 && c[i][j+3] == 0){
				cont[i][6]++;
			
			}else if(c[i][j] == 0 && c[i][j+1] == 1 && c[i][j+2] == 1 && c[i][j+3] == 1){
				cont[i][7]++;
				
			}else if(c[i][j] == 1 && c[i][j+1] == 0 && c[i][j+2] == 0 && c[i][j+3] == 0){
				cont[i][8]++;
				
			}else if(c[i][j] == 1 && c[i][j+1] == 0 && c[i][j+2] == 0 && c[i][j+3] == 1){
				cont[i][9]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 0 && c[i][j+2] == 1 && c[i][j+3] == 0){
				cont[i][10]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 0 && c[i][j+2] == 1 && c[i][j+3] == 1){
				cont[i][11]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 1 && c[i][j+2] == 0 && c[i][j+3] == 0){
				cont[i][12]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 1 && c[i][j+2] == 0 && c[i][j+3] == 1){
				cont[i][13]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 1 && c[i][j+2] == 1 && c[i][j+3] == 0){
				cont[i][14]++;
			
			}else if(c[i][j] == 1 && c[i][j+1] == 1 && c[i][j+2] == 1 && c[i][j+3] == 1){
				cont[i][15]++;
			}
		}
	}

	float div= 0.0032;
	float teste [21];
	for(int i = 0; i <= 20; i++){
		float somatoria = 0;
		for(int j = 0; j <= 15; j++){	
		    somatoria = somatoria + (cont[i][j]*cont[i][j]);
		}
	    teste[i] = (16.0000/5000.0000) * somatoria - 5000;

		printf("\nTeste %f",teste[i]);


 }
	}*/
 

 
 
 
 
 
 
//Funcao de teste RunTest
void runTest(){
	FILE * re = fopen("Resultados RunTest.txt","w");
	fprintf(re,"========== Resultados RunTest ==========");
	
	
    for (int i = 0; i < 20; i++)
    {

		int crv = 0;
		while(crv < 20000){
			
			int count1=0;
	    	while(c[i][crv] == 1){
				count1++;
				crv++;
			}
			
			int count0=0;
	  		while(c[i][crv] == 0){
				count0++;
				crv++;
			}
			
			//Conts 1
			if(count1 == 1){
	    		reRunTest1[i][1] = reRunTest1[i][1] +1;
			}
	    	if(count1 == 2){
	    		reRunTest2[i][1] = reRunTest2[i][1] +1;
			}
	    	if(count1 == 3){
	    		reRunTest3[i][1] = reRunTest3[i][1] +1;
			}
			if(count1 == 4){
	    		reRunTest4[i][1] = reRunTest4[i][1] +1;
			}
			if(count1 == 5){
	    		reRunTest5[i][1] = reRunTest5[i][1] +1;
			}
			if(count1 >= 6 ){
	    		reRunTest6[i][1] = reRunTest6[i][1] +1;
			}
			
			//Conts 0
			if(count0 == 1){
	    		reRunTest1[i][0] = reRunTest1[i][0] +1;
			}
			if(count0 == 2){
	    		reRunTest2[i][0] = reRunTest2[i][0] +1;
			}
	    	if(count0 == 3){
	    		reRunTest3[i][0] = reRunTest3[i][0] +1;
			}
			if(count0 == 4){
	    		reRunTest4[i][0] = reRunTest4[i][0] +1;
			}
			if(count0 == 5){
	    		reRunTest5[i][0] = reRunTest5[i][0] +1;
			}
			if(count0 >= 6 ){
	    		reRunTest6[i][0] = reRunTest6[i][0] +1;
			}
    	
    	}
	}

    for (int i = 0; i < 20; i++)
    {
    	int aprovado = 0;
		fprintf(re,"\n\n Chave %d",i+1);
		fprintf(re,"\n Numero de sequencias de tamanho 1:");
		fprintf(re,"\n 0 = %d",reRunTest1[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest1[i][1]);
		if(reRunTest1[i][1]>2267 && reRunTest1[i][1]<2733 && reRunTest1[i][0]>2267 && reRunTest1[i][0]<2733){
			aprovado++;
		}
		
		
		fprintf(re,"\n Numero de sequencias de tamanho 2:");
		fprintf(re,"\n 0 = %d",reRunTest2[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest2[i][1]);
		if(reRunTest2[i][1]>1079 && reRunTest2[i][1]<1421 && reRunTest2[i][0]>1079 && reRunTest2[i][0]<1421){
			aprovado++;
		}
		
		fprintf(re,"\n Numero de sequencias de tamanho 3:");
		fprintf(re,"\n 0 = %d",reRunTest3[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest3[i][1]);
		if(reRunTest3[i][1]>502 && reRunTest3[i][1]<748 && reRunTest3[i][0]>502 && reRunTest3[i][0]<748){
			aprovado++;
		}
		
		fprintf(re,"\n Numero de sequencias de tamanho 4:");
		fprintf(re,"\n 0 = %d",reRunTest4[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest4[i][1]);
		if(reRunTest4[i][1]>223 && reRunTest4[i][1]<402 && reRunTest4[i][0]>223 && reRunTest4[i][0]<402){
			aprovado++;
		}
		
		
		fprintf(re,"\n Numero de sequencias de tamanho 5:");
		fprintf(re,"\n 0 = %d",reRunTest5[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest5[i][1]);
		if(reRunTest5[i][1]>90 && reRunTest5[i][1]<223 && reRunTest5[i][0]>90 && reRunTest5[i][0]<220){
			aprovado++;
		}
		
		fprintf(re,"\n Numero de sequencias de tamanho 6+:");
		fprintf(re,"\n 0 = %d",reRunTest6[i][0]);
		fprintf(re,"\n 1 = %d",reRunTest6[i][1]);
		if(reRunTest6[i][1]>90 && reRunTest6[i][1]<223 && reRunTest6[i][0]>90 && reRunTest6[i][0]<220){
			aprovado++;
		}
		if(aprovado == 6){
			fprintf(re,"\n  Chave Aprovada");
		}else{
			fprintf(re,"\n  Chave Reprovada");
		}
	}
	fclose(re);
}

//Funcao de teste LogRunTest
void LongRunTest(){
	
	FILE * re = fopen("Resultados LogRunTest.txt","w");
	fprintf(re,"========== Resultados RunTest ==========");
	
    for (int i = 0; i < 20; i++)
    {

		int crv = 0;
		while(crv < 20000){
			
			int count1=0;
	    	while(c[i][crv] == 1 && crv < 20000){
				count1++;
				crv++;
			}
			
			int count0=0;
	  		while(c[i][crv] == 0 && crv < 20000){
				count0++;
				crv++;
			}
		
			if(count0 >= 34){
				reLongRunTest[i][0] = reLongRunTest[i][0] + 1;
			}
			if(count1 >= 34){
				reLongRunTest[i][1] = reLongRunTest[i][1] + 1;
			}
		}
	}
	
	for (int i = 0; i < 20; i++)
    {
		fprintf(re,"\n\n Chave %d",i+1);
		fprintf(re,"\n Numero de sequencias de tamanho 34+:");
		fprintf(re,"\n 0 = %d",reLongRunTest[i][0]);
		fprintf(re,"\n 1 = %d",reLongRunTest[i][1]);
		if( reLongRunTest[i][0] == 0 && reLongRunTest[i][1] == 0){
			fprintf(re,"\nChave Aprovada");
		}else{
			fprintf(re,"\nChave Reprovada");
		}
	}
	fclose(re);
}

//Funcao de print binario em arquivo
void fprintBIN(){
    FILE *file;
  file = fopen("binarios.txt", "w");

    for(int j=0; j<20;j++){
            fprintf(file,"\n\nChave %d = \n",j+1);
        for(int i=0;i<20000;i++){
            fprintf(file,"%d",c[j][i]);
        }
    }

  fclose(file);
}

int main(){

	input();
	convert();
	//printHEX();
	//printBIN();
	//fprintBIN();
	monobit();
	//pokerTest2();
	pokerTest();
	runTest();
	LongRunTest();


}
