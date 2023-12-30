#include "Musiclibrary.h"
#include <iostream>

MusicLibrary::MusicLibrary(int numArtists, int numPlaylists)
    : numArtists(numArtists), numPlaylists(numPlaylists) {}

MusicLibrary::MusicLibrary(const MusicLibrary& other) {
    numArtists = other.numArtists;
    numPlaylists = other.numPlaylists;
    allArtists = other.allArtists;
    allPlaylists = other.allPlaylists;
}

MusicLibrary::MusicLibrary() {};

void MusicLibrary::AddArtist(const Artist& artist) {
    allArtists.push_back(artist);
}

void MusicLibrary::AddPlaylist(const Playlist& playlist) {
    allPlaylists.push_back(playlist);
}

Artist* MusicLibrary::GetArtist(int index) {
    return &allArtists.at(index);
}

Playlist GetPlaylist(MusicLibrary& obj, int index) {
    return obj.allPlaylists.at(index);
}