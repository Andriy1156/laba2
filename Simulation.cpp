#include <iostream>
#include "Simulation.h"
using namespace std;

ParkedCar::ParkedCar(string mark, string model, string colour, string licenseNumber, unsigned int minutesParked)
{
    this->mark = mark;
    this->model = model;
    this->colour = colour;
    this->licenseNumber = licenseNumber;
    this->minutesParked = minutesParked;
}
string ParkedCar::getMark() const
{
    return this->mark;
}

string ParkedCar::getModel() const
{
    return this->model;
}

string ParkedCar::getColour() const
{
    return this->colour;
}

string ParkedCar::getLicenseNumber() const
{
    return this->licenseNumber;
}

int ParkedCar::getMinutesParked() const
{
    return this->minutesParked;
}


ParkingMeter::ParkingMeter(unsigned int purchased)
{
    this->purchased = purchased;
}
int ParkingMeter::getPurchased() const
{
    return this->purchased;
}



void ParkingTicket::ShowTicket(const ParkedCar& car) const
{
    if (car.getMark() == carMark && car.getModel() == carModel &&
        car.getColour() == carColour && car.getLicenseNumber() == carLicenseNumber)
    {
        cout << "Parking Ticket Information:" << endl;
        cout << "---------------------------" << endl;
        cout << "Car Details:" << endl;
        cout << "Mark: " << carMark << endl;
        cout << "Model: " << carModel << endl;
        cout << "Colour: " << carColour << endl;
        cout << "License Number: " << carLicenseNumber << endl;
        cout << "Minutes Parked: " << minutesParked;
        cout << "\n\nOfficer Details:" << endl;
        cout << "Name: " << Name << endl;
        cout << "Badge Number: " << badge << endl;
        cout << "\nFine: $" << fine << endl;
    }
    else
    {
        cout << "No Information about this Car" << endl;
    }
}

int ParkingTicket::calcFine(const ParkedCar& car, const ParkingMeter& meter)
{

    int overParked = car.getMinutesParked() - meter.getPurchased();

    if (overParked <= 0)
    {
        return 0; 
    }

    int fine = 25;
    if (overParked / 60 >= 1)
        fine += (overParked / 60) * 10; 


    return fine;
}


PoliceOfficer::PoliceOfficer(string officerName, string badgeNumber)
{
    this->officerName = officerName;
    this->badgeNumber = badgeNumber;
}

string PoliceOfficer::getOfficerName() const
{
    return this->officerName;
}

string PoliceOfficer::getBadgeNumber() const
{
    return this->badgeNumber;
}

ParkingTicket PoliceOfficer::CheckCar(const ParkedCar& car, const ParkingMeter& purchased)
{
    ParkingTicket ticket;
    int fine = ticket.calcFine(car, purchased);
    if (fine > 0)
    {
        ticket.badge = getBadgeNumber();
        ticket.Name = getOfficerName();
        ticket.fine = fine;
        ticket.carMark = car.getMark();
        ticket.carModel = car.getModel();
        ticket.carColour = car.getColour();
        ticket.carLicenseNumber = car.getLicenseNumber();
        ticket.minutesParked = car.getMinutesParked();
    }
    else
    {
        ticket.badge = getBadgeNumber();
        ticket.Name = getOfficerName();
        ticket.fine = 0;
        ticket.carMark = car.getMark();
        ticket.carModel = car.getModel();
        ticket.carColour = car.getColour();
        ticket.carLicenseNumber = car.getLicenseNumber();
        ticket.minutesParked = car.getMinutesParked();
    }
    return ticket;
}
