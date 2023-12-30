#pragma once
#include "Album.h"
#include <string>
#include <vector>
#include "Playlist.h"

class Favorites : public Playlist {

public:

	Favorites(const std::string& title, int numTracks, int numAlbums);

	void AddTrack(Track& track);

	void CallBaseAddTrack(Track& track);

	void operator=(Playlist& obj);

	void Display() override;
};