// intensity.c
// This program by Vishnu Pillai on 3/05/18

#include <stdio.h>
#include <assert.h>

#define ACTION_PLAYER_NAME    0
#define ACTION_DISCARD        1
#define ACTION_PLAY_CARD      2
#define ACTION_UNIT_TESTS     3

#define N_CARDS              40
#define N_CARDS_INITIAL_HAND 10
#define N_PLAYERS             4
#define N_CARDS_DISCARDED     3

#define CARD_MIN             10
#define CARD_MAX             49

#define FIRST_CARD            0
#define CARD_MAX_ROUND        3
#define TRUE                  1
#define FALSE                 0
#define DEFAULT_VALUE         0
#define N_CARDS_RECEIVED      3


void print_player_name(void);
void choose_discards(void);
void choose_card_to_play(void);
void run_unit_tests(void);

//prototype functions

void test_card_10_19(void);
void test_card_20_29(void);
void test_card_30_39(void);
void test_card_40_49(void);
void card_array_function(int cards, int count_round, int card_array[N_CARDS_INITIAL_HAND]);
int used_card_round_function(int card_array[N_CARDS_INITIAL_HAND], int count_round, 
                                int cards_in_round, int used_card_round[CARD_MAX_ROUND]);
int used_card_game_function(int cards, int cards_in_round, int count_round, 
                            int used_card_game[N_CARDS ]);
void discarded_card_function(int count_round, int discarded_card[N_CARDS_DISCARDED]);
void received_card_function(int count_round, int discarded_card_received[N_CARDS_RECEIVED]);
int card_10_19(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards);
int card_20_29(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards);
int card_30_39(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards);
int card_40_49(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND],
                int card_played, int cards);

// main function

int main(void) {

    int which_action = 0;
    scanf("%d", &which_action);
    if (which_action == ACTION_PLAYER_NAME) {
        print_player_name();
    } else if (which_action == ACTION_DISCARD) {
        choose_discards();
    } else if (which_action == ACTION_PLAY_CARD) {
        choose_card_to_play();
    } else {
        run_unit_tests();
    }

    return 0;
}

void print_player_name(void) {
    printf("Hello There!\n");
}

void choose_discards() {

    // ADD CODE TO READ THE CARDS OF YOUR HAND INTO AN ARRAY USING SCANF
    int card_array[N_CARDS_INITIAL_HAND];
    int count = DEFAULT_VALUE;
    while (count < N_CARDS_INITIAL_HAND) {
        scanf("%d", &card_array[count]);
        count++;
    }
    int count1 = DEFAULT_VALUE;
    int count2 = DEFAULT_VALUE;
    int count3 = DEFAULT_VALUE;
    int maximum1 = DEFAULT_VALUE;
    int maximum2 = DEFAULT_VALUE;
    int maximum3 = DEFAULT_VALUE;
    int value_given1 = FALSE; 
    int value_given2 = FALSE; 
    int value_given3 = FALSE; 
    
    //Code for cards to be discarded:
    
    //This loop finds the maximum value of the card between 10 and 19
    while (count1 < N_CARDS_INITIAL_HAND) { 
        while ((count1 < N_CARDS_INITIAL_HAND) && (card_array[count1] >= 10) 
                && (card_array[count1] <= 19)) {
            if ((maximum1 < card_array[count1]) && (count1 < N_CARDS_INITIAL_HAND)) {
                maximum1 = card_array[count1];
                value_given1 = TRUE;
                count1++;        
            } else if ((maximum1 > card_array[count1]) && (count1 < N_CARDS_INITIAL_HAND)) {
                count1++;
            }
        }
        count1++;
    }
    //This loop finds the maximum value of the card between 30 and 39
    while (count2 < N_CARDS_INITIAL_HAND) {
        while ((count2 < N_CARDS_INITIAL_HAND) && (card_array[count2] >= 30) 
                && (card_array[count2] <= 39)) {
            if ((maximum2 < card_array[count2]) && (count2 < N_CARDS_INITIAL_HAND)) {
                maximum2 = card_array[count2];
                value_given2 = TRUE;
                count2++;        
            } else if ((maximum2 > card_array[count2]) && (count2 < N_CARDS_INITIAL_HAND)) {
                count2++;
            }
        }
        count2++;
    }
    //This loop finds the maximum value of the card between 40 and 49
    while (count3 < N_CARDS_INITIAL_HAND) {
        while ((count3 < N_CARDS_INITIAL_HAND) && (card_array[count3] >= 40) 
                && (card_array[count3] <= 49)) {
            if ((maximum3 < card_array[count3]) && (count3 < N_CARDS_INITIAL_HAND)) {
                maximum3 = card_array[count3];
                value_given3 = TRUE;
                count3++;        
            } else if ((maximum3 > card_array[count3]) && (count3 < N_CARDS_INITIAL_HAND)) {
                count3++;
            }
        }
        count3++;
    }
    
    if (value_given1 == FALSE) { //If there are no cards between 10 and 19, first card is chosen
        maximum1 = card_array[FIRST_CARD];
    } else if (value_given2 == FALSE) { //If there are no cards between 30 and 39, first card is chosen
        maximum2 = card_array[FIRST_CARD];
    } else if (value_given3 == FALSE) { //If there are no cards between 40 and 49, first card is chosen
        maximum3 = card_array[FIRST_CARD];
    }             
    //Prints the 3 maximum cards found
    printf("%d %d %d\n", maximum1, maximum2, maximum3);
}

