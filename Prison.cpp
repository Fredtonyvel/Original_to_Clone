#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Prison
{
	public:
		void setbed(int);
		void setprisoners(int);
		int getbed() {return numOfbed;}
		int getprisoners() {return numOfprisoners;}
	
	private:
		int numOfbed;
		int numOfprisoners;
			
};

void Prison::setbed(int x)
{
	numOfbed = x;
}

void Prison::setprisoners(int y)
{
    if(y-numOfbed > 1)
    {std::cout << "There can only be 1 more prisoner than bed.";}     
    
    y = numOfbed;   
 	numOfprisoners = 2 * y;
}



class Prisoners
{
	public:
		void setTime()
			{
				cin >> time_variable;
				if(time_variable == 0)
				{std::cout << "Error!!! ";}
			}
		int getTime()
			{
				return time_variable;
			}
			
		void setArea(string a)
			{
				area = a;
			}
		string getArea()
			{
				return area;
			}
			
		void setNumber()
			{
				cin >> number;
				if(number == 0)
				{std:: cout << "Prisoner has no children";}
				else
				if(!number == 0)
				{std::cout << "Number of children: ";}
				}
		int getNumber()
			{
				return number;
			}
		
		void setreleaseTime(); 
		void printTimeRelease();	
		
	private:
		int time_variable;
		int number;
		string area;
		int month;
		int day;
		int year;
};

void Prisoners::setreleaseTime()
	{
		cin >> month >> day >> year;   
		month = (month > 0 && month < 12)? month : 0;
		day = (day > 0 && day <= 31)? day : 0;
		year = (year > 0 && year < 3000)? year : 0;   //Max year = 3000
	}
void Prisoners::printTimeRelease()
	{
		cout << setfill('0') << setw(2) << month << "--" << setw(2) << day << "--" << setw(4) << year;
	}


class Guard
{
	public:
		   void fav_weapon();
		   void steroid_use();
		   void fav_spot();
		   void gang_affili();
		   /*void num_infrac(int);
		   void contraband(int);
		   void prob_status(int);
		   */
	
	private:
			char weapon;
			char a;
			char b;
			bool steroid;
			int x;
			int spot;
			bool gang;		
};

void Guard::fav_weapon()
	{
		cin >> weapon;
		if(weapon == 'a')
		{std::cout << "Favorite weapon: Fist";} 
		else
		if(weapon == 'b')
		{std::cout << "Favorite weapon: Taser";}
	}

void Guard::steroid_use()
	{
		cin >> x;
		bool steriod = x;
		if(x == 1)
		{std::cout << "Guard is using steroids";}
		else
		if(x == 0)
		{std::cout << "Guard is not using steroids";}
		else
		if(x > 1)
		{std::cout << "Error! Not a valid input";}
	  }  

void Guard::fav_spot()
	{
		cin >> spot;
	}


int main(int argc, char *argv[])
{
	//Prison class objects for number of beds and prisoners
	Prison p;
	int user_bed = 0;
	int user_prisoners = 0;
	
	cout << "I need you to set the number of beds" << endl;
	cin >> user_bed;
	cout << "Attempting to set number of beds...(processing)" << endl;
	p.setbed(user_bed);
	cout << "Attempting to set the number of prisoners...(processing)" << endl;
	p.setprisoners(user_prisoners);
	cout << "\nNumber of beds in the 40 cells = " << p.getbed() << endl;
	cout << "The number of prisoners in each cell is twice more than the number of beds."
		 << "\nNumber of prisoners = " << p.getprisoners() << endl;
	
	
	//Prisoner class objects
	//A-> Sentence Months
	cout << "\nSet the number of months sentenced to prisoner:" << endl;
	Prisoners sentMonth;
	sentMonth.setTime();
	cout << "Prisoner is sentenced to: " <<sentMonth.getTime() << " months" << endl;
	
	//B-> Time Served
	cout << "\nEnter the number of years prisoner has served:" << endl;
	Prisoners timeServed;
	timeServed.setTime();
	cout << "Prisoner has served: " <<timeServed.getTime() << " years" << endl;
	
	//C-> Time To Release
	cout << "\nEnter prisoner release time in form of month, day, and year: " << endl;
	Prisoners timeRelease;
	timeRelease.setreleaseTime();
	cout << "\nPrisoner release time: ";
	timeRelease.printTimeRelease();
	cout << "\n";
	
	//D-> Number Of Children
	cout << "\nPrisoner's number of children:" << endl;
	Prisoners numChild;
	numChild.setNumber();
	cout << " " << numChild.getNumber() << endl;
	 
	//E-> Place Of Last Residence
	Prisoners lastResidence;
	lastResidence.setArea("Queens, NY");
	cout << "\nPrisoner's last place of residence: " << lastResidence.getArea() << endl;
	
	
	//Guard class objects
	//A-> Favorite Weapon
	cout << "\nSelect Guard's favorite weapon." << endl;
	cout << "\nEnter 'a' for fist \nEnter 'b' for taser" << endl;
	Guard favWeapon;
	favWeapon.fav_weapon();
	cout << "\n";
	
	//B-> Steroid Use
	cout << "\nEnter 1 or 0 if Guard is using steroid: "<< endl;
	Guard steroidUse;
	steroidUse.steroid_use();
	cout << "\n";	
	
	//C-> Favorite Spot
	cout << "\nEnter the guard's preferred spot to beat up prisoners: " << endl;
	Guard favSpot;
	favSpot.fav_spot();
	cout << "\n"; 
	
    return 0;
}

/*Write a class for prisoners. Prisoners should have 
• sentence months int
• time served int
• time to release
• number of children
• place of last residence
• approved visitors
• hours worked
• pay rate (float)
• commisary balance
• cell number
• health condition [1-5]

Write a class for guards:
• favorite weapon
• steroid use [0 or 1]
• preferred place to beat prisoners
• number of infractions
• contraband
• probationary status
• gang affiliation*/

