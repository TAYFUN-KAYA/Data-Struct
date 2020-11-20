#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hucre{
	int icerik;
	struct hucre *sonraki;
};

// dügüm oluþturma +
struct hucre* hucre_olustur(int icerik){
	struct hucre *a;
	a=(struct hucre*)(malloc(sizeof(struct hucre)));
	if(a==NULL){
		printf("Heapten yer ayrýlamadý...\n");
		exit(1);
	}
	a->icerik=icerik;
	a->sonraki=NULL;
	return a;
}


// Liste basýna eleman ekleme +
void liste_basina(int icerik,struct hucre **liste_basi){
	struct hucre *a=hucre_olustur(icerik);
	a->sonraki=*liste_basi;
	*liste_basi=a;
}

// Liste sonuna eleman ekleme +
void liste_sonu(int icerik,struct hucre **liste_basi){
	struct hucre *a=hucre_olustur(icerik);
	if(*liste_basi==NULL){
		a->sonraki=*liste_basi;
		*liste_basi=a;
	}else{
		struct hucre *x=*liste_basi;
		while(x->sonraki!=NULL){
			x=x->sonraki;
		}
		x->sonraki=a;
	}
}

// sýralý listeyee eleman ekleme +

void liste_sirali_ekle(int icerik,struct hucre **liste_basi){
	struct hucre *a,*b,*eklenen;
	b=*liste_basi;
	while(b!=NULL && b->icerik<=icerik){
		if(b->icerik==icerik) return ;
		a=b;
		b=b->sonraki;
	}
	eklenen=hucre_olustur(icerik);
	if(b==*liste_basi){
		eklenen->sonraki=*liste_basi;
		*liste_basi=eklenen;
	}
	else{
		a->sonraki=eklenen;
		eklenen->sonraki=b;
	}
}

// Listeden düðüm silme +
void liste_sil(int icerik,struct hucre **liste_basi){
	struct hucre *temp=*liste_basi;
	struct hucre *once;
	while(temp!=NULL && temp->icerik!=icerik){
		once=temp;
		temp=temp->sonraki;
	}
	if(temp==NULL) return ;
	else{
		if(temp==*list_basi)
			*liste_basi=*liste_basi->sonraki;
		else
			once->sonraki=temp->sonraki;
		free(temp);
	}
}

// sýralama iþlemleri

void liste_sirala(struct hucre **liste_basi){
	struct hucre *a,*b,*c,*d;
	if(*liste_basi == NULL || *liste_basi->sonraki==NULL) return ;
	
	d=*liste_basi->sonraki;
	*liste_basi->sonraki=NULL;
	
	while(d!=NULL){
		c=d;
		d=d->sonraki;
		b=*liste_basi;
		while(b!=NULL && b->icerik < c->icerik){
			a=b;
			b=b->sonraki;
		}
		if(b==*liste_basi){
			c->sonraki=*liste_basi;
			*liste_basi=c;
		}else{
			a->sonraki=c;
			c->sonraki=b;
		}
	}
}

// liste ters çevirme +


void liste_cevir(struct hucre **liste_basi){
	struct hucre *a,*b;
	a=NULL;
	while(*liste_basi != NULL){
		b=*liste_basi;
		*liste_basi=*liste_basi->sonraki;
		b->sonraki=a;
		a=b;
	}
	*liste_basi=a;
}



// liste yazdýrma  itterative +

void liste_yaz(struct hucre *liste_basi){
	while(liste_basi!=NULL){
		printf("%d",liste_basi->icerik);
		liste_basi=liste_basi->sonraki;
	}
	printf("\n");
}

// 2.yazdýrma   recursive +

void liste_yazdir(struct hucre *liste_basi){
	if(liste_basi!=NULL){
		printf("%d",liste_basi->icerik);
		liste_yazdir(liste_basi->sonraki);
	}else{
		printf("\n");
	}
}








int main(){
	
	struct hucre *liste1;
	liste_basina(19,&liste1);
	
	
}
