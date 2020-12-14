//  Name : Franklin Antony
//  ID : 200626510
//  College Username : ec20076

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX_ARRAY_LIMIT 50

void printAllComputers();
float ShowDisplayScreenSize(char computerType)
{
    if (computerType == 'L')
    {
        int DisplayScreenSize = 0;
        cout << "\nChoose the Laptop Screen Size";
        cout << "\n1) 11.1 \n2) 12.0 \n3) 13.3 \n4) 14.0 \n5) 15.6 \n6) 17.3";
        cin >> DisplayScreenSize;
        switch (DisplayScreenSize)
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
            return 0.0;
            break;
        }
    }
    else
    {
        return 0.0;
    }
}
class Computer
{
public:
    bool isDeleted = false;
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
    double cPrice = 0;

    char Manufacturer[50];
    float DisplayScreenSize;
    bool screenAvailable = false;
    int CPUNumber = 0;
    int GPUNumber = 0;

    void create(char computerTypeInput)
    {
        int tempType = 0;
        cout << "\nNew Computer Entry\n";
        cout << "\nPlease enter the following details:";
        cout << "\nID:";
        fgets(cStoreId, 6, stdin);
        cout << "\nManufacturer: ";
        fgets(Manufacturer, MAX_ARRAY_LIMIT, stdin);
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
        DisplayScreenSize = ShowDisplayScreenSize(computerTypeInput);
        computerType = computerTypeInput;
        cout << "\nChoose Storage Type";
        cout << "\n1) SSD \n2) HDD \n3) SSHD\n";
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
        cout << "\n1) Mac \n2) Windows \n3) Linux\n";
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
        if (computerType == 'L')
        {
            screenAvailable = true;
            CPUNumber = 1;
            GPUNumber = 1;
            cout << "\n\nLaptop record added..";
        }
        else if (computerType == 'D')
        {
            screenAvailable = false;
            CPUNumber = 2;
            GPUNumber = 2;
            cout << "\n\nDesktop record added..";
        }
        else if (computerType == 'S')
        {
            screenAvailable = false;
            CPUNumber = 4;
            GPUNumber = 4;
            cout << "\n\nServer record added..";
        }
    }

    int inputIntoFile(Computer obj)
    {
        ofstream fileObj;
        fileObj.open("Data.txt", ios::app);
        if (fileObj)
        {
            fileObj.write((char *)&obj, sizeof(obj));
        }
        fileObj.close();
        return 0;
    }
};

class Laptop : public Computer
{
public:
};

class Desktop : public Computer
{
public:
};

