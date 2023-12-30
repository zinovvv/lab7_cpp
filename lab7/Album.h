#pragma once

#include <string>
#include <vector>
#include "Track.h"  // Включаем заголовочный файл класса Track

//Класс "Альбом", содержит в себе вектор треков
class Album{
private:
    std::string title;
    std::string artist;
    int year;
    int numTracks;
    std::vector<Track> tracks;

public:
    //Конструкторы
    Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks);
    Album(const Album& other);
    Album();

    //Ввод альбома, возвращает указатель
    Album* InputAlbum();

    //Заполнение вектора tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //Перегрузка оператора << для вывода информации
    friend std::ostream& operator<<(std::ostream& os, const Album& obj);

    //Деструктор
    ~Album();
};