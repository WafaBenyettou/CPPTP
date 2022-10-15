
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;


int main() {

   ifstream file, file1;
 
   string filename1, filename2;

   vector <string> v;
   vector <string> d;

   string str, str1;


    cout << " compare : " ;
    cin >> filename1 >> filename2;

   file.open(filename1.c_str()); 
   file1.open(filename2.c_str()); 
   

   if(file.fail() || file1.fail()){
       cerr << "Error opening file" << endl;
       exit(1);
   }

   else{
   while(file >> str){
    v.push_back(str);
    }
   //copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));

   while(file1 >> str1){
    d.push_back(str1);
    }
   //copy(d.begin(), d.end(), ostream_iterator<string>(cout, "\n"));


        int sim =0;
        int dif =0;
        int percentage =0;
        for(int i=0; i<v.size(); i++){
            if(v[i] == d[i]){
                sim++;
            }
            else{
                dif++;
            }  
        }

        percentage= (sim*100)/v.size();
      
        cout << percentage << "%"<< endl;
            
      file.close();
      file1.close();
   }

   system("pause");
   return 0;
}