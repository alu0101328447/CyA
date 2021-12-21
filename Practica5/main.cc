#include "dfa.h"
#include "chain.h"
#include "languaje.h"

#include <fstream>
#include <cstring>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

void Help_Message(void);
Dfa FeqL_Dfa(void);

int main(int argc, char** argv) {

  std::string in_chain;
  std::string out_chain;
  std::string aux_chain;
  Simbol simbol;
  Chain chain;

  if (argc != 3) {
    if ((argv[1] == "-h") || (argv[1] == "--help")) {
      Help_Message();
      return 1;
    } else {
      std::cerr << "Modo de empleo: p05_dfa [CADENA] [FICHERO]" 
      << std::endl << "Pruebe ./ 'p05_dfa --help' para más informaci ́on."
      << std::endl;
      return 1;
    }
  }


  out_chain = argv[2];
  std::ofstream out_file(argv[2]);
  if (!out_file.is_open()) {
    std::cerr << "Error con la apertura del fichero" << std::endl;
    return 1;
  }

  in_chain = argv[1];
  for (int i = 0; i < in_chain.size(); i++) {
    aux_chain.push_back(in_chain[i]);
    simbol.set_simbol(aux_chain);
    chain.Add_Simbol(simbol);
    aux_chain.clear();
  }

  std::vector <Chain> sub_chains;
  sub_chains = chain.Sub_Chain();
  Languaje languaje(sub_chains);
  
  Dfa dfa;
  dfa = FeqL_Dfa();

  for (auto& sc : sub_chains) {
    if (dfa.Transition(sc).Is_Acceptance()) {
      out_file << sc << std::endl;
    }
  }
  out_file.close();
  return 0;
}

void Help_Message(void) {
  system("clear");
  std::cerr << "El modo de uso de este programa es el siguiente:" << std::endl
  << "./ p05_dfa 'chain' fileout.txt" << std::endl
  << "-Teniendo en cuenta que:" << std::endl
  << "\tchain : cadena que se analizara con respecto al dfa" 
  << std::endl << "\tfilout.txt : es el nombre de el fichero de salida"
  << std::endl;

  std::cerr << std::endl << "PRESIONE ENTER PARA SALIR ..." << std::endl;
  getchar();  
  system("clear");
}

Dfa FeqL_Dfa(void) {
  std::vector <States> states;
  Alphabet alphabet;

  Simbol A("A");
  Simbol T("T");
  Simbol G("G");
  Simbol C("C");
  
  alphabet.Add_Simbol(A);
  alphabet.Add_Simbol(T);
  alphabet.Add_Simbol(G);
  alphabet.Add_Simbol(C);


  States q0("q0", true, false);
  States q1("q1", false, false);
  States q2("q2", false, false);
  States q3("q3", false, false);
  States q4("q4", false, true);
  States q5("q5", false, true);

  q0.Add_Transition(A, q1);
  q0.Add_Transition(T, q2);
  q0.Add_Transition(G, q3);
  q0.Add_Transition(C, q3);

  q1.Add_Transition(A, q5);
  q1.Add_Transition(T, q1);
  q1.Add_Transition(G, q1);
  q1.Add_Transition(C, q1);

  q2.Add_Transition(A, q2);
  q2.Add_Transition(T, q4);
  q2.Add_Transition(G, q2);
  q2.Add_Transition(C, q2);

  q3.Add_Transition(A, q3);
  q3.Add_Transition(T, q3);
  q3.Add_Transition(G, q3);
  q3.Add_Transition(C, q3);

  q4.Add_Transition(A, q2);
  q4.Add_Transition(T, q4);
  q4.Add_Transition(G, q2);
  q4.Add_Transition(C, q2);

  q5.Add_Transition(A, q5);
  q5.Add_Transition(T, q1);
  q5.Add_Transition(G, q1);
  q5.Add_Transition(C, q1);

  states.push_back(q0);
  states.push_back(q1);
  states.push_back(q2);
  states.push_back(q3);
  states.push_back(q4);
  states.push_back(q5);

  Dfa dfa(states, alphabet);

  return dfa;
}