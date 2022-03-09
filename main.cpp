#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int SeatNotFoundFlag = 0;

void DisplayMenu()
{
    cout << "\nMenu Options: ";
    cout << "\n1. Display all seats status: ";
    cout << "\n2. Total number of available seats: ";
    cout << "\n3. Display available seats: ";
    cout << "\n4. Book seat: ";
    cout << "\n5. Cancel seat: ";
    cout << "\n6. Change seat: ";
    cout << "\n7. Quit: ";
    cout << "\nPlease select an option (1-7): ";
}
void DisplayAllSeatsStatus(const vector<string> &seats, const vector<bool> &SeatStatus)
{
    vector<string> AllSeats;
    vector<bool> status;
    string temp1;
    bool temp2;

    for (int i = 0; i < seats.size(); i++)
    {
        temp1 = seats.at(i);
        temp2 = SeatStatus.at(i);
        AllSeats.push_back(temp1);
        status.push_back(temp2);
    }
    for (int j = 0; j < AllSeats.size(); j++)
    {
        cout << AllSeats.at(j) << "      " << status.at(j) << endl;
    }
}
void DisplayAvailableSeats(const vector<string> &seats, const vector<bool> &SeatStatus)
{
    vector<string> AllSeats;
    vector<bool> status;
    string temp1;
    bool temp2;
    int flag = 0;

    for (int i = 0; i < seats.size(); i++)
    {
        temp1 = seats.at(i);
        temp2 = SeatStatus.at(i);
        AllSeats.push_back(temp1);
        status.push_back(temp2);
    }
    for (int j = 0; j < AllSeats.size(); j++)
    {
        temp2 = status.at(j);
        if (temp2 == 0)
        {
            cout << AllSeats.at(j) << endl;
            flag++;
        }
        else if (flag == 0)
        {
            cout << "No seats are available! Please come back later.";
        }
    }
}
int TotalNumberOfAvailableSeats(const vector<bool> &SeatStatus)
{
    vector<bool> status;
    bool temp2;
    int flag = 0;
    for (int i = 0; i < SeatStatus.size(); i++)
    {
        temp2 = SeatStatus.at(i);
        status.push_back(temp2);
    }
    for (int j = 0; j < status.size(); j++)
    {
        temp2 = status.at(j);
        if (temp2 == 0)
        {
            flag++;
        }
    }
    return flag;
}
vector<bool> BookSeat(const string &seat, const vector<string> &seats, const vector<bool> &SeatStatus)
{
    vector<string> AllSeats;
    vector<bool> status;
    string temp1;
    bool temp2;
    int indexOld;

    for (int i = 0; i < seats.size(); i++)
    {
        temp1 = seats.at(i);
        temp2 = SeatStatus.at(i);
        AllSeats.push_back(temp1);
        status.push_back(temp2);
    }

    vector<string>::iterator findSeatOld = find(AllSeats.begin(), AllSeats.end(), seat);
    if (findSeatOld != AllSeats.end())
    {
        indexOld = distance(AllSeats.begin(), findSeatOld);
        //! Check if seat is available or not then book seat
        if (SeatStatus.at(indexOld) == 0)
        {
            status.at(indexOld) = 1;
            
        }
        else
        {
            cout << "Please choose another seat. This is already booked." << endl;
            SeatNotFoundFlag++;
        }
    }
    else
    {
        cout << "Seat does not exist. Please try again." << endl;
    }
    return status;
}

vector<bool> cancelSeat(const string &seat, const vector<string> &seats, const vector<bool> &SeatStatus)
{
    vector<string> AllSeats;
    vector<bool> status;
    string temp1;
    bool temp2;
    int indexOld;

    for (int i = 0; i < seats.size(); i++)
    {
        temp1 = seats.at(i);
        temp2 = SeatStatus.at(i);
        AllSeats.push_back(temp1);
        status.push_back(temp2);
    }

    vector<string>::iterator findSeatOld = find(AllSeats.begin(), AllSeats.end(), seat);
    if (findSeatOld != AllSeats.end())
    {
        indexOld = distance(AllSeats.begin(), findSeatOld);
        if (SeatStatus.at(indexOld) == 1)
        {
            status.at(indexOld) = 0;
            
        }
        else
        {
            cout << "Wrong Seat! Please try again." << endl;
            SeatNotFoundFlag++;
        }
    }
    else
    {
        cout << "Seat does not exist. Please try again." << endl;
    }
    return status;
}

