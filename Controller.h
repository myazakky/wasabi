#ifndef Controller_h
#define Controller_h

class Controller
{
public:
  void initialize();
  void cool();
  void hot();
  void neutral();
  void receive();
  void displayState();
  const char *state;
};

#endif
