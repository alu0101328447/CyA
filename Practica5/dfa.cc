#include "dfa.h"

Dfa::Dfa()
{}

Dfa::Dfa(std::vector <States> states, Alphabet alphabet) {
  this->state(states);
  this->alphabet(alphabet);
}

Dfa::~Dfa()
{}

std::set <States>
Dfa::state(void) {
  return states_;
}

Alphabet
Dfa::alphabet(void) {
  return alphabet_;
}

void
Dfa::state(std::vector <States> state) {
  for (auto& s : state) {
    this->Add_State(s);
  }
}

void 
Dfa::Add_State(States state) {
  states_.insert(state);
}

void 
Dfa::alphabet(Alphabet alphabet) {
  alphabet_ = alphabet;
}

States 
Dfa::Initial(void) {
  for (auto& s : this->state()) {
    if (s.Is_Start()) {
      return s;
    }
  }
}

States 
Dfa::Transition(Chain chain) {
  States aux_state;
  std::string state_name;

  aux_state = Initial();
  for(int i = 0; i < chain.size(); i++) {
    if(!alphabet_.Contains(chain.chain()[i])) {
      return States("Do not belong", false, false);
    }
  }

  for (auto& c : chain.chain()) {
    state_name = aux_state.get_transition(c).name();
    for (const auto& d : states_) {
      if (state_name == d.name()) {
        aux_state = d;
      }
    }
  }
  return aux_state;
}



