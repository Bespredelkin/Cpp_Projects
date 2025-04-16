#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctype.h>
#include <stdio.h>
using namespace std;

class Educational_administration; // Существует учебное управление
class Psychologist;               // Существует психолог

// Класс студента
class Student
{
    friend Educational_administration; // Accoциативный класс
    Psychologist* psychologist;        // Указатель на психолога

private:
    const std::string firstname;   // Имя студента
    const std::string secondname;  // Фамилия студента
    const std::string group;       // Группа студента
    int age;                       // Возраст студента
    int money;                     // Деньги студента
    int time_student;              // Время бодрствованья студента
    int time_until_end_of_the_day; // Общее время бота студента
    int time_until_exam;           // Общее время до экзамена
    int time_bot;                  // Общее время бота студента
    int number_of_scolarships;     // Количество стипендий

public:
    int HP; // Здоровье студента которое видит психолог

    // Конструктор студента
    Student(std::string p_firstname,
        std::string p_secondname,
        std::string p_group,
        int p_age,
        int p_HP = 100,
        int p_money = 100,
        int p_time_student = 0,
        int p_time_until_end_of_the_day = 24,
        int p_time_until_exam = 120 * 24,
        int p_time_bot = 0,
        int p_number_of_scolarships = 0)
        : psychologist(NULL)
        , firstname(p_firstname)
        , secondname(p_secondname)
        , group(p_group)
        , age(p_age)
        , HP(p_HP)
        , money(p_money)
        , time_student(p_time_student)
        , time_until_end_of_the_day(p_time_until_end_of_the_day)
        , time_until_exam(p_time_until_exam)
        , time_bot(p_time_bot)
        , number_of_scolarships(p_number_of_scolarships) {}

    // Деструктор
    ~Student() {};

    // Метод указывания на психолога
    void SetPsychologist(Psychologist* somePsychologist)
    {
        psychologist = somePsychologist;
    }

    // Метод получения всей информации о студенте
    void Print()
    {
        std::cout << "\nFirstname: " << firstname
            << "\nSecondname: " << secondname
            << "\nGroup: " << group
            << "\nAge: " << age
            << "\nHP: " << HP
            << "\nMoney: " << money
            << "\nTime witout sleeping: " << time_student
            << "\nTime until end of the day: " << time_until_end_of_the_day
            << "\nTime until exam: " << time_until_exam
            << "\nTime the student studied in the semester: " << time_bot << std::endl;
    }

    // Получение значения здоровья  
    int GetHP()
    {
        std::cout << "\nHP: ";
        return HP;
    }

    // Получения информации о деньгах 
    int GetMoney()
    {
        std::cout << "\nMoney: ";
        return money;
    }

    // Получения оставшегося времени в сутках
    int GetTimeUntilEndOfTheDay()
    {
        std::cout << "\nTime until end of the day: ";
        return time_until_end_of_the_day;
    }

    // Метод для еды
    void Eating(int time)
    {
        Time24(time);
        if (money - 1 * time <= 0)
        {
            throw std::invalid_argument("You are homeless.\n");
        }
        HP = HP + 1 * time;
        time_student = time + time_student;
        money = money - 1 * time;
    }

    // Метод для учебы в общаге
    void Studying_yourself(int time)
    {
        Time24(time);
        if (time_student <= 24)
        {
            HP = HP - 2 * time;
            time_student = time + time_student;
            time_bot = time_bot + time;
        }
        else
        {
            HP = HP - 6 * time;
            time_student = time + time_student;
            time_bot = time_bot + time / 2;
        }
    }

    // Метод для учебы на паре
    void Studying_lectures(int time)
    {
        Time24(time);
        if (time_student <= 24)
        {
            HP = HP - 1 * time;
            time_student = time + time_student;
            time_bot = time_bot + time;
        }
        else
        {
            HP = HP - 3 * time;
            time_student = time + time_student;
            time_bot = time_bot + time / 2;

        }
    }

    // Метод для сна
    void Sleeping(int time)
    {
        Time24(time);
        if (time <= 6)
        {
            HP = HP + 2 * time;
            time_student = time + time_student;
        }
        else
        {
            HP = HP + 6 * time;
            time_student = 0;
        }
    }