void choose_card_to_play(void) {
   
    int count_card = DEFAULT_VALUE; //Position of card in array
    int count_round = DEFAULT_VALUE; //Boolean
    int card_played = FALSE; //Whether a card has been played or not in round

    int cards; //Number of cards in hand
    scanf("%d", &cards);
    
    int cards_in_round; //Number of cards played this round
    scanf("%d", &cards_in_round);
    
    int table_position; //Table position that player starts 
    scanf("%d", &table_position);
            
    int card_array[N_CARDS_INITIAL_HAND]; //Cards in hand
    card_array_function(cards, count_round, card_array); //Scans in cards into array

    int used_card_round[CARD_MAX_ROUND]; //Cards played this round before player's turn
    //Scans in cards into array
    used_card_round_function(card_array, count_round, cards_in_round, used_card_round);

    int used_card_game[N_CARDS]; //Cards played in previous rounds
    //Scans in cards into array
    used_card_game_function(cards, cards_in_round, count_round, used_card_game);

    int discarded_card[N_CARDS_DISCARDED]; //Cards discarded at the start
    discarded_card_function(count_round, discarded_card); //Scans in cards into array
    
    int discarded_card_received[N_CARDS_RECEIVED]; //Cards received at the start
    //Scans in cards into array
    received_card_function(count_round, discarded_card_received);
       
    //CODE TO CHOOSE AND PRINT CARD TO PLAY IN ROUND
    int count = DEFAULT_VALUE; //Used to check arrays
    int end_loop = FALSE; //Boolean used to exit loop
    int calf = FALSE; //Boolean used to check whether a calf has been played or not
    
    //Determines whether a calf has been played or not
    if ((used_card_round_function(card_array, count_round, cards_in_round, used_card_round) == TRUE)
        || (used_card_game_function(cards, cards_in_round, count_round, used_card_game) == TRUE)) {
            calf = TRUE;
    } else if ((used_card_round_function(card_array, count_round, cards_in_round, used_card_round) == FALSE)
        && (used_card_game_function(cards, cards_in_round, count_round, used_card_game) == FALSE)) {
            calf = FALSE;
    }
    
    //If a calf has been played    
    if (calf == TRUE) {
        if ((used_card_round[count_round] >= 10) && (used_card_round[count_round] <= 19) 
            && (card_played == FALSE)) {
           card_10_19(count_card, count_round, card_array, card_played, cards);        
        } else if ((used_card_round[count_round] >= 20) && (used_card_round[count_round] <= 29) 
                    && (card_played == FALSE)) {
           card_20_29(count_card, count_round, card_array, card_played, cards);        
        } else if ((used_card_round[count_round] >= 30) && (used_card_round[count_round] <= 39) 
                    && (card_played == FALSE)) {       
            card_30_39(count_card, count_round, card_array, card_played, cards);
        } else if (used_card_round[count_round] >= 40 && used_card_round[count_round] <= 49 
                    && card_played == FALSE) {
           card_40_49(count_card, count_round, card_array, card_played, cards);        
        }
        card_played = TRUE; 
    }
    //If a calf has not been played
    if (calf == FALSE) {
        if (used_card_round[count_round] >= 10 && used_card_round[count_round] <= 19 
            && card_played == FALSE) {
           card_10_19(count_card, count_round, card_array, card_played, cards);        
        } else if (used_card_round[count_round] >= 20 && used_card_round[count_round] <= 29 
                    && card_played == FALSE) {
           card_20_29(count_card, count_round, card_array, card_played, cards);        
        } else if (used_card_round[count_round] >= 40 && used_card_round[count_round] <= 49 
                    && card_played == FALSE) {
           card_40_49(count_card, count_round, card_array, card_played, cards);        
        } else if (cards_in_round == 0) { //If position in round is 0, and no calfs have been played.
            while ((count < cards) && (end_loop == FALSE)) {
                if ((card_array[count]>= 10 && card_array[count]<= 19) || (card_array[count]>= 20 
                    && card_array[count]<= 29) ||
                    (card_array[count]>= 40 && card_array[count]<= 49)) { //
                    printf("%d\n", card_array[count]);
                    end_loop = TRUE;
                }
                count++;
            }
            count = DEFAULT_VALUE;
            while ((end_loop == FALSE) && (count < cards)) { //If position is 0, no calfs have been played, 
                    //and only calfs left in hand
                printf("%d\n", card_array[FIRST_CARD]);
                end_loop = TRUE;
            }
        }            
    }             
}
// ADD A COMMENT HERE EXPLAINING YOUR OVERALL TESTING STRATEGY
//Testing to see whether program will play a card if:
// 1.) When card is between 10 and 19:
//      - if count_card is = 0 and 1 (= TRUE)
//      - if card_played is TRUE (= TRUE)
//      - if card_played is FALSE (=TRUE)
//      - if cards = 1 (=TRUE)
// 2.) When card is between 20 and 29:
//      - if count_card is = 0 and 1 (= TRUE)
//      - if count_card is = 2 and 3 (= TRUE)
//      - if card_played is TRUE (= TRUE)
//      - if card_played is FALSE (= TRUE)
//      - if cards = 3 (= TRUE)
// 3.) When card is between 30 and 39:
//      - if count_card is = 0 and 1 (= TRUE)
//      - if count_card is = 5 and 6 (= TRUE)
//      - if card_played is TRUE (= TRUE)
//      - if card_played is FALSE (= TRUE)
//      - if cards = 6 (= TRUE)
// 4.) When card is between 40 and 49:
//      - if count_card is = 0 and 1 (= FALSE)
//      - if count_card is = 7 and 8 (= TRUE)
//      - if card_played is TRUE (= TRUE)
//      - if card_played is FALSE (= TRUE)
//      - if cards = 8 (= TRUE)
void test_card_10_19(void) {
    int count_card;
    int count_round;
    int card_array[N_CARDS_INITIAL_HAND] = {10,15,20,25,26,30,33,36,42,45};
    int card_played;
    int cards;
    
    assert(card_10_19(0, 0, card_array, 0, 10) == TRUE);
    assert(card_10_19(1, 0, card_array, 0, 10) == TRUE);
    assert(card_10_19(0, 0, card_array, 1, 10) == TRUE);
    assert(card_10_19(0, 0, card_array, 0, 10) == TRUE);
    assert(card_10_19(0, 0, card_array, 0, 1) == TRUE);
    
}

