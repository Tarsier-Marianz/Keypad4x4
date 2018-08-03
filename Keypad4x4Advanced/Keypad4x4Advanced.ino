#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6}; //Rows 0 to 3
byte colPins[COLS]= {5,4,3,2}; //Columns 0 to 3

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int bufferLength = 5;
int bufferIndex = 0;
char bufferData[5];

void setup(){
   Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  if (key != NO_KEY){
    //Serial.write(key);
    bufferData[bufferIndex] = key;
    bufferIndex++;
  }
  if(bufferIndex>=bufferLength){
    for(int i=0; i < bufferLength; i++) {
      Serial.print( bufferData[i] ); 
    }
    //reset all the functions to be able to fill the string back with content
    bufferIndex  = 0;
    Serial.println();
  }
}
