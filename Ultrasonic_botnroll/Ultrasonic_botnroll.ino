/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define TrigEsq  A0
#define EchoEsq  A1
#define TrigMeio A2
#define EchoMeio A3
#define TrigDir A4
#define EchoDir A5
Ultrasonic ultrasonicEsq(TrigEsq, EchoEsq);
Ultrasonic ultrasonicMeio(TrigMeio, EchoMeio);
Ultrasonic ultrasonicDir(TrigDir, EchoDir);


void setup()
  {
  Serial.begin(9600);
  }

void loop()
  {

  // Sensor da Esquerda
  
  float CMEsq;
  long MSEsq = ultrasonicEsq.timing();

  CMEsq = ultrasonicEsq.convert(MSEsq, Ultrasonic::CM);
  Serial.print("MS Esq: ");
  Serial.print(MSEsq);
  Serial.print(", CM Esq: ");
  Serial.println(CMEsq);
  delay(1500);

  //Sensor do Meio

  float CMMeio;
  long MSMeio = ultrasonicMeio.timing();

  CMMeio = ultrasonicMeio.convert(MSMeio, Ultrasonic::CM);
  Serial.print("MS Meio: ");
  Serial.print(MSMeio);
  Serial.print(", CM Meio: ");
  Serial.println(CMMeio);
  delay(3000);

  //Sensor da Direita

  
  float CMDir;
  long MSDir = ultrasonicDir.timing();

  CMDir = ultrasonicDir.convert(MSDir, Ultrasonic::CM);
  Serial.print("MS Dir: ");
  Serial.print(MSDir);
  Serial.print(", CM Dir: ");
  Serial.println(CMDir);
  delay(5000);
  
  
  }
