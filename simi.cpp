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
    

   // variables and data
   ifstream file1, file2;
 
   string filename1, filename2;
  
   // two vectors
   vector <string> vector1;
   vector <string> vector2;

   string string1, string2;


//Handling files part

    // reading file from user input
    cout << "compare : " ;
    cin >> filename1 >> filename2;
   // opening files
   file1.open(filename1.c_str()); 
   file2.open(filename2.c_str()); 
   
   // check if file is not open
   if(file2.fail() || file1.fail()){
       cerr << "Error opening file" << endl;
       exit(1);
   }

   // else file is open
   else{
    // inserting values from file to vector
   while(file1 >> string1){
    vector1.push_back(string1);
    }
    //displaying vector values
   //copy(vector1.begin(), vector1.end(), ostream_iterator<string>(cout, "\n"));

   while(file2 >> string2){
    vector2.push_back(string2);
    }
   //copy(vector2.begin(), vector2.end(), ostream_iterator<string>(cout, "\n"));




// check similarity part
       
        int similar =0; 
        int diffrent =0;
        int percentage,max ;
       
       //getting the largest vector 

        if (vector1.size()>=vector2.size()){
            max= vector1.size();

        }else{
            
            max=vector2.size();
          
        }
         // checking similarity
     
        for(int i=0; i<max; i++){
            if(vector1[i] == vector2[i]){
                similar++;
                
            }
            else{
                diffrent++;
            } 
           
        }

       
        // fct of similarity
        percentage= ((similar)*100)/max;
      //displaying similarity
      cout << percentage << "%"<<endl;
     //closing file
      file1.close();
      file2.close();
   }

   system("pause");
   return 0;
}
