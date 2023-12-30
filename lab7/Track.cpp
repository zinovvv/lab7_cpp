#include "Track.h"
#include <iostream>
#include <iomanip>

Track::Track(const std::string& title, const std::string& artist, int duration, int year, const std::string& genre, int listens)
    :title(title), artist(artist), duration(duration), year(year), genre(genre), listens(listens) {
    ++trackCount;
}

Track::Track(const Track& other) {
    title = other.title;
    artist = other.artist;
    duration = other.duration;
    year = other.year;
    genre = other.genre;
    listens = other.listens;
}

Track::Track() {};

Track Track::InputTrack() {
    std::string title, artist, genre;
    int duration, year;

    std::cout << "\nНазвание трека: ";
    std::getline(std::cin, title);

    std::cout << "Имя исполнителя: ";
    std::getline(std::cin, artist);

    std::cout << "Жанр трека: ";
    std::getline(std::cin, genre);

    std::cout << "Длительность трека: ";
    std::cin >> duration;

    std::cout << "Год выхода трека: ";
    std::cin >> year;

    ++trackCount;

    return Track(title, artist, duration, year, genre, 0);
}

Track Track::InputShortTrack() {
    std::string title, artist, genre;
    int duration;

    std::cout << "\nНазвание трека: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Жанр трека: ";
    std::getline(std::cin, genre);

    std::cout << "Длительность трека: ";
    std::cin >> duration;

    ++trackCount;

    return Track(title, "", duration, 0, genre, 0);
}

std::ostream& operator<<(std::ostream& os, const Track& obj){
    os << "\nНазвание: " << obj.title << std::endl;
    os << "Исполнитель: " << obj.artist << std::endl;
    os << "Длительность: " << obj.duration << " seconds" << std::endl;
    os << "Год выхода: " << obj.year << std::endl;
    os << "Жанр: " << obj.genre << std::endl;
    os << "Кол-во прослушиваний: " << obj.listens << std::endl;
    return os;
}

void Track::DisplayInfo() const {
    std::cout << std::left << "Название: " << std::setw(25) << title;
    std::cout << std::left << "Длительность: " << duration << std::setw(10) << " сек";
    std::cout << "Жанр: " << genre << std::endl;
}

Track& Track::operator++() {
    ++listens;
    return *this;
}

Track Track::operator++(int) {
    Track temp = *this;
    ++listens;
    return temp;
}

int Track::trackCount = 0;

int Track::GetListens(){
    return this->listens;
}

std::string Track::GetTitle() {
    return this->title;
}