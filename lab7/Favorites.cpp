#include "Favorites.h"
#include <iostream>

//����� ������������ �������� ������ � ������������ ������������ ������ � �����������

Favorites::Favorites(const std::string& title, int numTracks, int numAlbums) :
    Playlist::Playlist(title, numTracks, numAlbums) {};

void Favorites::AddTrack(Track& track) {
    tracks.push_back(track);
}

void Favorites::CallBaseAddTrack(Track& track) {
    Playlist::AddTrack(track);
    std::cout << "������������ ���������� ������ �������� ������ � ������� ��� �� ������������ ������" << std::endl;
}

//���������� ��������� ������������ ������� ������������ ������ �������� �������� ������
void Favorites::operator=(Playlist& obj) {
    this->numTracks = obj.GetNumTracks();
    this->numAlbums = obj.GetNumAlbums();
    this->tracks = obj.GetTracks();
    this->albums = obj.GetAlbums();
}

void Favorites::Display() {
    std::cout << "����������� �����" << std::endl;
    for (const Track& track : tracks) {
        std::cout << track << std::endl;
    }
    for (const Album& album : albums) {
        std::cout << album << std::endl;
    }
}