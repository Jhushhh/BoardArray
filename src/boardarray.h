#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
             if (index == 0) {
                array[0] = *entry;
                index = 1;
                return;
            }
            
            
            int insertPos = index; 
            
           
            for (int i = 0; i < index; i++) {
                
                if (entry->compare(&array[i])) {
                    insertPos = i;
                    break;
                }
            }
            
            
            if (index < SIZE) {
               
                for (int i = index; i > insertPos; i--) {
                    array[i] = array[i-1];
                }
                
                array[insertPos] = *entry;
                index++;
            } else {
                
                if (insertPos < SIZE) {
                    
                    for (int i = SIZE - 1; i > insertPos; i--) {
                        array[i] = array[i-1];
                    }
                    
                    array[insertPos] = *entry;
                } else {
            
                    cout << entry->name << "'s score is too low to be added!" << endl;
                }
            }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};