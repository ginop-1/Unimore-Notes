//
// Created by enri on 6/2/24.
//

#include "tree.h"

extern void InvertRec(Node *left, Node* right) {
    if (left == NULL || right == NULL)
        return;
    ElemSwap(&right->value, &left->value);
    InvertRec(left->left, right->right);
    InvertRec(left->right, right->left);
}

extern Node* Invert(Node *t) {
    if (TreeIsEmpty(t) || TreeIsLeaf(t))
        return t;
    InvertRec(t->left, t->right);
    return t;
}

int main(void){
    ElemType ValoriAlberi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    // albero completo di 7 nodi (radice compresa)
    Node* AlberoCompleto =
            TreeCreateRoot(ValoriAlberi + 0,
                           TreeCreateRoot(ValoriAlberi + 1,
                                          TreeCreateRoot(ValoriAlberi + 3, NULL, NULL),
                                          TreeCreateRoot(ValoriAlberi + 4, NULL, NULL)),
                           TreeCreateRoot(ValoriAlberi + 2,
                                          TreeCreateRoot(ValoriAlberi + 5, NULL, NULL),
                                          TreeCreateRoot(ValoriAlberi + 6, NULL, NULL)));
    // albero con 5 figli a sinistra
    Node* AlberoSinistro =
            TreeCreateRoot(ValoriAlberi + 0,
                           TreeCreateRoot(ValoriAlberi + 1,
                                          TreeCreateRoot(ValoriAlberi + 2,
                                                         TreeCreateRoot(ValoriAlberi + 3,
                                                                        TreeCreateRoot(ValoriAlberi + 4,NULL,NULL),NULL),NULL),NULL),NULL);
    // albero con 5 figli a destra
    Node* AlberoDestro =
            TreeCreateRoot(ValoriAlberi + 0,NULL,
                           TreeCreateRoot(ValoriAlberi + 1,NULL,
                                          TreeCreateRoot(ValoriAlberi + 2,NULL,
                                                         TreeCreateRoot(ValoriAlberi + 3,NULL,
                                                                        TreeCreateRoot(ValoriAlberi + 4,NULL,NULL)))));
    // albero vuoto
    Node* AlberoVuoto = TreeCreateEmpty();
    // albero con solo la radice
    Node* AlberoSoloRadice = TreeCreateRoot(ValoriAlberi + 0, NULL, NULL);
    // albero con valori doppi
    Node* AlberoDoppioneStorto =
            TreeCreateRoot(ValoriAlberi + 0,
                           TreeCreateRoot(ValoriAlberi + 1,
                                          TreeCreateRoot(ValoriAlberi + 0, NULL, NULL),
                                          TreeCreateRoot(ValoriAlberi + 5,
                                                         TreeCreateRoot(ValoriAlberi + 6, NULL, NULL),NULL)),
                           TreeCreateRoot(ValoriAlberi + 2,
                                          TreeCreateRoot(ValoriAlberi + 6, NULL, NULL),
                                          TreeCreateRoot(ValoriAlberi + 6,
                                                         TreeCreateRoot(ValoriAlberi + 5,NULL,
                                                                        TreeCreateRoot(ValoriAlberi + 8, NULL, NULL)),NULL)));
    Node* test = Invert(AlberoCompleto);
    TreeDelete(AlberoCompleto); TreeDelete(AlberoSinistro); TreeDelete(AlberoDestro);
    TreeDelete(AlberoVuoto); TreeDelete(AlberoSoloRadice); TreeDelete(AlberoDoppioneStorto);
    return 0;
}