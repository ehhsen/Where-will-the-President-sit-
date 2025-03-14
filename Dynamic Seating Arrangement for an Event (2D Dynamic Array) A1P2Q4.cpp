/*Dynamic Seating Arrangement for an Event (2D Dynamic Array)
Background: You are organizing a conference and need to manage the seating arrangement. The
number of attendees and seating layout can change dynamically.
Task:
1. Ask the user to input the number of rows and columns for the seating arrangement.
2. Dynamically allocate a 2D array to represent the seating layout.
3. Populate the array with attendee names (or IDs) as they register.
4. Implement the following features:
	• Add a new attendee (resize the array if needed).
	• Remove an attendee (mark their seat as empty).
	• Display the current seating arrangement.
	• Find and display the location of a specific attendee.

5. Deallocate the memory after use.
Real-world connection: This scenario reflects real-world event management systems where seating
arrangements need to be dynamically updated based on attendee registrations.*/

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;
void display(string** event, int row, int col) {
    cout << "\nCurrent Sitting Arrangement" << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(event[i][j] == "") 
                cout << left << setw(10) << "Empty" << " ";
            else 
                cout << left << setw(10) << event[i][j] << " ";
            
        }
        cout << "\n";
    }
}
 int main()
 {
 	int row, col;
 	
//1. Ask the user to input the number of rows and columns for the seating arrangement.
    cout<<"Enter the number of rows for the seating arrangement: ";
    cin>>row;
    cout<<"Enter the number of columns for the seating arrangement: ";
    cin>>col;	
 
//2. Dynamically allocate a 2D array to represent the seating layout.
	string** event = new string*[row];
	for(int i = 0; i < row; i++)
		event[i] = new string[col];
		
//3. Populate the array with attendee names as they register.
	cout<<"\nRegistering Atendees By Name";
	cin.ignore();
	for(int i = 0; i < row; i++){
		for(int j=0; j < col; j++){
			cout << "\nEnter attendee for seat in row " << i << ", column " << j << ": ";		
			getline(cin, event[i][j]);
		}
	}

	// Initial display of the seating arrangement
	display(event, row, col);
	
//4. Implement the following features:
//• Add a new attendee (resize the array if needed).


 char choice; 

 do
 { 
 cout<<"\nEnter the Feature You Want To implement";
 cout<<"\no [a] Add a new Attandee";
 cout<<"\no [r] Remove an Attandee";
 cout<<"\no [d] Display the Current Sitting Arrangement";
 cout<<"\no [f] Find the Location of A Specific Attendee";
 cout<<"\no [e] Exit";
 cout<<"\no Enter Choice>> ";
 choice = getch();
 
int addRow;
switch (choice)
{
	case 'a':
{
// Add a new attendee
// Search for an empty seat
bool found = false;
int emptyRow, emptyCol;
for(int i = 0; i < row; i++)
 {
    for(int j = 0; j < col; j++) 
	{
        if(event[i][j] == "") 
		{
            found = true;
            emptyRow = i;
            emptyCol = j;
            
            break;
        }
    }
        if(found) break;
    }
if(found)
{// Add the new attendee to the empty seat
string name;
cout << "\nEnter the name: ";
getline(cin, name);
event[emptyRow][emptyCol] = name;
cout<<"\nAdded"<<endl;
display(event, row, col);
} 
else 
{
        // No empty seat available, resize by adding a new row
        string** newevent = new string*[row + 1];
        for(int i = 0; i < row; i++) {
            newevent[i] = event[i];
        }
        // Allocate and initialize the new row
        newevent[row] = new string[col];
        for(int j = 0; j < col; j++) {
            newevent[row][j] = "";
        }

        // Add the new attendee
        string name;
        cout << "\nEnter the name: ";
        getline(cin, name);
        newevent[row][0] = name;

        delete[] event;
        event = newevent;
        row++; 
        display(event, row, col);        
    }//end of else 
    break;
}// end of a 
 
case 'r': {
// Remove an attendee
string name;
cout << "\nEnter the name of the attendee to remove: ";
getline(cin, name);
bool found = false;
for(int i = 0; i < row; i++) {
	for(int j = 0; j < col; j++) {
        if(event[i][j]== name) {
        	event[i][j] = "";
            found = true;
            cout<<"\nREMOVED"<<endl;
            display(event, row, col);
            break;
        }
	}
    if(found) break;
}
if(!found) 
    cout<<"\nAttandee not found"<<endl;
    break;
}// end of r

//• Display the current seating arrangement.
case 'd': display(event, row, col);break;
//• Find and display the location of a specific attendee.
case 'f':
	{
		
	
string find;

 cout<<"\nEnter name of attendee you want to find"<<endl;
 getline(cin, find);
 // look for find attendeee
for(int i = 0; i < row; i++) {
for(int j = 0; j < col; j++) {
	bool f= 0;
	if (event[i][j] == find){
		
		cout<<"\nAttendee Found"<<endl;
		cout<<"\n row "<<i<<" column "<<j<<endl;
		f = 1;
	}
	if(f)break;
	}//col	
}//row
break;
}// end of f
//
//default:
//	cout<<"\nPlease Enter a valid option from the menu "<<endl;break;
		 


}// end of switch 
}
while(choice != 'e');
cout<<"\nMeow";
//5. Deallocate the memory after use.
for(int i = 0; i < row; i++)
{
	delete[] event[i];
}
delete[] event;

return 0;
}
	   
 	