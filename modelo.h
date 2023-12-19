#ifndef MODELO_H
#define MODELO_H

#include <iostream>
using namespace std;

class Modelo
{
private:
    int time;
    int date;
    string taskName;
public:
    Modelo();
    Modelo(string taskName,int date, int time);
    void setTime(int time);
    void setDate(int date);
    void setTaskName(string taskName);

    int getTime();
    int getDate();
    string getTaskNake;

};

#endif // MODELO_H
