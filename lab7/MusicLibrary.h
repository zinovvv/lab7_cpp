#pragma once

#include "Artist.h"
#include "Playlist.h"
#include "Favorites.h"
#include "ObjectList.h"
#include <string>
#include <vector>

//Заглавный класс "Музыкальная библиотека", в котором содержатся векторы с артистами и плейлистами
class MusicLibrary {
private:
    int numArtists;
    int numPlaylists;
    std::vector<Artist> allArtists;
    std::vector<Playlist> allPlaylists;

public:
    //Конструкторы
    MusicLibrary(int numArtists, int numPlaylists);
    MusicLibrary(const MusicLibrary& other);
    MusicLibrary();

    //Добавление артиста
    void AddArtist(const Artist& artist);

    //Добавление плейлиста
    void AddPlaylist(const Playlist& playlist);

    //Метод возврата указателя на артиста по определенному индексу
    Artist* GetArtist(int index);

    //Метод возврата плейлиста по индексу
    //Playlist GetPlaylist(int index);
    friend Playlist GetPlaylist(MusicLibrary &obj, int index);

    //Деструктор
    ~MusicLibrary() = default;
};