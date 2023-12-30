#include "Favorites.h"
#include <iostream>

//Вызов конструктора базового класса в конструкторе производного класса с параметрами

Favorites::Favorites(const std::string& title, int numTracks, int numAlbums) :
    Playlist::Playlist(title, numTracks, numAlbums) {};

void Favorites::AddTrack(Track& track) {
    tracks.push_back(track);
}

void Favorites::CallBaseAddTrack(Track& track) {
    Playlist::AddTrack(track);
    std::cout << "Демонстрация перегрузки метода базового класса с вызовом его из производного класса" << std::endl;
}

//Перегрузка оператора присваивания объекту производного класса объектов базового класса
void Favorites::operator=(Playlist& obj) {
    this->numTracks = obj.GetNumTracks();
    this->numAlbums = obj.GetNumAlbums();
    this->tracks = obj.GetTracks();
    this->albums = obj.GetAlbums();
}

void Favorites::Display() {
    std::cout << "Производный класс" << std::endl;
    for (const Track& track : tracks) {
        std::cout << track << std::endl;
    }
    for (const Album& album : albums) {
        std::cout << album << std::endl;
    }
}