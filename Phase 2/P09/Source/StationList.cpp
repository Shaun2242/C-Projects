#include <iostream>
#include "StationList.h"
#include "rankException.h"
#include <string>
#include <fstream>

using namespace std;

// Constructor
StationList::StationList(const string& fileName) {
    _FileName = fileName;
    _readTextFile();
}

// Methods
void StationList::exportEvenStationsToBinary(const string& binFile) {
    // Open binary file
    ofstream binaryFile(binFile, ios::binary);

    // Check if file opened
    if (!binaryFile) {
        cerr << "Error opening binary file" << endl;
        return;
    }

    // Write to binary
    binaryFile.write(reinterpret_cast<char*>(&_numStations), sizeof(_numStations));

    // Write even stations
    for (int i = 0; i < _numStations; i++) {
        if ((_station[i].Rank % 2) == 0) {
            binaryFile.write(reinterpret_cast<char*>(&_station[i]), sizeof(_station[i]));
        }
    }

    // Close binary file
    binaryFile.close();
}

int StationList::countStationsFromBinary(const string& binFile) {
    int count = 0;
    Stations station;

    ifstream binaryFile(binFile, ios::binary);
    if (!binaryFile) {
        cerr << "Error opening binary file" << endl;
        return count;
    }

    // Read number of stations
    binaryFile.read(reinterpret_cast<char*>(&count), sizeof(count));
    while (binaryFile.read(reinterpret_cast<char*>(&station), sizeof(station))) {
        count++;
    }

    binaryFile.close();
    return count;
}

string StationList::calcAveStartCloseFromBinary(const string& binFile) {
    int totalStartTime = 0;
    int totalCloseTime = 0;
    int count = 0;
    Stations station;

    ifstream binaryFile(binFile, ios::binary);
    if (!binaryFile) {
        cerr << "Error opening binary file" << endl;
        return "";
    }

    // Read number of stations
    binaryFile.read(reinterpret_cast<char*>(&_numStations), sizeof(_numStations));
    while (binaryFile.read(reinterpret_cast<char*>(&station), sizeof(station))) {
        totalStartTime += station.StartTime;
        totalCloseTime += station.CloseTime;
        count++;
    }

    if (count > 0) {
        int avgStartTime = totalStartTime / count;
        int avgCloseTime = totalCloseTime / count;
        return to_string(avgStartTime) + ' ' + to_string(avgCloseTime);
    }

    return "";
}

string StationList::fetchByRank(const string& binFile, int intRank) {
    Stations station;
    ifstream binaryFile(binFile, ios::binary);

    if (!binaryFile) {
        cerr << "Error opening file" << endl;
        return "";
    }

    // Read number of stations
    binaryFile.read(reinterpret_cast<char*>(&_numStations), sizeof(_numStations));
    while (binaryFile.read(reinterpret_cast<char*>(&station), sizeof(station))) {
        if (station.Rank == intRank) {
            return to_string(station.Rank) + " " + station.Name + " " + to_string(station.Frequency);
        }
    }

    binaryFile.close();
    throw rankException("ERRORNOTFOUND");
}

void StationList::_readTextFile() {
    // File object
    ifstream textFile;

    // Open file
    textFile.open(_FileName, ios::in);

    // Check if file opened successfully
    if (!textFile) {
        cerr << "Error: Opening file" << endl;
        return;
    }

    // Read number of radio stations
    textFile >> _numStations;

    // Allocate memory for stations
    _alloc(_numStations);

    // Read file contents
    for (int i = 0; i < _numStations; i++) {
        textFile >> _station[i].Rank >> _station[i].Name
                 >> _station[i].Frequency >> _station[i].StartTime
                 >> _station[i].CloseTime >> _station[i].Transmission;
    }

    // Close file
    textFile.close();
}

void StationList::_alloc(int numStations) {
    _numStations = numStations;
    _station = new Stations[_numStations];
}

void StationList::_dealloc() {
    delete[] _station;
}

// Destructor
StationList::~StationList() {
    _dealloc();
}
