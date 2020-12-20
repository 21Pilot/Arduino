//DAP Shawn, Jared, Min Joon, Flora Connect 4 Game

#include <FastLED.h>

#define LED_PIN   6
#define NUM_LEDS  50


int rowWin[] = {3, 4, 8, 9 , 13, 14, 18, 19, 23, 24};
int columnWin[] = {15, 20, 16, 21, 17, 22, 18, 23, 19 , 24};
int diagonalLR[] = {23, 18, 24, 19};
int diagonalRL[] = {15, 16, 20, 21};

int playerSwitch = 5; //button for switching players when someone misses
int button0 = 22; //Buttons to light leds... need to define pins.
int button1 = 23;
int button2 = 24;
int button3 = 25;
int button4 = 26;
int button5 = 28;
int button6 = 29;
int button7 = 30;
int button8 = 31;
int button9 = 32;
int button10 = 33;
int button11 = 34;
int button12 = 35;
int button13 = 36;
int button14 = 37;
int button15 = 38;
int button16 = 39;
int button17 = 40;
int button18 = 41;
int button19 = 42;
int button20 = 43;
int button21 = 44;
int button22 = 45;
int button23 = 46;
int button24 = 47;

int playerTurn = 1;

int statePlayerSwitch;

int stateButton0;
int stateButton1;
int stateButton2;
int stateButton3;
int stateButton4;
int stateButton5;
int stateButton6;
int stateButton7;
int stateButton8;
int stateButton9;
int stateButton10;
int stateButton11;
int stateButton12;
int stateButton13;
int stateButton14;
int stateButton15;
int stateButton16;
int stateButton17;
int stateButton18;
int stateButton19;
int stateButton20;
int stateButton21;
int stateButton22;
int stateButton23;
int stateButton24;


int previous0 = LOW;
int previous1 = LOW;
int previous2 = LOW;
int previous3 = LOW;
int previous4 = LOW;
int previous5 = LOW;
int previous6 = LOW;
int previous7 = LOW;
int previous8 = LOW;
int previous9 = LOW;
int previous10 = LOW;
int previous11 = LOW;
int previous12 = LOW;
int previous13 = LOW;
int previous14 = LOW;
int previous15 = LOW;
int previous16 = LOW;
int previous17 = LOW;
int previous18 = LOW;
int previous19 = LOW;
int previous20 = LOW;
int previous21 = LOW;
int previous22 = LOW;
int previous23 = LOW;
int previous24 = LOW;
int previous25 = LOW;


long time = 0;
long debounce = 500;

CRGB leds[NUM_LEDS];

