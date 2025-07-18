/** 
* @file BST.cpp 
* @description BST sinifi
* @course 1-b
* @assignment 2
* @date 29.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*		  İrfan Eren Çiftçi irfan.ciftci1@ogr.sakarya.edu.tr	
*/

#include "Stack.hpp"
#include "BST.hpp"
#include<string>
#include<sstream>
#include<fstream>
#include<windows.h>


int main()
{
    system("cls");
    fstream dosya;
    string satir;
    int sayi;
    dosya.open("sayilar.txt",ios::in);
    const int SIZE = 1000;

    Stack **dizi = new Stack*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        dizi[i] = NULL;
    }
    
    int length = 0;

    if(dosya.is_open())
    {  

        while(getline(dosya,satir)) //her satir
        {    
            stringstream ccc(satir);
            while(ccc>>sayi)  //her satirdaki sayilar
            {
                if(dizi[length] == NULL && length == 0)
                { 
                    dizi[length] = new Stack();
                    length++;
                    dizi[length-1]->push(sayi);
                }
                else if(sayi % 2 == 0 && sayi > dizi[length-1]->top()){
                    dizi[length] = new Stack();
                    length++;
                    dizi[length-1]->push(sayi);
                }
                else
                {
                    dizi[length-1]->push(sayi);  
                }                                
            }
            //agaca stack verilerini cikar
            BST** bst = new BST*[length];

            for(int i = 0; i<length; i++){
                bst[i] = new BST();
                while(!dizi[i]->isEmpty())
                {
                    bst[i]->searchAndAdd(bst[i]->root,dizi[i]->top());
                    dizi[i]->pop();
                }
            }
            //max tree
            int index = 0;  //secilecek agacın indeksini tutsun
       
            for(int index2 = 1; index2<length; index2++)
            {
                if(bst[index]->height(bst[index]->root) == bst[index2]->height(bst[index2]->root))
                {
                    if(bst[index]->toplam == bst[index2]->toplam)
                    {
                        continue;
                    }
                    else if(bst[index]->toplam < bst[index2]->toplam)
                    {
                        index = index2;
                    }
                }
                else
                {
                    if(bst[index]->height(bst[index]->root)<bst[index2]->height(bst[index2]->root))
                    {
                        index = index2;
                    }
                }
            }
            bst[index]->postOrder(bst[index]->root);
            cout<<endl;
            Sleep(10);
            for(int i = 0; i<length; i++){
                delete dizi[i];
                dizi[i] = NULL;
            }
             for(int i = 0; i<length; i++){
                delete bst[i];
                bst[i] = NULL;
            }
            length = 0;
        }
    }
    else
    {
        cout<<"dosya bulunamadi"<<endl;
    }
     
    delete [] dizi;
    return 0;
}






