#include "list.h"
#include "operation.h"
#include "my_data.h"


void insertAndSort(List &L, infotype x) {
    /**
    * IS : List may be empty
    * PR : insert a new element into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID.
    *      procedure must also check if such ID is already exists (No Duplicate ID).
    *      If new data has duplicate ID, new data is rejected.
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    address P;
    P = allocate(x);
    if(first(L) == NULL || x.ID < info(first(L)).ID){
        insertFirst(L, P);
    }else{
        address Q = first(L);
        while(next(Q) != NULL && x.ID >= info(next(Q)).ID){
            Q = next(Q);
        }
        if(info(Q).ID == x.ID){
            cout<<"ID SUDAH ADA";
        }else if(next(Q) == NULL){
            insertLast(L, P);
        }else if(info(Q).ID != x.ID){
            insertAfter(L, Q, P);
        }
    }
    cout<<endl;
    //----------------------------------------
}

void deletebyID(List &L, int id_x) {
    /**
    * IS : List L may be empty
    * FS : an element with ID info = id_x is deleted from List L (deallocate)
    */

    address Prec, P;
    //-------------your code here-------------
    if(first(L) != NULL){
        if(info(first(L)).ID == id_x){
            deleteFirst(L, P);
        }else if(info(last(L)).ID == id_x){
            deleteLast(L, P);
        }else{
             address Q = first(L);
             while(next(Q) != NULL && info(next(Q)).ID != id_x){
                Q = next(Q);
             }
             Prec = Q;
             deleteAfter(L, Prec, P);
        }

    }else{
        cout<<"LIST KOSONG"<<endl;
    }


    //----------------------------------------
}


void savePassedMember(List &L, List &L2){
    /**
    * IS : List L and L2 may be empty
    * FS : any element with score greater than 80 is moved to L2
    */
    address P;
    //-------------your code here-------------

    P = first(L);
    while(P != NULL){
        if(info(P).score > 80){
            address Q;
            Q = allocate(info(P));
            insertLast(L2, Q);
        }
        P = next(P);
    }

    //----------------------------------------
}