void test_card_20_29(void) {
    int count_card;
    int count_round;
    int card_array[N_CARDS_INITIAL_HAND] = {10,15,20,25,26,30,33,36,42,45};
    int card_played;
    int cards;
    
    assert(card_20_29(0, 0, card_array, 0, 10) == TRUE);
    assert(card_20_29(2, 0, card_array, 0, 10) == TRUE);
    assert(card_20_29(0, 0, card_array, 1, 10) == TRUE);
    assert(card_20_29(0, 0, card_array, 0, 10) == TRUE);
    assert(card_20_29(0, 0, card_array, 0, 3) == TRUE);
    
}

void test_card_30_39(void) {
    int count_card;
    int count_round;
    int card_array[N_CARDS_INITIAL_HAND] = {10,15,20,25,26,30,33,36,42,45};
    int card_played;
    int cards;
    
    assert(card_30_39(0, 0, card_array, 0, 10) == TRUE);
    assert(card_30_39(5, 0, card_array, 0, 10) == TRUE);
    assert(card_30_39(0, 0, card_array, 1, 10) == TRUE);
    assert(card_30_39(0, 0, card_array, 0, 10) == TRUE);
    assert(card_30_39(0, 0, card_array, 0, 6) == TRUE);
    
}

void test_card_40_49(void) {
    int count_card;
    int count_round;
    int card_array[N_CARDS_INITIAL_HAND] = {10,15,20,25,26,30,33,36,42,45};
    int card_played;
    int cards;
    
    assert(card_40_49(0, 0, card_array, 0, 10) == TRUE);
    assert(card_40_49(7, 0, card_array, 0, 10) == TRUE);
    assert(card_40_49(0, 0, card_array, 1, 10) == TRUE);
    assert(card_40_49(0, 0, card_array, 0, 10) == TRUE);
    assert(card_40_49(0, 0, card_array, 0, 8) == FALSE);
    
}

