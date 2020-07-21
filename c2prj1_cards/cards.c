#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";
  }
    
}

char value_letter(card_t c) {
  if(c.value >= 2 && c.value <= 9)
    return (char)('0' + c.value);
  else if (c.value == 10)
    return '0';
  else if (c.value == VALUE_JACK)
    return 'J';
  else if (c.value == VALUE_QUEEN)
    return 'Q';
  else if  (c.value == VALUE_KING)
    return 'K';
  else if (c.value == VALUE_ACE)
    return 'A';
  else
    return '?';
}


char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return '?';
  }
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  char x = value_let;
  if(x >= '2' && x <= '9')
    {
      x = '1';
    }
  switch (x){
  case '1':
    temp.value = value_let - '0';
    break;
  case '0':
    temp.value = 10;
    break;
  case 'J':
    temp.value = VALUE_JACK;
    break;
  case 'Q':
    temp.value = VALUE_QUEEN;
    break;
  case 'K':
    temp.value = VALUE_KING;
    break;
  case 'A':
    temp.value = VALUE_ACE;
    break;
  default:
    printf("Invalid value_let\n");
    break;
  }
  switch(suit_let){
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    printf("Invalid suit_let\n");
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = c%13 +2;
  temp.suit =  c/13;
  return temp;
}
