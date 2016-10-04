/*Project 2 for CSCI-272 designs a program which registers employees and students.
We design the program by designing employees and students under the object
"person" and give them specific attributes. These attributes (gender, age, name)
are also given to the employees and students.  We also design courses for each
student to register in and specify which student is not registered to any course.
This program also registers employees depending on attributes such as department,
work status, and salary.  This program sets up a code which uses many user defined
constructors having different paramters.  Each constructor designed had a function
defined which returns back data and information that allows us to print the outputs
in the main function.*/


#include <cstdlib>
#include <iostream>
#define MAX_CLASSES 6
#define TUITION 1000

using namespace std;

enum gender {male=12, female=41, Private=25};  //male=0, female=1, Private=2
                                               //automatically implements by 1
enum department {administration, academic};
enum status {full_time, part_time};

string Department(department d);
string Status (status);
string Gender(gender);


struct person {
       string name;
       gender sex;
       int age;
       string prefix();
       person(string s, gender g, int a): name(s), sex(g), age(a) {};
       person () {};
       };
       class student : public person {
             private:
             bool registered;  //Want to know if a student registered without
                               //looking at too much data.
             string* classes;
             int classCount;
             int balance;     //Want to know how much money
             public:
                    void enroll (string course);  //Using enroll method, 
                                                  //we add course to string classe.
                    void printClasses();          //Prints which classes are 
                                                  //enrolled too.
                    int accountBalance() {return balance;};
                    void payBalance(float&);
                    student () {classes = new string[MAX_CLASSES]; classCount = 0; balance = 0; registered = false;}
                               //new is a pointer to classes
                    };
struct classes {
       string course;
       classes* next;
       }class1, class2, class3, class4, class5, class6, class7, class8;
       //list of classes that uses a pointer
       
void printClasses(classes*);
                    
class employee : public person {
      private:
              department dept;     //regarding administration or academic
              status fullOrpart;   //regarding full time or part time
              int salary;          //salary that will be used for each employee
      public:
             void promote () {salary += 1000;};
             void printCredentials();
             department dpt () {return dept;}  
             status stt () {return fullOrpart;}
             int slry () {return salary;}
             employee (department d, status s, int pay) : dept(d), fullOrpart(s), salary(pay){};
             employee ();
             
      };
                          
