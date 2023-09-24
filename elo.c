// C program for Elo Rating
// 24.09.2023
// Vou para o desfile de "07 de setembro ainda..." em Riachuelo :((
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// #define COLORS
#define COLOR_GREEN_BOLD "\033[1;32m"
#define COLOR_NORMAL "\033[0m"

// Function to calculate the Probability
float Probability(int rating1, int rating2) {
  return 1.0 * 1.0 / (1 + 1.0 * pow(10, 1.0 * (rating1 - rating2) / 400));
}

// Function to calculate Elo rating
// K is a constant.
// d determines Player number of wins.
void EloRating(float Ra, float Rb, float Rc, float Rd, float Re, float Rf,
               int K, float d)

{

  // To calculate the Winning
  // Probability of Player against Opponent B
  float PaB = Probability(Rb, Ra);

  // To calculate the Winning
  // Probability of Player against Opponent C
  float PaC = Probability(Rc, Ra);

  // To calculate the Winning
  // Probability of Player against Opponent D
  float PaD = Probability(Rd, Ra);

  // To calculate the Winning
  // Probability of Player against Opponent E
  float PaE = Probability(Re, Ra);

  // To calculate the Winning
  // Probability of Player against Opponent F
  float PaF = Probability(Rf, Ra);

  float Pa = PaB + PaC + PaD + PaE + PaF;

  float Rn = Ra + K * (d - Pa);

  printf("----------------------\n");
  printf(COLOR_GREEN_BOLD);
  printf("\tNovo Rating = %.2f\n", Rn);
  printf(COLOR_NORMAL);
  printf("(Ctrl + C para sair)\n");
  printf("----------------------\n");
}

// Driver code
int main() {
  printf("\t***CALCULADORA DE RATING ALEKIBA***\n");

  float Ra = 0, Rb = 0, Rc = 0, Rd = 0, Re = 0, Rf = 0, d = 0;

  int K = 30;
  printf("\n");
  printf("Rating Jogador: ");
  scanf("%f", &Ra);
  printf("---\n");
  printf("Rating Adversário 1: ");
  scanf("%f", &Rb);
  printf("Rating Adversário 2: ");
  scanf("%f", &Rc);
  printf("Rating Adversário 3: ");
  scanf("%f", &Rd);
  printf("Rating Adversário 4: ");
  scanf("%f", &Re);
  printf("Rating Adversário 5: ");
  scanf("%f", &Rf);
  printf("Pontos Obtidos: ");
  scanf("%f", &d);

  // Function call
  EloRating(Ra, Rb, Rc, Rd, Re, Rf, K, d);
  while (Ra != 0) {
    printf("Rating Jogador: ");
    scanf("%f", &Ra);
    printf("---\n");
    printf("Rating Adversário 1: ");
    scanf("%f", &Rb);
    printf("Rating Adversário 2: ");
    scanf("%f", &Rc);
    printf("Rating Adversário 3: ");
    scanf("%f", &Rd);
    printf("Rating Adversário 4: ");
    scanf("%f", &Re);
    printf("Rating Adversário 5: ");
    scanf("%f", &Rf);
    printf("Pontos Obtidos: ");
    scanf("%f", &d);

    // Function call
    EloRating(Ra, Rb, Rc, Rd, Re, Rf, K, d);
    if (Ra == 0) {
      break;
    }
  }
  return 0;
}
