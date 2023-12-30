#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& title, int numTracks, int numAlbums)
    : title(title), numTracks(numTracks), numAlbums(numAlbums) {}

Playlist::Playlist(const Playlist& other) {
    numTracks = other.numTracks;
    numAlbums = other.numAlbums;
    tracks = other.tracks;
    albums = other.albums;
}

Playlist::Playlist() {};

void Playlist::AddTrack(Track& track) {
    tracks.push_back(track);
}
void Playlist::operator+(Track& track) {
    this->tracks.push_back(track);
}

void Playlist::SetTracks(const std::vector<Track>& newTracks) {
    tracks = newTracks;
}

void Playlist::Display() {
    std::cout << "������� �����" << std::endl;
    for (const Track& track : tracks) {
        std::cout << track << std::endl;
    }
    for (const Album& album : albums) {
        std::cout << album << std::endl;
    }
}

void Playlist::CallVirtualDisplay() {
    std::cout << "����� ����������� ������� ����� �������������" << std::endl;
    Display();
}

void Playlist::DeleteTrack() {
    int number;
    while (true) {
        try {
            std::cout << "������� ����� �����, ������� ������ �������:" << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number < 1 || number> tracks.size()) {
                throw std::out_of_range("������������ ����� �����");
            }
            tracks.erase(tracks.begin() + number - 1);
            --numTracks;
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "������ �������� �����: " << e.what() << std::endl;
        }
    }
}

void Playlist::AddAlbum(Album& album) {
    albums.push_back(album);
}

void Playlist::SetAlbums(const std::vector<Album>& newAlbums) {
    albums = newAlbums;
}

std::ostream& operator<<(std::ostream& os, const Playlist& obj) {
    for (const Track& track : obj.tracks) {
        std::cout << track << std::endl;
    }
    for (const Album& album : obj.albums) {
        std::cout << album << std::endl;
    }
    return os;
}


void Playlist::DeleteAlbum() {
    int number;
    while (true) {
        try {
            std::cout << "������� ����� �������, ������� ������ �������: " << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number<1 || number>albums.size()) {
                throw std::out_of_range("������������ ����� �������");
            }
            albums.erase(albums.begin() + number - 1);
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "������ �������� �������: " << e.what() << std::endl;
        }
    }
}

void Playlist::SortingByListens() {
    std::sort(this->GetTracks().begin(), this->GetTracks().end(),
        [](Track& a, Track& b) {
            return a.GetListens() > b.GetListens();
        });
}

void Playlist::FindTrackByName() {
    std::string trackToFind;
    std::cout << "������� �������� ����� ��� ������: ";
    std::getline(std::cin, trackToFind);

    auto it = std::find_if(tracks.begin(), tracks.end(), [&trackToFind](Track& track) {
        return track.GetTitle() == trackToFind;
        });

    if (it != tracks.end()) {
        std::cout << "���� ������: " << *it << std::endl;
    }
    else {
        std::cout << "���� �� ������." << std::endl;
    }
}