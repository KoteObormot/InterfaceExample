// InterfaceExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class I����������
{
public:
    virtual std::string ������() = 0;
};

/////////////////����������� ����� ���������/////////////////////////////////////////////////////////////////////////////////////////
class ���������: public I����������
{
public:
    I����������* _p������������;

    int ����������;
    int ����������;
    bool ��������;

    virtual std::string  �����() = 0;
};
/////////////////����������� ����� ���������/////////////////////////////////////////////////////////////////////////////////////////
class ��������� :public I����������
{
public:
    int �����������;
    int ���������������;
    bool �������������;

    virtual std::string  ������() = 0;
};
/////////////////����������� ����� ���������/////////////////////////////////////////////////////////////////////////////////////////
class ��������� :public I����������
{
public:
    int ���������������;


    virtual std::string  ������() = 0;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������������� : public ���������
{
public:

    virtual std::string  ������������() = 0;

    std::string  �����()
    {
        return ������();
    }

};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������� : public ���������
{
   
public:

    virtual std::string  ��������������() = 0;

    std::string  �����()
    {
        return ������();
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������������� : public ���������
{
public:

    virtual std::string  ������������() = 0;

    std::string  ������()
    {
        return ������();
    }
};

class ���������� : public ���������
{
public:

    virtual std::string  ������������() = 0;

    std::string  ������()
    {
        return ������();
    }
};

class ���������������� : public ���������
{

public:

    virtual std::string  �����������() = 0;

    std::string  ������()
    {
        return ������();
    }
};

class ���������� : public ���������
{
    
public:
    
    virtual std::string  �����������() = 0;

    std::string  ������()
    {
        return ������();
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Brown : public ����������������
{
public:
    
    ���������Brown(I���������� *pk)
    {
        _p������������ = pk;
    }

    std::string  ������()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", ������������().c_str(), _p������������->������().c_str());
        return std::string(buffer);
    }

    std::string  ������������()
    {
        return std::string("���������Brown. ������� ������, ���� �� ���������� ���� ����. �� �����");
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Ariston : public ����������
{

public:

    ���������Ariston(I����������* pk)
    {
        _p������������ = pk;
    }

    std::string  ������()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", ��������������().c_str(), _p������������->������().c_str());
        return std::string(buffer);
    }

    std::string  ��������������()
    {
        return std::string("���������Ariston. ����� �����, ���� �� ���������� ���� ����. �� �����");
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Brown : public ����������������
{
public:

    std::string  ������������()
    {
        return "���������Brown. ������ ����� ���������, ����� ����.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Ariston : public ����������
{
public:

    std::string  ������������()
    {
        return "���������Ariston. ����� ��������� �����, ����� ����.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Brown : public ����������������
{
public:

    std::string  ������()
    {
        char buffer[300];
        sprintf_s(buffer, sizeof(buffer), "%s %s", ������������().c_str(), _p������������->������().c_str());
        return std::string(buffer);
    }

    std::string  ������������()
    {
        return std::string("���������Brown. ������� ������, ���� �� ���������� ���� ����. �� �����");
    }

    std::string  ������������()
    {
        return "���������Brown. ������� ������ ���������, ����� ����. ���� ����.";
    }


};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ���������Ariston : public ����������
{
public:

    std::string  ������������()
    {
        return "���������Ariston. ����� ��������� �����, ����� ����. ���� ����.";
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    setlocale(LC_ALL, "");
    std::cout << "Hello World!\n";
    I���������� *devices[] = { new ���������Brown, new ���������Ariston, new ���������Ariston(new ���������Brown), new ���������Brown(new ���������Ariston)};

    for (int i = 0; i < 4; i++)
        std::cout << devices[i]->������() << std::endl;

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
