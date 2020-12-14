//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <fstream>
// #include <conio.h>
#include <stdio.h>
#include <iostream>
// #include <process.h>
#include <string.h>
// #include <iomanip.h>

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
#define MAX_ARRAY_LIMIT 50

float ShowLaptopScreenSize()
{
    int LaptopScreenSize=0;
    cout<<"\nChoose the Laptop Screen Size";
    cout<<"\n1) 11.1" 
        <<"\n2) 12.0"
        <<"\n3) 13.3"
        <<"\n4) 14.0"
        <<"\n5) 15.6"
        <<"\n6) 17.3";
    cin>>LaptopScreenSize;
    switch (LaptopScreenSize)
    {
    case 1:
        return 11.1;
        break;
    case 2:
        return 12.0;
        break;
    case 3:
        return 13.3;
        break;
    case 4:
        return 14.0;
        break;
    case 5:
        return 15.6;
        break;
    case 6:
        return 17.3;
        break;
    default:
        return 0;
        break;
    }
}

// class ProcessingPower {
//     public:
//     int CPUNumber;
//     int GPUNumber;
// }

class Computer
{
public:
    char cStoreId[6];
    char cCPUBrand[50];
    char cCPUModel[20];
    char cGPUBrand[50];
    char cGPUModel[20];
    float cMemory = 0;
    char computerType;
    char storageType[10];
    float cStorage = 0;
    char os[10];
    float cPrice = 0;
};

class Laptop : public Computer
{
public:
    char lManufacturer[50];
    float laptopScreenSize;
    bool screenAvailable = true;
    int CPUNumber = 1;
    int GPUNumber = 1;
    void create()
    {
        int tempType = 0;
        cout << "\nNew Laptop Entry\n";
        cout << "\nPlease enter the following details:";
        cout << "\nID:";
        fgets(cStoreId, MAX_ARRAY_LIMIT, stdin);
        cout << "\nManufacturer: ";
        fgets(lManufacturer, MAX_ARRAY_LIMIT, stdin);
        cout << "\nCPU Brand: ";
        fgets(cCPUBrand, MAX_ARRAY_LIMIT, stdin);
        cout << "\nCPU Model: ";
        fgets(cCPUModel, MAX_ARRAY_LIMIT, stdin);
        cout << "\nGPU Brand: ";
        fgets(cGPUBrand, MAX_ARRAY_LIMIT, stdin);
        cout << "\nGPU Model: ";
        fgets(cGPUModel, MAX_ARRAY_LIMIT, stdin);
        cout << "\nMemory: ";
        cin >> cMemory;
        // cout << "\nScreen size: ";
        laptopScreenSize=ShowLaptopScreenSize();
        computerType = 'L';
        cout << "\nChoose Storage Type";
        cout << "\n1) SSD \n2) HDD \n3) SSHD";
        cin >> tempType;
        if (tempType == 1)
        {
            strcpy(storageType, "SSD");

        }
        else if (tempType == 2)
        {
            strcpy(storageType, "HDD");

        }
        else if (tempType == 3)
        {
            strcpy(storageType, "SSHD");

        }
        else
        {
            strcpy(storageType, "No entry");
        }
        cout << "\nStorage: ";
        cin >> cStorage;
        cout << "\nChoose OS Type";
        cout << "\n1) Mac \n2) Windows \n3) Linux";
        cin >> tempType;
        if (tempType == 1)
        {
           
           strcpy(os, "Mac");
        }
        else if (tempType == 2)
        {
            strcpy(os, "Windows");
        }
        else if (tempType == 3)
        {
            strcpy(os, "Linux");
        }
        else
        {
            strcpy(os, "No entry");

        }
        cout << "\nPrice: ";
        cin >> cPrice;
        cout << "\n\nLaptop record added..";
    }
    int input(Laptop obj)
    {
        ofstream fileObj;
        fileObj.open("Data.txt", ios::app);
        fileObj.write((char *)&obj, sizeof(obj));
        return 0;
    }
    int printRecords()
    {
        ifstream file_obj;
        file_obj.open("Data.txt", ios::in);
        Laptop obj;
        file_obj.read((char *)&obj, sizeof(obj));
        while (!file_obj.eof())
        {
            cout << "ID: "
                 << obj.cStoreId << "\n";
            cout << "nManufacturer: "
                 << obj.lManufacturer << "\n";
            cout << "\nCPU Brand: "
                 << obj.cCPUBrand;
            cout << "\nCPU Model: "
                 << obj.cCPUModel;
            cout << "\nGPU Brand: "
                 << obj.cGPUBrand;
            cout << "\nGPU Model: "
                 << obj.cGPUModel;
            cout << "\nGPU Model: "
                 << obj.cGPUModel;
            cout << "\nMemory: "
                 << obj.cMemory;
            cout << "\nScreen size: "
                 << obj.laptopScreenSize;
            // TODO common fucntion
            cout << "\nType: "
                 << obj.computerType;
            // TODO common fucntion
            cout << "\nChoose Storage Type"
                 << obj.storageType;

            cout << "\nStorage: "
                 << obj.cStorage;
            cout << "\nOS Type:"
                 << obj.os;

            cout << "\nPrice: "
                 << obj.cPrice;
            file_obj.read((char *)&obj, sizeof(obj));
        }
    }
};

class Desktop : public Computer
{
    char dManufacturer[50];
    float desktopScreenSize = 0.0;
    bool screenAvailable = false;
    int CPUNumber = 2;
    int GPUNumber = 2;

public:
};

class Server : public Computer
{
    char sManufacturer[50];
    float desktopScreenSize = 0.0;
    bool screenAvailable = false;
    int CPUNumber = 4;
    int GPUNumber = 4;

public:
};

void addComputer(char computerType)
{
    char ch;
    do
    {
        if (computerType == 'L')
        {
            Laptop L;
            L.create();
            L.input(L);
            L.printRecords();
        }
        // else if(Type == ComputerType.Server){

        // }
        // else if(Type == ComputerType.Desktop){

        // }

        // fp.write((char*)&st,sizeof(student));
        cout << "\n\nDo you want to add more record..(y/n?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    // fp.close();
}

int main()
{
    Laptop L1;
    addComputer('L');
    cout << "Added";
    return 0;
}