    // Метод для работы в лабе
    void Working(int time)
    {
        Time24(time);
        if (time_student <= 24)
        {
            HP = HP - 1 * time;
            time_student = time + time_student;
        }
        else
        {
            HP = HP - 2 * time;
            time_student = 0;
        }
        money = money + 1 * time;
    }

    // Метод для развлечений
    void Entertainment(int time)
    {
        Time24(time);
        if (money - 2 * time <= 0)
        {
            throw std::invalid_argument("You are homeless.\n");
        }
        else if (time_student <= 24)
        {
            HP = HP + 6 * time;
            time_student = time + time_student;
        }
        else
        {
            HP = HP + 2 * time;
            time_student = time + time_student;
        }
        money = money - 2 * time;
    }

    // Метод проверки здоровья
    void Check_HP()
    {
        if (HP <= 0)
        {
            std::cout << "Went to academ" << std::endl;
            std::cout << "End of the game" << std::endl;
            exit(0);
        }
    }

    // Метод экзаменовки
    void Exams()
    {
        if (time_bot <= 800)
        {
            std::cout << "Bye bye, go from here" << std::endl;
            std::cout << "End of the game" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "You did it!" << std::endl;
            std::cout << "End of the game" << std::endl;
            exit(0);
        }
    }

    // Метод проверки времени до конца дня
    void TimeDay(int time)
    {
        time_until_end_of_the_day = time_until_end_of_the_day - time;
        if (time_until_end_of_the_day < 0)
        {
            time_until_end_of_the_day = time_until_end_of_the_day + 24;
        }
    }

    // Метод проверки времени до начала экзаменов
    void TimeExam(int time)
    {
        time_until_exam = time_until_exam - time;
        if (time_until_exam <= 0) Exams();
    }

    // Метод раздачи стипендии
    void scholarship()
    {
        int scolarship_required = (120 * 24 - time_until_exam) / (30 * 24);
        if (scolarship_required > number_of_scolarships)
        {
            number_of_scolarships++;
            money = money + 100;
        }
    }

    // Метод ограничения времени действий
    void Time24(int time)
    {
        if (time > 24 || time < 0)
        {
            throw std::invalid_argument("\nYou can not do something more than 24 hours or less than 0 hours.\n");
        }
    }
};

// Класс учебного управления
class Educational_administration
{
public:
    std::string administrator; // Имя замдекана 
    int students;              // Количество студентов

    // Конструктор учебного управления
    Educational_administration(std::string p_administrator = "Lisovsky", int p_students = 250)
        : administrator(p_administrator), students(p_students) {}

    // Деструктор
    ~Educational_administration() {};

    // Метод получения информации об учебном управлении
    void Print_administration()
    {
        std::cout << "\nAdministrator's name: " << administrator << "\nStudents number: " << students << std::endl;
    }

    // Метод ухода студента в академ
    void Academ(Student* student)
    {
        std::cout << "Went to academ" << std::endl;
        std::cout << "End of the game" << std::endl;
        exit(0);
    }

    // Метод исключения студента
    void Expel(Student* student)
    {
        std::cout << "Bye bye, go from here" << std::endl;
        std::cout << "End of the game" << std::endl;
        exit(0);
    }
};

// Класс психолога
class Psychologist
{
    Educational_administration* administrator; // Указатель на учебное управление

private:
    std::string psychologist; // Имя психолога

public:
    // Конструктор психолога
    Psychologist(Educational_administration* admin, std::string p_psychologist = "Lamion")
        : administrator(admin), psychologist(p_psychologist) {}

    // Деструктор
    ~Psychologist() {};

    // Метод получения информации о психологе
    void Print_psychologist()
    {
        std::cout << "\nPsychologist's name: " << psychologist << std::endl;
    }

    // Метод посещения психолога
    void Visit(Student* student, int time)
    {
        student->HP += 6 * time;
        Conversation();
    }

    // Метод разговора с замдеканом
    void Conversation()
    {
        std::cout << "\nConvertion with " << administrator->administrator << std::endl;
    }
};

