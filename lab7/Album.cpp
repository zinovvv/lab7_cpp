#include "Album.h"
#include <iostream>

Album::Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks)
    : title(title), artist(artist), year(year), numTracks(numTracks), tracks(tracks) {}

Album::Album(const Album& other) {
    this->title = other.title;
    this->artist = other.artist;
    this->year = other.year;
    this->numTracks = other.numTracks;
    this->tracks = other.tracks;
}

Album::Album() {};

Album* Album::InputAlbum() {
    std::string title, artist;
    int year, num_tracks;

    std::cout << "\nНазвание альбома: ";
    std::getline(std::cin, title);

    std::cout << "Имя исполнителя: ";
    std::getline(std::cin, artist);

    std::cout << "Год выхода альбома: ";
    std::cin >> year;

    std::cout << "Кол-во треков в альбоме: ";
    std::cin >> num_tracks;

    //Вводятся вручную треки вызовом метода InputShortTrack и добавляются в вектор tracks
    for (int i = 0; i < num_tracks; ++i) {
        std::cout << "Введите информацию о треке #" << (i + 1) << std::endl;
        Track track = Track::InputShortTrack();
        tracks.push_back(track);
    }

    //Выделяю память для newAlbum
    Album* newAlbum = new Album(title, artist, year, num_tracks, tracks);
    newAlbum->SetTracks(tracks);
    return newAlbum;
}

void Album::SetTracks(const std::vector<Track>& newTracks) {
    tracks = newTracks;
}

std::ostream& operator<<(std::ostream& os, const Album& obj) {
    os << "\nНазвание: " << obj.title << std::endl;
    os << "Исполнитель: " << obj.artist << std::endl;
    os << "Год выхода: " << obj.year << " seconds" << std::endl;
    os << "Кол-во треков: " << obj.numTracks << std::endl;
    for (const Track& track : obj.tracks) {
        track.DisplayInfo();
    }
    return os;
}

Album::~Album() {};