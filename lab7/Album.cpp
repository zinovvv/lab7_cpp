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

    std::cout << "\n�������� �������: ";
    std::getline(std::cin, title);

    std::cout << "��� �����������: ";
    std::getline(std::cin, artist);

    std::cout << "��� ������ �������: ";
    std::cin >> year;

    std::cout << "���-�� ������ � �������: ";
    std::cin >> num_tracks;

    //�������� ������� ����� ������� ������ InputShortTrack � ����������� � ������ tracks
    for (int i = 0; i < num_tracks; ++i) {
        std::cout << "������� ���������� � ����� #" << (i + 1) << std::endl;
        Track track = Track::InputShortTrack();
        tracks.push_back(track);
    }

    //������� ������ ��� newAlbum
    Album* newAlbum = new Album(title, artist, year, num_tracks, tracks);
    newAlbum->SetTracks(tracks);
    return newAlbum;
}

void Album::SetTracks(const std::vector<Track>& newTracks) {
    tracks = newTracks;
}

std::ostream& operator<<(std::ostream& os, const Album& obj) {
    os << "\n��������: " << obj.title << std::endl;
    os << "�����������: " << obj.artist << std::endl;
    os << "��� ������: " << obj.year << " seconds" << std::endl;
    os << "���-�� ������: " << obj.numTracks << std::endl;
    for (const Track& track : obj.tracks) {
        track.DisplayInfo();
    }
    return os;
}

Album::~Album() {};