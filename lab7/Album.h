#pragma once

#include <string>
#include <vector>
#include "Track.h"  // �������� ������������ ���� ������ Track

//����� "������", �������� � ���� ������ ������
class Album{
private:
    std::string title;
    std::string artist;
    int year;
    int numTracks;
    std::vector<Track> tracks;

public:
    //������������
    Album(const std::string& title, const std::string& artist, int year, int numTracks, std::vector<Track> tracks);
    Album(const Album& other);
    Album();

    //���� �������, ���������� ���������
    Album* InputAlbum();

    //���������� ������� tracks
    void SetTracks(const std::vector<Track>& newTracks);

    //���������� ��������� << ��� ������ ����������
    friend std::ostream& operator<<(std::ostream& os, const Album& obj);

    //����������
    ~Album();
};