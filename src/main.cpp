#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <unistd.h>
#include <stdio.h>
#include "function.h"

using namespace std;

int main(){
    srand(time(NULL));
    vector<dict> list;
    int change = 0;
    int session;
    ifstream fin("session"); 
    fin >> session; 
    if(session == 0){
        ofstream fout("session", ios::out);
        fout << 1;
        fout.close();
        cout << "1. Ввести слова для запоминания" << endl;
    }
    else 
        cout << "1. Добавить слова" << endl;

    cout << "2. Учить" << endl;
    cout << "3. Выйти из программы" << endl;
    cout << "Выберите №: ";
    cin >> change;
    switch(change)
    {   
        case 3:
            return 0;
            break;
        case 1:
            while(1){
                input_words(list);
                cout << endl << "1. Ввести ещё слова" << endl;
                cout << "2. Начать обучение" << endl;
                cout << "Выберите №: ";
                int input;
                cin >> input;
                if(input == 2) break;
            }

        case 2:
            list.clear();
            readfromfile(list);        
            list.pop_back();
            words_more_5(list);
            cout << endl << "Слова в вашем словаре: " << endl;

            cout << " #------------------------------------------------------------------------------#" << endl;
            cout << " |     на АНГЛИЙСКОМ    |"  << "      на РУССКОМ       |" << "       ВЫУЧЕННОСТЬ слов        |"<< endl; 
            cout << " |------------------------------------------------------------------------------|" << endl;

            for(unsigned int i = 0; i < list.size(); i++){
                cout << " |" << '\t' << list[i].eng << '\t' <<  '\t' << "|"  << '\t' << list[i].rus << '\t' << '\t' << "|"  <<  '\t' <<  '\t' << list[i].proc << "%" << '\t' <<  '\t' << "|" << endl;
                cout << " |------------------------------------------------------------------------------|" << endl;
            }

            cout << endl << " Нажмите Enter, для начала ОБУЧЕНИЯ... "  << endl;

            do{
                cin.get();
                sleep(0.1);
            } while(cin.get() != '\n');
            int k = 0;
            int test = 0;
            while(1){
                test = rand()%3 + 1;
                switch(test){
                    case 1:
                        correct_writing_word(list);
                        cout << endl << "Нажмите Enter, для следующего вопроса... ";
                        cin.clear();    
                        do{
                            cin.get();
                            sleep(1);
                        } while(cin.get() != '\n');
                        break;
                    case 2:
                        English_Russian_test(list);
                        cout << endl << "Нажмите Enter, для следующего вопроса... ";
                        cin.clear();    
                        do{
                            cin.get();
                            sleep(1);
                        } while(cin.get() != '\n');
                        break;
                    case 3:
                        Russian_English_test(list);
                        cout << endl << "Нажмите Enter, для следующего вопроса... ";
                        cin.clear();    
                        do{
                            cin.get();
                            sleep(1);
                        } while(cin.get() != '\n');
                        break;
                    default:
                    break;
                }
                k++;
                if( k == 5) break;
            }
            break;
    }

    writeinfile_rewrite(list);
    return 0;

}



