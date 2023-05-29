#include <iostream>

namespace suchbaum{
    struct BaumKnoten{
        int data;
        BaumKnoten *links;
        BaumKnoten *rechts ;
    };

    void einfuegen(BaumKnoten **tree, int data);

    void ausgeben(BaumKnoten *kopf_knoten);
    void knoten_ausgeben(BaumKnoten *knoten, unsigned int tiefe);
}

void suchbaum::einfuegen(suchbaum::BaumKnoten **tree, int data){
    suchbaum::BaumKnoten *trav;
    suchbaum::BaumKnoten *temp_knoten = new suchbaum::BaumKnoten;
    temp_knoten->data = data;
    temp_knoten->links = temp_knoten->rechts = NULL;
    if(*tree == NULL){
        *tree = temp_knoten;
        return;
    }

    trav = *tree;
    while(1){
        if(trav->data == data) return;
        if(data < trav->data){
            if(trav->links == NULL){
                trav->links = temp_knoten;
                break;
            }
            else trav = trav->links;
        }
        else{
            if(trav->rechts == NULL){
                trav->rechts = temp_knoten;
                break;
            }
            else trav = trav->rechts;
        }
    }
}

void suchbaum::knoten_ausgeben(suchbaum::BaumKnoten *knoten, unsigned int tiefe){
    if(knoten == NULL){
        return;
    }

    suchbaum::knoten_ausgeben(knoten->rechts, tiefe+1);

    for(unsigned int i=0; i<tiefe; i++)
        printf("++");
    printf("%d\n", knoten->data);

    suchbaum::knoten_ausgeben(knoten->links, tiefe+1);
}

void suchbaum::ausgeben(suchbaum::BaumKnoten *kopf_knoten){

    suchbaum::knoten_ausgeben(kopf_knoten, 0);
}

int main(){
    suchbaum::BaumKnoten *tree = NULL;
    int arr[] = {3, 3, 3, 2};

    for(int i=0; i<4; i++){
        einfuegen(&tree, arr[i]);
    }

    suchbaum::ausgeben(tree);
}