// Функция создает студента и возращает указатель на студента
Student *CreateStudent(Psychologist& fefmPsychologist)
{
    std::cout << "\nEnter student parameters: " << std::endl; 
    std::string firstName, secondName, group;
    int age = 0;
    std::cout << "\nEnter student's firstName: ";
    std::cin >> firstName;
    for (int i = 0; i < firstName.size(); i++) {
        if (isalpha(firstName[i]) == 0)
        {
            throw std::invalid_argument("\nYou can write only english letters in firstname.");
        }
    }
    std::cout << "\nEnter student's secondName: ";
    std::cin >> secondName;
    for (int i = 0; i < secondName.size(); i++) {
        if (isalpha(secondName[i]) == 0)
        {
            throw std::invalid_argument("\nYou can write only english letters in secondname.");
        }
    }
    std::cout << "\nEnter student's group: ";
    std::cin >> group;
    std::cout << "\nEnter student's age: ";
    std::cin >> age;
    if (std::cin.fail()) throw std::invalid_argument("\nAge should be a number.");
    if (age < 0 || age > 10000)
    {
        throw std::invalid_argument("\nYou can only write a number between 0 and 10000.");
    }
    Student *pstudent = new Student(firstName, secondName, group, age);
    pstudent->SetPsychologist(&fefmPsychologist);
    return pstudent;
}

int stud_main()
{
    std::cout << "Student survival simulator" << std::endl; // Начало игры
    
    Educational_administration administrator;
    Psychologist fefmPsychologist(&administrator);

    Student* student_mass[250];

    int student_number_create = 0;
    student_mass[student_number_create] = CreateStudent(fefmPsychologist);

    int student_number = 0;

    int condition = 1000 - 7;
    int time = 0;
    while (condition != 0)
    {
        student_number = 0;
        Student& student = *student_mass[student_number];

        if (std::cin.eof()) break;
        try
        {
            std::cout << "\nWhat you wanna do?" << std::endl;
            std::cout << "\n[1] - Present student's information"
                << "\n[2] - Presenting educational administration's information"
                << "\n[3] - Presenting psychologist's information"
                << "\n[4] - Presenting student's HP"
                << "\n[5] - Presenting student's money"
                << "\n[6] - Presenting time until end of the day"
                << "\n[7] - Gonna Eat"
                << "\n[8] - Gonna Study"
                << "\n[9] - Gonna hear lecture"
                << "\n[10] - Gonna sleep"
                << "\n[11] - Gonna work"
                << "\n[12] - Gonna watch anime"
                << "\n[13] - Gonna visit psychologist"
                << "\n[14] - Gonna go to academ"
                << "\n[15] - Gonna drop out"
                << "\n[16] - Create new student"
                << std::endl;
            std::cout << "\nChoose student: " << std::endl;
            std::cin >> student_number;
            if (std::cin.fail()) throw "\nStudent number should be a number.";
            if (student_number < 0 || student_number > 249)
            {
                throw std::invalid_argument("\nYou can only write a number between 1 and 250.");
            }
            if (student_number > student_number_create)
            {
                throw std::invalid_argument("\nYou can not play with non created student.");
            }
            if (student_number) Student& student = *student_mass[student_number];
            std::cout << "\nEnter command: ";
            std::cin >> condition;
            if (std::cin.fail()) throw "\nCommand should be a number.";
            switch (condition)
            {
            case 1: // Печатает информацию о студенте
                student.Print();
                break;
            case 2: // Печатает информацию об учебном управлении
                administrator.Print_administration();
                break;
            case 3: // Печатает информацию о психологе
                fefmPsychologist.Print_psychologist();
                break;
            case 4: // Возращает состояние здоровья студента
                std::cout << student.GetHP() << std::endl;
                break;
            case 5: // Возращает количество денег у студента
                std::cout << student.GetMoney() << std::endl;
                break;
            case 6: // Возращает количество часов до конца дня
                std::cout << student.GetTimeUntilEndOfTheDay() << std::endl;
                break;
            case 7: // Еда
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Eating(time);
                break;
            case 8: // Бот
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Studying_yourself(time);
                break;
            case 9: // Посещение лекций
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Studying_lectures(time);
                break;
            case 10: // Сон
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Sleeping(time);
                break;
            case 11: // Работа в лабах
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Working(time);
                break;
            case 12: // Смотрит аниме
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                student.Entertainment(time);
                break;
            case 13: // Посещение психолога
                std::cout << "\nEnter action time in hours: ";
                std::cin >> time;
                fefmPsychologist.Visit(&student, time);
                break;
            case 14: // Уход в академ
                std::cout << std::endl;
                administrator.Academ(&student);
                break;
            case 15: // Отчисление
                std::cout << std::endl;
                administrator.Expel(&student);
                break;
            case 16: // Создание студента
                if (student_number > 249)
                {
                    throw std::invalid_argument("\nYou can not create more than 250 students.\n");
                }
                student_mass[student_number_create] = CreateStudent(fefmPsychologist); // Сохраняем в массив указатель на созданного студента
                student_number_create += 1;
                break;
            default: // Другая команда
                std::cout << "\nWrong action" << std::endl;
            }
            student.Check_HP();     // Проверяем здоровье
            student.TimeDay(time);  // Рассчитываем время
            student.TimeExam(time); // Рассчитываем время
            student.scholarship();  // Проверяем пора ли выдавать стипендию
        }
        catch (std::invalid_argument& e) // Ловиться ввод недопустимых параметров
        {
            cout << e.what();
        }
    }
    return 0;
}

