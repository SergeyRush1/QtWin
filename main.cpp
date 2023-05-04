#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <windows.h>
#include <iostream>

using namespace std ;
void ShowCOMPorts()
{
    int r = 0;
    HKEY hkey = NULL;
    //Открываем раздел реестра, в котором хранится иинформация о COM портах
    r = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM\\"), 0, KEY_READ, &hkey);
    if (r != ERROR_SUCCESS)
        return;

    unsigned long CountValues = 0, MaxValueNameLen = 0, MaxValueLen = 0;
    //Получаем информацию об открытом разделе реестра
    RegQueryInfoKey(hkey, NULL, NULL, NULL, NULL, NULL, NULL, &CountValues, &MaxValueNameLen, &MaxValueLen, NULL, NULL);
    ++MaxValueNameLen;
    //Выделяем память
    TCHAR* bufferName = NULL, * bufferData = NULL;
    bufferName = (TCHAR*)malloc(MaxValueNameLen * sizeof(TCHAR));
    if (!bufferName)
    {
        RegCloseKey(hkey);
        return;
    }
    bufferData = (TCHAR*)malloc((MaxValueLen + 1) * sizeof(TCHAR));
    if (!bufferData)
    {
        free(bufferName);
        RegCloseKey(hkey);
        return;
    }

    unsigned long NameLen, type, DataLen;
    //Цикл перебора параметров раздела реестра
    for (unsigned int i = 0; i < CountValues; i++)
    {
        NameLen = MaxValueNameLen;
        DataLen = MaxValueLen;
        r = RegEnumValue(hkey, i, bufferName, &NameLen, NULL, &type, (LPBYTE)bufferData, &DataLen);
        if ((r != ERROR_SUCCESS) || (type != REG_SZ))
            continue;

       // tprintf(TEXT("%s\n"), bufferData);
        printf("dddd");
    }
    //Освобождаем память
    free(bufferName);
    free(bufferData);
    //Закрываем раздел реестра
    RegCloseKey(hkey);
}




bool SetComPort(LPCTSTR sPortName) {
     HANDLE hSerial;
     hSerial = ::CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
     if (hSerial == INVALID_HANDLE_VALUE)
     {
         if (GetLastError() == ERROR_FILE_NOT_FOUND)
         {
             cout << "serial port does not exist.\n";
         }
         cout << "some other error occurred.\n";
     }

     DCB dcbSerialParams = { 0 };
     dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
     if (!GetCommState(hSerial, &dcbSerialParams))
     {
         cout << "getting state error\n";
     }
     dcbSerialParams.BaudRate = CBR_9600;
     dcbSerialParams.ByteSize = 8;
     dcbSerialParams.StopBits = ONESTOPBIT;
     dcbSerialParams.Parity = NOPARITY;
     if (!SetCommState(hSerial, &dcbSerialParams))
     {
         cout << "error setting serial port state\n";
         return false;
     }

     char data[] = "Hello from C++";  // строка для передачи
     DWORD dwSize = sizeof(data);   // размер этой строки
     DWORD dwBytesWritten;    // тут будет количество собственно переданных байт
     BOOL iRet = WriteFile(hSerial, data, dwSize, &dwBytesWritten, NULL);
     cout << dwSize << " Bytes in string. " << dwBytesWritten << " Bytes sended. " << endl;
     
     return true;

}
int main(int argc, char *argv[])
{
    LPCTSTR sPortName = L"COM3";
    ShowCOMPorts();
   
   bool status =  SetComPort(sPortName);
   

    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
 
}

 

