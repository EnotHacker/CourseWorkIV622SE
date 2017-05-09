#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct word{
  char eng[64];
  char rus[64];
  int know;
};

int main()
{
  word *words;
  int size;
  cout << "Введите количество слов для запоминания: ";
  cin >> size;
  words = new word[size];

  //Ввод слов
  for(int i = 0; i < size; i++){
      cout << "Eng - Rus" << endl;
      cin >> words[i].eng >> words[i].rus;
      words[i].know = 0;
      system("clear");
  };

  //Отображение введённых слов
  cout << "Eng-Rus" << endl;
  for(int i = 0; i < size; i++){
      cout << words[i].eng << " " << words[i].rus << " " << words[i].know << endl;
  };

  FILE *file = fopen("dictionary.dat", "wb");

  fwrite(&size, sizeof(int), 1, file);
  for(int i = 0; i < size; i++){
      fwrite(&words[i], sizeof(word), 1, file);   
  };
  fclose(file);
  
  file = fopen("dictionary.dat", "rb");
  fread(&size, sizeof(int), 1, file);
  word *copyfromfile = new word[size];
  for(int i = 0; i < size; i++){
      fread(&copyfromfile[i], sizeof(word), 1, file);
  };

  cout << "From file" << endl;
  for(int i = 0; i < size; i++){
      cout << copyfromfile[i].eng << " " << copyfromfile[i].rus << " " << copyfromfile[i].know << endl;
  };


  return 0;
}