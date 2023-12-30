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

    std::cout << "\n�������� �����: ";
    std::getline(std::cin, title);

    std::cout << "��� �����������: ";
    std::getline(std::cin, artist);

    std::cout << "���� �����: ";
    std::getline(std::cin, genre);

    std::cout << "������������ �����: ";
    std::cin >> duration;

    std::cout << "��� ������ �����: ";
    std::cin >> year;

    ++trackCount;

    return Track(title, artist, duration, year, genre, 0);
}

Track Track::InputShortTrack() {
    std::string title, artist, genre;
    int duration;

    std::cout << "\n�������� �����: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "���� �����: ";
    std::getline(std::cin, genre);

    std::cout << "������������ �����: ";
    std::cin >> duration;

    ++trackCount;

    return Track(title, "", duration, 0, genre, 0);
}

std::ostream& operator<<(std::ostream& os, const Track& obj){
    os << "\n��������: " << obj.title << std::endl;
    os << "�����������: " << obj.artist << std::endl;
    os << "������������: " << obj.duration << " seconds" << std::endl;
    os << "��� ������: " << obj.year << std::endl;
    os << "����: " << obj.genre << std::endl;
    os << "���-�� �������������: " << obj.listens << std::endl;
    return os;
}

void Track::DisplayInfo() const {
    std::cout << std::left << "��������: " << std::setw(25) << title;
    std::cout << std::left << "������������: " << duration << std::setw(10) << " ���";
    std::cout << "����: " << genre << std::endl;
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