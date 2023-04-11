#ifndef F_P_L_IDE_DATA_H
#define F_P_L_IDE_DATA_H

#include <iostream>
#include <string>
#include <QString>

class Data {
public:
    Data();
    Data(std::string fileChoseName);
    ~Data();

    std::string currentFileEditing;
    std::string fileChoose;
};


#endif
