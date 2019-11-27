#define KEY 7 
#define LED 13
bool ok;
int var;
String bf = "";

void setup()
{
  pinMode(KEY, OUTPUT);
  digitalWrite(KEY, LOW);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(3000);
  Serial.begin(9600);
  
  ok = Configure_HC05();

  }
bool Configure_HC05()
    {
      digitalWrite(KEY, HIGH);
      Serial.println("AT");
      delay(2000);
      
    if (!Serial.find("OK"))
      return false;
      Serial.println("AT+RMAAD");
      delay(2000);
 
    if (!Serial.find("OK"))
      return false;
      Serial.println("AT+PSWD=1234");
      delay(2000);
 
    if (!Serial.find("OK"))
      return false;
      Serial.println("AT+ROLE=0");
      delay(2000);

    if (!Serial.find("OK"))
      return false;
      digitalWrite(KEY, LOW);
      Serial.println("AT+RESET");
      delay(2000);
 
    if (!Serial.find("OK"))
      return false;
      delay(5000);
      Serial.println("Bluetooth Ready!");
      return true;
    }
  
void loop()
{
  if (ok)
  {
    if (Serial.available() > 0)
    {
      var = Serial.read();
      Serial.println(var);
      if (var == '1')
      {
        digitalWrite(LED, HIGH);
      }
      else if (var == '2')
      {
        digitalWrite(LED, LOW);
      }
     
    }
  }
   
  
}
