#include<stdio.h>    
#include<iostream> 
#include<fstream> 
#include<string.h> 
using namespace std;

class dbms
{ private:
          
          string line;
          //int count=0;

  public:
         void addnewstudent(); //add-details-of-new-student-admin

         void studentlogin(); // check-for-the-marks

         void facultylogin(); //enter-the-marks

         void adminview();//show-all-data
}db; //object declared

// definition of member functions 

void dbms::addnewstudent() //funtion to add new students, by admin
{
     ifstream f("Database.txt");  
     //ifstream class with f as object, the text file Database is opened or created if it doesn't exist previously
     
     int count=0;
     int n;
     char data[25];
     
    for (int i = 0; std::getline(f, line); ++i)
    {     
        count++;
        //existing count of students as counted from the file
        //each line holds the data of one student
    }

    char password[25]; 
    string empty;
    empty="00";  
        
     
    cout << "Welcome,admin. Please enter the admin password: "; 
    start:  
    cin >> password; 
    //The value of the 'password' variable can be changed according to user's requirement of the admin password
  
        
    string admin_pass = "admin"; 
          
    if (strcmp(password,admin_pass.c_str()) == 0)
         { 
            cout << "Enter the number of students: "; 
            cin >> n; 
            
            count = count + n; //existing count of students + no.of new students = new total
            
            for (int i = 0;i < n;i++)
            {   //to write data onto file
                    ofstream outfile; 
                //ofstream class with outfile as object
                    outfile.open("Database.txt",ios::app); 
                //app is used to append data to the existing text file
                //The entire data of a single student is stored line-by-line. 
                
                cout << "Enter your registration number: "; 
                cin >> data; 
                outfile << data << "\t"; 
                
                cout << "Enter your name: "; 
                cin >> data; 
                outfile << data << "\t"; 
                
                // to check if the original string length has been fully used up
                
                int len = strlen(data); 
                
                while (len < 25){ 
                    data[len] = ' '; //adds an extra space to the string data at its end, thereby increasing it's length
                    len = len + 1; 
                } 
            
                
                //Inserting 'empty' data initially into the file 
                //marks of the five set as zero, zero
                
                outfile <<empty<< "\t"; 
                outfile <<empty << "\t";     
                outfile <<empty << "\t"; 
                outfile <<empty << "\t"; 
                outfile <<empty << endl; 
            
            }
           
        }
   else //i.e if the password is wrong
       { cout<<"The password is wrong. Please enter the correct password again."<<endl;
         cout<<"Re=enter the password: "; 
         goto start;   
       }
}

void dbms::studentlogin()

{     
  ifstream f("Database.txt"); 
  // Database text file is opened
  
  // initialise count=0 
       int count=0;
       char data[25];
       for (int i = 0;std::getline(f, line); ++i)
       
 {      //count is not a static variable, so it is not common to all the member functions
        //hence has to re-initialise at every stage
        count++; //count again, to get the number of students which is represented by the number of lines in the text file
 }
 
 char regno[10]; 
        cout << "Enter your registration number: "; 
        start:
        cin >> regno; 
        ifstream infile; 
        int check = 0; 
        infile.open("Database.txt",ios::in); //in-input 
       
        //This loop prints out the data according to the registration number specified. 
        while (infile >> data)
        //i.e as long as there is data in the file to extract
        
        { 
        if (strcmp(data,regno) == 0){ 
            cout<<"\nRegistration Number: " << data << endl; 
            infile >> data; 
            
            cout<<"Name: " << data << endl; 
            infile>>data; 
            
            
            cout<<"CSE1001 mark: " << data << endl; 
            infile>>data; 
            
            cout<<"BCE1001 mark: "<<data<<endl; 
            infile>>data; 
            
            cout<<"BEE1001 mark: "<<data<<endl; 
            infile>>data; 
            
            cout<<"PHY1001 mark: "<<data<<endl; 
            infile>>data; 
            
            cout<<"MAT1001 mark: "<<data<<endl; 
            infile>>data; 
        
            infile.close(); 
            
            check = 1;
            break;
            } 
        } 
          
        if (check == 0){ 
            cout<<"No such registration number found!"<<endl;
            cout<<"Re-enter register number: ";
            goto start;}    
      

}

void dbms::facultylogin()
{
       ifstream f("Database.txt");   
       char data[25];
       int count=0;
       for (int i = 0;std::getline(f, line); ++i)
     {     
        count++;
     }

        char subcode[7]; 
        cout << "Enter your subject code: "; 
        cin >> subcode; 
        string code1 = "CSE1001", code2 = "BCE1001",code3="BEE1001",code4="PHY1001",code5="MAT1001", mark = ""; 
        
        ifstream infile; //usage of multiple objects to enhance the readability
        int check = 0; 
        int option;
         
        cout << "\nAvailable operation: \n1. Add marks\n";
               
        cin >> option; 
          
        if (option == 1)
   { 
            cout << "You have chosen to add marks for the students!" << endl; 
            
        for(int i = 0;i < count;i++){ 
                fstream file("Database.txt"); 
  
             //The seek in file has been done according to the length 
            //of the data being inserted. It needs to adjusted accordingly 
            //for diffferent lengths of data. 
  
        if(strcmp(subcode,code1.c_str()) == 0)
        { 
           file.seekp(13+28*i,std::ios_base::beg); 
           cout << "Enter the mark of student#" << (i+1) << " : "; 
           cin >> mark; 
           file.write(mark.c_str(),2);
           check=1;
        } 
              
            if(strcmp(subcode,code2.c_str()) == 0)
        { 
           file.seekp(16+28*i,std::ios_base::beg); 
           cout << "Enter the mark of student#" << (i+1) << " : "; 
           cin >> mark; 
           file.write(mark.c_str(),2);
           check=1;} 
        
           if(strcmp(subcode,code3.c_str()) == 0)
        { 
           file.seekp(19+28*i,std::ios_base::beg); 
           cout << "Enter the mark of student#" << (i+1) << " : "; 
           cin >> mark; 
           file.write(mark.c_str(),2);
           check=1;} 
        
           if(strcmp(subcode,code4.c_str()) == 0)
        { 
           file.seekp(22+28*i,std::ios_base::beg); 
           cout << "Enter the mark of student#" << (i+1) << " : "; 
           cin >> mark; 
           file.write(mark.c_str(),2);
           check=1;} 
        
           if(strcmp(subcode,code5.c_str()) == 0)
        { 
           file.seekp(25+28*i,std::ios_base::beg); 
           cout << "Enter the mark of student#" << (i+1) << " : "; 
           cin >> mark; 
           file.write(mark.c_str(),2);
           check=1;
        } 
        }
        
        
              
    } 
  
   
          
        if (check == 0)
        { 
            cout << "No such subject code found!" << endl; 
        } 
           
      

}





// main function

int main()

{
int w;
cout<<"\t\t\t\twelcome to the student db"<<endl<<endl;
while(1)

{
 

  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Add new Student details:\n\t\t\t"

  <<"2.Enter as Student\n\t\t\t"

  <<"3.Enter as faculty\n\t\t\t"

  <<"4.Exit  \n\t\t\t";

 

  cout<<"\n\t\t\tEnter your choice:-> ";

  cin>>w;

  switch(w)

  {

    case 1:  
             db.addnewstudent();

      break;

    case 2:  db.studentlogin();

      break;

    case 3:  db.facultylogin();

      break;
    
     
    case 4:  exit(0);
            
      break;
    

  }

}

return 0;

}


