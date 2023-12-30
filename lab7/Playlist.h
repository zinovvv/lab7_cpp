#pragma once

#include "DeleteItem.h"
#include "Album.h"
#include <string>
#include <vector>
#include <algorithm>

//����� "��������", �������� ������ ������ � ������ ��������
class Playlist : public DeleteItem {
protected:
    std::string title;
    int numTracks;
    int numAlbums;
    std::vector<Track> tracks;
    std::vector<Album> albums;

public:
    //������������
    Playlist(const std::string& title, int numTracks, int numAlbums);
    Playlist(const Playlist& other);
    Playlist();

    //���������� ����� � ��������
    void AddTrack(Track& track);

    void operator+(Track& track);

    //���������� ������� tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //����������� ����� ������ ���������� � �����
    virtual void Display();

    void CallVirtualDisplay();

    void DeleteTrack();

    //���������� �������
    void AddAlbum(Album& album);

    //���������� ������� albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    friend std::ostream& operator<<(std::ostream& os, const Playlist& obj);

    //�������� �������
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

    //����������
    ~Playlist() = default;
};