void setup() {
  pinMode(button0, INPUT);
  pinMode(playerSwitch, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(1000);
}

int arr[5][5];

void loop() {
  //leds[24] = CRGB(255, 0, 0);
  //FastLED.show();

  statePlayerSwitch = digitalRead(playerSwitch);
  stateButton0 = digitalRead(button0); // defines variable as readout of button
  stateButton1 = digitalRead(button1);
  stateButton2 = digitalRead(button2);
  stateButton3 = digitalRead(button3);
  stateButton4 = digitalRead(button4);
  stateButton5 = digitalRead(button5);
  stateButton6 = digitalRead(button6);
  stateButton7 = digitalRead(button7);
  stateButton8 = digitalRead(button8);
  stateButton9 = digitalRead(button9);
  stateButton10 = digitalRead(button10);
  stateButton11 = digitalRead(button11);
  stateButton12 = digitalRead(button12);
  stateButton13 = digitalRead(button13);
  stateButton14 = digitalRead(button14);
  stateButton15 = digitalRead(button15);
  stateButton16 = digitalRead(button16);
  stateButton17 = digitalRead(button17);
  stateButton18 = digitalRead(button18);
  stateButton19 = digitalRead(button19);
  stateButton20 = digitalRead(button20);
  stateButton21 = digitalRead(button21);
  stateButton22 = digitalRead(button22);
  stateButton23 = digitalRead(button23);
  stateButton24 = digitalRead(button24);

  //Code for manually switching players turn

  if (statePlayerSwitch == HIGH && previous25 == LOW && millis() - time > debounce) {
    playerTurn = playerTurn * -1;
  }


  //Code for lighting up players plate and auto player switch... must copy and paste for all 25 buttons

  if (stateButton0 == HIGH && previous0 == LOW && millis() - time > debounce) {
    Serial.print(0);
    if (playerTurn == 1) {
      leds[0] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[1] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[0] = CRGB(0, 0, 255);
      FastLED.show();
      // leds[1] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton1 == HIGH && previous1 == LOW && millis() - time > debounce) {
    Serial.print(1);
    if (playerTurn == 1) {
      leds[1] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[3] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[1] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[3] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton2 == HIGH && previous2 == LOW && millis() - time > debounce) {
    Serial.print(2);
    if (playerTurn == 1) {
      leds[2] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[5] = CRGB(255, 0, 0);
      FastLED.show();
    } else if (playerTurn == -1) {
      leds[2] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[5] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  } 

  if (stateButton3 == HIGH && previous3 == LOW && millis() - time > debounce) {
    Serial.print(3);
    if (playerTurn == 1) {
      leds[3] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[7] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[3] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[7] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton4 == HIGH && previous4 == LOW && millis() - time > debounce) {
    Serial.print(4);
    if (playerTurn == 1) {
      leds[4] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[9] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[4] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[9] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton5 == HIGH && previous5 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[5] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[11] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[5] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[11] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button 6 pressed");
    delay(500);
  }

  if (stateButton6 == HIGH && previous6 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[6] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[13] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[6] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[13] = CRGB(0, 0, 255);
      // FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button 7 pressed");
    delay(500);
  }

  if (stateButton7 == HIGH && previous7 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[7] = CRGB(255, 0, 0);
      FastLED.show();
      // leds[15] = CRGB(255, 0, 0);
      // FastLED.show();
    } else if (playerTurn == -1) {
      leds[7] = CRGB(0, 0, 255);
      FastLED.show();
      // leds[15] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton8 == HIGH && previous8 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[8] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[17] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[8] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[17] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton9 == HIGH && previous9 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[9] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[19] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[9] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[19] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton10 == HIGH && previous10 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[10] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[21] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[10] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[21] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton11 == HIGH && previous11 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[11] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[23] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[11] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[23] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton12 == HIGH && previous12 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[12] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[25] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[12] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[25] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton13 == HIGH && previous13 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[13] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[27] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[13] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[27] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton14 == HIGH && previous14 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[14] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[29] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[14] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[29] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton15 == HIGH && previous15 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[15] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[31] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[15] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[31] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton16 == HIGH && previous16 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[16] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[33] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[16] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[33] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton17 == HIGH && previous17 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[17] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[35] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[17] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[35] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton18 == HIGH && previous18 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[18] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[37] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[18] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[37] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton19 == HIGH && previous19 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[19] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[39] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[19] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[39] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton20 == HIGH && previous20 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[20] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[41] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[20] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[41] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton21 == HIGH && previous21 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[21] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[43] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[21] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[43] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton22 == HIGH && previous22 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[22] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[45] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[22] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[45] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton23 == HIGH && previous23 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[23] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[47] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[23] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[47] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }

  if (stateButton24 == HIGH && previous24 == LOW && millis() - time > debounce) {
    if (playerTurn == 1) {
      leds[24] = CRGB(255, 0, 0);
      FastLED.show();
      //leds[49] = CRGB(255, 0, 0);
      //FastLED.show();
    } else if (playerTurn == -1) {
      leds[24] = CRGB(0, 0, 255);
      FastLED.show();
      //leds[49] = CRGB(0, 0, 255);
      //FastLED.show();
    }
    playerTurn = playerTurn * -1;
    checkwin();
    Serial.println("button pressed");
    delay(500);
  }


  previous0 = stateButton0;
  previous1 = stateButton1;
  previous2 = stateButton2;
  previous3 = stateButton3;
  previous4 = stateButton4;
  previous5 = stateButton5;
  previous6 = stateButton6;
  previous7 = stateButton7;
  previous8 = stateButton8;
  previous9 = stateButton9;
  previous10 = stateButton10;
  previous11 = stateButton11;
  previous12 = stateButton12;
  previous13 = stateButton13;
  previous14 = stateButton14;
  previous15 = stateButton15;
  previous16 = stateButton16;
  previous17 = stateButton17;
  previous18 = stateButton18;
  previous19 = stateButton19;
  previous20 = stateButton20;
  previous21 = stateButton21;
  previous22 = stateButton22;
  previous23 = stateButton23;
  previous24 = stateButton24;

  previous25 = statePlayerSwitch;


}

void checkwin () {
  //Serial.print(1);
  //Check for Win by Row
  for (int i = 0; i <= 9; i++) {
    // Serial.print(i);
    int x = rowWin[i];
    if (leds[x] == CRGB (255, 0, 0) && leds[x - 1] == CRGB (255, 0, 0) && leds[x - 2] == CRGB (255, 0, 0) && leds[x - 3] == CRGB (255, 0, 0)) {
      leds[x] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 1] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 2] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 3] = CRGB (0, 255, 0);
      FastLED.show();
    }
    else if (leds[x] == CRGB (0, 0, 255) && leds[x - 1] == CRGB (0, 0, 255) && leds[x - 2] == CRGB (0, 0, 255) && leds[x - 3] == CRGB (0, 0, 255)) {
      leds[x] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 1] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 2] = CRGB (0, 255, 0);
      FastLED.show();
      leds[x - 3] = CRGB (0, 255, 0);
      FastLED.show();
    }
  }
  //check win by column
  for (int j = 0; j <= 9; j++) {
    // Serial.print(j);
    int y = columnWin[j];
    if (leds[y] == CRGB (255, 0, 0) && leds[y - 5] == CRGB (255, 0, 0) && leds[y - 10] == CRGB (255, 0, 0) && leds[y - 15] == CRGB (255, 0, 0)) {
      leds[y] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 5] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 10] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 15] = CRGB (0, 255, 0);
      FastLED.show();

    }
    else if (leds[y] == CRGB (0, 0, 255) && leds[y - 5] == CRGB (0, 0, 255) && leds[y - 10] == CRGB (0, 0, 255) && leds[y - 15] == CRGB (0, 0, 255)) {
      leds[y] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 5] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 10] = CRGB (0, 255, 0);
      FastLED.show();
      leds[y - 15] = CRGB (0, 255, 0);
      FastLED.show();
    }
  }
  //check diagonal Left to Right win
  for (int k = 0; k <= 3; k++) {
    // Serial.print(k);
    int n = diagonalLR[k];
    if (leds[n] == CRGB (255, 0, 0) && leds[n - 6] == CRGB (255, 0, 0) && leds[n - 12] == CRGB (255, 0, 0) && leds[n - 18] == CRGB (255, 0, 0)) {
      leds[n] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 6] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 12] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 18] = CRGB (0, 255, 0);
      FastLED.show();
    }
    else if (leds[n] == CRGB (0, 0, 255) && leds[n - 6] == CRGB (0, 0, 255) && leds[n - 12] == CRGB (0, 0, 255) && leds[n - 18] == CRGB (0, 0, 255)) {
      leds[n] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 6] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 12] = CRGB (0, 255, 0);
      FastLED.show();
      leds[n - 18] = CRGB (0, 255, 0);
      FastLED.show();
    }
  }
  //Check for diagonal Right to left win
  for (int t = 0; t <= 3; t++) {
    // Serial.print(t);
    int z = diagonalRL[t];
    if (leds[z] == CRGB (255, 0, 0) && leds[z - 4] == CRGB (255, 0, 0) && leds[z - 8] == CRGB (255, 0, 0) && leds[z - 12] == CRGB (255, 0, 0)) {
      leds[z] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 4] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 8] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 12] = CRGB (0, 255, 0);
      FastLED.show();
    }
    else if (leds[z] == CRGB (0, 0, 255) && leds[z - 4] == CRGB (0, 0, 255) && leds[z - 8] == CRGB (0, 0, 255) && leds[z - 12] == CRGB (0, 0, 255)) {
      leds[z] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 4] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 8] = CRGB (0, 255, 0);
      FastLED.show();
      leds[z - 12] = CRGB (0, 255, 0);
      FastLED.show();
    }
  }
}


/*
  00 01 02 03 04
  05 06 07 08 09
  10 11 12 13 14
  15 16 17 18 19
  20 21 22 23 24

  row win = [3, 4, 8, 9 , 13, 14, 18, 19, 23, 24]

          column win = [15, 20, 16, 21, 17, 22, 18, 23, 19 , 24]

                       diagonal Lr = [23, 18, 24, 19]

                                     diagonal Rl = [15, 16, 20, 21]

*/






