#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include <windows.h>
#include <iostream>

using namespace std ;
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
   
   bool status =  SetComPort(sPortName);
   

    QApplication a(argc, argv);
    QtWidgetsApplication1 w;
    w.show();
    return a.exec();
 
}

 

