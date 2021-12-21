#ifndef STATUS
#define STATUS

#include "simbol.h"

class States {
  public:
    States();
    States(std::string, bool, bool);
    ~States();

    std::string name(void) const;
    std::vector <std::pair <Simbol, States>> get_transition(void);
    std::vector <std::pair <Simbol, States>> get_transition(void) const;
    States get_transition(Simbol);
    States get_transition(Simbol) const;

    bool Is_Start(void);
    bool Is_Start(void) const;
    bool Is_Acceptance(void);

    void name(std::string);
    void set_transition(std::vector <std::pair <Simbol, States>>);

    void Add_Transition(Simbol, States);

    void Is_Start(bool);
    void Is_Acceptance(bool);

    bool operator<(const States&) const;

  private:
    std::string name_;
    std::vector <std::pair <Simbol, States>> transition_;

    bool start_;
    bool acceptance_;
};

#endif