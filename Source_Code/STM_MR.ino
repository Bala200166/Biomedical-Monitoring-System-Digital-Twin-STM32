

#include <Arduino.h>
#include <LiquidCrystal.h>

extern "C" void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}

const int rs = PB4, en = PB5, d4 = PB12, d5 = PB13, d6 = PB14, d7 = PB15;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int oc;

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot
int sensorValue3 = 0;        // value read from the pot

void setup() {

  Serial1.begin(9600);
  lcd.begin(16,2);
  lcd.print("HEALTH MONITOR         ");
  delay(2000);
  lcd.clear();

pinMode(PA8,OUTPUT);
}

int i;
int sensorValue;

int temp,gas,flame;
int xc;
int count=0,fl;
unsigned long time1=0;  // store the initial time
unsigned long time2;    // store the current time
  int count1,count2;
void loop() {
  sensorValue1 = analogRead(PA0)/2;  
  sensorValue1 = analogRead(PA0)/19;  
  
  sensorValue2 = analogRead(PA2)/2;  

  sensorValue3 = analogRead(PA3)/2;  



  lcd.setCursor(0, 0);
  lcd.print("T:");
  delay(20);   
       delay(20);      
  lcd.write((sensorValue1/100)+0x30);      
      delay(20);  
  lcd.write(((sensorValue1%100)/10)+0x30);      
      delay(20); 
  lcd.write((sensorValue1%10)+0x30);       
    delay(20);  

  // read the value from the sensor:
  if(count==0)
  {
    time1=millis();
  }
  time2=millis();
  
  sensorValue = analogRead(A1);   


   lcd.setCursor(6, 0);
   lcd.print("H:");
  delay(20);   
       delay(20);      
  lcd.write((count1/100)+0x30);      
      delay(20);  
  lcd.write(((count1%100)/10)+0x30);      
      delay(20); 
  lcd.write((count1%10)+0x30);       
    delay(20);  

  lcd.setCursor(12, 0);
   lcd.print("P");
  delay(20);   
       delay(20);      
  lcd.write((count2/100)+0x30);      
      delay(20);  
  lcd.write(((count2%100)/10)+0x30);      
      delay(20); 
  lcd.write((count2%10)+0x30);       
    delay(20);  

    
  if(sensorValue>356)
  { 
    if(fl==0)
    {
    increment();
    fl=1;
    }
  }
  else
  {
   fl=0; 
  }


  
 lcd.setCursor(0, 1);
  lcd.print("R:");
  delay(20);   
       delay(20);      
  lcd.write((sensorValue2/100)+0x30);      
      delay(20);  
  lcd.write(((sensorValue2%100)/10)+0x30);      
      delay(20); 
  lcd.write((sensorValue2%10)+0x30);       
    delay(20);  


    
 if(sensorValue1>40)
    digitalWrite(PA8,1);
  else if(sensorValue2>20)
    digitalWrite(PA8,1);
  else if(count1>75)
    digitalWrite(PA8,1);
  else
    digitalWrite(PA8,0);

 

if(oc==0)
{
  oc=60;
  Serial.print("*Temp=");
  Serial.print(sensorValue1);
  Serial.print("_Resp=");
  Serial.print(sensorValue2);
  Serial.print("_HB=");
  Serial.print(count1);
  Serial.print("_PX=");
  Serial.print(count2);

  if(sensorValue1>40)
    Serial1.print("~1");
  else if(sensorValue2>20)
    Serial1.print("~1");
  else if(count1>75)
    Serial1.print("~1");
  else
    Serial1.print("~0");

    Serial1.print('#');  

  
}

delay(300);
    
oc--;

//Serial.write(','); 

  if(time2>=time1+10000)
  { 
    if(count>2)
      {
      count1=66+ (count%20);
      count2=90+count%10;
      }
  else
    {
    count1=0;
    count2=0;
    }
      count=0;


      
  }

}
void increment()
{
  count++;
}