void run_unit_tests(void) { 
   test_card_10_19();  
   test_card_20_29(); 
   test_card_30_39();   
   test_card_40_49();      
}





//Scanning cards into array
void card_array_function(int cards, int count_round, int card_array[N_CARDS_INITIAL_HAND]) {
    int count = DEFAULT_VALUE;
    
    if (cards == N_CARDS_INITIAL_HAND) {
        while (count < N_CARDS_INITIAL_HAND) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 1)) {
        while (count < (N_CARDS_INITIAL_HAND - 1)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 2)) {
        while (count < (N_CARDS_INITIAL_HAND - 2)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 3)) {
        while (count < (N_CARDS_INITIAL_HAND - 3)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 4)) {
        while (count < (N_CARDS_INITIAL_HAND - 4)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 5)) {
        while (count < (N_CARDS_INITIAL_HAND - 5)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 6)) {
        while (count < (N_CARDS_INITIAL_HAND - 6)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 7)) {
        while (count < (N_CARDS_INITIAL_HAND - 7)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 8)) {
        while (count < (N_CARDS_INITIAL_HAND - 8)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    } else if (cards == (N_CARDS_INITIAL_HAND - 9)) {
        while (count < (N_CARDS_INITIAL_HAND - 9)) {
            scanf("%d", &card_array[count]);
            count++;        
        }
    }   
}

