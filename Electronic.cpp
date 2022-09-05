#include "Electronic.h"
#include <iostream>

namespace electronic
{
    Monitor::Monitor(double diagonal): _diagonal(diagonal)
    {}

    Monitor::Monitor(std::string name, double diagonal): _name(name), _diagonal(diagonal)
    {}

    std::string Monitor::get_name()
    {
        return _name;
    }

    void Monitor::Show()
    {
        std::cout<<"Монитор. Название "<<_name<<". Диагональ экрана: "<<_diagonal<<"'."<<std::endl;
    }

    Monitor::~Monitor()
    {}

    Televisor::Televisor(std::string name, double diagonal, std::string quality): _name(name), _quality(quality), Monitor(diagonal)
    {}
    
    std::string Televisor::get_name()
    {
        return _name;
    }

    void Televisor::Show()
    {
        std::cout<<"Телевизор. Название "<<_name<<". Диагональ экрана: "<<_diagonal<<". Качество изображения: "<<_quality<<"."<<std::endl;
    }

    Televisor::~Televisor()
    {}
    
    Computer::Computer(double cpu, int ram, int hdd): _cpu(cpu), _ram(ram), _hdd(hdd)
    {}

    Computer::Computer(std::string name, double cpu, int ram, int hdd): _name(name), _cpu(cpu), _ram(ram), _hdd(hdd)
    {}

    std::string Computer::get_name()
    {
        return _name;
    }

    void Computer::Show()
    {
        std::cout<<"Компьютер. Название: "<<_name<<". Частота процессора: "<<_cpu<<"ГГц"<<std::endl;
        std::cout<<"Оперативная память: "<<_ram<<"Гб. Жесткий диск: "<<_hdd<<"Гб."<<std::endl;
    }

    Computer::~Computer()
    {}

    Console::Console(std::string name, double cpu, int ram, int hdd, std::string version): _name(name), Computer(cpu, ram, hdd) , _version(version)
    {}

    std::string Console::get_name()
    {
        return _name;
    }

    void Console::Show()
    {
        std::cout<<"Игровая приставка. Название: "<<_name<<". Частота процессора: "<<_cpu<<"ГГц"<<std::endl;
        std::cout<<"Опативная память: "<<_ram<<"Гб. Жестий диск: "<<_hdd<<"Гб. Версия: "<<_version<<std::endl;
    }
    
    Console::~Console()
    {}
    
    Laptop::Laptop(std::string name, int battery, double diagonal, double cpu, int ram, int hdd): _name(name), _battery(battery), Monitor(diagonal), Computer(cpu, ram, hdd)
    {}

    std::string Laptop::get_name()
    {
        return _name;
    }

    void Laptop::Show()
    {
        std::cout<<"Ноутбук. Название: "<<_name<<". Емкость батареи: "<<_battery<<"мА. Диагональ: "<<_diagonal<<"'."<<std::endl;
        std::cout<<"Частота процессора: "<<_cpu<<"ГГц. Оперативная память: "<<_ram<<"Гб. Жесткий диск: "<<_hdd<<"Гб."<<std::endl;
    }

    Laptop::~Laptop()
    {}
}