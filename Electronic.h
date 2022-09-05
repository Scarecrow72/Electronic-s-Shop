#pragma once
#include <string>

namespace electronic
{
    class IElectronic
    {
    public:
        virtual void Show() = 0;
        virtual std::string get_name()=0;
        
        virtual ~IElectronic() = default;
    };

    class Monitor: virtual public IElectronic
    {
    private:
        std::string _name;

    public:
        Monitor(double diagonal);
        Monitor(std::string name, double diagonal);
        
        void Show() override;
        std::string get_name() override;
        
        ~Monitor();

    protected:
        double _diagonal;
    };

    class Computer: virtual public IElectronic
    {
    private:
        std::string _name;

    public:
        Computer(double cpu, int ram, int hdd);
        Computer(std::string name, double cpu, int ram, int hdd);
        
        std::string get_name() override;
        void Show() override;
        
        ~Computer();

    protected:
        double _cpu;
        int _ram, _hdd;
    };
    
    class Televisor final: public Monitor
    {
    private:
        std::string _name;

    public:
        Televisor(std::string name, double diagonal, std::string quality);

        void Show() override;
        std::string get_name() override;

        ~Televisor();

    protected:
        std::string _quality;
    };

    class Console final: public Computer
    {
    private:
        std::string _name;

    public:
        Console(std::string name, double cpu, int ram, int hdd, std::string version);
        
        void Show() override;
        std::string get_name() override;

        ~Console();

    protected:
        std::string _version;
    };

    class Laptop final: virtual public Monitor, Computer
    {
    private:
        std::string _name;

    public:
        Laptop(std::string name, int battery, double diagonal, double cpu, int ram, int hdd);
        
        void Show() override;
        std::string get_name() override;
        
        ~Laptop();

    protected:
        int _battery;
    };
}

void show_menu(int category, electronic::IElectronic* devices[]);