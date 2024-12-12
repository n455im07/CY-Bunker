#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int id;
    int bf;
    struct AVL* left;
    struct AVL* right;

}AVL;

AVL* creationAVL(int id){
    AVL* new = malloc(sizeof(AVL));
    if( new == NULL){
        printf("creationAVL mallocfailed\n");
        exit (1);
    }   
    new -> bf = 0;
    new -> left = new -> right = NULL;
    new -> id = id;
    return new;
}

int searchAVL(AVL* avl,int id){
    if (avl == NULL){
        return 0;
    }
    if (avl->id == id){
        return 1;
    }
    if (avl->id < id && avl->right != NULL){
        return searchAVL(avl->right,id);
    }
    if (avl->id > id && avl->left !=NULL){
        return searchAVL(avl->left,id);
    }
}

int max(int a,int b){
    return (a>b) ? a : b;
}

int min(int a,int b){
    return (a>b) ? b : a;
}

AVL* rotateLeft(AVL* avl){
    AVL* pivot;
    int ea,ep;
    if (avl == NULL){
        return avl;
    }
    pivot = avl->right;
    avl->right = pivot->left;
    pivot->left = avl;
    // Updating balance factor;
    ea = avl->bf;
    ep = pivot->bf;
   
    avl->bf = ea - max(ep,0) - 1;
    pivot->bf = min(ea - 2, min(ea+ep-2, ep-1));
    avl = pivot;
    return avl;
}

AVL* rotateRight(AVL* avl){
    AVL* pivot;
    int ea, ep;
    if (avl == NULL){
        return avl;
    }
    pivot = avl->left;
    avl->left = pivot->right;
    pivot->right = avl;
    // Updating balance factor;
    ea = avl->bf;
    ep = pivot->bf;

    avl->bf = ea - min(ep,0) + 1;
    pivot->bf = max(ea +2, max(ea+ep+2, ep+1));
    avl = pivot;
    return avl;
}

AVL* doubleRight(AVL* avl){
    avl -> left = rotateLeft(avl->left);
    return rotateRight(avl);
}

AVL* doubleLeft(AVL* avl){
    avl->right = rotateRight(avl->right);
    return rotateLeft(avl);
}

AVL* balanceAVL(AVL* avl){
    

    if ( avl->bf >= 2){
        if ( avl->right != NULL && avl->right->bf >= 0){
            return rotateLeft(avl);
        }
        else{
            return doubleLeft(avl);
        }
    }
    if ( avl->bf <= -2){
        if ( avl->left != NULL && avl -> left -> bf <= 0){
            return rotateRight(avl);
        }
        else{
            return doubleRight(avl);
        }
    }
  
  return avl;
}

AVL* insertAVL(AVL* avl,int id,int* h){
    if (avl==NULL){
        *h=1;
        return creationAVL(id);   
    } else if (id < avl->id){
        avl->left = insertAVL(avl->left,id,h);
        *h=-*h;
    } else if (id > avl->id){
        avl->right = insertAVL(avl->right,id,h);
    }
    else{
        *h=0;
        return avl;
    }
   
    if (*h!=0){
        avl->bf+=*h;
        avl = balanceAVL(avl);
        *h = (avl->bf==0) ? 0 : 1 ; 
    }
    return avl;
}

AVL* removeMin(AVL* avl, int* id, int* h){
    AVL* tmp;
    if (avl==NULL){
        return avl;
    }
    if ( avl -> left == NULL){
        *id = avl -> id;
        tmp = avl;
        avl = avl -> left;
        free(tmp);
        *h = -1;
        return avl;
    }
    else{
        avl -> left = removeMin(avl -> left, id, h);
        *h = -*h;
    }
    if(*h!=0){
        avl -> bf = avl -> bf +*h;
        avl = balanceAVL(avl);
        *h = (avl->bf==0) ? -1 : 0;
    }
    return avl;
}

AVL* removeAVL(AVL* avl,int id,int* h){
    if (avl==NULL){
        *h=0;
        return avl ;
    }
    if (id<avl->id){
        avl->left = removeAVL(avl->left,id,h);
        *h=-*h;
    }
    else if (id>avl->id){
        avl->right = removeAVL(avl->right,id,h);
    }
    else if (avl->right != NULL){
        avl->right = removeMin(avl->right,&(avl->id), h);
    }
    else{
        AVL* temp = avl;
        avl=avl->left;
        free(temp);
        *h=-1;
    }
    if (avl!=NULL && *h!=0){
        avl->bf+=*h;
        avl=balanceAVL(avl);
        *h= (avl->bf==0) ? 0 : 1;
    }
    return avl;
}

void prefixe(AVL* avl){
    if (avl==NULL){
        return;
    }else{
        printf("%d eq = %d\n",avl->id,avl->bf);
        prefixe(avl->left);
        prefixe(avl->right);
    }
}

int main(int argc, char* argv[]){
    AVL* root = NULL;
    int h = 0;
// TESTING
    // Insert values into the AVL tree
    root = insertAVL(root, 42, &h);
    root = insertAVL(root, 17, &h);
    root = insertAVL(root, 68, &h);
    root = insertAVL(root, 3, &h);
    root = insertAVL(root, 25, &h);
    root = insertAVL(root, 91, &h);
    root = insertAVL(root, 54, &h);
    root = insertAVL(root, 36, &h);
    root = insertAVL(root, 77, &h);
    root = insertAVL(root, 12, &h);
    root = insertAVL(root, 89, &h);
    root = insertAVL(root, 5, &h);
    root = insertAVL(root, 63, &h);
    root = insertAVL(root, 29, &h);
    root = insertAVL(root, 48, &h);

    printf("tree before deletion\n");
    prefixe(root);

    // Delete specific values from the AVL tree with null checks

        printf("\nDeleting value 29\n");
        root = removeAVL(root, 29, &h);

        printf("\nDeleting value 5\n");  // Fixed message to match actual value
        root = removeAVL(root, 5, &h);

        printf("\nDeleting value 54\n");
        root = removeAVL(root, 54, &h);

        // Print the tree in prefix order after deletion
        printf("\nTree after deletion:\n");
        prefixe(root);
   
   // FREE AVL !!!!!!!!!!!!!!!!!!!!!!!!!!!

    if ( argc != 2){
        printf("Error mauvais nombres d'argumpent");
     exit(2);
    }
   
   FILE* file;
   const char* filename = argv[1];
   fopen(filename, "r");

  if ( file == NULL){
    printf("Error file");
    exit(1);
  }




}
