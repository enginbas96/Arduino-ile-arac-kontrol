int sariLed = 3, kirmiziLed = 4, maviLed = 2, kilitli = 0, kullaniciSifreSayaci = 0;
int solOnGuc = 8, solArkaGuc = 9, sagOnGuc = 10, sagArkaGuc = 11;
boolean arabaKullaniliyor = false;
String sifreGirisi;
void setup()
{
  pinMode(sariLed,OUTPUT);
  pinMode(kirmiziLed,OUTPUT);
  pinMode(maviLed,OUTPUT);
  pinMode(solOnGuc,OUTPUT);
  pinMode(solArkaGuc,OUTPUT);
  pinMode(sagOnGuc,OUTPUT);
  pinMode(sagArkaGuc,OUTPUT);  
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
        
        if(sifreGirisi == "1522")
        {
          digitalWrite(kirmiziLed,0);
          digitalWrite(sariLed,1);
          sifreGirisi = "";
          kilitli = 1;
          kullaniciSifreSayaci = 0;          
        }              
        else if(kullaniciSifreSayaci == 4 && kilitli == 0)
        {
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
                            
        if(sifreGirisi == "1453")
        {
          digitalWrite(sariLed,0);
          digitalWrite(maviLed,1);
          kilitli = 2;  
          sifreGirisi = "";           
          kullaniciSifreSayaci = 0;          
        }
        else if (sifreGirisi == "8888")
        {
          digitalWrite(kirmiziLed,1);
          digitalWrite(sariLed,0);
          kilitli = 0;  
          sifreGirisi = "";           
          kullaniciSifreSayaci = 0;    
        }        
         else if(kullaniciSifreSayaci == 4 && kilitli == 1)
         {
          kullaniciSifreSayaci = 0;
          sifreGirisi = "";
          digitalWrite(sariLed,0);
          delay(300);          
          digitalWrite(sariLed,1);
          delay(300); 
          digitalWrite(sariLed,0);
          delay(300);          
          digitalWrite(sariLed,1);
        }        
       }   
     }
      if(kilitli == 2)
      {
        if(Serial.available()>0)
        {
          char komut = Serial.read();
          sifreGirisi += komut;
           
          kullaniciSifreSayaci += 1;
          if(sifreGirisi == "8888")
          {
            digitalWrite(kirmiziLed,1);
            digitalWrite(maviLed,0);
            kilitli = 0;  
            sifreGirisi = "";
            kullaniciSifreSayaci = 0;          
          }
          else if (kullaniciSifreSayaci == 4)
          {       
            sifreGirisi = "";
            kullaniciSifreSayaci = 0;
          }
          else
          {
              arabaKullaniliyor = true;
              if(komut == 'S')
              {
                digitalWrite(solOnGuc,0);
                digitalWrite(sagOnGuc,0);
                digitalWrite(solArkaGuc,0);
                digitalWrite(sagArkaGuc,0);                
              }
              if(komut == 'F')
              {
                digitalWrite(solOnGuc,1);
                digitalWrite(sagOnGuc,1);
                digitalWrite(solArkaGuc,0);
                digitalWrite(sagArkaGuc,0);                
              }
              if(komut == 'B')
              {
                digitalWrite(solOnGuc,0);
                digitalWrite(sagOnGuc,0);
                digitalWrite(solArkaGuc,1);
                digitalWrite(sagArkaGuc,1);                
              }
              if(komut == 'L')
              {
                digitalWrite(solOnGuc,0);
                digitalWrite(sagOnGuc,1);
                digitalWrite(solArkaGuc,1);
                digitalWrite(sagArkaGuc,0);                
              }
              if(komut == 'R')
              {
                digitalWrite(solOnGuc,1);
                digitalWrite(sagOnGuc,0);
                digitalWrite(solArkaGuc,0);
                digitalWrite(sagArkaGuc,1);                
              }
            }
      }   
    }      
}
   
