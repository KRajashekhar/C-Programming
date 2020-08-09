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

void add_card_to(deck_t *deck, card_t c) {

  assert(deck!=NULL);
  card_t * card = malloc(sizeof(*card));
  card->value = c.value;
  card->suit = c.suit;
  deck->n_cards++;
  deck->cards = realloc(deck->cards,deck->n_cards* sizeof(*deck->cards));
  deck->cards[deck->n_cards -1] = card;
}

card_t * add_empty_card(deck_t * deck) {
  assert(deck != NULL);
  card_t * emt_card = malloc(sizeof(*emt_card));
  emt_card->value = 0;
  emt_card->suit = 0;
  add_card_to(deck, *emt_card);
  free(emt_card);
  return deck->cards[deck->n_cards-1];
}

deck_t * make_deck_exclude(deck_t *excluded_cards) {

  deck_t * ans = malloc(sizeof(*ans));
  ans->cards = NULL;
  ans->n_cards = 0;
  for(int i=0; i< 52; i++) {

    card_t c = card_from_num(i);
    if(!deck_contains(excluded_cards, c)) {
      add_card_to(ans,c);
    }
  }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {

  deck_t * hands_cards = malloc(sizeof(*hands_cards));
  hands_cards->cards = NULL;
  hands_cards->n_cards = 0;
  for(int i=0; i<n_hands; i++) {
    for(int j=0; j<hands[i]->n_cards; j++) {
      if(!((hands[i]->cards[j]->value == 0) && (hands[i]->cards[j]->suit == 0))) {
      add_card_to(hands_cards, *(hands[i]->cards[j]));
    }
    }
  }
  deck_t * ans = make_deck_exclude(hands_cards);
  return ans;
}

void free_deck(deck_t *deck) {
  for(int i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
      
