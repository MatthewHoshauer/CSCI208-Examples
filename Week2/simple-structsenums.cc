// Simple I/O stream examples for Week 2 of CSCI 208
// R. Paul Wiegand

#include<iostream>

enum DayQuality {DQ_GOOD, DQ_MEH, DQ_BAD};

struct Date {
  int day;
  int month;
  int year;
  DayQuality quality;
};  // <--- Don't forget the semicolon!


Date askUserAboutDay() {
  Date currentDate;

  std::cout << "Think of an important day, then answer these questions:" << std::endl;
  
  std::cout << "  What was the day of the month? ";
  std::cin >> currentDate.day;
  
  std::cout << "  What was the numeric month (1-12)? ";
  std::cin >> currentDate.month;

  std::cout << "  What was the year? ";
  std::cin >> currentDate.year;

  std::cout << "  Was it a good day (y, n, m)? ";
  char dq;
  std::cin >> dq;

  switch (dq) {
    case 'y' : currentDate.quality = DQ_GOOD; break;
    case 'n' : currentDate.quality = DQ_BAD; break;
    default : currentDate.quality = DQ_MEH;
  }

  return(currentDate);
}
  

void printDay(Date myDate) {
  std::cout << myDate.month << "/"
	    << myDate.day << "/"
	    << myDate.year << "  "
            << (int)myDate.quality << std::endl << std::endl;
}

int main() {
  char keepGoing;

  do {
    std::cout << "I'm going to ask you about somes days of your life." << std::endl;
    printDay(askUserAboutDay());
    
    std::cout << "Ask about more days? ";
    std::cin >> keepGoing;
    std::cout << std::endl;
  } while (keepGoing == 'y');
    
  
  // Everything ran okey-dokey, so tell the OS we're good
  return 0;
}
