
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command;             //String to store app command state.

const char* ssid = "Arduina";
ESP8266WebServer server(80);

void setup() {
 
 pinMode(14, OUTPUT);// Enable/speed motors Right        GPIO14(D5) speed 1024
 pinMode(12, OUTPUT);  // Enable/speed motors Left         GPIO12(D6)
 pinMode(15, OUTPUT);// L298N in1 motors Right           GPIO15(D8)
 pinMode(13, OUTPUT);// L298N in2 motors Right           GPIO13(D7)
 pinMode(2, OUTPUT);// L298N in3 motors Left            GPIO2(D4)
 pinMode(0, OUTPUT);  // L298N in4 motors Left            GPIO0(D3)
  
  Serial.begin(115200);
  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}


void loop() {
    server.handleClient();
    
      command = server.arg("State");
      if (command == "F") {
       digitalWrite(13, LOW);
      digitalWrite(15, HIGH);
      analogWrite(14, 520);

      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      analogWrite(12, 520);      
      }
      else if (command == "I") { 
      digitalWrite(13, LOW);
      digitalWrite(15, HIGH);
      analogWrite(14, 610);

      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      analogWrite(12, 610);      
      
       }
       else if (command == "B") { 
      digitalWrite(15, LOW);
      digitalWrite(13, HIGH);
      analogWrite(14, 520);

      digitalWrite(2, LOW);
      digitalWrite(0, HIGH);
      analogWrite(12, 520);      
      
       }
       else if (command == "J") { 
      digitalWrite(15, LOW);
      digitalWrite(13, HIGH);
      analogWrite(14, 610);

      digitalWrite(2, LOW);
      digitalWrite(0, HIGH);
      analogWrite(12, 610);      
      
       }

      else if (command == "L") { 
      digitalWrite(13, LOW);
      digitalWrite(15, HIGH);
      analogWrite(14, 520);

      digitalWrite(2, LOW);
      digitalWrite(0, HIGH);
      analogWrite(12, 520);      
      
       }
      else if (command == "G") { 
      digitalWrite(13, LOW);
      digitalWrite(15, HIGH);
      analogWrite(14, 610);

      digitalWrite(2, LOW);
      digitalWrite(0, HIGH);
      analogWrite(12, 610);      
      
       }

      else if (command == "R") { 
      digitalWrite(15, LOW);
      digitalWrite(13, HIGH);
      analogWrite(14, 520);

      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      analogWrite(12, 520);      
      
       }
       else if (command == "H") { 
      digitalWrite(15, LOW);
      digitalWrite(13, HIGH);
      analogWrite(14, 610);

      digitalWrite(0, LOW);
      digitalWrite(2, HIGH);
      analogWrite(12,610);      
      
       }
      else if (command == "S") {

      analogWrite(14,0);
      analogWrite(12,0);
  }
     
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}
