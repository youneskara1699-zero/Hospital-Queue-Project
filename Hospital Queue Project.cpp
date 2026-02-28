#include <iostream>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

class HospitalQueue
{
private:
    string _Department;
    int _AverageServeTime;
    int _TotalPatients;
    int _ServedPatients;
    int _WaitingPatients;

    string _GetDateTime()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        return to_string(now->tm_mday) + "/" +
               to_string(now->tm_mon + 1) + "/" +
               to_string(now->tm_year + 1900) + " " +
               to_string(now->tm_hour) + ":" +
               to_string(now->tm_min) + ":" +
               to_string(now->tm_sec);
    }

    struct PatientTicket
    {
        string TicketID;
        string DateTime;
        int WaitingPatients;
        int ServeTime;
    };

    queue<PatientTicket> _Queue;

public:
    HospitalQueue(string Department, int AvgServeTime)
    {
        _Department = Department;
        _AverageServeTime = AvgServeTime;
        _TotalPatients = 0;
        _ServedPatients = 0;
        _WaitingPatients = 0;
    }

    void RegisterPatient()
    {
        _TotalPatients++;
        _WaitingPatients++;

        PatientTicket ticket;
        ticket.TicketID = _Department + to_string(_TotalPatients);
        ticket.DateTime = _GetDateTime();
        ticket.WaitingPatients = _WaitingPatients;
        ticket.ServeTime = _WaitingPatients * _AverageServeTime;

        _Queue.push(ticket);
    }

    void ServeNextPatient()
    {
        if (!_Queue.empty())
        {
            _Queue.pop();
            _ServedPatients++;
            _WaitingPatients--;
        }
    }

    void PrintQueueInfo()
    {
        cout << "-----------------------------------------\n";
        cout << "Department       : " << _Department << endl;
        cout << "Total Patients   : " << _TotalPatients << endl;
        cout << "Served Patients  : " << _ServedPatients << endl;
        cout << "Waiting Patients : " << _WaitingPatients << endl;
        cout << "-----------------------------------------\n";
    }

    void PrintPatientsLTR()
    {
        queue<PatientTicket> temp = _Queue;
        cout << "Patients: ";
        while (!temp.empty())
        {
            cout << temp.front().TicketID << " ";
            temp.pop();
        }
        cout << endl;
    }

    void PrintPatientsRTL()
    {
        queue<PatientTicket> temp = _Queue;
        stack<string> s;

        while (!temp.empty())
        {
            s.push(temp.front().TicketID);
            temp.pop();
        }

        cout << "Patients: ";
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void PrintAllPatients()
    {
        queue<PatientTicket> temp = _Queue;

        cout << "------- Patients -------\n";

        while (!temp.empty())
        {
            PatientTicket p = temp.front();
            temp.pop();

            cout << "-----------------------------\n";
            cout << "Ticket     : " << p.TicketID << endl;
            cout << "DateTime   : " << p.DateTime << endl;
            cout << "Waiting    : " << p.WaitingPatients << endl;
            cout << "Serve Time : " << p.ServeTime << " Minutes\n";
        }
    }
};

int main()
{
    HospitalQueue Emergency("ER", 5);

    Emergency.RegisterPatient();
    Emergency.RegisterPatient();
    Emergency.RegisterPatient();
    Emergency.RegisterPatient();

    Emergency.PrintQueueInfo();
    Emergency.PrintPatientsLTR();
    Emergency.PrintPatientsRTL();
    Emergency.PrintAllPatients();

    Emergency.ServeNextPatient();

    Emergency.PrintQueueInfo();

    return 0;
}
