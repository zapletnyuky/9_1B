#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialnist { KN, IT, MATH, PHYSICS, TRYDN };
enum Curs { FIRST, SECOND, THIRD, FOUR };
string cursStr[] = { "I", "II", "III", "IV" };
string specialnistStr[] = { "КомпНауки", "Інформатика", "Мат+Ек", "Фіз+Інф", "ТрудНавч" };

struct Student
{
  string prizv;
  int curs;
  Specialnist specialnist;
  struct
  {
    int physic;
    int math;
  };
    union
    {
        int inform;
        int chiselni;
        int pedagog;
  };
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
void DisplayAverageGrades(Student *p, const int N);
double Procenti(Student *p, const int N);

int main()
{

  int N;
  cout << "Введіть кількість студентів: "; cin >> N;
    Student *p = new Student[N];
    Create(p, N);
    Print(p, N);
    DisplayAverageGrades(p, N);
    double proc = Procenti(p, N);
    cout << "2. Процент студентів, які отримали 4/5 з фізики: " << proc << "%" << endl;

}
void Create(Student* p, const int N)
{
  int specialnist;
 // int curs;
  for (int i = 0; i < N; i++)
  {
    cout << "Студент № " << i + 1 << ":" << endl;
    cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
    cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

cout << " прізвище: "; getline(cin, p[i].prizv);
      cout << " курс: "; cin >> p[i].curs;
    cout << " спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
    cin >> specialnist;
    cout << " оцінка з фізики : "; cin >> p[i].physic;
    cout << " оцінка з математики : "; cin >> p[i].math;
    p[i].specialnist = (Specialnist)specialnist;
    switch (p[i].specialnist)
    {
    case KN:
      cout << " оцінка з програмування : "; cin >> p[i].inform;
      break;
    case IT:
      cout << " оцінка з чисельних методів : "; cin >> p[i].chiselni;
      break;
    case MATH:
    case PHYSICS:
    case TRYDN:
      cout << " оцінка з педагогіки : "; cin >> p[i].pedagog;
      break;
    }
    cout << endl;
  }
}
void Print(Student* p, const int N)
{
  cout << "==========================================================================================================================================================="
    << endl;
  cout << "| № | Прізвище | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з програмування | Оцінка з чисельних методів | Оцінка з педагогіки |"
    << endl;
  cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------"
    << endl;
  for (int i = 0; i < N; i++)
  {
    cout << "| " << setw(2) << i + 1;
    cout << "| " << setw(9) << p[i].prizv;
    cout << "| " << setw(5) << cursStr[p[i].curs];
    cout << "| " << setw(14) << specialnistStr[p[i].specialnist];
    cout << "| " << setw(16) << p[i].physic;
    cout << "| " << setw(20) << p[i].math;
    switch (p[i].specialnist)
    {
    case KN:
      cout << "| " << setw(23) << p[i].inform << "|" << setw(29) << "|" << setw(22) << "|";
      break;
    case IT:
      cout << "| " << setw(24) << "|" << setw(28) << p[i].chiselni << "|" << setw(22) << "|";
      break;
    case MATH:
    case PHYSICS:
    case TRYDN:
      cout << "| " << setw(24) << "|" << setw(29) << "|" << setw(21) << p[i].pedagog << "|";
      break;
    }
    cout << endl;
  }
  cout << "==========================================================================================================================================================="
    << endl;
  cout << endl;
}
void DisplayAverageGrades(Student *p, const int N)
{
   // int sum = 0;
    for (int i = 0; i < N; i++)
    {
        float grade = static_cast<float>(p[i].physic + p[i].math + p[i].inform + p[i].chiselni + p[i].pedagog) / 5;
        
        cout << "1. Прізвище студента: " << p[i].prizv << ";" << " середній бал: " << grade << endl;
    }
}
double Procenti(Student *p, const int N) {
//    cout << "Прізвища студентів, які отримали з фізики 4/5:" << endl;
    int k=0;
    for (int i=0; i<N; i++)
    {
        if (p[i].physic == 4 || p[i].physic == 5)
        {
            k++;
        }

    }
  return 100.0*k/N;
}

