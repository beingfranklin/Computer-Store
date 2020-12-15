//  Name : Franklin Antony
//  ID : 200626510
//  College Username : ec20076

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define MAX_ARRAY_LIMIT 50

float ShowDisplayScreenSize(char computerType)
{
    if (computerType == 'L')
    {
        int DisplayScreenSize = 0;
        cout << "\nChoose the Laptop Screen Size";
        cout << "\n1) 11.1 \n2) 12.0 \n3) 13.3 \n4) 14.0 \n5) 15.6 \n6) 17.3" << endl;
        cin >> DisplayScreenSize;
        cin.ignore();
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
class ComputerStore
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
    float cScreenSize;
    bool screenAvailable = false;
    int CPUNumber = 0;
    int GPUNumber = 0;

    void create(char computerTypeInput)
    {
        int tempType = 0;
        cout << "\nNew Computer Entry\n";
        cout << "\nPlease enter the following details:";
        cout << "\nID:";
        cin.getline(cStoreId, 6);
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
        cScreenSize = ShowDisplayScreenSize(computerTypeInput);
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

    int inputIntoFile(ComputerStore obj)
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

class Laptop : public ComputerStore
{
public:
};

class Desktop : public ComputerStore
{
public:
};

class Server : public ComputerStore
{
public:
};

void deleteAndRewriteFile(ComputerStore localObject[], int length)
{
    std::ofstream ofs;
    ofs.open("Data.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    // for (int i = 0; i < length; ++i)
    // {
    //     cout << localObject[i].cStoreId << endl;
    // }
    // ofs.open("Data.txt", std::ofstream::out);
    // for (int i = 0; i < length; ++i)
    // {
    //     ofs.write((char *)&localObject[i], sizeof(*localObject));
    // }
    // // ofs.write((char *)&localObject, sizeof(localObject));
    // ofs.close();
}

string returnComputerType(char type)
{
    switch (type)
    {
    case 'L':
        return "Laptop";
    case 'D':
        return "Desktop";
    case 'S':
        return "Server";
    default:
        return "Unknown";
    }
}

void printRecord(ComputerStore obj)
{
    cout << "\nId: "
         << obj.cStoreId;
    cout << "Manufacturer: "
         << obj.Manufacturer;
    cout << "CPU Brand: "
         << obj.cCPUBrand;
    cout << "CPU Model: "
         << obj.cCPUModel;
    cout << "GPU Brand: "
         << obj.cGPUBrand;
    cout << "GPU Model: "
         << obj.cGPUModel;
    cout << "GPU Model: "
         << obj.cGPUModel;
    cout << "Memory: "
         << obj.cMemory;
    cout << "\nScreen size: "
         << obj.cScreenSize;
    cout << "\nType: "
         << returnComputerType(obj.computerType);
    cout << "\nChoose Storage Type: "
         << obj.storageType;
    cout << "\nStorage: "
         << obj.cStorage;
    cout << "\nOS Type: "
         << obj.os;
    cout << "\nPrice: "
         << obj.cPrice << endl;
}
void printAllComputers()
{
    int i = 1;
    ifstream file_obj;
    file_obj.open("Data.txt", ios::in);
    if (file_obj)
    {
        ComputerStore obj;
        file_obj.read((char *)&obj, sizeof(obj));
        while (!file_obj.eof())
        {
            if (!obj.isDeleted)
            {
                cout << "\nRecord " << i++ << endl;
                printRecord(obj);
            }
            file_obj.read((char *)&obj, sizeof(obj));
        }
        cout << endl;
    }
    file_obj.close();
}

int fileToMemory(ComputerStore (&localObject)[20])
{
    int i = 0;
    ComputerStore obj;
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
            localObject[i].cScreenSize = obj.cScreenSize;
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
    cout<<"length in read"<<i;
    return i;
}

void addComputer()
{
    ComputerStore C;
    int computerTypeInput;
    char ch;
    cout << "\nChoose the type of computer to be added: ";
    cout << "\n1 - Laptop \n2 - Desktop \n3 - Server \n";
    cin >> computerTypeInput;
    do
    {
        cin.ignore();
        if (computerTypeInput == 1)
        {
            C.create('L');
        }
        else if (computerTypeInput == 2)
        {
            C.create('D');
        }
        else if (computerTypeInput == 3)
        {
            C.create('S');
        }
        C.inputIntoFile(C);
        cout << "\nDo you want to add more record..(Y/N?)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

int removeComputer(ComputerStore localObject[], int length)
{
    ComputerStore C;
    char id[6];
    int temp = -1;
    cout << "\nInput the ID of computer to be deleted: ";
    // fgets(id, 6, stdin);
    cin.getline(id, 6);
    deleteAndRewriteFile(localObject, length);
    for (int i = 0; i < length; ++i)
    {
        if ((strcmp(id, localObject[i].cStoreId)) == 0)
        {
            cout << "\nFound record matyching ID in position : " << i + 1 << endl;
            temp = i;
        }
    }
    if (temp != -1)
    {
        for (int i = 0; i < length; ++i)
        {
            if ((strcmp(id, localObject[i].cStoreId)) == 0)
            {
                C.inputIntoFile(localObject[i]);
            }
            --length;
            cout << "\nRemoved record..." << endl;
        }
        deleteAndRewriteFile(localObject, length);
    }
    else
    {
        cout << "\nCannot find record matching ID..." << endl;
    }
    return length;
}

void searchComputer(ComputerStore localObject[], int length)
{
    
    char searchTerm[6], searchTypeTerm;
    int inputChoice = 0, computerTypeInput = 0;
    double max, min;
    bool recordfound = false;
    cout << "\nSearch by: ";
    cout << "\n1)Id \n2)Type \n3)Price \n4)Storage \n5)Screen Size" << endl;
    cin >> inputChoice;
    cin.ignore();

    switch (inputChoice)
    {
    case 1:
        cout << "\nInput Id: ";
        // cin >> searchTerm;
        cin.getline(searchTerm, 6);
        // cin.ignore();
        cout << "\nsearchTerm Size is" << strlen(searchTerm) << endl;
        break;
    case 2:
        cout << "\n1 - Laptop \n2 - Desktop \n3 - Server \n";
        cin >> computerTypeInput;
        cin.ignore();
        if (computerTypeInput == 1)
        {
            searchTypeTerm = 'L';
            cout << "\nShowing the List of Laptops: " << endl;
        }
        else if (computerTypeInput == 2)
        {
            searchTypeTerm = 'D';
            cout << "\nShowing the List of Desktops: " << endl;
        }
        else if (computerTypeInput == 3)
        {
            searchTypeTerm = 'S';
            cout << "\nShowing the List of Servers: " << endl;
        }
        break;
    case 3:
        cout << "\nMax price: ";
        cin >> max;
        cout << "\nMin price: ";
        cin >> min;
        cin.ignore();
        cout << "\nShowing the List of Computers within that range: " << endl;
        break;
    case 4:
        cout << "\nMax storage: ";
        cin >> max;
        cout << "\nMin storage: ";
        cin >> min;
        cout << "\nShowing the List of Computers within that range: " << endl;
        break;
    case 5:
        cout << "\nMax Screen: ";
        cin >> max;
        cout << "\nMin  Screen: ";
        cin >> min;
        cout << "\nShowing the List of Computers within that range: " << endl;
        break;
    default:
        cout << "\nError  :";
        break;
    }

    for (int i = 0; i < length; i++)
    {
        cout << "\nlocalObject[i].cStoreId Size is" << localObject[i].cStoreId << "->" << strlen(localObject[i].cStoreId) << endl;
        if ((strcmp(searchTerm, localObject[i].cStoreId) == 0) && inputChoice == 1)
        {
            cout << "\nRecord found at : \n";
            printRecord(localObject[i]);
            recordfound = true;
            break;
        }
        else if (searchTypeTerm && (searchTypeTerm == localObject[i].computerType) && inputChoice == 2)
        {
            printRecord(localObject[i]);
            recordfound = true;
            break;
        }
        else if (min && max && (localObject[i].cPrice > min && localObject[i].cPrice < max) && inputChoice == 3)
        {
            printRecord(localObject[i]);
            recordfound = true;
        }
        else if (min && max && (localObject[i].cStorage > min && localObject[i].cStorage < max) && inputChoice == 4)
        {
            printRecord(localObject[i]);
            recordfound = true;
        }
        else if (min && max && (localObject[i].cScreenSize > min && localObject[i].cScreenSize < max) && inputChoice == 5)
        {
            printRecord(localObject[i]);
            recordfound = true;
        }
    }
    if (!recordfound)
    {
        cout << "Record not found" << endl;
    }
}

int mainMenu(ComputerStore (&localObject)[20], int &length)
{
    char menuChoice;
    do
    {
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
            searchComputer(localObject, length);
            break;
        case 5:
            exit(0);
        default:
            cout << "\nInvalid choice" << endl;
            break;
        }
        if (inputChoice != 5)
        {
            cout << "\nDo you want to continue to main menu? (Y/N)" << endl;
            cin >> menuChoice;
            cin.ignore();
        }
        else
        {
            exit(0);
        }
    } while (menuChoice == 'y' || menuChoice == 'Y');
    length = fileToMemory(localObject);
    return length;
}

int main()
{
    ComputerStore localObject[20];
    int length = 0;
    length = fileToMemory(localObject);
    length = mainMenu(localObject, length);
    cout << endl;
    return 0;
}