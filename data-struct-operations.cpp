
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct agac{
    int sayi; 
    struct agac *sag; 
    struct agac *sol; 
};

struct agac* kucuk_deger(struct agac *dugum)
{
    if(dugum == NULL)
        return NULL;
    else if(dugum->sol != NULL)
        return kucuk_deger(dugum->sol); 
    return dugum;
}

struct agac* ara(struct agac *dugum, int x)
{
    if(dugum==NULL || dugum->sayi==x) 
        return dugum;
    else if(x>dugum->sayi) 
        return ara(dugum->sag, x);
    else 
        return ara(dugum->sol,x);
}


void yazdirma( struct agac* dugum, int bosluk )
{
  int i;
  if( dugum != NULL )
  {
    yazdirma( dugum->sol, bosluk + 3 );
    for( i = 0; i < bosluk; i++ )
 		printf(" ");
    printf("%d\n",dugum->sayi );
    yazdirma( dugum->sag, bosluk + 3 );
  }
  
}


struct agac* ekleme(struct agac* dugum) 
{ 
	int s;
    int dizi[10];
    for(s=0;s<10;s++){
		int randomm=1+rand()%101;
		if(s==0){
			dizi[s]=randomm;
			continue;
		}
		int dizuzun=(sizeof(dizi)/sizeof(int));
		int t=0;
		for(t;t<dizuzun;){
			if(dizi[t]==randomm){
				randomm=1+rand()%101;
				t=0;
			}else{
				t++;
			}
			
		}
		dizi[s]=randomm;
	}
	
    printf("R A N D O M   S A Y I L A R :\n\n");
    int y;
    for(y=0;y<10;y++){
    	printf("%d\t",dizi[y]);
	}
	printf("\n");
	printf("\n**************************************************\n");
	printf("\n");
    int i;
    for(i=0;i<10;i++){
    	if(i==0){
    		
    		struct agac* gecici_tutucu = (struct agac*)malloc(sizeof(struct agac));
   			gecici_tutucu->sayi = dizi[i]; 
    		gecici_tutucu->sol = NULL; 
    		gecici_tutucu->sag = NULL;
			dugum=gecici_tutucu;
    		continue;
    		
		}
		
    	struct agac* gecici_tutucu = (struct agac*)malloc(sizeof(struct agac));
   		gecici_tutucu->sayi = dizi[i]; 
    	gecici_tutucu->sol = NULL; 
    	gecici_tutucu->sag = NULL; 
	
   		struct agac* deger = dugum; 
  		struct agac* tut = NULL; 
  
   	 	while (deger != NULL) { 
   	 		
     		tut = deger; 
      	    if (dizi[i] < deger->sayi) 
      	    	deger = deger->sol; 
      	  	else if(dizi[i] >deger->sayi)
         	   deger = deger->sag;
			else
				return 0;
   	 	} 
  		if (dizi[i] < tut->sayi) 
        	tut->sol = gecici_tutucu; 
    	else
        	tut->sag = gecici_tutucu; 
	}
	return dugum;
}

struct agac* silmefonk(struct agac *dugum, int x)
{
    if(dugum==NULL)
        return NULL;
    if (x>dugum->sayi)
    {
    	dugum->sag = silmefonk(dugum->sag, x);
	}
    else if(x<dugum->sayi)
    {
    	dugum->sol = silmefonk(dugum->sol, x);
	}
    
	else{
    	
        if(dugum->sol==NULL && dugum->sag==NULL){
            free(dugum);
            return NULL;
        }
        else if(dugum->sol==NULL || dugum->sag==NULL){
            struct agac *gecici_tutucu;
            if(dugum->sol==NULL)
            {
            	gecici_tutucu = dugum->sag;
			}
            else
            {
            	gecici_tutucu = dugum->sol;	
			}    
            free(dugum);
            return gecici_tutucu;
        }
        else
        {
            struct agac *gecici_tutucu = kucuk_deger(dugum->sag);
            
            dugum->sayi = gecici_tutucu->sayi;
            
            dugum->sag = silmefonk(dugum->sag, gecici_tutucu->sayi);
        }
    }
    return dugum;
}

int main()
{
	srand(time(0));
	struct agac* dugum=NULL;
	dugum=ekleme(dugum);
	yazdirma(dugum,0);
	
	printf("\n****************\n");
	while(dugum != NULL){
		printf("\nKaldirilacak sayi giriniz : ");
		int sayii;
		scanf("%d",&sayii);
		if(ara(dugum,sayii) == NULL){
			printf("SAYI BULUNAMADI\n");
			continue;
		}
		dugum = silmefonk(dugum,sayii);
		yazdirma(dugum,0);
	}
	printf("AGAC TAMAMEN BOS\n");
	free(dugum);
    return 0;
}