class Server : public Computer
{

public:
};
void deleteAndRewriteFile(Computer localObject[], int length)
{
    std::ofstream ofs;
    ofs.open("Data.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    for (int i = 0; i < length; ++i)
    {
        cout << localObject[i].cStoreId << endl;
    }
    ofs.open("Data.txt", std::ofstream::out);
    for (int i = 0; i < length; ++i)
    {
        ofs.write((char *)&localObject[i], sizeof(*localObject));
    }
    // ofs.write((char *)&localObject, sizeof(localObject));
    ofs.close();
}

int fileToMemory(Computer localObject[])
{
    int i = 0;
    Computer obj;
    ifstream file_obj;
    file_obj.open("Data.txt", ios::in);
    if (file_obj)
    {
        file_obj.read((char *)&obj, sizeof(obj));
        while (!file_obj.eof())
        {
            strcpy(localObject[i].cStoreId, obj.cStoreId);
            strcpy(localObject[i].Manufacturer, obj.Manufacturer);
            strcpy(localObject[i].cCPUBrand, obj.cCPUBrand);
            strcpy(localObject[i].cCPUModel, obj.cCPUModel);
            strcpy(localObject[i].cGPUBrand, obj.cGPUBrand);
            strcpy(localObject[i].cGPUModel, obj.cGPUModel);
            localObject[i].cMemory = obj.cMemory;
            localObject[i].DisplayScreenSize = obj.DisplayScreenSize;
            localObject[i].computerType = obj.computerType;
            strcpy(localObject[i].storageType, obj.storageType);
            localObject[i].cStorage = obj.cStorage;
            strcpy(localObject[i].os, obj.os);
            localObject[i].cPrice = obj.cPrice;
            localObject[i] = obj;
            localObject[i] = obj;
            localObject[i] = obj;
            file_obj.read((char *)&obj, sizeof(obj));
            i++;
        }
        // file_obj.close();
    }
    file_obj.close();
    return i;
}

void addComputer()
{
    Computer C;
    int computerTypeInput;
    char ch;
    cout << "\nChoose the type of computer to be added: ";
    cout << "\n1 - Laptop \n2 - Desktop \n3 - Server \n";
    cin >> computerTypeInput;
    // cin.ignore();

    // cin.sync();
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        cin.ignore();
        if (computerTypeInput == 1)
        {
            C.create('C');
            C.inputIntoFile(C);
        }
        else if (computerTypeInput == 2)
        {
            C.create('D');
            C.inputIntoFile(C);
        }
        else if (computerTypeInput == 3)
        {
            C.create('S');
            C.inputIntoFile(C);
        }
        cout << "\nDo you want to add more record..(Y/N?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

int removeComputer(Computer localObject[], int length)
{
    char id[6];
    cout << "\nInput the ID of computer to be deleted: ";
    // fgets(id, 6, stdin);
    cin.getline(id, 6);
    for (int i = 0; i < length; ++i)
    {
        if (strcmp(id, localObject[i].cStoreId))
        {
            cout << "\nFound record matching ID..." << endl;
            for (int j = i; j < length - 1; j++)
            {
                localObject[i] = localObject[i + 1];
            }
            --length;

            cout << "\nRemoved record..." << endl;
        }
        else
        {
            cout << "\nCannot find record matching ID..." << endl;
        }
    }
    deleteAndRewriteFile(localObject, length);
    return length;
}
void printAllComputers()
{
    ifstream file_obj;
    file_obj.open("Data.txt", ios::in);
    if (file_obj)
    {
        Computer obj;
        file_obj.read((char *)&obj, sizeof(obj));
        while (!file_obj.eof())
        {
            if (!obj.isDeleted)
            {
                cout << "\nID: "
                     << obj.cStoreId << "\n";
                cout << "\nManufacturer: "
                     << obj.Manufacturer;
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
                     << obj.DisplayScreenSize;
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
            }
            file_obj.read((char *)&obj, sizeof(obj));
        }
        cout << endl;
    }
    file_obj.close();
}
void searchComputer()
{
    char searchTerm[10];
    cout << "\nSearch by: ";
    cout << "\n1)ID \n2)Type \n3)Price \nStorage \nScreen Size";
    cout << "\nInput ID: ";
    cin.getline(searchTerm, 10);
    // cin.ignore();

    ifstream file_obj;
    file_obj.open("Data.txt", ios::in);

    if (file_obj)
    {
        Computer obj;
        file_obj.read((char *)&obj, sizeof(obj));
        while (!file_obj.eof())
        {

            // if (!obj.isDeleted && obj.cStoreId == searchTerm)
            if (!obj.isDeleted && (strcmp(searchTerm, obj.cStoreId)))
            {
                cout << "\nRecord found at : ";
                cout << "\nID: "
                     << obj.cStoreId;
                cout << "\nManufacturer: "
                     << obj.Manufacturer;
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
                     << obj.DisplayScreenSize;
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
            }
            file_obj.read((char *)&obj, sizeof(obj));
        }
    }
    file_obj.close();
}

void printthefile(Computer localObject[], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << localObject[i].Manufacturer << "\n";
    }
}

int main()
{
    Computer localObject[20];
    int length = 0;
    length = fileToMemory(localObject);
    // printthefile(localObject,length);
    int inputChoice = 0;
    cout << "\nComputer Store";
    cout << "\nMain Menu: ";
    cout << "\n1) Add\n2) Remove\n3) Display\n4) Search\n5) Exit\n";
    cin >> inputChoice;
    cin.ignore();
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    switch (inputChoice)
    {
    case 1:
        addComputer();
        break;
    case 2:
        length = removeComputer(localObject, length);
        break;
    case 3:
        printAllComputers();
        break;
    case 4:
        searchComputer();
        break;
    default:
        // deleteAndRewriteFile(localObject, length);
        break;
    }
    cout << endl;
    return 0;
}