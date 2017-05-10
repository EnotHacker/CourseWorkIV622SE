#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
using namespace std;

struct dict
{
    string eng, rus;
    int proc;
};

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
            cout << "ВЕРНО!" << endl;
            break;
        }
        else
        {
            cout << "ВЫ ОШИБЛИСЬ!" << endl; 
            cout << "Правильный ответ: " << list[i].eng << endl;
            break;
        }
        answer.clear();
    }
}

//выбор вариант слова на английском
/*
int choice_word_on_ENG(vector<dict> &list){
    int k = rand() % 3 + 1;
    int word = rand()%list.size()-1;

    for(int i = 0; i < 4; i++){
        switch(k){
            case 1:
                

            case 2:
                

        }

    }
}
*/

//запись в файл
int writeinfile(vector<dict> &list){
    unsigned int i;
    ofstream fout("dict.dat", ios::out | ios::app);

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

    while(!fin.eof())    {
        dict tmp;
        fin >> tmp.eng >> tmp.rus >> tmp.proc;
        list.push_back(tmp);
    }
    fin.close();
    return 0;
}

int main(){
    vector<dict> list;
    int size, change = 0;
    int session;

    //сессия
    ifstream fin("session"); 
    fin >> session; 
    if(session == 0){
        ofstream fout("session", ios::out);
        fout << 1;
        fout.close();
        cout << "1. Введите слова для запоминания" << endl;
    }
    else 
        cout << "1. Добавить ещё слова" << endl;

    cout << "2. Учить" << endl;
    cout << "Вариант: ";
//while(1)
//{
    cin >> change;
    switch(change)
    {
    case 1:
        cout << "Введите количество слов, которые ВЫ хотите запомнить:" << endl;
        cin >> size;

        for(int i = 0; i < size; i++)
        {
            dict tmp;
            cin >> tmp.eng >> tmp.rus;
            tmp.proc = 0;
            list.push_back(tmp);
        }
        writeinfile(list);
        break;
    case 2:
        cout << endl << "Данные из файла: " << endl;
        list.clear();
        readfromfile(list);
        list.pop_back();
        /*if(list.size() <= 4){
            cout << "Слишком мало слов!" << endl << "Введите ещё " << 4- list.size()<< " слова" << endl;
            break;
        }*/
        for(int i = 0; i < list.size(); i++)
        {
            cout << list[i].eng << " " << list[i].rus << " " << list[i].proc << endl;
        }

        correct_writing_word(list);
       //choice_word_on_ENG(list);
    //}
}
}
