/**
 * barebones OSC listener adapted from:
 * oscP5sendreceive by andreas schlegel
 * example shows how to receive osc messages from the R-IoT.
 * oscP5 website at http://www.sojamo.de/oscP5
 */
 
import oscP5.*;
OscP5 oscP5;

float[] riot_data = new float[22];

void setup() {
  size(200,200);
  /* start oscP5, listening for incoming messages at port 12000 */
  oscP5 = new OscP5(this,8888);
  
}


void draw() {
  background(144);
  fill(255);
  for (int i = 0; i < 22; i++){
    text(riot_data[i],10,10*i);
    if (i < 9)
      rect(100 + (10*i), height, 10, -riot_data[i]*10);
  }
}

/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  String addr = theOscMessage.addrPattern();
  String[] riot_check = match(addr, "/*/raw");
  print("### received an osc message.");
  print(" addrpattern: "+addr);
  println(" typetag: "+theOscMessage.typetag()); 
  if (riot_check != null){
    for (int i = 0; i < 22; i++){
      riot_data[i] = theOscMessage.get(i).floatValue();
    }
  }  
  else{
    println("R-IoT data is sent under the address format '/<id>/raw'");
  }
}
