#include <Keypad.h>
#define makeKeyMap(x) ((char*)x)
const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[ROWS] = {5,4,3,2};

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad keypad = Keypad(makeKeyMap(keys), rowPins, colPins, ROWS, COLS);
const String password = "123456";
String userInput ;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  userInput.reserve(48);
  pinMode(13 , OUTPUT);
}

void loop() {
 digitalWrite(13 , LOW);
  // put your main code here, to run repeatedly:
  char keyInput = keypad.getKey();


if (keyInput){
  Serial.println(keyInput);

  if(keyInput == '*'){
    userInput = "";
    }
if(keyInput== '#'){
  
  if(password == userInput){
    Serial.println("Nice Hacks");
    userInput = "" ; 
   }
    else{
      Serial.println("Use hacks");
      userInput = "" ; 
      digitalWrite(13 , HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
       digitalWrite(13 , HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);

       digitalWrite(13 , HIGH);
      delay(500);
      digitalWrite(13,LOW);
      delay(500);
      
    }
    
  
  }
        else{
        userInput += keyInput;
      }
  }
  

  
}
