#pragma once

#include <string>

//Класс "Трек"
class Track{
private:

    std::string title;
    std::string artist;
    int duration;
    int year;
    std::string genre;
    int listens = 0;
    //Статическое поле(Общее кол-во треков)
    static int trackCount;
public:
    //Конструктор с параметрами
    Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre, int listens);

    //Конструктор копирования с одним параметром
    Track(const Track& other);

    //Пустой конструктор
    Track();

    //Ввод трека
    static Track InputTrack();

    //Короткй вариант ввода
    static Track InputShortTrack();

    //Вывод трека с помощью перегруженного оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Track& obj);
    
    //Короткий вывод трека
    void DisplayInfo() const;

    //Перегрузка оператора ++(префиксный)
    Track& operator++();

    //Перегрузка оператора ++(постфиксный)
    Track operator++(int);

    int GetListens();

    std::string GetTitle();

    //Деструктор
    ~Track() = default;
};
 