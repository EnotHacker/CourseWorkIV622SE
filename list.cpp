#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <unistd.h>
using namespace std;

struct dict
{
    string eng, rus;
    int proc;
};

//функция формирования ответов которые будет выбирать пользователь(для выбора перевода с английского)
int function_of_selectionRUS(vector<dict> &list, int k, int v, int x, int y)
{
    if  (k == v)  
    cout << "  "  << v << ". " << list[x].rus << endl;
    else 
    cout << "  "  << v << ". " << list[y].rus << endl;
    return 0;
}

//функция формирования ответов которые будет выбирать пользователь(для выбора перевода с русского)
int function_of_selectionENG(vector<dict> &list, int k, int v, int x, int y)
{
    if  (k == v)  
    cout << "  "  << v << ". " << list[x].eng << endl;
    else 
    cout << "  "  << v << ". " << list[y].eng << endl;
    return 0;
}


int func_check_choise(int k, int v)
{
    if (k == v)
    cout << "-----ВЕРНО!!-----" << endl;
    else
    cout << "-----ВЫ ОШИБЛИСЬ!-----" << endl;
    return 0;  

}
    

//функция - тест (выбор правильного перевода с английского на русский)

void English_Russian_test(vector<dict> &list){   
    system("clear");
    srand(time(NULL));
    int choice;
    int k = rand() % 4 + 1;
    int i = rand()%list.size();
    int p = i, c = i, s = i, l = i;
    while ( l == i ) 
    l = rand()%list.size();

    while ( s == i || s == l) 
    s = rand()%list.size();

    while ( c == i || c == l || c == s) 
    c = rand()%list.size();

    while ( p == i || p == l || p == s || p == c) 
    p = rand()%list.size();

    cout << "Выберите правильный перевод слова: " << list[i].eng << endl;

    function_of_selectionRUS( list, k, 1, i, l);
    function_of_selectionRUS( list, k, 2, i, s);
    function_of_selectionRUS( list, k, 3, i, c);
    function_of_selectionRUS( list, k, 4, i, p);

    cout << "Ваш ответ: " ;
    cin >> choice;

    switch(choice)
    
    {
        case 1: func_check_choise( k, 1);
            break;

        case 2: func_check_choise( k, 2);
            break;  

        case 3: func_check_choise( k, 3);
            break;

        case 4: func_check_choise( k, 4);
            break;
        }
    
}

//функция - тест (выбор правильного перевода с русского на английский)

void Russian_English_test(vector<dict> &list){   
    system("clear");
    srand(time(NULL));
    int choice;
    int k = rand() % 4 + 1;
    int i = rand()%list.size();
    int p = i, c = i, s = i, l = i;
    while ( l == i ) 
    l = rand()%list.size();

    while ( s == i || s == l) 
    s = rand()%list.size();

    while ( c == i || c == l || c == s) 
    c = rand()%list.size();

    while ( p == i || p == l || p == s || p == c) 
    p = rand()%list.size();

    cout << "Выберите правильный перевод слова: " << list[i].rus << endl;

    function_of_selectionENG(list,  k, 1, i, l);
    function_of_selectionENG(list,  k, 2, i, s);
    function_of_selectionENG(list,  k, 3, i, c);
    function_of_selectionENG(list,  k, 4, i, p);
    cout << "Ваш ответ: "  ;
    cin >> choice;
    switch(choice)
    {
        case 1: func_check_choise( k, 1);
            break;
        case 2: func_check_choise( k, 2);
            break;
        case 3: func_check_choise( k, 3);
            break;
        case 4: func_check_choise( k, 4);
            break; 
        }
}

//функция проверки проверки правильности написания англ. слова
void correct_writing_word(vector<dict> &list){
    srand(time(NULL));
    string answer;
    system("clear");
    while(1)
    {
        int i = rand()%list.size();
        cout << "Введите это слово на аглийском:" << endl;
        cout << list[i].rus << " -> ";
        cin >> answer;
        if(answer == list[i].eng)
        {
            cout << "-----ВЕРНО!!-----" << endl;
            break;
        }
        else
        {
            cout << "-----ВЫ ОШИБЛИСЬ!-----" << endl; 
            cout << "Правильный ответ: " << list[i].eng << endl;
            break;
        }
        answer.clear();
    }

}

//запись в файл
int writeinfile_1(vector<dict> &list){
    unsigned int i;
    ofstream fout("dict.dat", ios::out);

    if(fout == 0)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }

    for(i = 0; i < list.size(); i++)
        fout << list[i].eng << "\t" << list[i].rus << "\t" << list[i].proc << endl;
    fout.close();
    return 0;
}

//запись в файл
int writeinfile_2(vector<dict> &list){
    unsigned int i;
    ofstream fout("dict.dat", ios::out | ios ::app);

    if(fout == 0)
    {
        cout << "Ошибка открытия файла!" << endl;
        return -1;
    }

    for(i = 0; i < list.size(); i++)
        fout << list[i].eng << "\t" << list[i].rus << "\t" << list[i].proc << endl;
    fout.close();
    return 0;
}

//чтение из файла
int readfromfile(vector<dict> &list){
    ifstream fin("dict.dat", ios::in);
    while(!fin.eof()){
        dict tmp;
        fin >> tmp.eng >> tmp.rus >> tmp.proc;
        list.push_back(tmp);
    }
    fin.close();
    return 0;
}

//проверка, что слов в базе >= 4
void words_more_5(vector<dict> &list){
    int k = list.size();
    if(k < 4){
        cout << "Слишком мало слов!" << endl;
        cout << "Введите ещё " << 5 - list.size() << " слова:" << endl;
        for(int i = 0; i < 5 - k; i++){
            dict tmp;
            cout << "Введите слово на АНГЛИЙСКОМ: ";
            cin >> tmp.eng ;
            cout << "Введите слово на РУССКОМ: ";
            cin >> tmp.rus;
            tmp.proc = 0;
            list.push_back(tmp);
        }
        writeinfile_1(list);
    }
}

int main(){
    vector<dict> list;
    int size, change = 0;
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
    cout << "Вариант: ";
    cin >> change;
    switch(change)
    {
        case 1:
            cout << "Введите количество слов, которые ВЫ хотите запомнить: ";
            cin >> size;
            for(int i = 0; i < size; i++){
                dict tmp;
                    cout <<  endl << i+1 << ". " << "Введите слово на АНГЛИЙСКОМ: ";
                    cin >> tmp.eng ;
                    cout << i+1 << ". " << "Введите слово на РУССКОМ: ";
                    cin >> tmp.rus;
                tmp.proc = 0;
                list.push_back(tmp);
            }  
            writeinfile_2(list);
            break;

        case 2:
            list.clear();
            readfromfile(list);
            list.pop_back();
            words_more_5(list);
            cout << endl << "Ваш список слов: " << endl;
            for(unsigned int i = 0; i < list.size(); i++){
                cout << list[i].eng << " " << list[i].rus << " " << list[i].proc << endl;
            }
            int k = 0;
            int y = 0;
            while(1){
                /*
                while(rand()%500 - 1 != -1){
                    y = rand()%2 + 1;
                }*/
                switch(1){
                    case 1:
                        correct_writing_word(list);
                        sleep(1);
                        break;
                    default:
                    break;
                }
                k++;
                if( k == 6) break;
            }
            break;

        }
    return 0;

}
