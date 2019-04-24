// Link1: http://osoyoo.com/2017/07/arduino-lesson-8x8-led-matrix/
// Link2: https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a


// 2-dimensional array of row pin numbers:
int Rows[] = {2, 7, A5, 5, 13, A4, 12, A2};
// 2-dimensional array of column pin numbers:
int Cols[] = {6, 11, 10, 1, A3, 4, 8, 9};
String string = "I LOVE YOU";
// Port 3 Not good change 3 -> 1
byte ALL[] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};

unsigned char characterHEX[][8] = {
  {B00000000, B00111100, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110},
  {B01111000, B01001000, B01001000, B01110000, B01001000, B01000100, B01000100, B01111100},
  {B00000000, B00011110, B00100000, B01000000, B01000000, B01000000, B00100000, B00011110},
  {B00000000, B00111000, B00100100, B00100010, B00100010, B00100100, B00111000, B00000000},
  {B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00111100, B00000000},
  {B00000000, B00111100, B00100000, B00111000, B00100000, B00100000, B00100000, B00000000},
  {B00000000, B00111110, B00100000, B00100000, B00101110, B00100010, B00111110, B00000000},
  {B00000000, B00100100, B00100100, B00111100, B00100100, B00100100, B00100100, B00000000},
  {B00000000, B00111000, B00010000, B00010000, B00010000, B00010000, B00111000, B00000000},
  {B00000000, B00011100, B00001000, B00001000, B00001000, B00101000, B00111000, B00000000},
  {B00000000, B00100100, B00101000, B00110000, B00101000, B00100100, B00100100, B00000000},
  {B00000000, B00100000, B00100000, B00100000, B00100000, B00100000, B00111100, B00000000},
  {B00000000, B00000000, B01000100, B10101010, B10010010, B10000010, B10000010, B00000000},
  {B00000000, B00100010, B00110010, B00101010, B00100110, B00100010, B00000000, B00000000},
  {B00000000, B00111100, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000},
  {B00000000, B00111000, B00100100, B00100100, B00111000, B00100000, B00100000, B00000000},
  {B00000000, B00111100, B01000010, B01000010, B01000010, B01000110, B00111110, B00000001},
  {B00000000, B00111000, B00100100, B00100100, B00111000, B00100100, B00100100, B00000000},
  {B00000000, B00111100, B00100000, B00111100, B00000100, B00000100, B00111100, B00000000},
  {B00000000, B01111100, B00010000, B00010000, B00010000, B00010000, B00010000, B00000000},
  {B00000000, B01000010, B01000010, B01000010, B01000010, B00100100, B00011000, B00000000},
  {B00000000, B00100010, B00100010, B00100010, B00010100, B00010100, B00001000, B00000000},
  {B00000000, B10000010, B10010010, B01010100, B01010100, B00101000, B00000000, B00000000},
  {B00000000, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B00000000},
  {B00000000, B01000100, B00101000, B00010000, B00010000, B00010000, B00010000, B00000000},
  {B00000000, B00111100, B00000100, B00001000, B00010000, B00100000, B00111100, B00000000},
  {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}
};
char character[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    //'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    ' '
                   };





unsigned char biglove[8][8] =     //the big "heart"
{
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 0, 0, 1, 1, 0,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
};

unsigned char smalllove[8][8] =      //the small "heart"
{
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

void setup()
{
  // iterate over the pins:
  for (int i = 0; i < 8; i++)
    // initialize the output pins:
  {
    pinMode(Rows[i], OUTPUT);
    pinMode(Cols[i], OUTPUT);
  }



}


void loop()
{


  for (int k = 0; k < string.length(); k++)
  {
    for (int i = 0; i < sizeof(character); i++)
    {
      if (string.charAt(k) == character[i])
      {
        for (int z = 0; z < 100; z++) {
          Display2(characterHEX[i]);
        }

      }
    }
    delay(300);
  }


}

void Display(unsigned char dat[8][8])
{
  for (int c = 0; c < 8; c++)
  {
    digitalWrite(Cols[c], LOW); //use thr column
    //loop
    for (int r = 0; r < 8; r++)
    {
      digitalWrite(Rows[r], dat[r][c]);
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
      digitalWrite(Cols[c], ~(buffer2[r] >> (8 - c - 1)) & 0x01); // initiate whole column

      delayMicroseconds(100);

      digitalWrite(Cols[c], 1);      // reset whole column
    }
    digitalWrite(Rows[r], LOW);     // reset whole row
    // otherwise last row will intersect with next row
  }
}


void Clear()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(Rows[i], LOW);
    digitalWrite(Cols[i], HIGH);
  }
}