vector<bool> ChangeSeat(const string &oldSeat, const string &NewSeat, const vector<string> &seats, const vector<bool> &SeatStatus)
{
    vector<string> AllSeats;
    vector<bool> status;
    string temp1;
    bool temp2;
    int indexOld,indexNew;

    for (int i = 0; i < seats.size(); i++)
    {
        temp1 = seats.at(i);
        temp2 = SeatStatus.at(i);
        AllSeats.push_back(temp1);
        status.push_back(temp2);
    }

    vector<string>::iterator findSeatOld = find(AllSeats.begin(), AllSeats.end(), oldSeat);
    vector<string>::iterator findSeatNew = find(AllSeats.begin(), AllSeats.end(), NewSeat);
    //! Cancel seat
    if (findSeatOld != AllSeats.end())
    {
        indexOld = distance(AllSeats.begin(), findSeatOld);
        if (SeatStatus.at(indexOld) == 1)
        {
            status.at(indexOld) = 0;
        }
        else
        {
            cout << "Wrong Seat! Please try again." << endl;
            SeatNotFoundFlag++;
        }
    }
    else
    {
        cout << "Old Seat does not exist. Please try again." << endl;
    }
    //! Book new seat
    if (findSeatNew != AllSeats.end())
    {
        indexNew = distance(AllSeats.begin(), findSeatNew);
        if (SeatStatus.at(indexNew) == 0)
        {
            status.at(indexNew) = 1;
        }
        else
        {
            cout << "Wrong Seat! Please try again." << endl;
            SeatNotFoundFlag++;
        }
    }
    else
    {
        cout << "New Seat does not exist. Please try again." << endl;
    }
    return status;
}

void printSpace()
{
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
    cout << "                                                         " << endl;
}

int main()
{
    vector<string> seats = {"1A", "1B", "1C", "1D", "1E", "2A", "2B", "2C", "2D", "2E", "3A", "3B", "3C", "3D", "3E", "4A", "4B", "4C", "4D", "4E", "5A", "5B", "5C", "5D", "5E"};
    vector<bool> SeatStatus = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string oldSeat, NewSeat, seat;
    char labelMenu, labelSeatName, labelSeatNameCancel, labelSeatNameChange;
    int userInput;

labelMenu:

    DisplayMenu();
    cin >> userInput;
    switch (userInput)
    {
    case 1:
        DisplayAllSeatsStatus(seats, SeatStatus);
        system("pause");
        printSpace();
        goto labelMenu;
        break;
    case 2:
        system("CLS");
        cout << "The total number of available seats are: " << TotalNumberOfAvailableSeats(SeatStatus) << endl;
        system("pause");
        printSpace();
        goto labelMenu;
        break;
        
    case 3:
        DisplayAvailableSeats(seats, SeatStatus);
        system("pause");
        printSpace();
        goto labelMenu;
        break;
        
    case 4:
    labelSeatName:
        cout << "Enter the name of seat you would like to book: ";
        cin >> seat;
        SeatStatus = BookSeat(seat, seats, SeatStatus);
        if (SeatNotFoundFlag == 0)
        {
            cout << "Seat"<<"           "<<"Status"<<endl;
            for (int j = 0; j < SeatStatus.size(); j++)
            {
                cout << seats.at(j)<<"                "<< SeatStatus.at(j) << endl;
            }
            goto labelMenu;
        }
        else
        {
            goto labelSeatName;
        }
        break;
    case 5:
    labelSeatNameCancel:
        cout << "Enter the name of seat you would like to cancel: ";
        cin >> seat;
        SeatStatus = cancelSeat(seat, seats, SeatStatus);
        if (SeatNotFoundFlag == 0)
        {
            cout << "Seat"<<"           "<<"Status"<<endl;
            for (int j = 0; j < SeatStatus.size(); j++)
            {
                cout << seats.at(j)<<"                "<< SeatStatus.at(j) << endl;
            }
            goto labelMenu;
        }
        else
        {
            goto labelSeatNameCancel;
        }
        break;
    case 6:
    labelSeatNameChange:
        cout << "Enter the name of seat you would like to cancel: ";
        cin >> oldSeat;
        cout << "Enter the name of seat you would like to book: ";
        cin >> NewSeat;
        SeatStatus = ChangeSeat(oldSeat,NewSeat,seats, SeatStatus);
        if (SeatNotFoundFlag == 0)
        {
            cout << "Seat"<<"           "<<"Status"<<endl;
            for (int j = 0; j < SeatStatus.size(); j++)
            {
                cout << seats.at(j)<<"                "<< SeatStatus.at(j) << endl;
            }
            goto labelMenu;
        }
        else
        {
            goto labelSeatNameChange;
        }
        break;
    case 7:
        cout<<"Thank you for using Airline Management System.";
        break;
    default:
        cout<<"Wrong choice. Please try again.";
        goto labelMenu;
        break;
    }

    return 0;
}