int main()
{
    // Выбираем между тестом и игрой
    std::cout << "What do you want to do ? " << "\n[0] - game" << "\n[1] - test: ";
    int workTest = 0;
    std::cin >> workTest;
    if (workTest == 1)
    {
        // Массив вводных строк
        const char* array[11] =
        {
            "1FirstName\nLastName\n1\n100\n",
            "FirstName\n1LastName\n1\n100\n",
            "FirstName\nLastName\n1\nn00\n",
            "FirstName\nLastName\n1\n100000\n",
            "FirstName\nLastName\n1\n-100\n",
            "",
            "FirstName\n",
            "FirstName\nLastName",
            "FirstName\nLastName\n1",
            "FirstName\nLastName\n1\n100\nf",
            "FirstName\nLastName\n1\n100\n0\nf",
        };

        // Массив ожидаемых ошибок
        const char* except[11] =
        {
            "\nYou can write only english letters in firstname.",
            "\nYou can write only english letters in secondname.",
            "\nAge should be a number.",
            "\nYou can only write a number between 0 and 10000.",
            "\nYou can only write a number between 0 and 10000.",
            "\nAge should be a number.",
            "\nAge should be a number.",
            "\nAge should be a number.",
            "\nAge should be a number.",
            "\nStudent number should be a number.",
            "\nCommand should be a number.",

        };

        for (int t = 0; t < 11; t++) // Для каждого ввода работаем с файлом
        {
            FILE* out = fopen("test.txt", "w"); // Открываем файл
            fprintf(out, "%s", array[t]);       // Вводим строку с командами в файл
            fclose(out);                        // Закрываем файл
            freopen("test.txt", "r", stdin);    // Связываем поток ввода с созданным файлом
            std::cin.clear();                   // Сбрасываем флажок ошибки в потоке ввода
            try
            {
                stud_main();
            }

            catch (const std::invalid_argument& e) // Ловиться ввод известных недопустимых параметров
            {
                // Сравниваем ожидаемую и получаемую ошибки
                if (!strcmp( e.what(), except[t])) 
                    std::cout << "\n================================ Test Passed" << std::endl;
                else
                    std::cout << "\n================================ Test Failed. unexpected exception: " << e.what() << std::endl;
            }

            catch (const char* s) // Ловиться ввод известных недопустимых параметров
            {
                // Сравниваем ожидаемую и получаемую ошибки
                if (!strcmp(s, except[t]))
                    std::cout << "\n================================ Test Passed" << std::endl;
                else
                    std::cout << "\n================================ Test Failed. unexpected exception: " << s << std::endl;
            }

            catch (...) // Ловиться ввод неизвестных недопустимых параметров
            {
                std::cout << "\n================================ Test Failed. Unhandled exception" << std::endl;
            }
        }
    }
    else if (workTest == 0)
    {
        try {
            stud_main();
        }
        catch (std::invalid_argument& e)    // Ловиться ввод известных недопустимых параметров
        {
            cout << e.what() << std::endl;
        }
        catch (const char* s)               // Ловиться ввод известных недопустимых параметров
        {
                std::cout << s << std::endl;
        }
        catch (...)                         // Ловиться ввод неизвестных недопустимых параметров
        {
            cout << "Unknown exception" << std::endl;
        }
    }

    else
    {
        cout << "Invalid command" << std::endl; // Выбрана несуществующая команда
    }
    return 0;
}