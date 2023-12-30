#pragma once

#include "DeleteItem.h"
#include "Album.h"
#include <string>
#include <vector>
#include <algorithm>

//Класс "Плейлист", содержит вектор треков и вектор альбомов
class Playlist : public DeleteItem {
protected:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    //Конструкторы
    Playlist(const std::string& title, int numTracks, int numAlbums);
    Playlist(const Playlist& other);
    Playlist();

    //Добавление трека в плейлист
    void AddTrack(Track& track);

    void operator+(Track& track);

    //Заполнение вектора tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //Виртуальный метод вывода информации о треке
    virtual void Display();

    void CallVirtualDisplay();

    void DeleteTrack();

    //Добавление альбома
    void AddAlbum(Album& album);

    //Заполнение вектора albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    friend std::ostream& operator<<(std::ostream& os, const Playlist& obj);

    //Удаление альбома
    void DeleteAlbum() override;

    std::string GetTitle() {
        return title;
    }

    int GetNumTracks() {
        return numTracks;
    }

    int GetNumAlbums() {
        return numAlbums;
    }

    std::vector<Track>& GetTracks() {
        return tracks;
    }

    std::vector<Album>& GetAlbums() {
        return albums;
    }

    void SortingByListens();

    void FindTrackByName();

    //Деструктор
    ~Playlist() = default;
};