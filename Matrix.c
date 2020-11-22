#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matris_yaz(int **diz,int satir,int sutun){
	for(int i=0;i<satir;i++){
		for(int j=0;j<sutun;j++){
			printf(" %d ",*(*(diz+i)+j));
		}
		printf("\n");
	}
}

void dinamik_yap(int *one,int **two,int uzun){
	for(int i=0;i<uzun;i++){
		*(*two+i)=*(one+i);
	}
}

void tek_boyut(int *dizi,int uzun){
	for(int i=0;i<uzun;i++){
		printf(" %d ",dizi[i]);
	}
}


void matris_carp(int **one,int one_sat,int one_sut,int **two,int two_sat,int two_sut,int **carp,int carp_sat,int carp_sut){
	
	if(one_sut!=two_sat){
		printf("\nSatir ve sutun esit degil\n");
	}else if(one_sat!=carp_sat && two_sut!=carp_sut){
		printf("\ncarpým Satir ve sutun esit degil\n");
	}else{
		for(int i=0;i<one_sat;i++){
			for(int j=0;j<two_sut;j++){
				carp[i][j]=0;
				for(int a=0;a<one_sut;a++){
					carp[i][j]=carp[i][j]+one[i][a]*two[a][j];
				}
			}
		}
	}
}


void matris_ol(int ***diz,int satir,int sutun){
	*diz=(int**)(malloc(sizeof(int*)*satir));
	srand(time(NULL));
	for(int i=0;i<satir;i++){
		*(*diz+i)=(int*)(malloc(sizeof(int)*sutun));
		for(int j=0;j<sutun;j++){
			*(*(*diz+i)+j)=rand()%100;
		}
	}
}




int main(){
	
	
	// normal dizi dinamik dizi yapma
	
	printf("\n\n");
	
	int dizi[]={2,4,6,7,8};
	
	int *dinamik;
	int uzunluk=5;
	
	dinamik_yap(dizi,&dinamik,uzunluk);
	
	tek_boyut(dinamik,uzunluk);
	
	//------------------------------
	
	// 1. M A T R Ý S
	
	int **diz;
	matris_ol(&diz,5,4);
	matris_yaz(diz,5,4);
	
	// 2.  M A T R Ý S
	
	printf("\n 2. matris \n");
	int **two_diz;
	matris_ol(&two_diz,4,2);
	matris_yaz(two_diz,4,2);
	
	// M A T R Ý S    Ç A R P I M I 
	
	printf("\n M A T R I S   C A R P I M\n");
	int **carpim;
	matris_ol(&carpim,5,2);
	
	matris_carp(diz,5,4,two_diz,4,2,carpim,5,2);
	
	matris_yaz(carpim,5,2);

	
	
}
