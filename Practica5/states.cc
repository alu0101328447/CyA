#include "states.h"

States::States()
{}

States::States(std::string name, bool start, bool acceptance) {
  name_ = name;
  Is_Start(start);
  Is_Acceptance(acceptance);
}

States::~States()
{}

std::string
States::name(void) const {
  return name_;
}

std::vector <std::pair <Simbol, States>>
States::get_transition(void) {
  return transition_;
}

std::vector <std::pair <Simbol, States>>
States::get_transition(void) const {
  return transition_;
}

States 
States::get_transition(Simbol simbol) {
  for(auto& t : transition_) {
    if(t.first == simbol) {
      return t.second;
    }
  }
}

States 
States::get_transition(Simbol simbol) const {
  for(auto& t : transition_) {
    if(t.first == simbol) {
      return t.second;
    }
  }
}

bool
States::Is_Start(void) {
  return start_;
}

bool
States::Is_Start(void) const{
  return start_;
}

bool
States::Is_Acceptance(void) {
  return acceptance_;
}

void
States::name(std::string name) {
  name_ = name;
}

void
States::set_transition(std::vector <std::pair <Simbol, States>> transition) {
  transition_ = transition;
}

void
States::Add_Transition(Simbol simbol, States state) {
  std::pair <Simbol, States> transition;
  transition.first = simbol;
  transition.second = state;
  transition_.push_back(transition);
}

void
States::Is_Start(bool start) {
  start_ = start;
}

void
States::Is_Acceptance(bool acceptance) {
  acceptance_ = acceptance;
}

bool
States::operator <(const States& states) const {
  return name_ < states.name();
}