int main(int argc, char *argv[])
{
    student* newstudent = new student;      //Using new and deletion for
    newstudent->name = "Mr. New";           //newstudent as well as setting
    delete newstudent;                      //up a pointer.
    
    //Employee1 = Slade Wilson
    //This will print out information about Slade Wilson regarding
    //his name, age, gender, employee status, department, and salary.
    employee employee1(academic, full_time, 1000);
    employee1.name = "Slade Wilson";
    employee1.sex = male;
    employee1.age = 26;
    cout << employee1.name << " is hired in " ;
    cout << Department(employee1.dpt()) << " as "; 
    cout << Status(employee1.stt());
    cout << " with a salary of ";
    cout << employee1.slry() << endl;
    
    float UTuitionbalance = 0;
    person person1("Slade Wilson", male, 28);
    
    cout << person1.prefix();
    cout << person1.name << " is a " << person1.age;
    cout << " years old " << Gender(person1.sex) << "." << endl << endl;
    
    //Employee2 = Harley Quinn
    //This will print out information about Harley Quinn regarding
    //her name, age, gender, employee status, department, and salary.
    employee employee2(administration, part_time, 500);
    employee2.name = "Harley Quinn";
    employee2.sex = female;
    employee2.age = 28;
    cout << employee2.name << " is hired in " ;
    cout << Department(employee2.dpt()) << " as "; 
    cout << Status(employee2.stt());
    cout << " with a salary of ";
    cout << employee2.slry() << endl;
    
    person person2("Harley Quinn", female, 23);
    
    cout << person2.prefix();
    cout << person2.name << " is a " << person2.age;
    cout << " years old " << Gender(person2.sex) << "." << endl << endl;
    //Person2 is of type person. 
    
    //pointer that will create a list of classes that students can register to
    cout << "Classes that students can register to: " << endl;
    classes* list = &class1;
    class1.course = "MAT-101 College Algebra";
    class1.next = &class2;
    class2.course = "ENG-101 Intro to Writing";
    class2.next = &class3;
    class3.course = "LWS-200 Intro to Law and Society";
    class3.next = &class4;
    class4.course = "POL-375 Law, Order, Justice, and Society";
    class4.next = &class5;
    class5.course = "CSCI-271 Intro to Programming";
    class5.next = &class6;
    class6.course = "MAT-241 Calculus I";
    class6.next = &class7;
    class7.course = "MAT-242 Calculus II";
    class7.next = &class8;
    class8.course = "PED-145 Self-Defense";
    class8.next = NULL;
    
    printClasses(list);      //prints the list of classes in the main that 
                             //is constructed and defined
    
    //Student1 = Oliver Queen
    //This will print out information about Oliver Queen regarding
    //his name, age, gender.  He is not registered in any courses.
    student student1;
    student1.name = "Oliver Queen";
    student1.sex = male;
    student1.age = 23;
    person person3("Oliver Queen", male, 23);
    cout << "\n" << person3.prefix();
    cout << person3.name << " is a " << person3.age;
    cout << " year old " << Gender(person3.sex);
    cout << " and is unregistered in any classes." << endl << endl << endl;
    
    //Student2 = Barry Allen
    //This will print out information about Barry Allen regarding
    //his name, age, gender, courses registered, and tuition information.
    student student2;
    student2.name = "Barry Allen";
    student2.sex = male;
    student2.age = 19;
    person person4("Barry Allen", male, 19);
    cout << person4.prefix();
    cout << person4.name << " is a " << person4.age;
    cout << " year old " << Gender(person4.sex);
    cout << " and is registered in 3 courses: \n";
    cout << class2.course << "\n"<< class6.course << "\n";
    cout << class5.course << endl;
    float UTuition1 = 750;
    float AccountBalance1 = 750;
    cout << student2.name << "'s fee is: $" << UTuition1 * 3 << endl;
    cout << "Balance for student = $" << AccountBalance1 - 750 << endl << endl;
    
    //Student3 = Laurel Lance
    //This will print out information about Laural Lance regarding
    //her name, age, gender, courses registered, and tuition information.
    student student3;
    student3.name = "Laurel Lance";
    student3.sex = female;
    student3.age = 21;
    person person5("Laurel Lance", female, 21);
    cout << person5.prefix();
    cout << person5.name << " is a " << person5.age;
    cout << " year old " << Gender(person5.sex);
    cout << " and is registered in 4 courses: \n";
    cout << class2.course << "\n"<< class3.course << "\n";
    cout << class4.course << "\n" << class8.course << endl;
    float UTuition2 = 750;
    float AccountBalance2 = 750;
    cout << student3.name << "'s fee is: $" << UTuition2 * 4 << endl;
    cout << "Balance for student = $" << AccountBalance2 - 750 << endl << endl;
    
    //Student4 = Nyssa Raakto
    //This will print out information about Barry Allen regarding
    //her name, age, gender, courses registered, and tuition information.
    student student4;
    student4.name = "Nyssa Raakto";
    student4.sex = female;
    student4.age = 20;
    person person6("Nyssa Raakto", female, 20);
    cout << person6.prefix();
    cout << person6.name << " is a " << person6.age;
    cout << " year old " << Gender(person6.sex);
    cout << " and is registered in 5 courses: \n";
    cout << class3.course << "\n"<< class4.course << "\n";
    cout << class5.course << "\n" << class7.course << "\n";
    cout << class8.course << endl;
    float UTuition3 = 750;
    float AccountBalance3 = 750;
    cout << student4.name << "'s fee is: $" << UTuition3 * 5 << endl;
    cout << "Balance for student = $" << AccountBalance3 - 200 << endl << endl;
    
    cout << "Summary Information:" << endl;
    int reg_courses_oliverqueen = 0;
    int reg_courses_barryallen = 3;
    int reg_courses_laurellance = 4;
    int reg_courses_nyssaraakto = 5;
    int Total_courses;
    Total_courses = reg_courses_oliverqueen + reg_courses_barryallen + reg_courses_laurellance + reg_courses_nyssaraakto;
    cout << "Total number of courses registered is: " << Total_courses << endl; 
    //Information regarding the total number of courses registered
    
    float Total_fee;
    float Balance_Barry = 2250;
    float Balance_Laurel = 3000;
    float Balance_Nyssa = 3750;
    Total_fee = Balance_Barry + Balance_Laurel + Balance_Nyssa;
    cout << "Total fee for registered courses: $" << Total_fee << endl; 
    //Total fee for all courses registered
    
    float average_employee_age;
    average_employee_age = (employee1.age + employee2.age)/2;
    cout << "The average age of the employees is: " << average_employee_age << endl;
    //Takes the average of the ages of the 2 employees
    
    float average_student_age;
    average_student_age = (student1.age + student2.age + student3.age + student4.age)/4;
    cout << "The average age of the students is: " << average_student_age << endl << endl;
    //Takes the average of the ages of the 4 students
    
    //Promotion which raises Slade Wilson's salary
    cout << "Promotion for: " << employee1.name << endl;
    cout << "Old salary: $" << employee1.slry() << endl;
    cout << "New salary: $" << employee1.slry() + 500 << endl << endl;
    
    //Promotion which raises Harley Quinn's salary
    cout << "Promotion for: " << employee2.name << endl;
    cout << "Old salary: $" << employee2.slry() << endl;
    cout << "New salary: $" << employee2.slry() + 250 << endl << endl;
    
    return 0;
}
string Gender(gender g)
{
       switch (g)
       {
              case 12: return "male";        //function definition which returns
              break;                         //gender depending on the variable
              case 41: return "female";
              break;
              default:
              break;
              }
       }
string person::prefix()  //: : = scope operator
{
       switch (sex)
       {
              case male: return "Mr. ";        //function definition which returns
              break;                           //prefix depending on gender
              case female: return "Ms. ";
              break;
              default: return " ";
              break;
              }
}
void student::enroll(string course) {
     registered = true;
     classes[classCount] = course;
     ++classCount;
     balance += TUITION;
}
void student::payBalance(float& UTuition) {
    UTuition += balance;
    balance = 0;
}
string Department(department d){
       switch (d) {
              case administration: return "administration";
              break;                                //function definition that
              case academic: return "academic";     //returns department status
              break;
              default: return "Unknown";
              break;
       }
}
string Status (status s) {
       switch (s) {
              case full_time: return "full time";   //function definition that 
              break;                                //returns employment status
              case part_time: return "part time";
              break;
              default: return "Unknown";
              break;
       }
}
void printClasses(classes* c)
{
     do                                          //function definition that returns
     {                                           //the list of courses that need
                    cout << c->course <<endl;    //to be printed in the main
                    c = c->next;
     } while (c != NULL);
}
