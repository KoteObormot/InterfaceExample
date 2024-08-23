// InterfaceExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class IКрутящиеся
{
public:
    virtual std::string Крутим() = 0;
};

/////////////////Абстрактный класс Велосипед/////////////////////////////////////////////////////////////////////////////////////////
class Велосипед: public IКрутящиеся
{
public:
    IКрутящиеся* _pЧтоТоНаБорту;

    int КолвоРулей;
    int КолвоСедел;
    bool Багажник;

    virtual std::string  Ехать() = 0;
};
/////////////////Абстрактный класс Кофемолка/////////////////////////////////////////////////////////////////////////////////////////
class Кофемолка :public IКрутящиеся
{
public:
    int длинаКабеля;
    int количествоНожей;
    bool кнопкаВклВыкл;

    virtual std::string  Молоть() = 0;
};
/////////////////Абстрактный класс Мясорубка/////////////////////////////////////////////////////////////////////////////////////////
class Мясорубка :public IКрутящиеся
{
public:
    int количествоНожей;


    virtual std::string  Молоть() = 0;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ВелосипедОбычный : public Велосипед
{
public:

    virtual std::string  КрутимПедали() = 0;

    std::string  Ехать()
    {
        return Крутим();
    }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ЕВелосипед : public Велосипед
{
   
public:

    virtual std::string  КрутитьсяМотор() = 0;

    std::string  Ехать()
    {
        return Крутим();
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class КофемолкаОбычная : public Кофемолка
{
public:

    virtual std::string  КрутитьРучку() = 0;

    std::string  Молоть()
    {
        return Крутим();
    }
};

class ЕКофемолка : public Кофемолка
{
public:

    virtual std::string  КрутитьМотор() = 0;

    std::string  Молоть()
    {
        return Крутим();
    }
};

class МясорубкаОбычная : public Мясорубка
{

public:

    virtual std::string  КрутимРучку() = 0;

    std::string  Молоть()
    {
        return Крутим();
    }
};

class ЕМясорубка : public Мясорубка
{
    
public:
    
    virtual std::string  КрутимМотор() = 0;

    std::string  Молоть()
    {
        return Крутим();
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ВелосипедBrown : public ВелосипедОбычный
{
public:
    
    ВелосипедBrown(IКрутящиеся *pk)
    {
        _pЧтоТоНаБорту = pk;
    }

    std::string  Крутим()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", КрутимПедали().c_str(), _pЧтоТоНаБорту->Крутим().c_str());
        return std::string(buffer);
    }

    std::string  КрутимПедали()
    {
        return std::string("ВелосипедBrown. Скрипят педали, едем на велосипеде кофе пить. На борту");
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ВелосипедAriston : public ЕВелосипед
{

public:

    ВелосипедAriston(IКрутящиеся* pk)
    {
        _pЧтоТоНаБорту = pk;
    }

    std::string  Крутим()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", КрутитьсяМотор().c_str(), _pЧтоТоНаБорту->Крутим().c_str());
        return std::string(buffer);
    }

    std::string  КрутитьсяМотор()
    {
        return std::string("ВелосипедAriston. Мотор урчит, едем на велосипеде кофе пить. На борту");
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class КофемолкаBrown : public КофемолкаОбычная
{
public:

    std::string  КрутитьРучку()
    {
        return "КофемолкаBrown. Крутим ручку кофемолки, мелем кофе.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class КофемолкаAriston : public ЕКофемолка
{
public:

    std::string  КрутитьМотор()
    {
        return "КофемолкаAriston. Мотор кофемолки урчит, мелем кофе.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class МясорубкаBrown : public МясорубкаОбычная
{
public:

    std::string  Крутим()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", КрутимПедали().c_str(), _pЧтоТоНаБорту->Крутим().c_str());
        return std::string(buffer);
    }

    std::string  КрутимПедали()
    {
        return std::string("ВелосипедBrown. Скрипят педали, едем на велосипеде кофе пить. На борту");
    }

    std::string  КрутитьРучку()
    {
        return "МясорубкаBrown. Скрипим ручкой мясорубки, мелем мясо. Фарш идет.";
    }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class МясорубкаAriston : public ЕМясорубка
{
public:

    std::string  КрутитьМотор()
    {
        return "МясорубкаAriston. Мотор мясорубки урчит, мелем мясо. Фарш идет.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Hello World!\n";
    IКрутящиеся *devices[] = { new МясорубкаBrown, new МясорубкаAriston, new ВелосипедAriston(new КофемолкаBrown), new ВелосипедBrown(new КофемолкаAriston)};

    for (int i = 0; i < 4; i++)
        std::cout << devices[i]->Крутим() << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
