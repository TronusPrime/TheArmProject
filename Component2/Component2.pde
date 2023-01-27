/* 
  * Component 2- This is the program I wrote to receive raw EEG signals via Bluetooth
    and revert them back to usable values. These values are then transmitted to 
  * Arduino across Serial. 
*/
import netP5.*;
import processing.serial.*;
import oscP5.*;
OscP5 oscp5;
Serial porter;
float currentAttention;
void setup(){
  oscp5 = new OscP5(this, 7771);
  size(320, 240);
  background(0,255,255);
 
  println(Serial.list()[0]);
  //String portName = Serial.list()[0];
 porter = new Serial(this, "COM5",9600);
}
void draw(){ 
  //int servoVal = 4;
//println("Your attention is at: " + currentAttention);
//String s = "Your Attention is at: " + currentAttention;
}
  void oscEvent(OscMessage theMessage){
if (theMessage.checkAddrPattern("/attention") == true) {

currentAttention = theMessage.get(0).floatValue();

println("Your attention is at: " + currentAttention);
  porter.write((int)currentAttention);
}
// Print the address and typetag of the message to the console
//println("OSC Message received! The address pattern is " + theMessage.addrPattern() + ". The typetag is: " + theMessage.typetag());

}
