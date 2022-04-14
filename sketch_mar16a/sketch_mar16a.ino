int D0=6,D1=7,D2=8,D3=9,D4=10,D5=11,D6=12,D7=13;
int m1,m2,m3,m4,m5,m6,m7,m8;
int in1=A0,in2=A1,in3=A2,in4=A3;
void setup ()
{
pinMode(D0,INPUT);
pinMode(D1,INPUT);
pinMode(D2,INPUT);
pinMode(D3,INPUT);
pinMode(D4,INPUT);
pinMode(D5,INPUT);
pinMode(D6,INPUT);
pinMode(D7,INPUT);

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

Serial.begin(9600);
}                      //IF TIME MATTERS THEN I HAVE TO ADJUST DELAY FUNCTION



void backward()
{
  analogWrite(in1,0);
  analogWrite(in2,600);
  analogWrite(in3,0);
  analogWrite(in4,600); 
  delay(20); //it will help to turn but not good for black and white line 
}



void forward_1()
{
  analogWrite(in1,1000);
  analogWrite(in2,0);
  analogWrite(in3,1000);
  analogWrite(in4,0);
  delay(200); //if line is black and white otherwise remove it I CAN CHECK AND REMOVE IT THEN AGAIN WRITE IT FOR TRACK
}
void forward_2()
{
  analogWrite(in1,680);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);    //forward_n are use for normal turns and curves
}
void forward_3()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,680);
  analogWrite(in4,0);
}
void forward_4()
{
  analogWrite(in1,690);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);
}
void forward_5()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,690);
  analogWrite(in4,0);
}
void forward_6()
{
  analogWrite(in1,670);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);
}
void forward_7()
{
  analogWrite(in1,670);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);
}
void forward_8()
{
  analogWrite(in1,660);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);
}
void forward_9()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,660);
  analogWrite(in4,0);
}
void forward_10()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,700);
  analogWrite(in4,0);
}



void stp()
{
  analogWrite(in1,0);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,0); //it will make issue in turning
}



void left()
{
  analogWrite(in1,0);
  analogWrite(in2,700);
  analogWrite(in3,700);
  analogWrite(in4,0);
  delay(0);  
}
void left_10()
{
  analogWrite(in1,0);
  analogWrite(in2,700);
  analogWrite(in3,700);
  analogWrite(in4,0);
  delay(50);  
}
void left_1 ()
{
   analogWrite(in1,0);
   analogWrite(in2,680);
   analogWrite(in3,700);
   analogWrite(in4,0);  
   delay(0);
}
void left_2 ()
{
   analogWrite(in1,0);
   analogWrite(in2,680);
   analogWrite(in3,700);
   analogWrite(in4,0);  
   delay(0);
}
void left_3 ()
{
   analogWrite(in1,0);
   analogWrite(in2,0);
   analogWrite(in3,700);
   analogWrite(in4,0);  
   delay(1000); //FOR ACUTE ANGLE TURNelse if ((m1==0 && m2==1) && (m4==0 && m5==0) && m8==1)left_3();
}



void right()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,700);  
  delay(0); //right are use major turns
}
void right_10()
{
  analogWrite(in1,700);
  analogWrite(in2,0);
  analogWrite(in3,0);
  analogWrite(in4,700);  
  delay(50); //right are use major turns
}
void right_1 ()
{
   analogWrite(in1,700);
   analogWrite(in2,0);
   analogWrite(in3,0);
   analogWrite(in4,680);
   delay(0); 
}
void right_2 ()
{
   analogWrite(in1,700);
   analogWrite(in2,0);
   analogWrite(in3,0);
   analogWrite(in4,680);
   delay(0); 
}


void loop()
{
  m1=digitalRead(D0);
  m2=digitalRead(D1);
  m3=digitalRead(D2);
  m4=digitalRead(D3);
  m5=digitalRead(D4);
  m6=digitalRead(D5);
  m7=digitalRead(D6);
  m8=digitalRead(D7);

  Serial.print(m1);
  Serial.print(m2);
  Serial.print(m3);
  Serial.print(m4);
  Serial.print(m5);
  Serial.print(m6);
  Serial.print(m7);
  Serial.print(m8);
  Serial.println();

   if(m3==1 && m4==0 && m5==0 && m6==1) 
   forward_1();



   else if ((m1==0 && m2==0) && ((m3==0 || m4==0 || m5==0 || m6==0) && m8==1))
   left_10();

   else if ((m1==0 && m2==0) && ((m3==1 || m4==1 || m5==1 || m6==1) && m8==1))
   left();
  
   else if ((m1==0 && m2==1) && ((m3==1 || m4==1 || m5==1 || m6==1) && m8==1))
   left_1();

   else if ((m1==1 && m2==0) && ((m3==1 || m4==1 || m5==1 || m6==1) && m8==1))
   left_1();

 


   else if ((m8==0 && m7==0) && ((m6==0 || m5==0 || m4==0 || m3==0) && m1==1))
   right_10();

   else if ((m8==0 && m7==0) && ((m6==1 || m4==1 || m5==1 || m3==1) && m1==1))
   right();

   else if ((m8==1 && m7==0) && ((m3==1 || m4==1 || m5==1 || m6==1) && m1==1))
   right_1();

   else if ((m8==0 && m7==1) && ((m3==1 || m4==1 || m5==1 || m6==1) && m1==1))
   right_1();

    


   else if(m1==1 && m3==0 && m4==0 && m5==0 && m6==0 && m8==1) 
   forward_1();

   else if(m3==0 && m4==0 && m5==1 && m6==1) 
   forward_2();
  
   else if(m3==1 && m4==1 && m5==0 && m6==0) 
   forward_3();

   else if(m3==0 && m4==0 && m5==0 && m6==1) 
   forward_4();

   else if(m3==1 && m4==0 && m5==0 && m6==0) 
   forward_5();

   else if(m3==0 && m4==1 && m5==1 && m6==1) 
   forward_6();

   else if(m3==1 && m4==1 && m5==1 && m6==0) 
   forward_7();

   else if((m3==0 && m4==0 && m5==0 && m6==0) && (m1==1 || m2==1))
   forward_8();

   else if((m3==0 && m4==0 && m5==0 && m6==0) && (m7==1 || m8==1))
   forward_9();

   else if((m1==1 && m2==1 && m3==1) && (m4==0 || m5==0) && (m6==1 && m7==1 && m8==1))
   forward_10();



   

   else if ((m1==1 && m2==0) && ((m3==0 || m4==0 || m5==0 || m6==0) && m8==1))
   left_2 ();


   else if ((m8==1 && m7==0) && ((m6==0 || m5==0 || m4==0 || m3==0) && m1==1))
   right_2 ();




  
   
   else if(m1==0 && m2==0 && m3==0 && m4==0 && m5==0 && m6==0 && m7==0 && m8==0)
   forward_1();

   else if(m1==1 && m2==1 && m3==1 && m4==1 && m5==1 && m6==1 && m7==1 && m8==1)
   backward();

}
