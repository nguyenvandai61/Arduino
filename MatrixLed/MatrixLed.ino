// Link1: http://osoyoo.com/2017/07/arduino-lesson-8x8-led-matrix/
// Link2: https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a


// 2-dimensional array of row pin numbers:
int Rows[] = {2,7,A5,5,13,A4,12,A2};  
// 2-dimensional array of column pin numbers:
int Cols[] = {6,11,10,1,A3,4,8,9};    

// Port 3 Not good change 3 -> 1
byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};
byte A[] = {B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};


unsigned char biglove[8][8] =     //the big "heart"   
{  
  0,0,1,0,0,0,0,0,  
  0,1,1,0,0,1,1,0,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  1,1,1,1,1,1,1,1,  
  0,1,1,1,1,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
};  
  
unsigned char smalllove[8][8] =      //the small "heart" 
{  
  0,0,0,0,0,0,0,0,  
  0,0,0,0,0,0,0,0,  
  0,0,1,0,0,1,0,0,  
  0,1,1,1,1,1,1,0,  
  0,1,1,1,1,1,1,0,  
  0,0,1,1,1,1,0,0,  
  0,0,0,1,1,0,0,0,  
  0,0,0,0,0,0,0,0,  
};  
  
void setup()  
{  
   // iterate over the pins:
  for(int i = 0;i<8;i++)  
  // initialize the output pins:
  {  
    pinMode(Rows[i],OUTPUT);  
    pinMode(Cols[i],OUTPUT);  
  }  
}  


void loop()  
{  
  
  for(int i = 0 ; i < 100 ; i++)         //Loop display 50 times
  {     

    Display2(O);
  }

  for(int i = 0 ; i < 100 ; i++)         //Loop display 50 times
  {     

    Display2(K);
  }
  delay(500);
   
   
}  
  
void Display(unsigned char dat[8][8])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(Cols[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(Rows[r],dat[r][c]);  
    }  
    delay(1);  
    Clear();  //Remove empty display light
  }
    
}  


void  Display2(byte buffer2[])
 { 
   // Turn on each row in series
    for (byte r = 0; r < 8; r++)        // count next row
     {
        digitalWrite(Rows[r], HIGH);    //initiate whole row
        for (byte c = 0; c < 8; c++)    // count next row
        {
          // if You set (~buffer2[i] >> a) then You will have positive
          digitalWrite(Cols[c], ~(buffer2[r] >> (8-c-1)) & 0x01); // initiate whole column
          
          delayMicroseconds(100);
          
          digitalWrite(Cols[c], 1);      // reset whole column
        }
        digitalWrite(Rows[r], LOW);     // reset whole row
        // otherwise last row will intersect with next row
    }
}

  
void Clear()                            
{  
  for(int i = 0;i<8;i++)  
  {  
    digitalWrite(Rows[i],LOW);  
    digitalWrite(Cols[i],HIGH);  
  }  
}  
