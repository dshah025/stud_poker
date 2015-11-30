#include <stdio.h>
#include <stdlib.h> // provides atoi
#include <ctype.h> // provides isdigit
#include <time.h>   // allows the use of time_t

#define TRUE 1
#define FALSE 0
#define N_ARGS 3
#define DECK 52
#define N_CARDS 5
#define MAX_HANDS DECK / N_CARDS
#define MIN_HANDS 0
#define MAX_FACES 13
#define N_CARDS_LINE 10
#define N_RANKS 9
#define N_SUITS 4
#define ACE 14
enum ranks { SF = 1, FK, FH, F, S, TK, TP, OP, HC };

#define TOP_LEFT_CORNER   "\xE2\x94\x8C"
#define TOP_RIGHT_CORNER  "\xE2\x94\x90"
#define BOT_LEFT_CORNER   "\xE2\x94\x94"
#define BOT_RIGHT_CORNER  "\xE2\x94\x98"
#define H_LINE            "\xE2\x94\x80"
#define V_LINE            "\xE2\x94\x82"

typedef enum { HEART, CLUB, DIAMOND, SPADE } Suit;

typedef struct card {
  Suit suit;
  int face;
  int index;
} Card;

int checkInput(int argc, char *argv[]);
void constructDeck(Card *deck);
void shuffleDeck(Card *deck);
void swapElements(Card *hands, int pos1, int pos2);
void displayCards(Card *cards, int nCards);
void dealCards(Card hands[][N_CARDS], Card *deck, int nHands);
void displayHands(Card hands[][N_CARDS], int ranks[][2], int nHands,
                  int printRank);
void quickSort(Card *hand, int start, int end);
void sortHands(Card hands[][N_CARDS], int ranks[][2], int nHands);
void getRank(Card *hand, int ranks[][2], int handIndex);
int *isFlush(Card *hand);
int *isStraight(Card *hand);
int *getMatch(Card *hand);
void chooseWinner(int ranks[][2], int nHands);
