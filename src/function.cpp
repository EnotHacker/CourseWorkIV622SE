#include "function.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <unistd.h>

int mt_setfgcolor(enum colors c)
{
	char str[20];
	if(!sprintf(str, "\E[%dm", (c+30)))
		return -1;
	else
		std::cout << str;
	return 0;
}

int mt_setbgcolor(enum colors c)
{
	char str[20];
	if(!sprintf(str, "\E[%dm", (c+40)))
		return -1;
	else
		std::cout << str;
	
	return 0;
}

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


//рейтинг изученности слов
void rating(vector<dict> &list, int right, int i){
    if(right)
       list[i].proc += 10;
    else
        list[i].proc -= list[i].proc * 0.5;
}

int func_check_choiseRU(vector<dict> &list, int k, int v, int i)
{
    if (k == v){
    	mt_setfgcolor(GREEN);
        cout << endl << "----- ВЕРНО! -----" << endl;
        mt_setfgcolor(DEFAULT);
        rating(list, 1, i);
    }
    else{ 
    	mt_setfgcolor(RED);
    	cout << endl << "----- ВЫ ОШИБЛИСЬ! -----" << endl;
    	mt_setfgcolor(DEFAULT);
		cout << endl << "Правильный ответ: " << k << ". " << list[i].rus << endl;
        rating(list, 0, i);
	}
    return 0;  

}

int func_check_choiseENG(vector<dict> &list, int k, int v, int i)
{
    if (k == v){
    	mt_setfgcolor(GREEN);
        cout << endl << "----- ВЕРНО! -----" << endl;
        mt_setfgcolor(DEFAULT);
        rating(list, 1, i);
    }
    else{
    	mt_setfgcolor(RED);
        cout << endl << "----- ВЫ ОШИБЛИСЬ! -----" << endl;
        mt_setfgcolor(DEFAULT);
        cout << endl << "Правильный ответ: " << k << ". " << list[i].eng << endl;
        rating(list, 0, i);        
    }
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
        case 1: func_check_choiseRU( list, k, 1, i);
            break;

        case 2: func_check_choiseRU( list, k, 2, i);
            break;  

        case 3: func_check_choiseRU( list, k, 3, i);
            break;

        case 4: func_check_choiseRU( list, k, 4, i);
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

    function_of_selectionENG( list,  k, 1, i, l);
    function_of_selectionENG( list,  k, 2, i, s);
    function_of_selectionENG( list,  k, 3, i, c);
    function_of_selectionENG( list,  k, 4, i, p);
    cout << "Ваш ответ: "  ;
    cin >> choice;
    switch(choice)
    {
        case 1: func_check_choiseENG(  list, k, 1, i);
            break;

        case 2: func_check_choiseENG(  list, k, 2, i);
            break;  

        case 3: func_check_choiseENG(  list, k, 3, i);
            break;

        case 4: func_check_choiseENG(  list, k, 4, i);
            break; 
        }
}


//функция проверки проверки правильности написания англ. слова
void correct_writing_word(vector<dict> &list){
    srand(time(NULL));
    string answer;
    system("clear");
    int i = rand()%list.size();
    cout << "Введите это слово на английском:" << endl;
    cout << list[i].rus << " -> ";
    cin >> answer;
    if(answer == list[i].eng)
    {   
        rating(list, 1, i);
        mt_setfgcolor(GREEN);
        cout << endl << "----- ВЕРНО! -----" << endl;
        mt_setfgcolor(DEFAULT);
    }
    else{
        rating(list, 0, i);
        mt_setfgcolor(RED);
        cout << endl << "----- ВЫ ОШИБЛИСЬ! -----" << endl;
        mt_setfgcolor(DEFAULT); 
        cout << endl << "Правильный ответ: " << list[i].eng << endl;
    }
    answer.clear();
}

void input_words(vector<dict> &list);

//запись в файл
int writeinfile_rewrite(vector<dict> &list){
    unsigned int i;
    ofstream fout("dict.dat", ios::out);

    for(i = 0; i < list.size(); i++)
        fout << list[i].eng << "\t" << list[i].rus << "\t" << list[i].proc << endl;
    fout.close();
    return 0;
}

//запись в файл
int writeinfile_add(vector<dict> &list){
    unsigned int i;
    ofstream fout("dict.dat", ios::out | ios ::app);

    for(i = 0; i < list.size(); i++)
        fout << list[i].eng << "\t" << list[i].rus << "\t" << list[i].proc << endl;
    fout.close();
    return 0;
}

