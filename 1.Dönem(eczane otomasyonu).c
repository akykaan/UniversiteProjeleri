#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int DepoIlac(int n){
	FILE *outfile,*infile;
	
	if(n==0){
		
		char ch;
		outfile=fopen("DepoilacListesi.txt","r");
	
		while(!feof(outfile)){
			ch=getc(outfile);
			printf("%c",ch);
		}
		fclose(outfile);
	}
	
	if(n==1){
		char IlacAdi[30],FirmaAdi[30];
		int adet=0;
		float fiyat=0;
		
		printf("\n---------------\n"
		"Ilac Adi giriniz:");
		fflush(stdin); //gets kullanmak sakıncalı olduğu için 
		gets(IlacAdi);
		
		printf("Firma Adini giriniz:");
		fflush(stdin);
		gets(FirmaAdi);
				
		printf("Adet sayisini giriniz:");
		scanf("%d",&adet);
		
		printf("Fiyat giriniz:");
		scanf("%f",&fiyat);
				
		infile=fopen("DepoIlacListesi.txt","a+");	
		fprintf(infile,"%s --- %s --- %d --- %f\n",IlacAdi,FirmaAdi,adet,fiyat);	
		fclose(infile);
	}
}
void PersonelListe(){
	
	char* personelListe[3][2]={{"Ozan Yilmaz","35"},{"Furkan Cesur","27"},{"Elif Ak","35"}};
	for(int i=0; i<3; i++){
		for(int j=0; j<1; j++){
			printf("\t %d) Ad-Soyad: %s  Yas: %s \n",i+1,personelListe[i][j],personelListe[i][j+1]);
		}
	}
}

void KisiList(){
	
	long long int tcNo[10]={
	57854123448,85247963123,
	35789621321,65478932451,
	48154891632,89451232623,
	48621321412,23215468853,
	32154987162,12345678713};
	
	char *Kisiler[10][2]={
	{"Cem Candan","18"},
	{"Batuhan Ulun","19"},
	{"Furkan Kaan Akyuz","24"},
	{"Turgay Kurt","23"},
	{"Orcun Holta","23"},
	{"Cem Eroksuz","25"},
	{"Mehmet Eryilmaz","24"},
	{"Furkan Aydin","22"},
	{"Elif Sahin","24"},
	{"Elif Sahinkaya","25"}
	};
	
	for(int i=0; i<10; i++){
		for(int j=0; j<1; j++){
			printf("\tAd ve Soyad=%s | Yas=%s | TcNo=%lld\n",Kisiler[i][j],Kisiler[i][j+1],tcNo[i]);
		}
	}
}
void yuklemeEkrani(){
		char *yuklemeEkrani[3]={"Veri Tabani yukleniyor","Sistem Guncelleniyor","Bilgiler Aliniyor"};
		printf("----Ak Eczanesine Hosgeldiniz----\n"
		"Sistem Yukleniyor.\nLutfen Bekleyiniz.\n");
		sleep(1); // bilerek yavaşlatma
		int sayac=0;
		for(int i=0; i<3; i++){
			printf("%s",yuklemeEkrani[i]);
			while(sayac<=3){
				printf("%c",46); // ascii tablosu  . (Nokta) simgesi
				sleep(1);
				sayac++;
			}
			printf("\n");
			sayac=0;
			sleep(1);
		}
}
int main(void) {
	
	bool cikis=true; //whileden istenildiği zaman çıkmak için
	yuklemeEkrani();  // fonksiyon çağırma
	do{
		printf("\n\n1Yapmak istediklerinizi asagidaki listeden seciniz lutfen:\n" // Kullanıcıya sunulan seçim listesi
		"1)Depodaki ilac listesini getir.\n"
		"2)Eczaneye kayitli hastalari getir.\n"
		"3)Personel Listesini getir.\n"
		"4)Depoya ilac ekle.\n"
		"5)Cikis.\n");
	int liste;
	
	scanf("%d",&liste);
	switch(liste){
		case 1:
			DepoIlac(0);
			break;
		case 2:
			KisiList();
			break;
		case 3:
			PersonelListe();
			break;
		case 4:
			DepoIlac(1);
			break;
		case 5:
			cikis=false;
	}
	}while(cikis);
	return 0;
}
