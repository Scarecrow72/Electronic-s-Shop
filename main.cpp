#include "Electronic.h"
#include <iostream>

int main()
{
    electronic::IElectronic* devices[5][5];

    devices[0][0] = new electronic::Monitor("Samsung", 22.0);
    devices[0][1] = new electronic::Monitor("LG", 24.0);
    devices[0][2] = new electronic::Monitor("Honor", 18.0);
    devices[0][3] = new electronic::Monitor("<none>", 0);
    devices[0][4] = new electronic::Monitor("<none>", 0);
    devices[1][0] = new electronic::Televisor("Samsung", 43.0, "UHD");
    devices[1][1] = new electronic::Televisor("LG", 32.0, "LED");
    devices[1][2] = new electronic::Televisor("Honor", 65.0, "LED");
    devices[1][3] = new electronic::Televisor("Sony", 88.0, "QLED");
    devices[1][4] = new electronic::Televisor("JVC", 28.7, "soft");
    devices[2][0] = new electronic::Computer("Neon", 2.3, 4, 512);
    devices[2][1] = new electronic::Computer("IBM", 6, 8, 1024);
    devices[2][2] = new electronic::Computer("<none>", 0, 0, 0);
    devices[2][3] = new electronic::Computer("Omen", 12, 16, 2048);
    devices[2][4] = new electronic::Computer("Corsair", 6, 12, 1024);
    devices[3][0] = new electronic::Console("PlayStation 3", 1.8, 8, 256, "<none>");
    devices[3][1] = new electronic::Console("XBox 360", 2.0, 6, 256, "<none>");
    devices[3][2] = new electronic::Console("PlayStation 4", 4.8, 8, 512, "Slim");
    devices[3][3] = new electronic::Console("PlayStation 4", 8.2, 16, 1024, "Pro");
    devices[3][4] = new electronic::Console("PlayStation 5", 7.6, 12, 825, "Digital Edition");
    devices[4][0] = new electronic::Laptop("Acer Aspire", 20000, 15.0, 2.4, 4, 512);
    devices[4][1] = new electronic::Laptop("HP Pavilion", 25000, 15.0, 2.4, 8, 512);
    devices[4][2] = new electronic::Laptop("Lenovo", 20000, 16.0, 3.3, 4, 512);
    devices[4][3] = new electronic::Laptop("MSI", 40000, 17.3, 6.0, 16, 1024);
    devices[4][4] = new electronic::Laptop("MacBook", 20000, 15.0, 3.3, 8, 512);

    int category=-1;
    bool search=true;
    while(search)
    {
        std::cout<<"Выберите категорию товара:"<<std::endl;
        std::cout<<"1-мониторы   | 2-телевизоры"<<std::endl;
        std::cout<<"3-компьютеры | 4-игровые приставки"<<std::endl;
        std::cout<<"5-ноутбуки   | 0-выход"<<std::endl;
        std::cin>>category;
        switch(category)
        {
        //Monitors
        case 1:
        //Televisors
        case 2:
        //Computers
        case 3:
        //Consoles
        case 4:
        //Latops
        case 5:
            {
                --category;
                for(int i=0;i<5;++i)
                {
                    if((*devices[category][i]).get_name()=="<none>")
                    {
                        continue;
                    }
                    else
                    {
                        std::cout<<i+1<<"-"<<(*devices[category][i]).get_name()<<std::endl;
                    }
                }
                while(true)
                {
                    int model;
                    std::cout<<"Введите номер интересующей вас модели или 0 для выхода: ";
                    std::cin>>model;
                    if((model<0)||(model>5))
                    {
                        continue;
                    }
                    else if(model==0)
                    {
                        break;
                    }
                    else if((*devices[category][model-1]).get_name()=="<none>")
                    {
                        continue;
                    }
                    else
                    {
                        devices[category][model-1]->Show();
                    }
                }
                break;
            }
        case 0:
            {
                search=false;
                break;
            }
        default:
            {
                std::cout<<"Введите от 1 до 5 для выбора категории или 0 для выхода."<<std::endl;
                break;
            }
        }
    }
    
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<5;++j)
        {
            delete devices[i][j];
        }
    }
    return 0;
}