#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

   map<string,string> split(string s)
     {   int field_lengths[9] = {15,15,15,10,5,20,15,15,6};
        string fields[9] ={"lastn","firstn","middlen","aka","houseno","street","city","state","zip"};
        int numberof_fields = 9;
        vector<string> row_elements;
        std::map<string, string> my_map;
        int start=0;
        for(int i=0; i < numberof_fields; i++)
        {  string element = s.substr(start,field_lengths[i]);
           element.erase(std::remove_if(element.begin(), element.end(), ::isspace), element.end());
           my_map[fields[i]]=element;
           start+=field_lengths[i];
        }
        return my_map;
       }
    

    void envelop(vector<map<string,string>> list)
    {
      for (int i = 0; i < list.size(); i++)
      {
        cout<<list[i]["firstn"]<<" "<<list[i]["lastn"]<<","<<endl;
        cout<<list[i]["houseno"]<<" "<<list[i]["street"]<<","<<endl;
        cout<<list[i]["city"]<<","<<" "<<list[i]["state"]<<" "<<list[i]["zip"]<<endl;
        cout << endl;
      }
    }

     void fixed_length(vector<map<string,string>> list)
    {
      for (int i = 0; i < list.size(); i++)
      {
        int spaces = 31-(list[i]["firstn"].length()+list[i]["lastn"].length());
        cout<<list[i]["firstn"]<<" "<<list[i]["lastn"];
        for (int i=0;i<spaces;i++)
        {
          cout<<" ";
        }
        spaces = 26-(list[i]["houseno"].length()+list[i]["street"].length());
        cout<<list[i]["houseno"]<<" "<<list[i]["street"];
         for (int i=0;i<spaces;i++)
        {
          cout<<" ";
        }
        spaces = 38-(list[i]["city"].length()+list[i]["state"].length() + list[i]["zip"].length());
        cout<<list[i]["city"]<<" "<<list[i]["state"]<<" "<<list[i]["zip"];
         for (int i=0;i<spaces;i++)
        {
          cout<<" ";
        }
        cout<<endl;
      }
    }

     void csv(vector<map<string,string>> list)
     {

  
       for (int i = 0; i < list.size(); i++)
      {
        cout<<list[i]["firstn"]<<" "<<list[i]["lastn"]<<",";
        cout<<list[i]["houseno"]<<" "<<list[i]["street"]<<",";
        cout<<list[i]["city"]<<" "<<list[i]["state"]<<" "<<list[i]["zip"]<<",";
        cout<<endl;
      }
     }

int main(int argc, char **argv)
{
    string line;
    ifstream MyFile(argv[0]);
    vector<map<string, string> > list;
    string fields[9] ={"lastn","firstn","middlen","aka","houseno","street","city","state","zip"};

    while (getline (MyFile, line))
      {
        list.push_back(split(line));
      }
    cout<<list.size();
    cout<<endl;
  
    if (argv[1]=="envelop")
    {
      cout<<"####################    Envelop Format       ###################"<<endl<<endl;
      envelop(list);
      cout<<endl;
    }
    if (argv[1]=="fixed_length")
    {
    cout<<"####################    Fixed Format       ###################"<<endl<<endl;
    fixed_length(list);
    cout<<endl;
    }
    if (argv[1]=="csv")
    {
    cout<<"####################    CSV Format       ###################"<<endl<<endl;
    csv(list);
    cout<<endl;
    }

    MyFile.close();
    return 1;
}

