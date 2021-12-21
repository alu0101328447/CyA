#ifndef DFA
#define DFA

#include "alphabet.h"
#include "states.h"
#include "chain.h"

class Dfa {
  public:
    Dfa();
    Dfa(std::vector <States>, Alphabet);
    ~Dfa();

    std::set <States> state(void);
    Alphabet alphabet(void);

    void state(std::vector <States>);
    void Add_State(States);
    void alphabet(Alphabet);

    States Initial(void);

    States Transition(Chain);

  private:
    Alphabet alphabet_;
    std::set <States> states_;


};

#endif