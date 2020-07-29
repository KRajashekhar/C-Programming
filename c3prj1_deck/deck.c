#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(int i=0; i<hand->n_cards ; i++)
    {
      
      print_card(*(hand->cards[i]));
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {

  for(int i=0; i<d->n_cards; i++)
    {
      if( d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
	{
	  return 1;
	}
    }
  return 0;
}

void shuffle(deck_t * d){

  for(int i=0; i<d->n_cards; i++)  {
    
      int r = rand()% d->n_cards;
      card_t *temp = d->cards[i];
      d->cards[i] = d->cards[r];
      d->cards[r] = temp;
}
}

void assert_full_deck(deck_t * d) {

  for(int i=2; i<=VALUE_ACE; i++) {

    for(int j=SPADES; j<=CLUBS; j++) {

      card_t temp;
      temp.value = i;
      temp.suit = j;
      assert(deck_contains(d, temp));
    }
  }
    
}
