//  Copyright ITT Eugenio Barsanti / Produced by MARAZZATO MATTEO - 4BI  //

#include <LiquidCrystal.h>


int btnSX = 8;
int btnCX = 9;
int btnDX = 10;

int lives = 1;
bool select;

int typeOfCharact;
int location;

int startTime;
int finalTime;

//int nmbrOfLivels;
//bool choose;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


byte heart[8] = 
{
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
};

byte good[8] = 
{
  B00000,
  B00000,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000,
};

byte bad[8] = 
{
  B00000,
  B00000,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000,
};


void setup() 
{
  randomSeed(analogRead(0));
  //lives = random(1,6);
  
  bool select = false;
  bool choose = false;
  
  lcd.createChar(0, heart);
  lcd.createChar(1, good);
  lcd.createChar(2, bad);
  
  lcd.begin(16,2);
  
  moveDisplay();

  lcd.clear();

}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  
  while (select == false)
  {
    printStringLives();
    selectLives();
  }

    delay(500);
    
  if (lives >= 1)
  {
    for (int i = 1;i<=lives*i;i++)
    {
      printCharacter();
      delay(750);
    }
  }

  else
  {
    //lcd.clear();
    timer();
    delay(4000);
    select = false;
  }

  lcd.clear();
}



void selectLives()
{
  if (digitalRead(btnSX) == HIGH && lives > 1)
  {
    lives--;
    lcd.clear();
    for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
    delay(200);
  }

  else if (digitalRead(btnDX) == HIGH && lives < 6) 
  {
    lives++;
    lcd.clear();
    for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
    delay(200);
  }

  else if (digitalRead(btnCX) == HIGH)
  {
    select = true;
    startTime = millis();
    lcd.clear();
  }
}

void moveDisplay()
{
  lcd.setCursor(4,0);
  lcd.print("PUSH THE");
  lcd.setCursor(5,1);
  lcd.print("BUTTON");
    delay(1200);
    
  for(int i = 0; i<16; i++)
  {
    lcd.scrollDisplayLeft();
    delay(120);
  }
}

void printStringLives()
{
  lcd.setCursor(10,0);
  lcd.print("SELECT");
  lcd.setCursor(6,1);
  lcd.print("YOUR LIVES");
}

void timer()
{
    finalTime = millis();
    lcd.setCursor(1,0);
    lcd.print("PLAYING TIME:");
    lcd.setCursor(7,1);
    lcd.print((finalTime - startTime)/1000);
}

void printCharacter()
{
  typeOfCharact = random(0,9);
  location = random(1,4);

  if (location == 1)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.write(byte(1));
      redrawLives();
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(3,1);
      lcd.write(byte(2));
      redrawLives();
      
        delay(500);

      if (digitalRead(btnSX) == HIGH)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
    
  }

  else if (location == 2)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(8,1);
      lcd.write(byte(1));
      redrawLives();
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(8,1);
      lcd.write(byte(2));
      redrawLives();
      
        delay(500);

      if (digitalRead(btnCX) == HIGH)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
  }

  else if (location == 3)
  {
    if (typeOfCharact < 8)
    {
      lcd.clear();
      lcd.setCursor(12,1);
      lcd.write(byte(1));
      redrawLives();
    }

    else if (typeOfCharact >= 8)
    {
      lcd.clear();
      lcd.setCursor(12,1);
      lcd.write(byte(2));
      redrawLives();
      
        delay(500);

      if (digitalRead(btnDX) == HIGH)
      {
        redrawLives();
      }

      else
      {
        lives--;
        redrawLives();
      }
    }
  }
  
}

void redrawLives()
{
  for (int i = 0;i<lives;i++)
    {
      lcd.setCursor(i,0);
      lcd.write(byte(0));
    }
}

void printLevels()
{
  lcd.setCursor(0,0);
  lcd.print("EASY");
  lcd.setCursor(5,1);
  lcd.print("MEDIUM");
  lcd.setCursor(12,0);
  lcd.print("HARD");
}

void finalScore()
{
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("PLAYING TIME:");
  lcd.setCursor(7,1);
  lcd.print((finalTime - startTime)/1000);
}




















//  Copyright ITT Eugenio Barsanti / Produced by MARAZZATO MATTEO - 4BI  //
