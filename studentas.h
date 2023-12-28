#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <numeric>
#include <list>
#include <cctype>
#include <iterator>

#ifndef ZMOGUS_H
#define ZMOGUS_H

using namespace std;

class zmogus {
private:
    std::string vardas;
    std::string pavarde;
    std::list<int> nd;
    int egz;
    float vidur;
    float median;
    float galutinis;

public:
    zmogus(): egz(0), vidur(0), median(0), galutinis(0) {}
    zmogus(istream& is);
    istream& readzmogus(istream&);
    void clearND() { nd.clear(); }

    ~zmogus() {}

    void setVardas(const string& v) { vardas = v; }
    void setPavarde(const string& p) { pavarde = p; }
    void setEgzaminas(int egzaminas) { egz = egzaminas; }
    void setVid(float vid) { vidur = vid; }
    void setMed(float med) { median = med; }
    void setGalutinis(float gal) { galutinis = gal; }
    void addPazymys(int paz) { nd.push_back(paz); }


    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    float getVid() const { return vidur; }
    float getMed() const { return median; }
    float getGalutinis() const { return galutinis; }
    int getEgzaminas() const { return egz; }
    const list<int>& getPaz() const { return nd; }

};

void processLine(const std::string& line, std::list<zmogus>& grupe);
void inputStudentData(std::list<zmogus>& grupe);
void processFileData(std::list<zmogus>& grupe);
void printStudentData(const std::list<zmogus>& grupe, int choice);
void generateRandomGrades(zmogus& zmog, int ndskaicius);
bool rikiavimas(const zmogus& a, const zmogus& b);
void printStudentDataToFile(const std::list<zmogus>& grupe, int choice, std::ofstream& outputFile);

void generateStudentFile(int numStudents, int numHomeworks, const std::string& filename);
void generateStudentFilesAutomatically();
void calculateGalutinisForFile(const std::string& filename, std::string rusiavimoKriterijus, int strategija);
bool compareStudents(const zmogus& a, const zmogus& b);
bool rikiavimaspav(const zmogus& a, const zmogus& b);
void calculateMedian(zmogus& laikinas);
void calculateAverage(zmogus& laikinas);
void calculateGalutinis(zmogus& student);

#endif //ZMOGUS_H
