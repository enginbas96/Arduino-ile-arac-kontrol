int sariLed = 3;
int kirmiziLed = 4;
int maviLed = 2;
int kilitli = 0;
int kullaniciSifreSayaci = 0;
String sifreGirisi;

void setup()
{
  pinMode(sariLed,OUTPUT);
  pinMode(kirmiziLed,OUTPUT);
  pinMode(maviLed,OUTPUT);
  Serial.begin(9600);
}



void loop()
{
  if(kilitli == 0)
    {
       digitalWrite(kirmiziLed,1);
       if(Serial.available()>0)
       {        
        char komut = Serial.read();        
        sifreGirisi += komut;
        kullaniciSifreSayaci += 1;
              
        if(sifreGirisi == "1111")
        {
          digitalWrite(kirmiziLed,0);
          digitalWrite(sariLed,1);
          sifreGirisi = "";
          kilitli = 1;
          kullaniciSifreSayaci = 0;          
        }
        
        else if(kullaniciSifreSayaci == 4 && kilitli == 0)
        {
          Serial.println("Aktivasyon Şifreniz Yanlış Tekrar Deneyin");
          kullaniciSifreSayaci = 0;
          sifreGirisi = "";
          digitalWrite(kirmiziLed,0);
          delay(300);          
          digitalWrite(kirmiziLed,1);
          delay(300); 
          digitalWrite(kirmiziLed,0);
          delay(300);          
          digitalWrite(kirmiziLed,1);
        }               
       }      
    }
    if(kilitli == 1)
    {
      if(Serial.available()>0)
      {
        char komut = Serial.read(); 
        sifreGirisi += komut; 
        kullaniciSifreSayaci += 1;
                    
        if(sifreGirisi == "1234")
        {
          digitalWrite(sariLed,0);
          digitalWrite(maviLed,1);
          kilitli = 2;  
          sifreGirisi = "";        
        } 
        else if(kullaniciSifreSayaci == 4 && kilitli == 1)
        {
          Serial.println("Şifreniz Yanlış Tekrar Deneyin");
          kullaniciSifreSayaci = 0;          
          if(sifreGirisi != "8888")
          {
            digitalWrite(sariLed,0);
            delay(300);          
            digitalWrite(sariLed,1);
            delay(300); 
            digitalWrite(sariLed,0);
            delay(300);          
            digitalWrite(sariLed,1);
          } 
          sifreGirisi = "";         
        }   
       }      
    }
  if((kilitli == 1 || kilitli == 2) && Serial.available()>0)
  {
   
              
        char komut = Serial.read();        
        sifreGirisi += komut;
        kullaniciSifreSayaci += 1;
              
        if(sifreGirisi == "8888")
        {
          digitalWrite(kirmiziLed,1);
          digitalWrite(maviLed,0);
          digitalWrite(sariLed,0);
          sifreGirisi = "";
          kilitli = 0;
          kullaniciSifreSayaci = 0;          
        }
        if(kullaniciSifreSayaci == 4)
        {
          kullaniciSifreSayaci = 0;
        }
    
}}
