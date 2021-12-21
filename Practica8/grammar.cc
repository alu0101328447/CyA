#include "grammar.h"

/**
 * @author: José Pablo Ruiz Galván
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 3º Ingeniería Informática
 * Práctica 8: Grammar 
 */

/**
*
*  @brief  Grammar constructor -> initialize Alphabet objects-
*
*/
Grammar::Grammar() 
{}

/**
*
*  @brief  Grammar constructor -> initialize Alphabet objects-
*  @param Alphabet -> the termal simbol alphabet
*  @param Alphabet -> the non-termal simbol alphabet
*  @param Symbol -> the start symbol
*
*/
Grammar::Grammar(Alphabet terminals, Alphabet non_terminals, Symbol start) {
  set_terminals(terminals);
  set_non_terminals(non_terminals);
  set_start(start);
}

/**
*
*  @brief  Grammar destructor -> destroys Alphabet objects-
*
*/
Grammar::~Grammar()
{}


/**
*
*  @brief  Grammar getter
*  @return Alphabet -> the termal simbol alphabet
*
*/
Alphabet
Grammar::get_terminals(void) {
  return terminals_;
}

/**
*
*  @brief  Grammar getter
*  @return Alphabet -> the non-termal simbol alphabet
*
*/
Alphabet
Grammar::get_non_terminals(void) {
  return non_terminals_;
}

/**
*
*  @brief  Grammar getter
*  @return Symbol -> the start symbol
*
*/
Symbol 
Grammar::get_start(void) {
  return start_;
}

/**
*
*  @brief  Grammar getter 
*  @return std::vector <Chain> -> the production chain in relation whith @param symbol
*
*/
std::vector <Chain>
Grammar::get_production(Symbol symbol) {
  return productions_[symbol];
}

/**
*
*  @brief  Grammar setter 
*  @param Alphabet -> the termal simbol alphabet
*
*/
void 
Grammar::set_terminals(Alphabet terminals) {
  terminals_ = terminals;
}

/**
*
*  @brief  Grammar setter
*  @param Alphabet -> the non-termal simbol alphabet
*
*/
void 
Grammar::set_non_terminals(Alphabet non_terminals) {
  non_terminals_ = non_terminals;
}

/**
*
*  @brief  Grammar setter 
*  @param Symbol -> the start symbol
*
*/
void 
Grammar::set_start(Symbol start) {
  start_ = start;
}

/**
*
*  @brief  Grammar setter
*  @param std::map <Symbol, std::vector <Chain>> productions -> the productions
*  of the grammar
*
*/
void 
Grammar::set_production(std::map <Symbol, std::vector <Chain>> productions) {
  productions_ = productions;
}

/**
*
*  @brief  Grammar add funtion
*  @param Symbol -> another terminal symbol
*
*/
void 
Grammar::Add_Terminal(Symbol symbol) {
  terminals_.Add_Symbol(symbol);
}

/**
*
*  @brief  Grammar add funtion
*  @param Symbol -> another non-terminal symbol
*
*/
void 
Grammar::Add_Non_Terminal(Symbol symbol) {
  non_terminals_.Add_Symbol(symbol);
}

/**
*
*  @brief  Grammar add funtion
*  @param Symbol -> the key of the map class
*  @param Chain -> the chain mapped with the @param symbol
*
*/
void 
Grammar::Add_Production(Symbol non_terminal, Chain terminal) {
  productions_[non_terminal].push_back(terminal);
}

/**
*
*  @brief  Grammar funtion to get the production
*  @param Chain -> the pre production line
*  @param Chain -> the production line
*  @return Chain -> the actual production line
*
*/
Chain 
Grammar::Product(Chain line, Chain production) {
  Chain aux;
  aux.clear();
  for (int i = 0; i < line.size(); i++) {
    if (non_terminals_.Contains(line.chain()[i])) {
      for (int j = 0; j < production.size(); j++) {
        aux.Add_Symbol(production.chain()[j]);
      }
      for (int j = i + 1; j < line.size(); j++) {
        aux.Add_Symbol(line.chain()[j]);
      }
      return aux;
    } else {
      aux.Add_Symbol(line.chain()[i]);
    }
  }
  return production;
}

/**
*
*  @brief  Grammar funtion to get the derivations
*  @param Chain -> the non_terminals
*  @param std::vector <int> -> the position of the transition
*  @return std::string -> the derivation process
*
*/
std::string
Grammar::Derivations(Chain non_terminals, std::vector <int> pos) {
  Symbol current(start_);
  std::vector <Symbol> non_terminal_list;
  Chain list;
  Chain aux;
  std::string result;
  
  // Compruebo que todos los simbolos son no terminales
  for (int i = 0; i < non_terminals.size(); i++) {
    if (!non_terminals_.Contains(non_terminals.chain()[i])) {
      std::cerr << "ERROR con la introduccion de los no terminales"
      << std::endl;
      exit(1);
    }
  }

  result = current.get_symbol();
  result += " -> ";

  for (int i = 0; i < non_terminals.size(); i++) {

    non_terminals.chain()[i] == current;
    if (pos[i] > get_production(current).size()) {
      std::cerr << "Error con la introduccion de datos" << std::endl;
      exit(1);
    }

    aux = get_production(current)[pos[i] - 1];
    list = Product(list, aux);
    result += list.to_s();
    if (i < non_terminals.size() - 1) {
      result += " -> ";
    }
    
    non_terminal_list.clear();
    for (int j = 0; j < list.size(); j++) {
      if ((non_terminals_.Contains(list.chain()[j])) && (list.chain()[j].get_symbol() != " ")) {
        non_terminal_list.push_back(list.chain()[j]);
      }
    }

    if (non_terminal_list.size() > 0) {
      current = non_terminal_list[0];
      non_terminal_list.erase(non_terminal_list.begin());
    } else {
      return result;
    }

  }

  return result;
}

