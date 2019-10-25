#include <Bounce.h>

// https://cnx.org/contents/csA1TDZU@3/MIDI-Messages

// assigning buttons as ints for easy pin recognition
const int buttonOne = 1;
const int buttonTwo = 2;
const int buttonThree = 3;
const int buttonFour = 4;
const int buttonFive = 5;
const int buttonSix = 6;
const int buttonSeven = 7;
const int buttonEight = 8;
const int buttonNine = 9;
const int buttonTen = 10;
const int buttonEleven = 11;
const int buttonTwelve = 12;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce bankUp = Bounce(buttonOne, 10);  // 10 ms debounce
Bounce bankDown = Bounce(buttonTwo, 10); 
Bounce presetOne = Bounce(buttonThree, 10);  
Bounce presetTwo = Bounce(buttonFour, 10); 
Bounce presetThree = Bounce(buttonFive, 10);  
Bounce presetFour = Bounce(buttonSix, 10); 
Bounce presetFive = Bounce(buttonSeven, 10);  
Bounce presetSix = Bounce(buttonEight, 10); 
Bounce presetSeven = Bounce(buttonNine, 10);  
Bounce presetEight = Bounce(buttonTen, 10);  
Bounce tapTempoButton = Bounce(buttonEleven, 10); 
Bounce whoKnowsButton = Bounce(buttonTwelve, 10);

// create some MIDI integers to get us going

int previousMIDI = 0;
int newMIDI = 0;
int bankCount = 0;
int tapCount = 0;

void setup() {
  
  Serial.begin(31250);
  
  pinMode(buttonOne, INPUT_PULLUP); // Button 1
  pinMode(buttonTwo, INPUT_PULLUP); // Button 2
  pinMode(buttonThree, INPUT_PULLUP); // Button 3
  pinMode(buttonFour, INPUT_PULLUP); // Button 4
  pinMode(buttonFive, INPUT_PULLUP); // Button 5
  pinMode(buttonSix, INPUT_PULLUP); // Button 6
  pinMode(buttonSeven, INPUT_PULLUP); // Button 7
  pinMode(buttonEight, INPUT_PULLUP); // Button 8
  pinMode(buttonNine, INPUT_PULLUP); // Button 9
  pinMode(buttonTen, INPUT_PULLUP); // Button 10
  pinMode(buttonEleven, INPUT_PULLUP); // Button 11
  pinMode(buttonTwelve, INPUT_PULLUP); // Button 12
  
}

void loop() {

  bankSelect();
  presetSelect();
  tapTempo();
  whoKnows();
  delay(100);
}

void bankSelect() {
  
  // MIDI Bank Up (Button 1)
  if (bankUp.update()){  
    if (bankUp.fallingEdge()) {
      bankCount ++;
      if (bankCount > 19) {bankCount = 0;}
      Serial.print("Bank Up! ");
      Serial.println(bankCount);
    }
  }
  
  // MIDI Bank Down (Button 2)
  if (bankDown.update()){  
    if (bankDown.fallingEdge()) {
      bankCount --;
      if (bankCount < 0) {bankCount = 19;}
      Serial.print("Bank Down! ");
      Serial.println(bankCount);
    }
  }
  
}

// the presetSelect object is meant to take the bankCount
// and put together a MIDI message for a bank change and program change.
// A bank change consists of two CC messages.
// CC 0 is the MSB Bank message, the first half of it.
// CC 32 is the LSB Bank message, the second half of it.
// That means you can have 128x128 = 16,384 banks!
// I am sticking with 20 banks for now, as limited by the bankSelect object.

// Basically, I am sending 3 MIDI messages one after another
// each time a preset button is pressed.
// The two bank messages via the control change function
// and then a program change via the program change fucntion.

void presetSelect() {

  // Preset 1 (Button 3)
  if (presetOne.update()){  
    if (presetOne.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1); // (CC 0 [Bank change MSB], MSB Bank 0-128, MIDI channel)
      usbMIDI.sendControlChange(32, 0, 1); // (CC 32 [Bank change LSB], LSB Bank 0, MIDI channel)
      usbMIDI.sendProgramChange(1, 1); // (program number, MIDI channel)
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 1!");
    }
  }

  // Preset 2 (Button 4)
  if (presetTwo.update()){  
    if (presetTwo.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(2, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 2!");
    }
  }

   // Preset 3 (Button 5)
   if (presetThree.update()){  
    if (presetThree.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(3, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 3!");
    }
  }

  // Preset 4 (Button 6)
  if (presetFour.update()){  
    if (presetFour.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(4, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 4!");
    }
  }
  
  // Preset 5 (Button 7)
  if (presetFive.update()){  
    if (presetFive.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(5, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 5!");
    }
  }

  // Preset 6 (Button 8)
  if (presetSix.update()){  
    if (presetSix.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(6, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 6!");
    }
  }
  
  // Preset 7 (Button 9)
  if (presetSeven.update()){  
    if (presetSeven.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(7, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 7!");
     }
  }

  // Preset 8 (Button 10)
  if (presetEight.update()){  
    if (presetEight.fallingEdge()) {
      usbMIDI.sendControlChange(0, bankCount, 1);
      usbMIDI.sendControlChange(32, 0, 1);
      usbMIDI.sendProgramChange(8, 1);
      Serial.print("Bank ");
      Serial.print(bankCount);
      Serial.println("! Preset 8!");
    }
  } 
}

void tapTempo(){
  
  // Tap Tempo (Button 11)
  if (tapTempoButton.update()){  
    if (tapTempoButton.fallingEdge()) {
      Serial.println("Tap!");
    }
  }
}

void whoKnows() {
  
  // whoKnows (Button 12)
  if (whoKnowsButton.update()){  
    if (whoKnowsButton.fallingEdge()) {
      Serial.println("Who knows?!");
    }
  }
}

//void midiSendTest() {
//  usbMIDI.sendControlChange(0, bankCount, 1);
//  usbMIDI.sendControlChange(32, 0, 1);
//  usbMIDI.sendProgramChange(1, 1);
//}
