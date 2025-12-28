#ifndef STATIONLIST_H_INCLUDED
#define STATIONLIST_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
// Use #pragma pack to change alignment to 1 byte boundary
#pragma pack(push, 1)

using namespace std;

struct Stations {
    int Rank;
    char Name[100];
    double Frequency;
    unsigned int StartTime;
    unsigned int CloseTime;
    char Transmission[3];
};

// Use #pragma pack to change alignment to 1 byte boundary
#pragma pack(pop)

class StationList {
public:
    // Constructors
    StationList(const string& fileName);

    // Methods
    void exportEvenStationsToBinary(const string& binFile);
    int countStationsFromBinary(const string& binFile);
    string calcAveStartCloseFromBinary(const string& binFile);
    string fetchByRank(const string& binFile, int intRank);

    // Destructor
    ~StationList();

private:
    string _FileName;
    Stations* _station;
    int _numStations;

    void _alloc(int numStations);
    void _dealloc();
    void _readTextFile();
};

#endif // STATIONLIST_H_INCLUDED