//чтение из файла
int readfromfile(vector<dict> &list){
    ifstream fin("dict.dat", ios::in);
    if (!fin.is_open()){
        cout << endl << "----- Пока нет слов в словаре! -----" << endl;
        input_words(list);
        return 0;
    }
    while(!fin.eof()){
        dict tmp;
        fin >> tmp.eng >> tmp.rus >> tmp.proc;
        if(tmp.proc < 100)
            list.push_back(tmp);
    }
    if( list.empty() ){
        cout << endl << "------ Все слова изучены! ДОБАВЬТЕ НОВЫЕ -----" << endl;
        input_words(list);
    }
    fin.close();
    return 0;
}

//проверка, что слов в базе >= 5
void words_more_5(vector<dict> &list){
    int k = list.size();
    if(k < 5){
    	mt_setfgcolor(RED);
        cout << endl << "Слишком мало слов!" << endl;
        mt_setfgcolor(DEFAULT);
        cout << "Введите ещё " << 5 - list.size() << " слов(а):" << endl;
        for(int i = 0; i < 5 - k; i++){
            dict tmp;
            cout <<  endl << i+1 << ". " << "Введите слово на АНГЛИЙСКОМ: ";
            cin >> tmp.eng ;
            cout << i+1 << ". " << "Введите слово на РУССКОМ: ";
            cin >> tmp.rus;
            tmp.proc = 0;
            list.push_back(tmp);
        }
        writeinfile_rewrite(list);
    }
}
void input_words(vector<dict> &list){
    int size;
    cout << endl << " Введите количество слов, которые ВЫ хотите запомнить: ";
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
    writeinfile_add(list);
}

void menu(){   
    srand(time(NULL));
    vector<dict> list;
    int change = 0;
    int session;
    ifstream fin("session"); 
    fin >> session; 
    while(1){
        if(session == 0){
            ofstream fout("session", ios::out);
            fout << 1;
            fout.close();
            cout << endl << "1. Ввести слова для запоминания" << endl;
        }
        else 
            cout << endl << "1. Добавить слова" << endl;

        cout << "2. Учить" << endl;
        cout << "3. Выйти из программы" << endl;
        cout << "Выберите №: ";
        cin >> change;
        if( (change == 1) || (change == 2) || (change == 3) )
            break;

        else{
            system("clear");
            mt_setfgcolor(RED);
            cout << endl << "----- ОШИБКА!!! Введите цифру от 1 до 3 -----" << endl;
            mt_setfgcolor(DEFAULT);
        }
    }
    switch(change)
    {   
        case 3:
            exit(1);
            break;
        case 1:
            while(1){
                system("clear");
                input_words(list);
                system("clear");
                mt_setfgcolor(GREEN);
                cout << endl << "----- Слова добавленны! -----" << endl;
                mt_setfgcolor(DEFAULT);              
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
            system("clear");
            mt_setfgcolor(BLUE);
            cout << endl << " Слова для запоминания: " << endl;
            mt_setfgcolor(DEFAULT);
            cout << " #------------------------------------------------------------------------------#" << endl;
            cout << " |№|   на АНГЛИЙСКОМ    |"  << "      на РУССКОМ       |" << "       ВЫУЧЕННОСТЬ слов        |"<< endl; 
            cout << " |------------------------------------------------------------------------------|" << endl;

            for(unsigned int i = 0; i < list.size(); i++){
                cout << " |" << i+1 << "|" << '\t' << list[i].eng << '\t' <<  '\t' << "|"  << '\t' << list[i].rus << '\t' << '\t' << "|"  <<  '\t' <<  '\t' << list[i].proc << "%" << '\t' <<  '\t' << "|" << endl;
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
    system("clear");
    mt_setfgcolor(BLUE);
    cout << endl << " Прогресс запоминания: " << endl;
    mt_setfgcolor(DEFAULT);
    cout << " #------------------------------------------------------------------------------#" << endl;
    cout << " |№|   на АНГЛИЙСКОМ    |"  << "      на РУССКОМ       |" << "       ВЫУЧЕННОСТЬ слов        |"<< endl; 
    cout << " |------------------------------------------------------------------------------|" << endl;

    for(unsigned int i = 0; i < list.size(); i++){
        cout << " |" << i+1 << "|" << '\t' << list[i].eng << '\t' <<  '\t' << "|"  << '\t' << list[i].rus << '\t' << '\t' << "|"  <<  '\t' <<  '\t' << list[i].proc << "%" << '\t' <<  '\t' << "|" << endl;
        cout << " |------------------------------------------------------------------------------|" << endl;
    }


    writeinfile_rewrite(list);
    mt_setfgcolor(YELLOW);
    cout << endl << "----- Обучение завершено! -----" << endl;
    mt_setfgcolor(DEFAULT);
    cout << endl;
    menu();
}