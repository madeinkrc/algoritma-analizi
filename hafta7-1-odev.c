#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

struct Node{
  int veri;
  struct Node *sol,*sag;
};

struct Node *dugumEkle(struct Node *root,int veri){
    if(root==NULL){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp->veri = veri;
        temp->sol = NULL;
        temp->sag = NULL;
        return temp;
    }
    if(root->veri < veri){
        root->sag = dugumEkle(root->sag,veri);
    }else{
       root->sol = dugumEkle(root->sol,veri);
    }
    return root;
}

void Print(struct Node *root){
    if(root){
        printf("%d ",root->veri);
        Print(root->sol);
        Print(root->sag);
    }
}

int minimum(struct Node *root){
  if(root->sol == NULL){
    return root->veri;
  }
  return minimum(root->sol);
}

int maximum(struct Node *root){
  if(root->sag == NULL){
    return root->veri;
  }
  return maximum(root->sag);
}

int dugumSayisi(struct Node *root){
    if(root==NULL) return 0;
    return 1+dugumSayisi(root->sol)+dugumSayisi(root->sag);
}

int derinlik(struct Node * root){
    if(root==NULL) return 0;
    else{
        int sol_yukseklik=0, sag_yukseklik=0;
        sol_yukseklik=derinlik(root->sol);
        sag_yukseklik=derinlik(root->sag);
        if(sag_yukseklik>sol_yukseklik){
            return sag_yukseklik+1;
        }
        else{
            return sol_yukseklik+1;
        }
    }
}

int toplamDerinlik(struct Node * root){
    if(root==NULL) return 0;
    int derinlikValue = derinlik(root)-1;
    int i, toplam=0;
    for(i=derinlikValue; i>=0; i--){
        toplam += i;
    }
    return toplam;
}

int main(){

  struct Node *root=NULL;

  int rastgele;
  srand(time(NULL));

  int i, number;
  printf("DUGUM SAYISINI GIRINIZ: ");
  scanf("%d", &number);

  for(i=0; i<number; i++){
    rastgele=1+rand()%100;
    root = dugumEkle(root,rastgele);
  }

printf("\n");
Print(root);
printf("\n");
printf("\nMiNiMUM \t: %d",minimum(root));
printf("\n");
printf("\nMAXiMUM \t: %d",maximum(root));
printf("\n");
printf("\nDugum Sayisi \t: %d",dugumSayisi(root));
printf("\n");
printf("\nDerinlik \t: %d",derinlik(root)-1);
printf("\n");
printf("\nToplam Derinlik : %d\n",toplamDerinlik(root));
printf("\n");

  getch();
  return 0;
}