//Cards played in current round
int used_card_round_function(int card_array[N_CARDS_INITIAL_HAND], int count_round, 
                            int cards_in_round, int used_card_round[CARD_MAX_ROUND]) {
    int calf = FALSE;
    int count = DEFAULT_VALUE;
    
    if (cards_in_round == 0) {
        used_card_round[0] = card_array[FIRST_CARD];
    }        
    if ((count_round == 0) && (cards_in_round != 0)) {
        while (count < cards_in_round) {
            scanf("%d", &used_card_round[count]);
            if (used_card_round[count]>= 30 && used_card_round[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    return calf;
}

//Cards played in previous rounds
int used_card_game_function(int cards, int cards_in_round, int count_round, 
                            int used_card_game[N_CARDS]) {   
    int count = DEFAULT_VALUE;
    int round = 11 - cards; 
    int position = cards_in_round;
    int cards_played = ((round - 1) * (N_PLAYERS)) - 1;
    int calf = FALSE;
    
    if (round == 2) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 3) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 4) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 5) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 6) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 7) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 8) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 9) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }
    if (round == 10) {
        while (count <= cards_played) {        
            scanf("%d", &used_card_game[count]);
            if (used_card_game[count]>= 30 && used_card_game[count]<= 39) {   
                calf = TRUE;
            }
            count++;
        }
    }   
    return calf;
}

//Cards discarded at the beginning
void discarded_card_function(int count_round, int discarded_card[N_CARDS_DISCARDED]) {
    
    if (count_round == 0) {
        scanf("%d", &discarded_card[0]);
        scanf("%d", &discarded_card[1]);
        scanf("%d", &discarded_card[2]);
    }
}

//Cards received at the beginning
void received_card_function(int count_round, int discarded_card_received[N_CARDS_RECEIVED]) {
    
    if (count_round == 0) {
        scanf("%d", &discarded_card_received[0]);
        scanf("%d", &discarded_card_received[1]);
        scanf("%d", &discarded_card_received[2]);   
    }
}

//Choosing card between 10 and 19
int card_10_19(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards) {    
    int count = DEFAULT_VALUE;
        
    while (count_card <= (cards - 1) && card_played == FALSE) { //Lowest card between 10 and 19 played
            if (card_array[count_card] >= 10 && card_array[count_card] <= 19) {
                card_played = TRUE;
                count = DEFAULT_VALUE;
                printf("%d\n", card_array[count_card]);
                
             }
             count_card++;
    }
    if (card_played == FALSE) { //If no card is played, the first card in array is played
        printf("%d\n", card_array[FIRST_CARD]);
    } 
    return card_played;
}

//Choosing card between 20 and 29
int card_20_29(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND],
                 int card_played, int cards) {
     int count = DEFAULT_VALUE; 
   
    while (count_card <= (cards - 1) && card_played == FALSE) { //Lowest card between 20 and 29 played
            if (card_array[count_card] >= 20 && card_array[count_card] <= 29) {
                card_played = TRUE;
                printf("%d\n", card_array[count_card]);
             }
             count_card++;
    }
    if (card_played == FALSE) { //If no card is played, the first card in array is played
        printf("%d\n", card_array[FIRST_CARD]);
    } 
    return card_played;
}

//Choosing card between 30 and 39
int card_30_39(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards) {
    int count = DEFAULT_VALUE;
    
    while (count_card <= (cards - 1) && card_played == FALSE) { //Lowest card between 30 and 39 played
            if (card_array[count_card] >= 30 && card_array[count_card] <= 39) {
                card_played = TRUE;
                count = DEFAULT_VALUE;
                printf("%d\n", card_array[count_card]);
             }
             count_card++;
    }
    if (card_played == FALSE) { //If no card is played, the first card in array is played
        printf("%d\n", card_array[FIRST_CARD]);
    } 
    return card_played;
}

//Choosing card between 40 and 49
int card_40_49(int count_card, int count_round, int card_array[N_CARDS_INITIAL_HAND], 
                int card_played, int cards) { 
    int count = DEFAULT_VALUE;
    
    while (count_card <= (cards - 1) && card_played == FALSE) { //Lowest card between 40 and 49 played
            if (card_array[count_card] >= 40 && card_array[count_card] <= 49) {
                card_played = TRUE;
                count = DEFAULT_VALUE;
                printf("%d\n", card_array[count_card]);
             }
             count_card++;
    }
    if (card_played == FALSE) { //If no card is played, the first card in array is played
        printf("%d\n", card_array[FIRST_CARD]);
    }    
    return card_played;
}
       
