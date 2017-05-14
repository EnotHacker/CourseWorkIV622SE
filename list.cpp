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
