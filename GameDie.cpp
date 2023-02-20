#include "GameDie.h"

#include <cstdlib>
#include <ctime>
#include <vector>

// class constructor that seeds the random number generator
GameDie::GameDie() {
  srand(time(NULL));
  counter.resize(FACES);

  for (int i = 0; i < FACES; i++) counter[i] = 0;
}

// overloaded constructor
GameDie::GameDie(unsigned int num) {
  if (num == 0) {
    counter.resize(FACES);
  } else {
    counter.resize(num);
  }
  for (int i = 0; i < FACES; i++) {
    counter[i] = 0;
  }
}

// generate a random number between 1-n where n is the counter size
//  (inclusive) and return it
int GameDie::roll() {
  int roll = rand() % counter.size();
  counter[roll]++;
  return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector<int> GameDie::get_distribution() { return counter; }

// returns percent of rolling each side of the die
vector<double> GameDie::get_percentages() {
  if (counter[0] == 0) {
    for (int i = 0; i < (int)FACES; i++) percentages.push_back(0);
    return percentages;
  }
  double pct = (double)(1 / FACES);
  for (int i = 0; i < (int)FACES; i++) percentages.push_back(pct);
  return percentages;
}