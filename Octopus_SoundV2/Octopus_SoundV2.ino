/*
SparkFun Inventor's Kit
 Example sketch 04
 
 This sketch was written by SparkFun Electronics,
 with lots of help from the Arduino community.
 This code is completely free for any use.
 Visit http://learn.sparkfun.com/products/2 for SIK information.
 Visit http://www.arduino.cc to learn about the Arduino.
 
 Version 2.0 6/2012 MDG
 */
 
// A fun sketch to demonstrate the use of the Tone library.
// By Brett Hagman
// bhagman@roguerobotics.com
// www.roguerobotics.com

// You can get more RTTTL (RingTone Text Transfer Language) songs from
// http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation

#define OCTAVE_OFFSET 0
#define TONE_PIN 18

#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951

int notes[] = { 
  0,
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
  NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
  NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
  NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

int ledPins[] = {5,6,9,10,11};

const int buttonPin = 17;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p"; //short version

void setup(void)
{
  int index;

  for(index = 0; index <= 5; index++)
  {
    pinMode(ledPins[index],OUTPUT); // ledPins[index] is replaced by the value in the array.
  }
  
  pinMode(buttonPin, INPUT);
  pinMode(A4, OUTPUT); 
 
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}


void loop()
{ 
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      
      Serial.println("off"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;

  
  // turns on the LED every four button pushes by 
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of 
  // the division of two numbers:
  if (buttonPushCounter % 2 == 0) {
    pingPong();
    play_rtttl(song);
  } else {
    int index;
    int delayTime = 400; // milliseconds to pause between LEDs
  // make this smaller for faster switching

  // step through the LEDs, from 0 to 7

  for(index = 0; index <= 4; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
  }
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

}


/*
oneOnAtATime()
 
 This function will step through the LEDs,
 lighting only one at at time.
 */

void oneOnAtATime()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
  // make this smaller for faster switching

  // step through the LEDs, from 0 to 7

  for(index = 0; index <= 4; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}

/*
pingPong()
 
 This function will step through the LEDs,
 lighting one at at time in both directions.
 */

void pingPong()
{
  int index;
  int delayTime = 150; // milliseconds to pause between LEDs
  // make this smaller for faster switching

  // step through the LEDs, from 0 to 7

  for(index = 0; index <= 4; index++)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }

  // step through the LEDs, from 7 to 0

  for(index = 4; index >= 0; index--)
  {
    digitalWrite(ledPins[index], HIGH);  // turn LED on
    delay(delayTime);                    // pause to slow down
    digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}


/*
marquee()
 
 This function will mimic "chase lights" like those around signs.
 */

void marquee()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
  // Make this smaller for faster switching

  // Step through the first four LEDs
  // (We'll light up one in the lower 4 and one in the upper 4)

  for(index = 0; index <= 4; index++) // Step from 0 to 3
  {
    digitalWrite(ledPins[index], HIGH);    // Turn a LED on
    digitalWrite(ledPins[index+2], HIGH);  // Skip four, and turn that LED on
    delay(delayTime);                      // Pause to slow down the sequence
    digitalWrite(ledPins[index], LOW);     // Turn the LED off
    digitalWrite(ledPins[index+2], LOW);   // Skip four, and turn that LED off
  }
}

#define isdigit(n) (n >= '0' && n <= '9')

void play_rtttl(char *p)
{
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; 
    p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  //Serial.print("ddur: "); 
  //Serial.println(default_dur, 10);

  // get default octave
  if(*p == 'o')
  {
    p++; 
    p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }

 // Serial.print("doct: "); 
 // Serial.println(default_oct, 10);

  // get BPM
  if(*p == 'b')
  {
    p++; 
    p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }

 // Serial.print("bpm: "); 
//  Serial.println(bpm, 10);

  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

 // Serial.print("wn: "); 
  //Serial.println(wholenote, 10);


  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }

    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

      // now get the note
    note = 0;

    switch(*p)
    {
    case 'c':
      note = 1;
      break;
    case 'd':
      note = 3;
      break;
    case 'e':
      note = 5;
      break;
    case 'f':
      note = 6;
      break;
    case 'g':
      note = 8;
      break;
    case 'a':
      note = 10;
      break;
    case 'b':
      note = 12;
      break;
    case 'p':
    default:
      note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }

    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note

    if(note)
    {
     // Serial.print("Playing: ");
     // Serial.print(scale, 10); 
     // Serial.print(' ');
     // Serial.print(note, 10); 
     // Serial.print(" (");
     // Serial.print(notes[(scale - 4) * 12 + note], 10);
     // Serial.print(") ");
     // Serial.println(duration, 10);
      tone(TONE_PIN, notes[(scale - 4) * 12 + note]);
      delay(duration);
      noTone(TONE_PIN);
    }
    else
    {
     // Serial.print("Pausing: ");
     // Serial.println(duration, 10);
      delay(duration);
    }
  }
}


