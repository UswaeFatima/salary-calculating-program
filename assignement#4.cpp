#include <iostream>
using namespace std;

// Declare structures for hourly paid and salaried workers
struct HourlyPaidWorker {
  int hoursWorked;
  double hourlyRate;
};

struct SalariedWorker {
  double salary;
  double bonus;
};

// Declare union with two members: one for hourly paid worker and one for salaried worker
union Worker {
  HourlyPaidWorker hourlyWorker;
  SalariedWorker salariedWorker;
};

int main() {
  // Declare union variable
  Worker worker;

  // Ask user whether they are calculating pay for hourly paid or salaried worker
  cout << "Are you calculating pay for an hourly paid worker or a salaried worker? (Enter 'hourly' or 'salaried'): ";
  string workerType;
  cin >> workerType;

  // If calculating pay for hourly paid worker, get data and calculate pay
  if (workerType == "hourly") {
    cout << "Enter number of hours worked: ";
    cin >> worker.hourlyWorker.hoursWorked;
    // Input validation: do not accept negative numbers or values greater than 80 for hours worked
    while (worker.hourlyWorker.hoursWorked < 0 || worker.hourlyWorker.hoursWorked > 80) {
      cout << "Invalid input. Enter a number between 0 and 80: ";
      cin >> worker.hourlyWorker.hoursWorked;
    }

    cout << "Enter hourly rate: ";
    cin >> worker.hourlyWorker.hourlyRate;
    // Input validation: do not accept negative numbers
    while (worker.hourlyWorker.hourlyRate < 0) {
      cout << "Invalid input. Enter a positive number: ";
      cin >> worker.hourlyWorker.hourlyRate;
    }

    double pay = worker.hourlyWorker.hoursWorked * worker.hourlyWorker.hourlyRate;
    cout << "Pay for hourly paid worker: $" << pay << endl;
  }
  // If calculating pay for salaried worker, get data and calculate pay
  else if (workerType == "salaried") {
    cout << "Enter salary: ";
    cin >> worker.salariedWorker.salary;
    // Input validation: do not accept negative numbers
    while (worker.salariedWorker.salary < 0) {
      cout << "Invalid input. Enter a positive number: ";
      cin >> worker.salariedWorker.salary;
    }

    cout << "Enter bonus: ";
    cin >> worker.salariedWorker.bonus;
    // Input validation: do not accept negative numbers
    while (worker.salariedWorker.bonus < 0) {
      cout << "Invalid input. Enter a positive number: ";
      cin >> worker.salariedWorker.bonus;
    }
}
   
}




