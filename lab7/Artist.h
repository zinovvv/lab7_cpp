#pragma once

#include "DeleteItem.h"
#include "Album.h"
#include <string>
#include <vector>

//Класс "Артист", содержит вектор альбомов
class Artist: public DeleteItem{
private:
    std::string name;
    int numAlbums;
    std::vector<Album> albums;

public:
    //Конструкторы
    Artist(const std::string& name, int numAlbums);
    Artist(const Artist& other);
    Artist();

    //Заполнение вектора albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //Вывод альбомов
    friend std::ostream& operator<<(std::ostream& os, const Artist& obj);

    //Удаление альбома
    void DeleteAlbum() override;

    //Деструктор
    ~Artist() = default;
};